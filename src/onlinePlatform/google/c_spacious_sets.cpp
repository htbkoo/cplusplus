// https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94/0000000000cad7cf 
// Colliding Encoding

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

string solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    // set<int> sortedA = set(A.begin(), A.end());
    vector<int> sortedA;
    for (auto a: set(A.begin(), A.end())) {
        sortedA.push_back(a);
    }

    unordered_map<int, int> findSizeRight;
    findSizeRight[sortedA.size()] = 0;
    for (int currIdx = sortedA.size() - 1; currIdx >= 0; --currIdx) {
        int curr = sortedA[currIdx];
        int nextIdx = distance(sortedA.begin(), lower_bound(sortedA.begin(), sortedA.end(), curr + K));
        findSizeRight[currIdx] = 1  + findSizeRight[nextIdx];
    }

    unordered_map<int, int> findSizeLeft;
    findSizeLeft[-1] = 0;
    for (int currIdx = 0; currIdx < sortedA.size(); ++currIdx) {
        int curr = sortedA[currIdx];
        int nextIdx = distance(sortedA.begin(), upper_bound(sortedA.begin(), sortedA.end(), curr - K)) - 1;
        findSizeLeft[currIdx] = 1  + findSizeLeft[nextIdx];
    }

    unordered_map<int, int> indices;
    for (int i = 0; i < sortedA.size(); ++i) {
        int x = sortedA[i];
        indices[x] = i;
    }

    string answer;
    for (auto a: A) {
        int xIdx = indices[a];
        if (answer.size() > 0) {
            answer += " ";
        }
        answer += to_string(findSizeLeft[xIdx] + findSizeRight[xIdx] - 1);
    }

    return answer;
}

using namespace std; // since cin and cout are both in namespace std, this saves some text
int main() {
  int t, n, m;
  cin >> t; // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": " << solve() << endl;
    // cout knows that n + m and n * m are ints, and prints them accordingly.
    // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
  }
  return 0;
}
  