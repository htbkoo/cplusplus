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
    bool isAlienSorted(vector<string>& words, string order) {        
        for (string& word: words) {
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                char mapTo = order.find(ch) + 'a';                
                word[i] = mapTo;
            }
        }
        
        vector<string> sortedWords(words);
        sort(sortedWords.begin(), sortedWords.end());
        
        return words == sortedWords;
    }
};

template <typename T>
void printVector(vector<T> v) {
    for (auto item: v) {
        cout << item << " ";
    }
    cout << endl;
}

class WASolution {
public:
    bool isAlienSorted(vector<string>& words, string order) {        
        for (string word: words) {
            cout << "before: " << word << endl;
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                char mapTo = order.find(ch) + 'a';                
                word[i] = mapTo;
            }
            cout << "after: " << word << endl;
        }
        
        vector<string> sortedWords(words);
        sort(sortedWords.begin(), sortedWords.end());

        printVector(words);
        printVector(sortedWords);

        return words == sortedWords;
    }
};

int main() {
    Solution soln;
    vector<string> words = {"ubg","kwh"};
    string order = "qcipyamwvdjtesbghlorufnkzx";
    cout << soln.isAlienSorted(words, order) << endl;
    return 0;
}