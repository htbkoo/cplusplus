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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<long> minDists = vector<long>(n, numeric_limits<int>::max());
        minDists[src] = 0;
        
        for (int numStops = 0; numStops <= k; numStops++) {
            vector<long> prevMinDists(minDists);
            
            for (auto flight: flights) {
                int fromCity = flight[0], toCity = flight[1], price = flight[2];
                
                minDists[toCity] = min(
                    minDists[toCity],
                    prevMinDists[fromCity] + price
                );
            }
        }
        
        if (minDists[dst] < numeric_limits<int>::max()) {
            return (int) minDists[dst];
        } else {
            return -1;
        }
    }
};

class TLESolution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<unordered_map<int, int>> neighbours = vector<unordered_map<int, int>>(n);
        for (auto flight: flights) {
            int fromCity = flight[0], toCity = flight[1], price = flight[2];
            if (neighbours[fromCity].count(toCity) > 0) {
                neighbours[fromCity][toCity] = min(neighbours[fromCity][toCity], price);
            } else {
                neighbours[fromCity][toCity] = price;
            }
        }

 
        // std::vector<int> vec {3, 1, 4, 1, 5};
        // std::priority_queue<int> pq3 {std::less<int>(), vec};

        vector<tuple<int, int, int>> startPoint = {make_tuple(0, 0, src)};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq(startPoint.begin(), startPoint.end(), greater<tuple<int, int, int>>());
        // pq.push(make_tuple(0, 0, src));
        
        while (pq.size() > 0) {
            auto t = pq.top();
            pq.pop();
            
            int totalPrices = get<0>(t), numFlight = get<1>(t), city = get<2>(t);

            if (city == dst) {
                return totalPrices;
            }
            if (numFlight > k) {
                continue;
            }
            
            for (auto [nextCity, price]: neighbours[city]) {
                int nextPrices = totalPrices + price;
                pq.push(make_tuple(nextPrices, numFlight + 1, nextCity));
            }
        }
        
        return -1;
    }
};

int main() {
    Solution soln;

    // int n = 4, src = 0, dst = 3, k = 1;
    // vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    int n = 3, src = 0, dst = 2, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};

    cout << soln.findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}