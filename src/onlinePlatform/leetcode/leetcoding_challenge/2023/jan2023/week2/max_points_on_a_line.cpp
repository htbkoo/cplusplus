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
    int maxPoints(vector<vector<int>>& points) {
        int answer = 0;
        for (int i = 0; i < points.size(); i++) {
            answer = max(answer, 1 + getCount(points, i));
        }
        return answer;
    }

private:
    int getCount(vector<vector<int>>& points, int baseIdx) {
        int maxCount = 0;
        int verticalCount = 0;
        unordered_map<double, int> counter;

        int bx = points[baseIdx][0], by = points[baseIdx][1];
        for (int i = 0; i < points.size(); i++) {
            if (i != baseIdx) {
                int x = points[i][0], y = points[i][1];
                double slope = atan2(y - by, x - bx);
                counter[slope]++;
                maxCount = max(maxCount, counter[slope]);
            }
        }
        return maxCount;
    }
};

class FirstSolution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int answer = 0;
        for (int i = 0; i < points.size(); i++) {
            answer = max(answer, 1 + getCount(points, i));
        }
        return answer;
    }

private:
    int getCount(vector<vector<int>>& points, int baseIdx) {
        int maxCount = 0;
        int verticalCount = 0;
        unordered_map<double, int> counter;

        int bx = points[baseIdx][0], by = points[baseIdx][1];
        for (int i = 0; i < points.size(); i++) {
            if (i != baseIdx) {
                int x = points[i][0], y = points[i][1];
                if (x == bx) {
                    // vertical
                    verticalCount++;
                    maxCount = max(maxCount, verticalCount);
                } else {
                    // TODO: handle precision problem
                    double slope = (double) (y - by) / (double) (x - bx);
                    counter[slope]++;
                    maxCount = max(maxCount, counter[slope]);
                }
            }
        }
        return maxCount;
    }
};
