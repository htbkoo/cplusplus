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

class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        int totalSize = minHeap.size() + maxHeap.size();

        minHeap.push(num);
        num = minHeap.top();
        minHeap.pop();

        maxHeap.push(num);

        if (maxHeap.size() > minHeap.size()) {
            num = maxHeap.top();
            maxHeap.pop();
            minHeap.push(num);
        }
    }
    
    double findMedian() {
        int totalSize = minHeap.size() + maxHeap.size();
        if (totalSize == 0) {
            throw invalid_argument("empty");
        }
        if (totalSize % 2 == 0) {
            return ((double)(minHeap.top() + maxHeap.top())) / 2.0; 
        } else {
            return minHeap.top();
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */