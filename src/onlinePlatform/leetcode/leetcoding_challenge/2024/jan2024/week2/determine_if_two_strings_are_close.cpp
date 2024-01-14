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
    bool closeStrings(string word1, string word2) {
        bool hasSameCharset = getCharset(word1) == getCharset(word2);

        if (!hasSameCharset) {
            return false;
        }

        auto counter1 = getCountsOfCounts(word1);
        auto counter2 = getCountsOfCounts(word2);

        if (counter1.size() != counter2.size()) {
            return false;
        }

        for (auto& [freq, count]: counter1) {
            if (counter2.count(freq) == 0) {
                return false;
            }

            if (counter2[freq] != count) {
                return false;
            }
        }

        return true;
    }

private:
    unordered_map<int, int> getCountsOfCounts(string& word) {
        unordered_map<char, int> charsFrequencies;
        for (auto ch: word) {
            charsFrequencies[ch]++;
        }

        unordered_map<int, int> counter;
        for (auto& [ch, count]: charsFrequencies) {
            counter[count]++;
        }

        return counter;
    }

    unordered_set<char> getCharset(string& word) {
        return unordered_set<char>(begin(word), end(word));
    }
};

int main() {
    string a = "1234";
    string a2 = "1234a";
    unordered_set<char> s(begin(a), end(a));
    unordered_set<char> s2(begin(a2), end(a2));

    cout << s.size() << endl;
    cout << (s == s2) << endl;
    cout << (unordered_set<char>(begin(a), end(a)) == unordered_set<char>(begin(a2), end(a2))) << endl;

    return 0;
}