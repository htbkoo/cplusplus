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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double NO_EDGE = -1.0;
        
        vector<unordered_map<int, double>> neighbours;
        for (int i = 0; i < n; ++i) {
            neighbours.push_back(unordered_map<int, double>());
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            neighbours[a][b] = p;
            neighbours[b][a] = p;            
        }
        
        unordered_set<int> visited;
        vector<pair<double, int>> pq = {pair{1.0, start}};
        
        while (pq.size() > 0) {
            pop_heap(pq.begin(), pq.end());
            
            auto [currProb, node] = pq.back();
            pq.pop_back();
            
            if (node == end) {
                return currProb;
            }
            
            if (visited.count(node) > 0) {
                continue;
            }
            visited.insert(node);
            
            for (auto const& [neighbour, edgeProb]: neighbours[node]) {
                double newProb = currProb * edgeProb;
                
                pq.push_back(pair{newProb, neighbour});
                push_heap(pq.begin(), pq.end());
            }
        }
        
        return 0;
    }
};

class MLESolution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double NO_EDGE = -1.0;
        
        vector<vector<double>> neighbourProbs;
        vector<vector<int>> neighbours;
        for (int i = 0; i < n; ++i) {
            neighbourProbs.push_back(vector<double>(n, NO_EDGE));
            neighbours.push_back(vector<int>());
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            neighbourProbs[a][b] = p;
            neighbourProbs[b][a] = p;
            
            neighbours[a].push_back(b);
            neighbours[b].push_back(a);
        }
        
        unordered_set<int> visited;
        vector<pair<double, int>> pq = {pair{1.0, start}};
        
        while (pq.size() > 0) {
            pop_heap(pq.begin(), pq.end());
            
            auto [currProb, node] = pq.back();
            pq.pop_back();
            
            if (node == end) {
                return currProb;
            }
            
            if (visited.count(node) > 0) {
                continue;
            }
            visited.insert(node);
            
            for (int neighbour: neighbours[node]) {
                double edgeProb = neighbourProbs[node][neighbour];
                double newProb = currProb * edgeProb;
                
                pq.push_back(pair{newProb, neighbour});
                push_heap(pq.begin(), pq.end());
            }
        }
        
        return 0;
    }
};

int main() {
    Solution soln;
    
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};

    std::cout << soln.maxProbability(n, edges, succProb, start, end) << endl;
    return 0;
}