#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <random>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class RandomizedSet {
public:
    RandomizedSet() {
        v = vector<int>();
        m = unordered_map<int, int>();
        
        rng = mt19937(dev());
    }
    
    bool insert(int val) {
        if (m.count(val) == 0) {
            m[val] = v.size();            
            v.push_back(val);
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) {
            return false;
        } else {
            int lastVal = v.back();
            int valPos = m[val];

            v[valPos] = lastVal;
            m[lastVal] = valPos;
            
            v.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return v[getRandInt(0, v.size() - 1)];
    }
    
private:
    vector<int> v;
    unordered_map<int, int> m;
    
    random_device dev;
    mt19937 rng;
    
    int getRandInt(int lo, int hi) {
        uniform_int_distribution<mt19937::result_type> dist(lo, hi); // distribution in range [1, 6]
        return dist(rng);
    }
};

class WARandomizedSet {
public:
    WARandomizedSet() {
        v = vector<int>();
        m = unordered_map<int, int>();
        
        rng = mt19937(dev());
    }
    
    bool insert(int val) {
        if (m.count(val) == 0) {
            m[val] = v.size();            
            v.push_back(val);
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) {
            return false;
        } else {
//             if (v.size() == 0) {
//                 throw logic_error("programming bug, vector is empty");
//             } else if (v.size() == 1) {
//                 m.erase(val);
//                 v.pop_back();
//             } else {
//                 int lastVal = v.back();
//                 int valPos = m[val];
                
//                 v[valPos] = lastVal;
//                 m[lastVal] = valPos;
//                 m.erase(val);
//             }
            int lastVal = v.back();
            int valPos = m[val];

            v[valPos] = lastVal;
            m[lastVal] = valPos;
            
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return v[getRandInt(0, v.size() - 1)];
    }
    
private:
    vector<int> v;
    unordered_map<int, int> m;
    
    random_device dev;
    mt19937 rng;
    
    int getRandInt(int lo, int hi) {
        uniform_int_distribution<mt19937::result_type> dist(lo, hi); // distribution in range [1, 6]
        return dist(rng);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet obj;
    obj.insert(0);
    obj.insert(1);
    obj.remove(0);
    obj.insert(2);
    obj.remove(1);
    int param_3 = obj.getRandom();
    cout << param_3 << endl;
    return 0;
}