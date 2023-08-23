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
    string reorganizeString(string s) {
        unordered_map<char, int> counter;
        for (char ch: s) {
            counter[ch]++;
            
            if (counter[ch] * 2 > s.size() + 1) {
                return "";
            }
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, count]: counter) {
            pq.push(pair{count, ch});
        }
        
        string answer;
        answer.reserve(s.size());
        
        pair<int, char> prev;
        
        while (pq.size() > 0) {
            auto [count, ch] = pq.top();
            pq.pop();
            
            if (answer.size() > 0 && answer.back() == ch) {
                auto [count2, ch2] = pq.top();
                pq.pop();

                answer.push_back(ch2);

                if (count2 > 1) {
                    pq.push(pair{count2 - 1, ch2});
                }
                
                pq.push(pair{count, ch});
            } else {
                answer.push_back(ch);

                if (count > 1) {
                    pq.push(pair{count - 1, ch});
                }
            }
        }
        
        return answer;
    }
};