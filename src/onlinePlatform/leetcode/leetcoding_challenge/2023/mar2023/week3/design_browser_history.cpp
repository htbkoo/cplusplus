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

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history = vector<string>{homepage};
        idx = 0;
        bound = 0;
    }
    
    void visit(string url) {
        idx++;
        if (idx >= history.size()) {
            history.push_back(url);
        } else {
            history[idx] = url;
        }
        
        bound = idx;
    }
    
    string back(int steps) {
        idx = max(0, idx - steps);
        return history[idx];
    }
    
    string forward(int steps) {
        idx = min(bound, idx + steps);
        return history[idx];
    }

private:
    vector<string> history;
    int idx;
    int bound;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
