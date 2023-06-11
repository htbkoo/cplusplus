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

const int INITIAL_VALUE = 0;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        snapId = 0;
        snapshots = vector<map<int, int>>(length);
        for (int i = 0; i < length; ++i) {
            snapshots[i][snapId] = INITIAL_VALUE;
        }
    }
    
    void set(int index, int val) {
        snapshots[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        // return *lower_bound(snapshots[index].begin(), snapshots[index].end(), snap_id);
        // return snapshots[index].lower_bound(snap_id)->second;
        return prev(snapshots[index].upper_bound(snap_id))->second;
    }
    
private:
    int snapId;
    vector<map<int, int>> snapshots;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */