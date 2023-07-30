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

const int UNINITIALIZED = 9999999;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.size() == 0) {
            return 0;
        }

        memo = vector<vector<vector<int>>>();
        for (int chIdx = 'a' - 'a'; chIdx <= 'z' - 'a' + 1; ++chIdx) {
            memo.push_back(vector<vector<int>>());
            for (int i = 0; i <= s.size(); ++i) {
                memo[chIdx].push_back(vector<int>(s.size() + 1, UNINITIALIZED));
            }
        }
        
        return 1 + findMin(s, s[0], 0, s.size() - 1);
    }
    
private:
    vector<vector<int>> chPositions;
    
    vector<vector<vector<int>>> memo;
    
    int findMin(string& s, char currCh, int lo, int hi) {
        if (lo > hi) {
            return 0;
        }
        
        if (lo == hi) {
            if (currCh == s[lo]) {
                return 0;
            } else {
                return 1;
            }
        }
        
        int currChIdx = currCh - 'a';
        if (memo[currChIdx][lo][hi] == UNINITIALIZED) {
            int firstStart = UNINITIALIZED;
            int firstEnd = -1;
            for (int i = lo; i <= hi; ++i) {
                if (s[i] != currCh) {
                    if (firstStart == UNINITIALIZED) {
                        firstStart = i;
                    }
                    firstEnd = i;
                }
                int count = findMin(s, currCh, firstStart, firstEnd); 
                if (firstStart != UNINITIALIZED) {
                    count = min(count, 1 + findMin(s, s[firstStart], firstStart, firstEnd));
                }

                if (i < hi) {
                    if (s[i + 1] != currCh) {
                        count++;
                    }
                    count += findMin(s, s[i + 1], i + 1, hi);
                }
                memo[currChIdx][lo][hi] = min(
                    memo[currChIdx][lo][hi],
                    count
                );
            }
        }
        return memo[currChIdx][lo][hi];
    }
};

/*
class WASolution3 {
public:
    int strangePrinter(string s) {
        // merge substring with same characters
        vector<char> stack;
        for (auto ch: s) {
            if (stack.size() == 0 || stack.back() != ch) {
                stack.push_back(ch);
            }
        }
        s = string(stack.begin(), stack.end());        

        chPositions = vector<vector<int>>();
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            chPositions.push_back(vector<int>());
        }
        
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            chPositions[ch - 'a'].push_back(i);
        }
        
        memo = vector<vector<int>>();
        for (int i = 0; i <= s.size(); ++i) {
            memo.push_back(vector<int>(s.size() + 1, UNINITIALIZED));
        }
        
        return findMin(s, 0, s.size() - 1);
    }
    
private:
    vector<vector<int>> chPositions;
    
    vector<vector<int>> memo;
    
    int findMin(string& s, int lo, int hi) {
        if (lo > hi) {
            return 0;
        }
        
        if (lo == hi) {
            return 1;
        }
        
        if (memo[lo][hi] != UNINITIALIZED) {
            return memo[lo][hi];
        }
        
        auto chIdx = s[lo] - 'a';
        auto it = lower_bound(chPositions[chIdx].begin(), chPositions[chIdx].end(), lo);

        int beginPosIdx = distance(chPositions[chIdx].begin(), it);

        for (int posIdx = beginPosIdx; posIdx < chPositions[chIdx].size(); posIdx++) {
            auto nextHi = chPositions[chIdx][posIdx];
            int turns = 1 + findMin(s, nextHi + 1, hi);

            if (posIdx > beginPosIdx) {
                turns += findMin(s, lo + 1, nextHi - 1);
            }
            memo[lo][hi] = min(
                memo[lo][hi],
                turns
            );
        }

        return memo[lo][hi];
    }
};

class WASolution2 {
public:
    int strangePrinter(string s) {
        memo = unordered_map<string, int>();
        return findMin(s);
    }
    
private:
    unordered_map<string, int> memo;
    
    int findMin(string s) {
// cout << s << endl;

        if (s.size() == 0) {
            return 0;
        }
        
        if (memo.count(s) > 0) {
            return memo[s];
        }
        
        memo[s] = 1 + findMin(s.substr(1, s.size() - 1));
        // cout << s << " (before): " << memo[s] << endl;
        auto ch = s[0];
        string curr = "";
        curr.reserve(s.size());
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ch) {
                memo[s] = min(
                    memo[s],
                    1 + findMin(curr) + findMin(s.substr(i + 1, s.size() - i - 1))
                );

                if (s == "abbbbbabbbaaaaaaaaaaaa") {
                    cout << curr << " - " << memo[s] << endl; 
                }

            } else {
                curr += s[i];
            }
        }
        
        // cout << s << " (after): " << memo[s] << endl;
        
        return memo[s];
    }
};

class WASolution {
public:
    int strangePrinter(string s) {
        chPositions = vector<vector<int>>();
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            chPositions.push_back(vector<int>());
        }
        
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            chPositions[ch - 'a'].push_back(i);
        }
        
        memo = vector<vector<int>>();
        for (int i = 0; i <= s.size(); ++i) {
            memo.push_back(vector<int>(s.size() + 1, UNINITIALIZED));
        }
        
        return findMin(s, 0, s.size() - 1);
    }
    
private:
    vector<vector<int>> chPositions;
    
    vector<vector<int>> memo;
    
    int findMin(string& s, int lo, int hi) {
        cout << lo << " " << hi << endl;

        if (lo > hi) {
            return 0;
        }
        
        if (lo == hi) {
            return 1;
        }
        
        if (memo[lo][hi] != UNINITIALIZED) {
            return memo[lo][hi];
        }
        
        auto chIdx = s[lo] - 'a';
        auto it = lower_bound(chPositions[chIdx].begin(), chPositions[chIdx].end(), lo);

        int beginPosIdx = distance(chPositions[chIdx].begin(), it);

        for (int posIdx = beginPosIdx; posIdx < chPositions[chIdx].size(); posIdx++) {
            auto nextHi = chPositions[chIdx][posIdx];
            int turns = 1 + findMin(s, nextHi + 1, hi);

            cout << nextHi << "_" << turns << endl;
 
            if (posIdx > beginPosIdx) {
                turns += findMin(s, chPositions[chIdx][posIdx - 1] + 1, nextHi - 1);
            }
            
            cout << nextHi << "__" << turns << endl;

            memo[lo][hi] = min(
                memo[lo][hi],
                turns
            );
        }

        // cout << "size: " << chPositions[chIdx].size() << " dist: " << distance(chPositions[chIdx].begin(), it) << " isEnd: " << (it == chPositions[chIdx].end()) << endl; 
        
        while (it != chPositions[chIdx].end()) {        
            it++;
        }
        
        cout << lo << " " << hi << ": " << memo[lo][hi] << endl;


        return memo[lo][hi];
    }
};
*/

int main() {
    Solution soln;

    // string s = "aaabbb";
    // string s = "aba";
    // string s = "ixpmjltdrrdxxtjhjnxupoqdiisqhqhpzysbknpwjqozuzugfezepissmxxjzkouhdtcszsujbsoerrzfsasqpqkmqdrckudctdw";
    // string s = "ixpmjltdrrdxx";
    // string s = "abbbbbabbbbbabbbbbabbbaaaaaaaaaaaa";
    // string s = "ababa";
    // string s = "aaa";
    string s = "aabbabbaa";

    cout << soln.strangePrinter(s) << endl;

    return 0;
}