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

auto cmp = [](int left, int right) { return left > right; };

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto num: nums) {
            addNum(num);
        }
    }
    
    int add(int val) {
        addNum(val);
        return pq[0];
    }
    
private:
    int _k;
    vector<int> pq;
    
    void addNum(int num) {
        pq.push_back(num);
        push_heap(pq.begin(), pq.end(), cmp);
        
        if (pq.size() > _k) {
            pop_heap(pq.begin(), pq.end(), cmp);
            pq.pop_back();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */