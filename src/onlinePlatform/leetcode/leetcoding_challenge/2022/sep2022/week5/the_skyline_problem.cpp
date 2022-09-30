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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int> counter;
        priority_queue<pair<int, int>> pq;

        vector<vector<int>> answer;

        if (buildings.size() == 0) {
            return answer;
        }

        for (auto building: buildings) {
            int left = building[0], right = building[1], height = building[2];

            while (pq.size() > 0 && left >= -pq.top().first) {
                auto [negPrevRight, prevHeight] = pq.top();

                auto prevRight = -negPrevRight;
                pq.pop();

                counter[prevHeight]--;
                if (counter[prevHeight] == 0) {
                    counter.erase(prevHeight);
                }

                addToAnswer(answer, prevRight, counter, true);
            }

            pq.push(pair{-right, height});

            if (counter.count(height) == 0) {
                counter[height] = 0;
            }
            counter[height]++;

            addToAnswer(answer, left, counter, false);
        }

        int maxRight = buildings[0][1];
        while (pq.size() > 0) {
            auto [negPrevRight, prevHeight] = pq.top();

            auto prevRight = -negPrevRight;
            pq.pop();

            maxRight = max(maxRight, prevRight);
        
            counter[prevHeight]--;
            if (counter[prevHeight] == 0) {
                counter.erase(prevHeight);
            }

            addToAnswer(answer, prevRight, counter, false);
        }

        addToAnswer(answer, maxRight, counter, true);

        return answer;
    }

    void addToAnswer(vector<vector<int>>& answer, int x, map<int, int> counter, bool isReversed) {
        int y = 0;
        if (counter.size() > 0) {
            y = (*(counter.rbegin())).first;
        }

        while (answer.size() > 0) {
            auto prevPoint = answer[answer.size() - 1];
            int prevX = prevPoint[0], prevY = prevPoint[1];

            if (prevX != x && prevY != y) {
                answer.push_back({x, y});
                return;
            }

            if (prevX == x && prevY == y) {
                return;
            }

            if (prevX == x) {
                bool shouldPop = y > prevY;
                if (y == 0) {
                    shouldPop = !shouldPop;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }

            if (prevY == y) {
                bool shouldPop = x < prevX;
                if (isReversed) {
                    shouldPop = !shouldPop;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }
        }
    
        answer.push_back({x, y});
        return;
    }
};

class WASolution3 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> ms;
        deque<pair<int, int>> dq;

        vector<vector<int>> answer;

        if (buildings.size() == 0) {
            return answer;
        }

        for (auto building: buildings) {
            int left = building[0], right = building[1], height = building[2];

            while (dq.size() > 0 && left >= dq[0].first) {
                auto &[prevRight, prevHeight] = dq[0];
                dq.pop_front();

                ms.erase(prevHeight);

                addToAnswer(answer, prevRight, ms, false);
            }

            dq.push_back(pair{right, height});
            ms.insert(height);
            addToAnswer(answer, left, ms, false);
        }
        int maxRight = buildings[0][1];
        while (dq.size() > 0) {
            auto &[prevRight, prevHeight] = dq[0];
            dq.pop_front();

            maxRight = max(maxRight, prevRight);
            ms.erase(prevHeight);

            addToAnswer(answer, prevRight, ms, false);
        }

        addToAnswer(answer, maxRight, ms, true);

        return answer;
    }

    void addToAnswer(vector<vector<int>>& answer, int x, multiset<int> ms, bool isReversed) {
        int y = 0;
        if (ms.size() > 0) {
            y = *(ms.rbegin());
        }

        while (answer.size() > 0) {
            auto prevPoint = answer[answer.size() - 1];
            int prevX = prevPoint[0], prevY = prevPoint[1];

            if (prevX != x && prevY != y) {
                answer.push_back({x, y});
                return;
            }

            if (prevX == x && prevY == y) {
                return;
            }

            if (prevX == x) {
                bool shouldPop = y > prevY;
                if (isReversed) {
                    shouldPop = !shouldPop;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }

            if (prevY == y) {
                bool shouldPop = x < prevX;
                if (isReversed) {
                    shouldPop = !shouldPop;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }
        }
    
        answer.push_back({x, y});
        return;
    }
};

class WA2Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> ms;
        deque<pair<int, int>> dq;

        vector<vector<int>> answer;

        for (auto building: buildings) {
            int left = building[0], right = building[1], height = building[2];

            while (dq.size() > 0 && left >= dq[0].first) {
                auto &[prevRight, prevHeight] = dq[0];
                dq.pop_front();

                ms.erase(prevHeight);

                addToAnswer(answer, prevRight, ms, false);
            }

            dq.push_back(pair{right, height});
            ms.insert(height);
            addToAnswer(answer, left, ms, false);
        }

        while (dq.size() > 0) {
            auto &[prevRight, prevHeight] = dq[0];
            dq.pop_front();

            ms.erase(prevHeight);

            addToAnswer(answer, prevRight, ms, true);
        }

        return answer;
    }

    void addToAnswer(vector<vector<int>>& answer, int x, multiset<int> ms, bool isReversed) {
        int y = 0;
        if (ms.size() > 0) {
            y = *(ms.rbegin());
        }

        while (answer.size() > 0) {
            auto prevPoint = answer[answer.size() - 1];
            int prevX = prevPoint[0], prevY = prevPoint[1];

            if (prevX != x && prevY != y) {
                answer.push_back({x, y});
                return;
            }

            if (prevX == x) {
                bool shouldPop = y > prevY;
                if (isReversed) {
                    shouldPop = !shouldPop;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }

            if (prevY == y) {
                bool shouldPop = x < prevX;
                if (isReversed) {
                    shouldPop = !shouldPop;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }
        }
    
        answer.push_back({x, y});
        return;
    }
};

class WASolution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> ms;
        deque<pair<int, int>> dq;

        vector<vector<int>> answer;

        for (auto building: buildings) {
            int left = building[0], right = building[1], height = building[2];

            while (dq.size() > 0 && left >= dq[0].first) {
                auto &[prevRight, prevHeight] = dq[0];
                dq.pop_front();

                ms.erase(prevHeight);

                addToAnswer(answer, prevRight, ms, false);
            }

            dq.push_back(pair{right, height});
            ms.insert(height);
            addToAnswer(answer, left, ms, false);
        }

        while (dq.size() > 0) {
            auto &[prevRight, prevHeight] = dq[0];
            dq.pop_front();

            ms.erase(prevHeight);

            addToAnswer(answer, prevRight, ms, true);
        }

        return answer;
    }

    void addToAnswer(vector<vector<int>>& answer, int x, multiset<int> ms, bool isSmallerYBetter) {
        int y = 0;
        if (ms.size() > 0) {
            y = *(ms.rbegin());
        }

        while (answer.size() > 0) {
            auto prevPoint = answer[answer.size() - 1];
            int prevX = prevPoint[0], prevY = prevPoint[1];

            if (prevX != x && prevY != y) {
                answer.push_back({x, y});
                return;
            }

            if (prevX == x) {
                bool shouldPop;
                if (isSmallerYBetter) {
                    shouldPop = y < prevY;
                } else {
                    shouldPop = y > prevY;
                }
                if (shouldPop) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }

            if (prevY == y) {
                if (x < prevX) {
                    answer.pop_back();                    
                } else {
                    return;
                }
            }
        }
    
        answer.push_back({x, y});
        return;
    }
};

