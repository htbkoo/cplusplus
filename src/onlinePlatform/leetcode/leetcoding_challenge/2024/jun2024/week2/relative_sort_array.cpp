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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> counter;
        for (auto num: arr1) {
            counter[num]++;
        }

        vector<int> answer;
        for (auto num: arr2) {
            for (int i = 0; i < counter[num]; ++i) {
                answer.push_back(num);
            }
            counter.erase(num);
        }

        for (auto& [num, count]: counter) {
            for (int i = 0; i < count; ++i) {
                answer.push_back(num);
            }
        }

        return answer;
    }
};
