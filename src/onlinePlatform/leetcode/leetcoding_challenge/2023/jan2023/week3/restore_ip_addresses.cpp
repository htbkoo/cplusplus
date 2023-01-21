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
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        vector<int> positions = {0};
        build(s, 1, positions, answer);
        return answer;
    }
    
private:
    void build(string& s, int i, vector<int>& positions, vector<string>& answer) {        
        if (i >= s.size()) {
            if (positions.size() == 4 && isValid(s, positions.back(), i)) {
                vector<int> newPositions = withPos(positions, i);
                answer.push_back(getIpAddress(s, newPositions));
            }
            return;
        }
        
        if (isValid(s, positions.back(), i)) {
            vector<int> newPositions = withPos(positions, i);
            build(s, i + 1, newPositions, answer);
        }
        build(s, i + 1, positions, answer);
    }
    
    bool isValid(string& s, int begin, int end) {
        string sub = getSubstr(s, begin, end);
        if (sub.size() == 0) {
            return false;
        }
        if (sub[0] == '0' && sub.size() > 1) {
            return false;
        }
        if (sub.size() > 3) {
            return false;
        }
        long val = stoi(sub);
        return 0 <= val && val <= 255;
    }
    
    string getSubstr(string& s, int begin, int end) {
        int count = end - begin;
        return s.substr(begin, count);
    }
    
    string getIpAddress(string& s, vector<int>& positions) {
        string answer;
        for (int i = 0; i < positions.size() - 1; i++) {
            if (answer.size() > 0) {
                answer += ".";
            }
            answer += getSubstr(s, positions[i], positions[i + 1]);
        }
        return answer;
    }
    
    vector<int> withPos(vector<int>& positions, int i) {
        vector<int> newPositions(positions);
        newPositions.push_back(i);
        return newPositions;
    }
};
int main() {
    Solution soln;
    auto answer = soln.restoreIpAddresses("25525511135");
    
    cout << endl;
    return 0;
}