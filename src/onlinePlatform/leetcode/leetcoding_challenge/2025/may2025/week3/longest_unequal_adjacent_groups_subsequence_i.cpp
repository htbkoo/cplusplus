// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

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
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups) {
        int NO_PREV = -1;

        vector<pair<int, int> > best(words.size());
        for (int i = 0; i < words.size(); ++i) {
            best[i] = pair{words[i].size(), NO_PREV};
        }

        int bestIdx = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] == groups[j]) {
                    continue;
                }
                int lengthJ = best[j].first + words[i].size();
                if (lengthJ > best[i].first) {
                    best[i] = pair{lengthJ, j};
                }
                if (best[i].first > best[bestIdx].first) {
                    bestIdx = i;
                }
            }
        }

        deque<string> answer;
        while (bestIdx != NO_PREV) {
            answer.push_front(words[bestIdx]);
            bestIdx = best[bestIdx].second;
        }

        // return vector(begin(answer), end(answer));
        return {begin(answer), end(answer)};
    }
};

int main() {
    Solution soln;
    vector<string> words{"a", "b", "c", "d"};
    vector groups{1, 0, 1, 1};

    auto result = soln.getLongestSubsequence(words, groups);
    for (auto w: result) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
