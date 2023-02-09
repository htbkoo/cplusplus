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
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> firstCharToTail;
        unordered_set<char> allCharsSet;
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            string tail = idea.substr(1, idea.size() - 1);
            firstCharToTail[firstChar].insert(tail);
            allCharsSet.insert(firstChar);
        }
        
        long long answer = 0;
        vector<char> allChars(allCharsSet.begin(), allCharsSet.end());
        for (int i = 0; i < allChars.size(); i++) {
            for (int j = i + 1; j < allChars.size(); j++) {
                char ch1 = allChars[i], ch2 = allChars[j];
                unordered_set<string> set1 = firstCharToTail[ch1], set2 = firstCharToTail[ch2];
                
                long long count1 = set1.size(), count2 = set2.size();
                for (auto tail1: set1) {
                    if (set2.count(tail1) > 0) {
                        count1--;
                        count2--;
                    }
                }
                
                answer += 2 * count1 * count2;
            }
        }
        
        return answer;
    }
};

class WASolution3 {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, unordered_set<char>> tailToFirstChars;
        unordered_map<char, long long> firstCharCounter;
        
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            string tail = idea.substr(1, idea.size() - 1);
            tailToFirstChars[tail].insert(firstChar);
            firstCharCounter[firstChar]++;
        }
        
        long long answer = 0;
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            string tail = idea.substr(1, idea.size() - 1);
            for (auto &[otherFirstChar, count]: firstCharCounter) {
                bool isCompatible = firstChar != otherFirstChar && tailToFirstChars[tail].count(otherFirstChar) == 0;
                if (isCompatible) {
                    answer += count;
                }
            }
        }
        
        return answer;
    }
};

class WASolution2 {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, unordered_set<char>> tailToFirstChars;
        unordered_map<char, long long> firstCharCounter;
        
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            string tail = idea.substr(1, idea.size() - 1);
            tailToFirstChars[tail].insert(firstChar);
            firstCharCounter[firstChar]++;
        }
        
        long long answer = 0;
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            string tail = idea.substr(1, idea.size() - 1);
            for (auto &[otherFirstChar, count]: firstCharCounter) {
                bool isCompatible = firstChar != otherFirstChar && tailToFirstChars[tail].count(otherFirstChar) == 0;
                if (isCompatible) {
                    answer += count;
                }
            }
        }
        
        return answer;
    }
};

template <typename Map>
void printMap(Map &m) {
    cout << "{" << endl;
    for (auto &[key, val]: m) {
        cout << key << " -> " << val << endl;
    }
    cout << "}" << endl;
}

template <typename Iterable>
void printIterable(Iterable &i) {
    cout << "[";
    for (auto &item: i) {
        cout << item << ", ";
    }
    cout << "]";
}

template <typename Map>
void printMapWithIterable(Map &m) {
    cout << "{" << endl;
    for (auto &[key, val]: m) {
        cout << key << " -> ";
        printIterable(val);
        cout << endl;
    }
    cout << "}" << endl;
}

class WASolution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, unordered_set<char>> tailToFirstChars;
        unordered_map<char, long long> firstCharCounter;
        unordered_map<char, unordered_set<char>> incompatibleFirstChars;
        
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            string tail = idea.substr(1, idea.size() - 1);
            tailToFirstChars[tail].insert(firstChar);
            firstCharCounter[firstChar]++;
        }

        printMapWithIterable(tailToFirstChars);
        printMap(firstCharCounter);

        for (auto &[tail, chars]: tailToFirstChars) {
            vector<char> v(chars.begin(), chars.end());
            
            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    char ch1 = v[i], ch2 = v[j];
                    incompatibleFirstChars[ch1].insert(ch2);
                    incompatibleFirstChars[ch2].insert(ch1);
                }   
            }
        }

        printMapWithIterable(incompatibleFirstChars);
        
        long long answer = 0;
        for (auto &idea: ideas) {
            char firstChar = idea[0];
            for (auto &[otherFirstChar, count]: firstCharCounter) {

                // cout << idea << " " << firstChar << " " << otherFirstChar << " " << idea << " " << idea << " " 

                bool isCompatible = firstChar != otherFirstChar && incompatibleFirstChars[firstChar].count(otherFirstChar) == 0;
                if (isCompatible) {
                    answer += count;
                }
            }
        }
        
        return answer;
    }
};

int main() {
    Solution soln;
    // vector<string> ideas = {"coffee","donuts","time","toffee"};
    vector<string> ideas = {"sfuzder","spklurny","kvdolme","kbbdklkpgk","za","mdbsmnjiu","pzydbfwiw","lvvyshmd","ow","ssipb","jucpsquexm","ffuzder","uftruik","ringlxh","jz","sjlxouiv","csdbtsvg","openygbaix","dcn","r","hwql","ok","y","sze","ttptd","atxp","ejfpsea","vjfpsea","lj","drmvufbt","zxambug","ozpxq","qzydbfwiw","lqxik","bjo","rrmvufbt","jvl","rzxaaa","nmfydhawa","shlwkf","rcl","hhn","yrmcsc","yieuzizaeh","nrmvufbt","rinsldgdpp","wqg","tyhkgqcu","rsdbtsvg","zvehtqiqxa","jtz","mjaguebiy","fztbpozhf","zzpxq","ue","foktqxiqe","ztf","dn","lxambug","kinsldgdpp","jhn","k","i","qxtava","roktqxiqe","hr","bwzw","mot","cadj","x","bcep","u","kzydbfwiw","ahku","ijo"};
    cout << soln.distinctNames(ideas) << endl;

    return 0;
}