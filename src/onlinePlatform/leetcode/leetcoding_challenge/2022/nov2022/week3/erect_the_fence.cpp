#include <algorithm>
#include <cmath>
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
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        return findWithGrahamScan(trees);        
    }
    
private:
    vector<vector<int>> findWithGrahamScan(vector<vector<int>> trees) {
        // trees = vector<vector<int>>(trees);
        
        // find the lowest y-coordinate and leftmost point, called P0
        vector<int> point0 = findPointWithLowestXY(trees);
        
        // sort points by polar angle with P0, if several points have the same polar angle then sort by dist
        sort(trees.begin(), trees.end(), [&](auto& pointA, auto& pointB) { 
            double angleA = getAngle(point0, pointA);
            double angleB = getAngle(point0, pointB);
            
            if (angleA == angleB) {
                long distA = getDistSq(point0, pointA);
                long distB = getDistSq(point0, pointB);
                
                return distA < distB;
            }
            
            return angleA < angleB;
        });
        
        vector<vector<int>> stack;
        for (vector<int>& point: trees) {
            while (stack.size() > 1) {
                vector<int>& nextToTop = stack[stack.size() - 2];
                vector<int>& top = stack.back();                
                bool shouldPop = isClockWise(nextToTop, top, point);
                if (shouldPop) {
                    stack.pop_back();
                } else {
                    break;
                }
            }
            stack.push_back(point);
        }
        return stack;
    }
    
    bool isClockWise(vector<int>& nextToTop, vector<int>& top, vector<int>& point) {
        // https://math.stackexchange.com/a/1324210
        int x1 = nextToTop[0], y1 = nextToTop[1], x2 = top[0], y2 = top[1], x3 = point[0], y3 = point[1];
        long A = x2 * y1 + x3 * y2 + x1 * y3;
        long B = x1 * y2 + x2 * y3 + x3 * y1;
        return A > B;
    }
    
    vector<int> findPointWithLowestXY(vector<vector<int>>& trees) {
        vector<int> point0 = trees[0];
        for (vector<int> point: trees) {
            if (point[1] < point0[1] || (point[1] == point0[1] && point[0] < point0[0])) {
                point0 = point;
            }
        }
        return point0;
    }
    
    double getAngle(vector<int>& fromPoint, vector<int>& toPoint) {
        return atan2(toPoint[1] - fromPoint[1], toPoint[0] - fromPoint[0]);
    }
    
    long getDistSq(vector<int>& fromPoint, vector<int>& toPoint) {
        long dy = toPoint[1] - fromPoint[1];
        long dx = toPoint[0] - fromPoint[0];
        return dy * dy + dx * dx;
    }
};

int main() {
    Solution soln;
    
    // vector<vector<int>> points = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    // {{1,2},{2,2},{4,2}}
    vector<vector<int>> points = {{3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}};

    soln.outerTrees(points);
}