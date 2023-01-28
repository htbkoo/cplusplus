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
class SummaryRanges {
public:
    SummaryRanges() {
        bst = set<pair<int, int>>();
    }
    
    void addNum(int value) {
        pair<int, int> p = pair{value, value};
        if (bst.size() == 0) {
            bst.insert(p);
        } else {
            int start = value;
            int end = value;
            
            auto left = bst.lower_bound(p);
            if (left != bst.begin()) {
                left = prev(left);
                
                if (left->second >= value - 1) {
                    start = min(start, left->first);
                    end = max(end, left->second);
                    bst.erase(left);
                }                
            }
            
            auto right = bst.upper_bound(p);
            if (right != bst.end()) {                
                if (right->first <= value + 1) {
                    start = min(start, right->first);
                    end = max(end, right->second);
                    bst.erase(right);
                }                
            }            
            bst.insert(pair{start, end});
        }
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;
        for (auto [start, end]: bst) {
            answer.push_back({start, end});
        }
        return answer;
    }
    
private:
    set<pair<int, int>> bst;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

int main() {
    set<pair<int, int>> bst;

    bst.insert(pair{1, 3});
    bst.insert(pair{7, 9});

    auto it = bst.lower_bound(pair{2, 2});

    cout << it->first << endl;


    return 0;
}