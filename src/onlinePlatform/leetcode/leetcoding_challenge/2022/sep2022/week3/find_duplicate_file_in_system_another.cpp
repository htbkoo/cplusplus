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
#include <string>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> fileContents;

        for (string rawPath: paths) {
            vector<string> words = splitString(rawPath, ' ');
            // TODO: add error handling, e.g. if words is empty;

            string directory = words[0];
            for (int i = 1; i < words.size(); i++) {
                string rawNameAndContent = words[i];
                        
                pair<string, string> nameAndContent = parseNameAndContent(rawNameAndContent);
                string name = nameAndContent.first;
                string content = nameAndContent.second;
                fileContents[content].push_back(directory + "/" + name);
            }
        }

        vector<vector<string>> answer;
        for (auto &[_, filePaths]: fileContents) {
            if (filePaths.size() > 1) {
                answer.push_back(filePaths);
            }
        }

        return answer;
    }
    
private:
    vector<string> splitString(string s, char delimiter) {
        stringstream  ss(s);

        vector<string> words;
        string word;
        while (getline(ss, word, delimiter)) {
            words.push_back(word);
        }

        return words;
    }

    pair<string, string> parseNameAndContent(string rawNameAndContent) {
        int idx = rawNameAndContent.find("(", 0);
        string name = rawNameAndContent.substr(0, idx);
        string content = rawNameAndContent.substr(idx + 1, rawNameAndContent.size() - 2 - idx);
        return pair<string, string>{name, content};
    }
};

int main () {
    Solution soln;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    soln.findDuplicate(paths);
    return 0;
}