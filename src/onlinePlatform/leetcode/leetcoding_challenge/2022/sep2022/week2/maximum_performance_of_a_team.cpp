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

struct sortByEfficientDescThenSpeedDesc {
    vector<int>& speed;
    vector<int>& efficiency;
    sortByEfficientDescThenSpeedDesc(vector<int>& aSpeed, vector<int>& aEfficiency):
    speed(aSpeed), efficiency(aEfficiency) {
    }

    inline bool operator() (int i1, int i2) {
        int speed1 = this->speed[i1];
        int speed2 = this->speed[i2];
        int efficiency1 = this->efficiency[i1];
        int efficiency2 = this->efficiency[i2];

        if (efficiency1 == efficiency2) {
            return speed1 > speed2;
        }

        return efficiency1 > efficiency2;
    }
};
    
struct sortBySpeedDescThenEfficiencyDesc {
    vector<int>& speed;
    vector<int>& efficiency;
    sortBySpeedDescThenEfficiencyDesc(vector<int>& aSpeed, vector<int>& aEfficiency):
    speed(aSpeed), efficiency(aEfficiency) {
    }

    inline bool operator() (int i1, int i2) {
        int speed1 = this->speed[i1];
        int speed2 = this->speed[i2];
        int efficiency1 = this->efficiency[i1];
        int efficiency2 = this->efficiency[i2];

        if (speed1 == speed2) {
            return efficiency1 > efficiency2;
        }

        return speed1 > speed2;
    }
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (k == 0) {
            return 0;
        }

        vector<int> indicesByEfficientDescThenSpeedDesc;
        for (auto i = 0; i < n; i++) {
            indicesByEfficientDescThenSpeedDesc.push_back(i);
        }
        sort(indicesByEfficientDescThenSpeedDesc.begin(), indicesByEfficientDescThenSpeedDesc.end(), sortByEfficientDescThenSpeedDesc(speed, efficiency));
        
        int firstIdx = indicesByEfficientDescThenSpeedDesc[0];

        priority_queue<int, vector<int>, sortBySpeedDescThenEfficiencyDesc> pq(sortBySpeedDescThenEfficiencyDesc(speed, efficiency));
        pq.push(firstIdx);

        long answer = (long) speed[firstIdx] * (long) efficiency[firstIdx];
        long totalSpeed = speed[firstIdx];
        int minEff = efficiency[firstIdx];

        for (int i = 1; i < indicesByEfficientDescThenSpeedDesc.size(); i++) {
            int idx = indicesByEfficientDescThenSpeedDesc[i];
            
            int prevSlowestSpeed = speed[pq.top()];

            if (pq.size() < k || speed[idx] > prevSlowestSpeed) {
                pq.push(idx);
                totalSpeed += speed[idx];
                minEff = min(minEff, efficiency[idx]);
                if (pq.size() > k) {                    
                    totalSpeed -= prevSlowestSpeed;
                    pq.pop();
                }

                answer = max(answer, totalSpeed * minEff);
            }
        }

        return answer % 1000000007;        
    }
};

/* 
class WASolution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (k == 0) {
            return 0;
        }

        vector<int> indicesByEfficientDescThenSpeedDesc;
        for (auto i = 0; i < n; i++) {
            indicesByEfficientDescThenSpeedDesc.push_back(i);
        }
        sort(indicesByEfficientDescThenSpeedDesc.begin(), indicesByEfficientDescThenSpeedDesc.end(), sortByEfficientDescThenSpeedDesc(speed, efficiency));
        
        int firstIdx = indicesByEfficientDescThenSpeedDesc[0];

        priority_queue<int, vector<int>, sortBySpeedDescThenEfficiencyDesc> pq(sortBySpeedDescThenEfficiencyDesc(speed, efficiency));
        pq.push(firstIdx);

        long answer = speed[firstIdx] * efficiency[firstIdx];
        long totalSpeed = speed[firstIdx];
        int minEff = efficiency[firstIdx];

        for (int i = 1; i < indicesByEfficientDescThenSpeedDesc.size(); i++) {
            int idx = indicesByEfficientDescThenSpeedDesc[i];
            
            int prevSlowestSpeed = speed[pq.top()];

            if (pq.size() < k || speed[idx] > prevSlowestSpeed) {
                pq.push(idx);
                totalSpeed += speed[idx];
                minEff = min(minEff, efficiency[idx]);
                if (pq.size() > k) {                    
                    totalSpeed -= prevSlowestSpeed;
                    pq.pop();
                }

                answer = max(answer, totalSpeed * minEff);
            }
        }

        return answer % 10000007;
    }
};

/* 
class WIPSolution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (k == 0) {
            return 0;
        }

        vector<int> indicesByEfficientDescThenSpeedDesc;
        for (auto i = 0; i < n; i++) {
            indicesByEfficientDescThenSpeedDesc.push_back(i);
        }
        sort(indicesByEfficientDescThenSpeedDesc.begin(), indicesByEfficientDescThenSpeedDesc.end(), sortByEfficientDescThenSpeedDesc(speed, efficiency));
        
        int firstIdx = indicesByEfficientDescThenSpeedDesc[0];

        priority_queue<int, vector<int>, sortBySpeedDescThenEfficiencyDesc> pq(sortBySpeedDescThenEfficiencyDesc(speed, efficiency));
        pq.push(firstIdx);

        long answer = speed[firstIdx] * efficiency[firstIdx];
        long totalSpeed = speed[firstIdx];

        for (int i = 1; i < indicesByEfficientDescThenSpeedDesc.size(); i++) {
            int idx = indicesByEfficientDescThenSpeedDesc[i];
            pq.push(idx);
            totalSpeed += speed[idx];

            if (pq.size() > k) {
                int removedIdx = pq.top();
                int removedSpeed = speed[removedIdx];
                totalSpeed -= removedSpeed;
                pq.pop();
            }

            answer = max(answer, totalSpeed * efficiency[idx]);
        }

        return answer % 10000007;
    }
};
 */

int main() {
    Solution soln;
    int n = 6;
    vector<int> speed = {2,10,3,1,5,8}; 
    vector<int> efficiency = {5,4,3,9,7,2};
    int k = 2;
    soln.maxPerformance(n, speed, efficiency, k);
    return 0;
}