int main() {
    Solution soln;
    // vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    // vector<vector<int>> buildings = {{0,2,3},{2,5,3}};
    // vector<vector<int>> buildings = {{2,9,10},{3,9,9},{4,9,8},{5,9,7}};
    // vector<vector<int>> buildings = {{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
    // vector<vector<int>> buildings = {{1,2,1},{1,2,2},{1,2,3}};
    // vector<vector<int>> buildings = {{2,14,4},{4,8,8},{6,16,4}};
    // vector<vector<int>> buildings = {{4,9,10},{4,9,15},{4,9,12},{10,12,10},{10,12,8}};
    vector<vector<int>> buildings = {{1,38,219},{2,19,228},{2,64,106},{3,80,65},{3,84,8},{4,12,8},{4,25,14},{4,46,225},{4,67,187},{5,36,118},{5,48,211},{5,55,97},{6,42,92},{6,56,188},{7,37,42},{7,49,78},{7,84,163},{8,44,212},{9,42,125},{9,85,200},{9,100,74},{10,13,58},{11,30,179},{12,32,215},{12,33,161},{12,61,198},{13,38,48},{13,65,222},{14,22,1},{15,70,222},{16,19,196},{16,24,142},{16,25,176},{16,57,114},{18,45,1},{19,79,149},{20,33,53},{21,29,41},{23,77,43},{24,41,75},{24,94,20},{27,63,2},{31,69,58},{31,88,123},{31,88,146},{33,61,27},{35,62,190},{35,81,116},{37,97,81},{38,78,99},{39,51,125},{39,98,144},{40,95,4},{45,89,229},{47,49,10},{47,99,152},{48,67,69},{48,72,1},{49,73,204},{49,77,117},{50,61,174},{50,76,147},{52,64,4},{52,89,84},{54,70,201},{57,76,47},{58,61,215},{58,98,57},{61,95,190},{66,71,34},{66,99,53},{67,74,9},{68,97,175},{70,88,131},{74,77,155},{74,99,145},{76,88,26},{82,87,40},{83,84,132},{88,99,99}};
    vector<vector<int>> answer = soln.getSkyline(buildings);

    return 0;
}