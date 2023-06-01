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

class UndergroundSystem {
public:
    UndergroundSystem() {
        customerCheckIns = unordered_map<int, pair<string, int>>();
        travelTimes = unordered_map<string, unordered_map<string, pair<long, long>>>();
    }
    
    void checkIn(int id, string stationName, int t) {
        // TODO: validate there is no existing check in for id
        customerCheckIns[id] = pair{stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [checkInStationName, checkInT] = customerCheckIns[id];
        customerCheckIns.erase(id);
        
        int travelTime = t - checkInT;
        
        if (travelTimes.count(checkInStationName) == 0 || travelTimes[checkInStationName].count(stationName) == 0) {
            travelTimes[checkInStationName][stationName] = pair{0L, 0L};
        }
        
        auto [prevTravelTotal, prevTravelCount] = travelTimes[checkInStationName][stationName];
        travelTimes[checkInStationName][stationName] = pair{prevTravelTotal + (long) travelTime, prevTravelCount + 1};
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto [travelTotal, travelCount] = travelTimes[startStation][endStation];
        return (double) travelTotal / (double) travelCount;
    }
    
private:
    unordered_map<int, pair<string, int>> customerCheckIns;
    unordered_map<string, unordered_map<string, pair<long, long>>> travelTimes;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */