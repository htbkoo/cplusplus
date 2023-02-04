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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        unordered_map<char, int> s1Counter;
        for (char ch: s1) {
            s1Counter[ch]++;
        }
        
        unordered_map<char, int> currCounter;
        for (int i = 0; i < s1.size(); i++) {
            char ch = s2[i];
            currCounter[ch]++;
        }
        
        if (areMapsEqual(s1Counter, currCounter)) {
            return true;
        }
        
        for (int i = s1.size(); i < s2.size(); i++) {
            char ch = s2[i];
            currCounter[ch]++;
            
            char prevCh = s2[i - s1.size()];
            currCounter[prevCh]--;
            if (currCounter[prevCh] == 0) {
                currCounter.erase(prevCh);
            }

            if (areMapsEqual(s1Counter, currCounter)) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    template <typename Map>
    bool areMapsEqual(Map const &lhs, Map const &rhs) {
        if (lhs.size() != rhs.size()) {
            return false;
        }
        return lhs == rhs;
    }    
};

class WASolution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1Counter;
        for (char ch: s1) {
            s1Counter[ch]++;
        }
        
        unordered_map<char, int> currCounter;
        for (int i = 0; i < s1.size(); i++) {
            char ch = s2[i];
            currCounter[ch]++;
        }
        
        if (areMapsEqual(s1Counter, currCounter)) {
            return true;
        }
        
        for (int i = s1.size(); i < s2.size(); i++) {
            char ch = s2[i];
            currCounter[ch]++;
            
            char prevCh = s2[i - s1.size()];
            currCounter[prevCh]--;
            if (currCounter[prevCh] == 0) {
                currCounter.erase(prevCh);
            }

            if (areMapsEqual(s1Counter, currCounter)) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    template <typename Map>
    bool areMapsEqual(Map const &lhs, Map const &rhs) {
        cout << lhs.size() << " " << rhs.size() << endl;
        printMap(lhs);
        printMap(rhs);

        if (lhs.size() != rhs.size()) {
            return false;
        }
        return lhs == rhs;
        // return equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    
    template <typename Map>
    void printMap(Map const &m) {
        cout << "{" << endl;
        for (auto& [key, val]: m) {
            cout << key << "->" << val << endl;
        }
        cout << "}" << endl;
    }
};

int main() {
    Solution soln;
    cout << soln.checkInclusion("ab", "eidbaooo") << endl;
    cout << soln.checkInclusion( "dinitrophenylhydrazine", "dimethylhydrazine" ) << endl;

    return 0;
}