#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

const int CANNOT_DETERMINE = -1.0;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> relations;
        for (int i = 0; i < values.size(); i++) {
            auto equation = equations[i];
            auto value = values[i];
            
            auto fromVar = equation[0];
            auto toVar = equation[1];
            
            relations[fromVar][toVar] = value;
            
            if (value != 0.0) {
                // TODO: handle floating point precision problem
                relations[toVar][fromVar] = 1.0 / value;    
            } else {
                relations[toVar][fromVar] = CANNOT_DETERMINE;
            }
            
            relations[fromVar][fromVar] = 1.0;
            relations[toVar][toVar] = 1.0;
        }
        
        vector<double> answer;
        for (auto query: queries) {
            answer.push_back(compute(query, relations));
        }
        return answer;
    }
    
private:
    double compute(vector<string>& query, unordered_map<string, unordered_map<string, double>>& relations) {
        auto fromVar = query[0];
        auto toVar = query[1];
            
        unordered_set<string> visited;
        vector<pair<string, double>> stack{pair{fromVar, 1.0}};

        while (stack.size() > 0) {
            auto [curr, val] = stack.back();
            stack.pop_back();
            
            if (curr == toVar && relations.count(curr) > 0) {
                return val;
            }
            
            if (visited.count(curr) > 0) {
                continue;
            }
            visited.insert(curr);
            
            for (auto& [nextVar, relationVal]: relations[curr]) {
                double nextVal = val == CANNOT_DETERMINE ? CANNOT_DETERMINE : (val * relationVal);
                stack.push_back(pair{nextVar, nextVal});
            }
        }

        return CANNOT_DETERMINE;
    }
};