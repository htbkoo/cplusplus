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
    string simplifyPath(string path) {
        if (path.size() == 0) {
            return path;
        }
        
        string DELIMITER = "/";
        
        vector<string> directories = split(path, DELIMITER);
        
        vector<string> curr;
        
        for (auto directory: directories) {
            if (directory == "." || directory.size() == 0) {
                // no-op
            } else if (directory == "..") {
                if (curr.size() > 0) {
                    curr.pop_back();
                }
            } else {
                curr.push_back(directory);
            }
        }
        
        return DELIMITER + join(curr, DELIMITER);
    }
    
private:
    vector<string> split(string s, string delimiter) {
        vector<string> v;
        
        // reference: https://stackoverflow.com/a/46931770        
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        
        while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
            string token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            v.push_back(token);
        }

        v.push_back(s.substr(pos_start));
        
        return v;
    }
    
    string join(vector<string> ss, string delimiter) {
        if (ss.size() == 0) {
            return "";
        }
        
        string s = ss[0];
        for (int i = 1; i < ss.size(); i++) {
            s += delimiter;
            s += ss[i];
        }
        
        return s;
    }
};
