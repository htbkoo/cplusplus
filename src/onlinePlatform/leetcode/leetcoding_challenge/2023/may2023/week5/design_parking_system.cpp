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

const int BIG = 1;
const int MEDIUM = 2;
const int SMALL = 3;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        remainSlots = unordered_map<int, int>();
        remainSlots[BIG] = big;
        remainSlots[MEDIUM] = medium;
        remainSlots[SMALL] = small;
    }
    
    bool addCar(int carType) {
        if (remainSlots[carType] <= 0) {
            return false;
        } else {
            remainSlots[carType]--;
            return true;
        }
    }
    
private:
    unordered_map<int, int> remainSlots;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */