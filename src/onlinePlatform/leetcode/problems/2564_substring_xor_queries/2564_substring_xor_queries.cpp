#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<long, int> startPos;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                continue;
            }
            
            int val = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (val >= 2147483647 / 2 + 1 || i + j >= s.size()) {
                    break;
                }
                val *= 2;
                if (s[i + j] == '1') {
                    val += 1;
                }

                if (startPos.count(val) == 0) {
                    startPos[val] = i;
                }
            }
        }
        
        int firstZeroIdx = s.find("0");
        
        vector<vector<int>> answer;        
        for (auto &query: queries) {
            int first = query[0], second = query[1];
            int val = first ^ second;


            if (val == 0) {
                answer.push_back({firstZeroIdx, firstZeroIdx});
            } else {
                if (startPos.count(val) > 0) {
                    int endPos = startPos[val] + getLength(val) - 1;
                    answer.push_back({startPos[val], endPos});
                } else {
                    answer.push_back({-1, -1});
                }
            }
        }
        
        return answer;
    }
    
private:
    int getLength(int x) {
        int length = 0;
        while (x > 0) {
            length++;
            x /= 2;
        }
        return length;
    }
};

int main() {
    Solution soln;
    string s = "101101";
    vector<vector<int>> queries = {{0,5},{1,2}};
    soln.substringXorQueries(s, queries);
    return 0;
}