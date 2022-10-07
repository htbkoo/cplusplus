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

class MyCalendarThree {
public:
    MyCalendarThree() {
        maxCount = 0;
        bookings = map<int, int>();
    }
    
    int book(int start, int end) {
        if (bookings.count(start) == 0) {
            bookings[start] = 0;
        }
        if (bookings.count(end) == 0) {
            bookings[end] = 0;
        }
        bookings[start]++;
        bookings[end]--;

        int currCount = 0;
        for (auto [time, count]: bookings) {
            currCount += count;
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }

private:
    int maxCount;
    map<int, int> bookings;
};

class WAMyCalendarThree {
public:
    WAMyCalendarThree() {
        bookings = map<int, int>();
    }
    
    int book(int start, int end) {
        if (bookings.count(start) == 0) {
            bookings[start] = 0;
        }
        if (bookings.count(end) == 0) {
            bookings[end] = 0;
        }
        bookings[start]++;
        bookings[end]--;

        int currCount = 0;
        int maxCount = 0;
        for (auto [time, count]: bookings) {
            if (time > end) {
                return maxCount;
            }
            currCount += count;
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }

private:
    map<int, int> bookings;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

int main() {
    MyCalendarThree cal;

    // cal.book(10, 20);
    // cal.book(50, 60);
    // cal.book(10, 40);
    // cal.book(5, 15);
    // cal.book(5, 10);
    // cal.book(25, 55);

    cal.book(26,35);
    cal.book(26,32);
    cal.book(25,32);
    cal.book(18,26);
    cal.book(40,45);
    cal.book(19,26);
    cal.book(48,50);
    cal.book(1,6);
    cal.book(46,50);
    cal.book(11,18);

}