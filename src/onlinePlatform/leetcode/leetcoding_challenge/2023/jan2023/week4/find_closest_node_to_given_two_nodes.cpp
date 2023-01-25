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
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> distFromNode1 = computeDists(edges, node1);
        vector<int> distFromNode2 = computeDists(edges, node2);
        
        int answer = -1;
        for (int i = 0; i < n; i++) {
            bool isReachable1 = distFromNode1[i] < numeric_limits<int>::max();
            bool isReachable2 = distFromNode2[i] < numeric_limits<int>::max();
            if (isReachable1 && isReachable2) {                
                if (answer == -1) {
                    answer = i;
                } else {
                    int prevDist = max(distFromNode1[answer],  distFromNode2[answer]);
                    int currDist = max(distFromNode1[i],  distFromNode2[i]);
                    if (currDist < prevDist) {
                        answer = i;
                    }
                }
            }
        }
        
        return answer;
    }
    
private:
    vector<int> computeDists(vector<int>& edges, int node) {
        int n = edges.size();
        
        vector<int> dists(n, numeric_limits<int>::max());
        
        queue<int> q = queue<int>({node});
        
        int dist = 0;
        while (q.size() > 0) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                int curr = q.front();
                q.pop();
                
                if (dists[curr] < numeric_limits<int>::max()) {
                    continue;
                }
                
                dists[curr] = dist;
                
                int nextNode = edges[curr];
                if (nextNode != -1) {
                    q.push(nextNode);
                }
            }
            
            dist++;
        }
        
        return dists;
    }
};