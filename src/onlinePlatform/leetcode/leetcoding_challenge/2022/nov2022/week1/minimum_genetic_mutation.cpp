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

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int IMPOSSIBLE = -1;
        
        unordered_set<string> bankSet = unordered_set<string>(bank.begin(), bank.end());
        if (bankSet.count(end) == 0) {
            return IMPOSSIBLE;
        }
        bankSet.insert(start);
        
        unordered_map<string, unordered_set<string>> neighbours;
        for (string fromStr: bankSet) {
            for (string toStr: bankSet) {
                if (fromStr != toStr && getDiff(fromStr, toStr) == 1) {
                    neighbours[fromStr].insert(toStr);
                }
            }
        }
        
        int numMutations = 0;
        unordered_set<string> visited;
        queue<string> q = queue<string>({start});
        
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == end) {
                    return numMutations;
                }
                if (visited.count(curr) > 0) {
                    continue;
                }
                visited.insert(curr);
                
                for (string nextStr: neighbours[curr]) {
                    q.push(nextStr);
                }
            }
            numMutations++;
        }
        
        return -1;
    }
    
private:
    int getDiff(string str1, string str2) {
        // TODO: validate string all have same length
        int diff = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                diff++;
            }
        }
        return diff;
    }
};

int main() {
    Solution soln;
    string start = "AACCGGTT", end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout << soln.minMutation(start, end, bank) << endl;
}