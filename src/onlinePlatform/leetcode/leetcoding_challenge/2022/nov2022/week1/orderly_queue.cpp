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
    string orderlyQueue(string s, int k) {
        string answer = string(s);
        if (k == 1) {
            for (int i = 1; i < s.size(); i++) {
                string temp = s.substr(i, s.size() - i) + s.substr(0, i);
                if (temp < answer) {
                    answer = temp;
                }
            }
            return answer;
        } else {
            sort(answer.begin(), answer.end());
            return answer;
        }
    }
};

int main() {
    string str = "bacd";
    cout << "before: " << str << endl;
    sort(str.begin(), str.end());
    cout << "after: " << str << endl;

    Solution soln;
    cout << soln.orderlyQueue("cba", 1) << endl;
}