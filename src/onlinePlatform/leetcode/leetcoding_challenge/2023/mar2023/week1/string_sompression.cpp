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
    int compress(vector<char>& chars) {
        if (chars.size() == 0) {
            return 0;
        }
        
        int write = 0, start = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] != chars[start]) {
                write++;
                int size = i - start;
                if (size > 1) {
                    string sizeString = to_string(size);
                    for (int j = 0; j < sizeString.size(); j++) {
                        chars[write] = sizeString[j];
                        write++;
                    }
                }
                
                start = i;
            }
        }
        
        // TODO: handle the tail compression
        int size = chars.size() - start;
        write++;
        if (size > 1) {
            string sizeString = to_string(size);
            for (int j = 0; j < sizeString.size(); j++) {
                chars[write] = sizeString[j];
                write++;
            }
        }

        return write;
    }
};