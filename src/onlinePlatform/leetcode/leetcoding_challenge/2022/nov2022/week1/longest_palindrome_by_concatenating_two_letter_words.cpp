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
    int longestPalindrome(vector<string>& words) {
        unordered_map<char, unordered_map<char, int>> startEndCounter;
        unordered_map<char, unordered_map<char, int>> endStartCounter;
        
        for (string word: words) {
            addCount(startEndCounter, word[0], word[1]);
            addCount(endStartCounter, word[1], word[0]);
        }
        
        int answer = 0;
        bool hasRemainSame = false;
        
        for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                if (ch1 == ch2) {
                    answer += 4 * (getCount(startEndCounter, ch1, ch2) / 2);
                    if (getCount(startEndCounter, ch1, ch2) % 2 == 1) {
                        hasRemainSame = 1;
                    }
                } else {
                    answer += 2 * min(getCount(startEndCounter, ch1, ch2), getCount(endStartCounter, ch1, ch2));
                }
                setCountToZero(startEndCounter, ch1, ch2);
                setCountToZero(endStartCounter, ch1, ch2);
            }   
        }
        
        if (hasRemainSame) {
            answer += 2;
        }
        return answer;
    }

private:    
    void addCount(unordered_map<char, unordered_map<char, int>> &counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            counter[ch1] = unordered_map<char, int>();
        }
        
        if (counter[ch1].count(ch2) == 0) {
            counter[ch1][ch2] = 0;
        }
        
        counter[ch1][ch2]++;
    }
    
    void setCountToZero(unordered_map<char, unordered_map<char, int>> &counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            return;
        }
        
        if (counter[ch1].count(ch2) == 0) {
            return;
        }
        
        counter[ch1][ch2] = 0;
    }
    
    int getCount(unordered_map<char, unordered_map<char, int>> &counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            return 0;
        }
        
        if (counter[ch1].count(ch2) == 0) {
            return 0;
        }
        
        return counter[ch1][ch2];
    }
};

class WASolution2 {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<char, unordered_map<char, int>> startEndCounter;
        unordered_map<char, unordered_map<char, int>> endStartCounter;
        
        for (string word: words) {
            addCount(startEndCounter, word[0], word[1]);
            addCount(endStartCounter, word[1], word[0]);
        }
        
        int answer = 0;
        int same = 0;
        
        for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                if (ch1 == ch2) {
                    same = max(same, 2 * getCount(startEndCounter, ch1, ch2));
                } else {
                    answer += 2 * min(getCount(startEndCounter, ch1, ch2), getCount(endStartCounter, ch1, ch2));
                }
                setCountToZero(startEndCounter, ch1, ch2);
                setCountToZero(endStartCounter, ch1, ch2);
            }   
        }
            
        return answer + same;
    }

private:    
    void addCount(unordered_map<char, unordered_map<char, int>> &counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            counter[ch1] = unordered_map<char, int>();
        }
        
        if (counter[ch1].count(ch2) == 0) {
            counter[ch1][ch2] = 0;
        }
        
        counter[ch1][ch2]++;
    }
    
    void setCountToZero(unordered_map<char, unordered_map<char, int>> &counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            return;
        }
        
        if (counter[ch1].count(ch2) == 0) {
            return;
        }
        
        counter[ch1][ch2] = 0;
    }
    
    int getCount(unordered_map<char, unordered_map<char, int>> &counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            return 0;
        }
        
        if (counter[ch1].count(ch2) == 0) {
            return 0;
        }
        
        return counter[ch1][ch2];
    }
};

class WASolution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<char, unordered_map<char, int>> startEndCounter;
        unordered_map<char, unordered_map<char, int>> endStartCounter;
        
        for (string word: words) {
            addCount(startEndCounter, word[0], word[1]);
            addCount(endStartCounter, word[1], word[0]);
        }
        
        int answer = 0;
        
        for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                if (ch1 == ch2) {
                    answer += 2 * getCount(startEndCounter, ch1, ch2);
                } else {
                    answer += 2 * min(getCount(startEndCounter, ch1, ch2), getCount(endStartCounter, ch1, ch2));
                }
                setCountToZero(startEndCounter, ch1, ch2);
                setCountToZero(endStartCounter, ch1, ch2);
            }   
        }
            
        return answer;
    }

private:    
    void addCount(unordered_map<char, unordered_map<char, int>> counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            counter[ch1] = unordered_map<char, int>();
        }
        
        if (counter[ch1].count(ch2) == 0) {
            counter[ch1][ch2] = 0;
        }
        
        counter[ch1][ch2]++;
    }
    
    void setCountToZero(unordered_map<char, unordered_map<char, int>> counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            return;
        }
        
        if (counter[ch1].count(ch2) == 0) {
            return;
        }
        
        counter[ch1][ch2] = 0;
    }
    
    int getCount(unordered_map<char, unordered_map<char, int>> counter, char ch1, char ch2) {
        if (counter.count(ch1) == 0) {
            return 0;
        }
        
        if (counter[ch1].count(ch2) == 0) {
            return 0;
        }
        
        return counter[ch1][ch2];
    }
};

int main() {
    Solution soln;
    vector<string> words = {"lc","cl","gg"};
    cout << soln.longestPalindrome(words) << endl;
}