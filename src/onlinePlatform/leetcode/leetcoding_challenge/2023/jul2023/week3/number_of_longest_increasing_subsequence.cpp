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
    int findNumberOfLIS(vector<int>& nums) {
        unordered_map<int, pair<int, int>> lengths;
        
        for (auto num: nums) {
            // cout << "WIP " << num <<  ": " << lengths.size() << endl;
            unordered_map<int, pair<int, int>> newLengths;
            
            for (auto& [key, p]: lengths) {
                auto& [length, count] = p;
                
                if (num > key) {
                    if (lengths.count(num) != 0) {
                        auto& [numLength, numCount] = lengths[num];
                        if (length + 1 > numLength) {
                            lengths[num] = pair{length + 1, count};
                        } else if (length + 1 == numLength) {
                            numCount += count;
                        } 
                    } else {
                        if (newLengths.count(num) == 0) {
                            newLengths[num] = pair{length + 1, count};
                        } else {
                             auto& [numLength, numCount] = newLengths[num];
                            if (length + 1 > numLength) {
                                newLengths[num] = pair{length + 1, count};
                            } else if (length + 1 == numLength) {
                                numCount += count;
                            }   
                        }
                    }
                }
            }
            
            for (auto& [key, p]: newLengths) {
                lengths[key] = newLengths[key];
            }
            
            if (lengths.count(num) == 0) {
                lengths[num] = pair{1, 1};
            } else if (lengths[num].first == 1) {
                lengths[num].second++;
            }
        }
        
        int longestLength = 0;
        int answer = 0;
        
        for (auto& [key, p]: lengths) {
            auto& [length, count] = p;

            // cout << "end: " << key << " " << length << " " << count << endl;

            if (length > longestLength) {
                longestLength = length;
                answer = count;
            } else if (length == longestLength) {
                answer += count;
            }
        }
        
        return answer;
    }
};

class WASolution2 {
public:
    int findNumberOfLIS(vector<int>& nums) {
        unordered_map<int, pair<int, int>> lengths;
        
        for (auto num: nums) {
            for (auto [key, p]: lengths) {
                auto [length, count] = p;
                
                if (num > key) {
                    if (lengths.count(num) == 0) {
                        lengths[num] = pair{length + 1, count};
                    } else {
                        auto [numLength, numCount] = lengths[num];
                        if (length + 1 > numLength) {
                            lengths[num] = pair{length + 1, count};
                        } else if (length + 1 == numLength) {
                            lengths[num].second += count;
                        } 
                    }
                }
            }
            if (lengths.count(num) == 0) {
                lengths[num] = pair{1, 1};
            } else if (lengths[num].first == 1) {
                lengths[num].second++;
            }
        }
        
        int longestLength = 0;
        int answer = 0;
        
        for (auto& [key, p]: lengths) {
            auto& [length, count] = p;

            if (length > longestLength) {
                longestLength = length;
                answer = count;
            } else if (length == longestLength) {
                answer += count;
            }
        }
        
        return answer;
    }
};

class WASolution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        unordered_map<int, pair<int, int>> lengths;
        
        for (auto num: nums) {
            for (auto& [key, p]: lengths) {
                auto& [length, count] = p;

                cout << "WIP " << num <<  ": " << key << " " << length << " " << count << endl;
                
                if (num > key) {
                    if (lengths.count(num) == 0) {
                        lengths[num] = pair{length + 1, count};
                    } else {
                        auto& [numLength, numCount] = lengths[num];
                        if (length + 1 > numLength) {
                            lengths[num] = pair{length + 1, count};
                        } else if (length + 1 == numLength) {
                            numCount += count;
                        } 
                    }
                }
            }
            if (lengths.count(num) == 0) {
                lengths[num] = pair{1, 1};
            } else if (lengths[num].first == 1) {
                lengths[num].second++;
            }
        }
        
        int longestLength = 0;
        int answer = 0;  
        
        for (auto& [key, p]: lengths) {
            auto& [length, count] = p;

            cout << "end: " << key << " " << length << " " << count << endl;

            if (length > longestLength) {
                longestLength = length;
                answer = count;
            } else if (length == longestLength) {
                answer += count;
            }
        }
        
        return answer;
    }
};

int main() {
    Solution soln;

    // [1,3,5,4,7]
    // [2,2,2,2,2]
    // [1,2,3,3,3]
    vector<int> nums = {26,72,68,8,-91,-89,-15,62,61,96,-70,89,-72,69,3};

    cout << soln.findNumberOfLIS(nums) << endl;

    return 0;
}