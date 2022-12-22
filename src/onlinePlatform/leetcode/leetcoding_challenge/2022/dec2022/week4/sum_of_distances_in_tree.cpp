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

class Result {
public:
    int numNodes;
    int dist;

    // Result() {
    //     numNodes = 0;
    //     dist = 0;
    // };
    Result(int n = 1, int d = 0) {
        numNodes = n;
        dist = d;
    };
    // Result(int, int);

    void addBy(Result other) {
        numNodes += other.numNodes;
        dist += other.dist;
    }

};

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // map<pair<int, int>, Result> cache;
        unordered_map<string, Result> cache;

        vector<vector<int>> neighbours(n);
        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            neighbours[a].push_back(b);
            neighbours[b].push_back(a);
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = computeDist(cache, neighbours, i);
        }

        return answer;
    }

private:
    const string SEPARTOR = "_";
    static const int NO_PREV = -1;

    int computeDist(
        unordered_map<string, Result>& cache,
        vector<vector<int>>& neighbours,
        int start
    ) {
        auto result = dfs(cache, neighbours, start);
        return result.dist - result. numNodes;
    }
    
    Result dfs(
        unordered_map<string, Result>& cache,
        vector<vector<int>>& neighbours,
        int node, 
        int prev = NO_PREV
    ) {
        string key = getKey(prev, node);
        if (cache.count(key) > 0) {
            return cache[key];
        }
        cache[key] = Result(1, 0);
        for (int nextNode: neighbours[node]) {
            if (nextNode != prev) {
                cache[key].addBy(dfs(cache, neighbours, nextNode, node));
            }
        }
        cache[key].dist += cache[key].numNodes;
        return cache[key];
    }
    
    string getKey(int from, int to) {
        return to_string(from) + SEPARTOR + to_string(to);
    }
};

int main() {
    Solution soln;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    auto result = soln.sumOfDistancesInTree(6, edges);
    cout << "hello" << endl;
    return 0;
}