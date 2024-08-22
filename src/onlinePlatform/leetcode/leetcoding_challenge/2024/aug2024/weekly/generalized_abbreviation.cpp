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
    vector<string> generateAbbreviations(string word) {
        if (word.size() == 0) {
            // TODO: confirm this
            return {};
        }
     
        auto answer = generate(word, 0);
        return vector<string>(begin(answer), end(answer));
    }
    
private:
    unordered_set<string> generate(string &word, int i) {
        if (i >= word.size()) {
            return {""};
        }
        
        unordered_set<string> answer;
        
        int start = i;        
        while (start < word.size()) {        
            int headSize = start - i;
            int abbreviationSize = 1;
            while (start + abbreviationSize <= word.size()) {
                string head = word.substr(i, headSize) + to_string(abbreviationSize);
                if (start + abbreviationSize < word.size()) {
                    head += word[start + abbreviationSize];
                }

                for (auto& tail: generate(word, start + abbreviationSize + 1)) {

                    if (head + tail == "1o" || head + tail == "" || i == 2) {
                        cout << start << ": " << head << "_" << abbreviationSize << "_" << tail << ":" << (start + abbreviationSize + 1) << endl;
                    }

                    answer.insert(head + tail);
                }

                abbreviationSize++;
            }            

            start++;
            headSize = start - i;
            string head = word.substr(i, headSize);
            for (auto& tail: generate(word, start)) {

                if (head + tail == "1o" || head + tail == "" || i == 2) {
                    cout << start << ": " << head << "_0_" << tail << endl;
                }


                answer.insert(head + tail);
            }
        }
        

        return answer;
    }
};