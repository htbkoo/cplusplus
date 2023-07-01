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
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distributions = vector<int>(k, 0);
        
        return findMin(0, cookies, distributions);
    }
    
private:
    int findMin(int i, vector<int>& cookies, vector<int>& distributions) {
        if (i >= cookies.size()) {
            return computeUnfairness(distributions);
        }
        
        int answer = numeric_limits<int>::max();
        for (int k = 0; k < distributions.size(); ++k) {
            distributions[k] += cookies[i];
            answer = min(answer, findMin(i + 1, cookies, distributions));
            distributions[k] -= cookies[i];            
        }
        
        return answer;
    }
    
    int computeUnfairness(vector<int>& distributions) {
        int unfairness = distributions[0];
        
        for (auto d: distributions) {
            unfairness = max(unfairness, d);
        }
        
        return unfairness;
    }
};