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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        
        for (auto& flower: flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1]);
        }
        sort(begin(starts), end(starts));
        sort(begin(ends), end(ends));
        
        
        vector<int> answer;
        
        for (auto person: people) {
            int right = distance(begin(starts), upper_bound(begin(starts), end(starts), person));
            int left = distance(begin(ends), lower_bound(begin(ends), end(ends), person));
            
            answer.push_back(right - left);
        }
        
        return answer;
    }
};

class WIPSolution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> answer(people.size(), 0);
        
        vector<pair<int, int>> peopleWithId;
        for (int i = 0; i < people.size(); ++i) {
            peopleWithId.push_back(pair{people[i], i});
        }
        
        sort(begin(peopleWithId), end(peopleWithId));
        
        int count = 0;
        
        return {};    
    }
};