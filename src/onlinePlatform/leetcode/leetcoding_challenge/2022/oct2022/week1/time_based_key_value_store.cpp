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

class TimeMap {
public:
    TimeMap() {
        mapping = map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string NO_VALUE = "";
        if (mapping.count(key) == 0) {
            return NO_VALUE;
        }
        auto values = mapping[key];
        auto it = values.upper_bound(timestamp);
        if (it == values.begin()) {
            return NO_VALUE;
        }
        it--;
        auto [_, value] = *it;
        return value;
    }
    
private:
    map<string, map<int, string>> mapping;
};

class WATimeMap {
public:
    WATimeMap() {
        mapping = map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (mapping.count(key) == 0) {
            string NO_VALUE = "";
            return NO_VALUE;
        }
        auto values = mapping[key];
        auto it = values.lower_bound(timestamp);
        if (it == values.end()) {
            it--;
        }
        auto [_, value] = *it;
        return value;
    }
    
private:
    map<string, map<int, string>> mapping;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap tm;
    // tm.set("foo", "bar", 1);
    // tm.get("foo", 1);
    // tm.get("foo", 3);
    // tm.set("foo", "bar2", 4);
    // tm.get("foo", 4);
    // tm.get("foo", 5);

    tm.set("love","high",10);
    tm.set("love","low",20);
    tm.get("love",5);
    tm.get("love",10);
    tm.get("love",15);
    tm.get("love",20);
    tm.get("love",25);
}