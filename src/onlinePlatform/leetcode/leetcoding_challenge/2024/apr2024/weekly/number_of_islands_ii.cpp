#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<pair<int, int>> DIRECTIONS{
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1}
        };
        
        parents = map<pair<int, int>, pair<int, int>>();
        sizes = map<pair<int, int>, int>();
        
        int curr = 0;
        vector<int> answer;
        for (auto position: positions) {
            int y = position[0], x = position[1];
            
            pair<int, int> islandPosition = pair{y, x};
            if (parents.count(islandPosition) == 0) {
                find(islandPosition);            
                curr++;

                for (auto &[dy, dx]: DIRECTIONS) {
                    int ny = y + dy;
                    int nx = x + dx;
                    pair<int, int> another = pair{ny, nx};
                    if (parents.count(another) > 0) {
                        curr -= unionSets(islandPosition, another);
                    }
                }
            }
            
            answer.push_back(curr);
        }
        
        return answer;
    }
    
private:
    map<pair<int, int>, pair<int, int>> parents;
    map<pair<int, int>, int> sizes;

    pair<int, int> find(pair<int, int> x) {
        if (parents.count(x) == 0) {
            parents[x] = x;
            sizes[x] = 1;
        }
        
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        
        return parents[x];
    }
    
    int unionSets(pair<int, int> x, pair<int, int> y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        }
        
        if (sizes[y] > sizes[x]) {
            auto temp = x;
            x = y;
            y = temp;
        }
        
        parents[y] = x;
        sizes[x] += sizes[y];
        
        return 1;
    }
};

class WASolution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<pair<int, int>> DIRECTIONS{
            pair{-1, 0},
            pair{1, 0},
            pair{0, -1},
            pair{0, 1}
        };
        
        parents = map<pair<int, int>, pair<int, int>>();
        sizes = map<pair<int, int>, int>();
        
        int curr = 0;
        vector<int> answer;
        for (auto position: positions) {
            int y = position[0], x = position[1];
            
            pair<int, int> islandPosition = pair{y, x};
            find(islandPosition);
            
            curr++;
            
            for (auto &[dy, dx]: DIRECTIONS) {
                int ny = y + dy;
                int nx = x + dx;
                pair<int, int> another = pair{ny, nx};
                if (parents.count(another) > 0) {
                    curr -= unionSets(islandPosition, another);
                }
            }
            
            answer.push_back(curr);
        }
        
        return answer;
    }
    
private:
    map<pair<int, int>, pair<int, int>> parents;
    map<pair<int, int>, int> sizes;

    pair<int, int> find(pair<int, int> x) {
        if (parents.count(x) == 0) {
            parents[x] = x;
            sizes[x] = 1;
        }
        
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        
        return parents[x];
    }
    
    int unionSets(pair<int, int> x, pair<int, int> y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return 0;
        }
        
        if (sizes[y] > sizes[x]) {
            auto temp = x;
            x = y;
            y = temp;
        }
        
        parents[y] = x;
        sizes[x] += sizes[y];
        
        return 1;
    }
};