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
    int countSubstrings(string s) {
        int answer = s.size(); // for 1-length palinedomes

        vector<bool> isPalindrome;

        // odd length
        isPalindrome = vector<bool>(s.size(), true);

        for (int length = 3; length <= s.size(); length += 2) {
            vector<bool> prev = isPalindrome;
            isPalindrome = vector<bool>();

            for (int i = 0; i < s.size(); ++i) {
                int right = i + length - 1;
                if (right >= s.size()) {
                    break;
                }

                if (prev[i + 1] && s[i] == s[right]) {
                    isPalindrome.push_back(true);
                    answer++;
                } else {
                    isPalindrome.push_back(false);
                }
            }
        }

        // even length
        isPalindrome = vector<bool>();
        for (int i = 0; i < s.size(); ++i) {
            int right = i + 1;
            if (right >= s.size()) {
                break;
            }

            if (s[i] == s[right]) {
                isPalindrome.push_back(true);
                answer++;
            } else {
                isPalindrome.push_back(false);
            }
        }

        for (int length = 4; length <= s.size(); length += 2) {
            vector<bool> prev = isPalindrome;
            isPalindrome = vector<bool>();

            for (int i = 0; i < s.size(); ++i) {
                int right = i + length - 1;
                if (right >= s.size()) {
                    break;
                }

                if (prev[i + 1] && s[i] == s[right]) {
                    isPalindrome.push_back(true);
                    answer++;
                } else {
                    isPalindrome.push_back(false);
                }
            }
        }

        return answer;
    }
};

class WASolution2 {
public:
    int countSubstrings(string s) {
        int answer = s.size(); // for 1-length palinedomes

        vector<bool> isPalindrome;

        // odd length
        isPalindrome = vector<bool>(s.size(), true);

        for (int length = 3; length <= s.size(); length += 2) {
            vector<bool> prev = isPalindrome;
            isPalindrome = vector<bool>();

            for (int i = 0; i < s.size(); ++i) {
                int right = i + length - 1;
                if (right >= s.size()) {
                    break;
                }

                if (prev[i] && s[i] == s[right]) {
                    isPalindrome.push_back(true);
                    answer++;
                } else {
                    isPalindrome.push_back(false);
                }
            }
        }



        // even length
        isPalindrome = vector<bool>();
        for (int i = 0; i < s.size(); ++i) {
            int right = i + 1;
            if (right >= s.size()) {
                break;
            }

            if (s[i] == s[right]) {
                isPalindrome.push_back(true);
                answer++;
            } else {
                isPalindrome.push_back(false);
            }
        }

        for (int length = 4; length <= s.size(); length += 2) {
            vector<bool> prev = isPalindrome;
            isPalindrome = vector<bool>();

            for (int i = 0; i < s.size(); ++i) {
                int right = i + length - 1;
                if (right >= s.size()) {
                    break;
                }

                if (prev[i + 1] && s[i] == s[right]) {
                    isPalindrome.push_back(true);
                    answer++;
                } else {
                    isPalindrome.push_back(false);
                }
            }
        }

        return answer;
    }
};

class WASolution {
public:
    int countSubstrings(string s) {
        int answer = s.size(); // for 1-length palinedomes

        vector<int> isPalindrome;

        // odd length
        isPalindrome = vector<int>(s.size(), true);

        for (int length = 3; length <= s.size(); length += 2) {
            vector<int> prev = isPalindrome;
            isPalindrome = vector<int>();

            for (int i = 0; i < s.size(); ++i) {
                int right = i + length - 1;
                if (right >= s.size()) {
                    break;
                }

                if (prev[i] && s[i] == s[right]) {
                    isPalindrome.push_back(true);
                    answer++;
                } else {
                    isPalindrome.push_back(false);
                }
            }
        }



        // even length
        isPalindrome = vector<int>();
        for (int i = 0; i < s.size(); ++i) {
            int right = i + 1;
            if (right >= s.size()) {
                break;
            }

            if (s[i] == s[right]) {
                isPalindrome.push_back(true);
                answer++;
            } else {
                isPalindrome.push_back(false);
            }
        }

        for (int length = 4; length <= s.size(); length += 2) {
            vector<int> prev = isPalindrome;
            isPalindrome = vector<int>();

            for (int i = 0; i < s.size(); ++i) {
                int right = i + length - 1;
                if (right >= s.size()) {
                    break;
                }

                if (prev[i] && s[i] == s[right]) {
                    isPalindrome.push_back(true);
                    answer++;
                } else {
                    isPalindrome.push_back(false);
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution soln;

    // cout << soln.countSubstrings("aaa") << endl;
    cout << soln.countSubstrings("bbccaacacdbdbcbcbbbcbadcbdddbabaddbcadb") << endl;

    return 0;
}