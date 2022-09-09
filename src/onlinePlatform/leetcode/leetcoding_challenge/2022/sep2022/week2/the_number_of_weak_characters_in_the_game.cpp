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

struct sortByAttackDescAndDefenseAsc {
    inline bool operator() (vector<int>& properties1, vector<int>& properties2) {
        if (properties1[0] == properties2[0]) {
            return properties1[1] < properties2[1];
        }
        return properties1[0] > properties2[0];
    }
};

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int answer = 0;
        
        sort(properties.begin(), properties.end(), sortByAttackDescAndDefenseAsc());
        
        int prevLargestDef = -1;
        
        for (vector<int> property: properties) {
            if (prevLargestDef > property[1]) {
                answer++;
            }
            
            prevLargestDef = max(prevLargestDef, property[1]);
        }
        
        return answer;
    }
};