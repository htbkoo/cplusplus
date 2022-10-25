#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text


class Solution {
public:
    int maxLength(vector<string>& arr) {
        storedArr = arr;
        memo = unordered_map<string, int>();
        
        return findLongest(0, 0);
    }
    
private:
    unordered_map<string, int> memo;
    vector<string> storedArr;
    
    int findLongest(int i, int used) {
        if (i >= storedArr.size()) {
            return 0;
        }
        
        string SEPARTOR = "_";
        string key = to_string(i) + SEPARTOR + to_string(used);
        
        if (memo.count(key) > 0) {
            return memo[key];
        }
                
        memo[key] = findLongest(i + 1, used);
            
        if (canConcatendate(i, used)) {
            int newUsed = updateBitmask(i, used);
            memo[key] = max(
                (int) memo[key],
                (int) (storedArr[i].size() + findLongest(i + 1, newUsed))
            );
        } 
        
        return memo[key];
    }
    
    bool canConcatendate(int i, int used) { 
        unordered_set<char> usedChars = unordered_set<char>(storedArr[i].begin(), storedArr[i].end());
        if (usedChars.size() != storedArr[i].size()) {
            return false;
        }

        for (int j = 0; j < storedArr.size(); j++) {
            if (isUsed(j, used)) {
                for (char ch: storedArr[j]) {
                    if (usedChars.count(ch)) {
                        return false;
                    }
                    usedChars.insert(ch);
                }
            }
        }
        return true;
    }

    bool isUsed(int j, int used) {
        return (((int) pow(2, j)) & used) > 0;
    }
    
    int updateBitmask(int i, int used) {
        return ((int) pow(2, i)) | used;
    }
};

int main() {
    Solution soln;

    // vector<string> arr = {"un","iq","ue"};
    vector<string> arr = {"cha","r","act","ers"};
    cout << soln.maxLength(arr) << endl;
}