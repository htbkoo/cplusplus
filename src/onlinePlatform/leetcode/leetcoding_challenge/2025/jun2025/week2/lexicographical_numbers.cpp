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
    vector<int> lexicalOrder(int n) {
        vector<int> answer;

        vector<int> stack;
        stack.push_back(1);

        // in-order
        while (stack.size() > 0) {
            auto v = stack.back();
            stack.pop_back();

            if (v > n) {
                continue;
            }

            answer.push_back(v);

            if (v % 10 < 9) {
                stack.push_back(v + 1);
            }
            stack.push_back(v * 10);
        }

        return answer;
    }
};

class WASolution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;

        deque<int> q;
        q.push_back(1);

        // in-order
        while (q.size() > 0) {
            auto v = q.front();
            q.pop_front();

            if (v > n) {
                continue;
            }

            answer.push_back(v);

            q.push_back(v * 10);
            q.push_back(v + 1);
        }

        return answer;
    }
};
