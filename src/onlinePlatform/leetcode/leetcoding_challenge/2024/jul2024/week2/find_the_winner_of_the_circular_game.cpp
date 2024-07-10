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
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for (int i = 1; i <= n; ++i) {
            friends.push_back(i);
        }

        int curr = 0;
        while (friends.size() > 1) {
            curr = (curr + k - 1) % friends.size();

            friends.erase(friends.begin()+curr);

        }

        return friends[0];
    }
};
