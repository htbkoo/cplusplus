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

enum Color {
    RED, BLUE
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int START = 0;
        int INF = numeric_limits<int>::max();
        int UNREACHABLE = -1;
        unordered_map<Color, Color> NEXT_COLORS = {{Color::RED, Color::BLUE}, {Color::BLUE, Color::RED}};
        
        unordered_map<Color, unordered_map<int, unordered_set<int>>> neighbours;        
        for (auto [color, edges]: {pair{Color::RED, redEdges}, pair{Color::BLUE, blueEdges}}) {
            for (auto &edge: edges) {
                int fromNode = edge[0], toNode = edge[1];
                neighbours[color][fromNode].insert(toNode);
            }
        }
        
        vector<int> answer(n, INF);
        
        unordered_map<Color, unordered_set<int>> visited;
        
        queue<pair<Color, int>> q;
        q.push(pair{Color::RED, START});
        q.push(pair{Color::BLUE, START});
        
        int step = 0;
        while (q.size() > 0) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                auto [color, node] = q.front();
                q.pop();
                
                answer[node] = min(answer[node], step);
                
                bool isVisited = visited[color].count(node) > 0;
                if (isVisited) {
                    continue;
                }
                visited[color].insert(node);
                
                for (int nextNode: neighbours[color][node]) {
                    Color nextColor = NEXT_COLORS[color];
                    q.push(pair{nextColor, nextNode});
                }
            }
            
            step++;
        }

        for (int i = 0; i < n; i++) {
            if (answer[i] == INF) {
                answer[i] = UNREACHABLE;
            }
        }
        
        return answer;
    }
};

class WIPSolution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int START = 0;
        char RED_COLOR = 'R';
        char BLUE_COLOR = 'B';
        
        vector<int> answer(n, numeric_limits<int>::max());
        // answer[START] = 0;
        
        unordered_map<char, unordered_set<int>> visited;
        
        queue<pair<char, int>> q;  // TODO: migrate this to an enum
        q.push(pair{RED_COLOR, START});
        q.push(pair{BLUE_COLOR, START});
        
        int step = 0;
        while (q.size() > 0) {
            int count = q.size();
            
            for (int i = 0; i < count; i++) {
                auto &[color, node] = q.front();
                q.pop();
                
                answer[node] = min(answer[node], step);
                
                // if ()
                
            }
            
            step++;
        }

        return answer;
    }
};

template <typename Vector>
void printVector(Vector &v) {
    cout << "[";
    for (auto &item: v) {
        cout << item << ", ";
    }
    cout << "]";
    cout << endl;
}

int main() {
    Solution soln;
    int  n = 100;
    vector<vector<int>> redEdges = {{95,4},{95,38},{56,93},{98,81},{22,76},{14,94},{14,28},{24,46},{35,64},{77,77},{57,51},{65,85},{83,97},{33,9},{16,49},{6,42},{73,84},{53,23},{63,49},{98,70},{85,98},{29,3},{87,16},{94,11},{19,61},{21,2},{73,48},{0,7},{42,5},{80,37},{27,25},{45,39},{52,87},{70,43},{95,97},{0,81},{5,41},{31,93},{92,23},{31,75},{99,56},{30,77},{18,33},{45,17},{83,12},{89,49},{17,22},{8,28},{45,87},{34,68},{41,91},{42,13},{3,40},{30,23},{16,2},{52,58},{19,17},{58,69},{64,61},{32,89},{91,1},{41,77},{47,19},{18,84},{99,36},{9,57},{86,61},{5,74},{57,99},{93,88},{0,15},{94,1},{15,34},{9,86},{24,1},{90,72},{1,72},{95,81},{58,59},{94,2},{19,52},{11,33},{8,22},{2,28},{39,5},{67,18},{33,77},{94,5},{54,37},{29,62},{60,6},{27,35},{6,96},{15,5},{13,31},{90,0},{91,45},{85,30},{29,29},{58,22},{90,87},{58,24},{8,33},{23,82},{96,51},{43,56},{68,59}};
    vector<vector<int>> blueEdges = {{81,24},{98,66},{15,66},{78,20},{14,4},{39,10},{81,68},{61,0},{99,84},{76,82},{27,69},{97,80},{7,38},{77,13},{61,42},{1,6},{96,18},{74,28},{31,39},{3,86},{44,98},{85,45},{89,42},{23,55},{1,2},{1,40},{51,84},{14,45},{31,40},{33,20},{65,79},{41,85},{31,32},{81,55},{50,10},{53,24},{87,4},{8,15},{18,28},{73,18},{83,14},{35,26},{34,42},{59,81},{6,36},{13,42},{16,26},{54,16},{23,57},{9,50},{34,46},{46,27},{2,80},{14,83},{81,21},{19,48},{56,19},{53,35},{92,48},{85,18},{33,6},{37,17},{93,61},{63,1},{51,59},{40,22},{25,87},{99,73},{70,92},{87,54},{6,39},{54,81},{60,60},{41,54},{5,0},{31,46},{10,30},{1,98},{79,79},{6,49},{31,33},{62,15},{7,42},{19,3},{53,2},{69,74},{99,18},{86,65},{55,20},{3,58},{8,49},{52,13},{99,53},{29,70},{81,85},{9,82},{30,7},{69,44},{34,90},{41,18},{95,69},{5,59},{26,64},{21,37},{45,23},{60,37},{84,9},{92,49},{69,7},{77,28},{27,38},{94,66},{68,1},{29,22},{65,45},{19,43},{55,9},{92,0},{33,33},{70,87},{10,3},{21,28},{25,35},{51,2},{74,14},{79,1},{92,39},{12,41},{84,34},{91,77},{51,9},{87,73},{50,66},{2,19}};    
    
    auto answer = soln.shortestAlternatingPaths(n, redEdges, blueEdges);

    printVector(answer);

    return 0;
}