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
    vector<vector<string>> partition(string s) {
        vector<int> partitions = {0};
        vector<vector<string>> answer;
        
        build(s, 1, partitions, answer);
        return answer;
    }

private:
    void build(string& s, int i, vector<int>& partitions, vector<vector<string>>& answer) {
        if (i == s.size()) {
            if (isPalindrome(s, partitions.back(), i)) {
                auto newPartitions = withPos(i, partitions);
                auto substrings = buildSubstrings(s, newPartitions);
                answer.push_back(substrings);
            }
            return;
        }
        
        build(s, i + 1, partitions, answer);
        
        if (isPalindrome(s, partitions.back(), i)) {
            partitions.push_back(i);
            build(s, i + 1, partitions, answer);
            partitions.pop_back();
        }
    }

    vector<int> withPos(int i, vector<int>& partitions) {
        vector<int> newPartitions = vector<int>(partitions);
        newPartitions.push_back(i);
        return newPartitions;
    }
    
    string substr(string& s, int begin, int end) {
        int count = end - begin;
        return s.substr(begin, count);
    }
    
    bool isPalindrome(string& s, int begin, int end) {
        string ss = substr(s, begin, end);
        
        string reversed(ss);
        reverse(reversed.begin(), reversed.end());
        
        return ss == reversed;
    }
    
    vector<string> buildSubstrings(string& s, vector<int>& partitions) {
        vector<string> substrings;
        
        for (int i = 0; i < partitions.size() - 1; i++) {
            string ss = substr(s, partitions[i], partitions[i + 1]);
            substrings.push_back(ss);
        }
        
        return substrings;
    }
};