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

#include <random>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Solution(ListNode* head) {
        arr = vector<int>();
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head -> next;
        }
        
        random_device dev;
        mt19937 rng(dev());
        // uniform_int_distribution<mt19937::result_type> dist(0, arr.size() - 1); // distribution in range [0, arr.size() - 1]
    }
    
    int getRandom() {
        if (arr.size() == 1) {
            return arr[0];
        }
        
        // int idx = randInt(0, arr.size() - 1);
        // int idx = dist(rng);
        uniform_int_distribution<mt19937::result_type> dist(0, arr.size() - 1); // distribution in range [0, arr.size() - 1]
        int idx = dist(rng);
        
        return arr[idx];
    }
    
private:
    vector<int> arr;
    mt19937 rng;
    // uniform_int_distribution<mt19937::result_type> dist;
    
    int randInt(int lo, int hi) {
        // return lo + std::rand()/((RAND_MAX + 1u)/hi);
        return 0;
        // return dist(rng);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
