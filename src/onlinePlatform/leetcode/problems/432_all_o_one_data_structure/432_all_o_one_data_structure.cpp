#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {        
        if (counter.count(key) > 0 && counter[key] > 0) {
            bst.erase(pair(counter[key], key));
        }
        counter[key]++;
        bst.insert(pair(counter[key], key));
    }
    
    void dec(string key) {                
        if (counter.count(key) > 0 && counter[key] > 0) {
            bst.erase(pair(counter[key], key));
            
            counter[key]--;
            if (counter[key] > 0) {
                bst.insert(pair(counter[key], key));
            }    
        }
        // TODO: else throw invalid_argument?
    }
    
    string getMaxKey() {
        if (bst.size() > 0) {
            return (*prev(bst.end())).second;
        } else {
            return "";
        }
        
    }
    
    string getMinKey() {        
        if (bst.size() > 0) {
            return (*bst.begin()).second;
        } else {
            return "";
        }
    }
    
private:
    map<string, int> counter;
    set<pair<int, string>> bst;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */