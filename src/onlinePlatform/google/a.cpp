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

    unordered_map<char, char> mapping;
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        int d;
        cin >> d;
        mapping[ch] = d + '0';
    }

    int N;
    cin >> N;

    unordered_set<string> appeared;
    for (int j = 0; j < N; ++j) {
        string word;
        cin >> word;
        for (int k = 0; k < word.size(); ++k) {
            word[k] = mapping[word[k]];
        }
        if (appeared.count(word) > 0) {
            return "YES";
        }

        appeared.insert(word);
    } 

    return "NO";
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
  