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

class File {
public:
    string directory;
    string name;
    string content;

    File(string d, string rawNameAndContent) {
        directory = d;

        pair<string, string> nameAndContent = parseNameAndContent(rawNameAndContent);
        name = nameAndContent.first;
        content = nameAndContent.second;
    }

    string getFullPath() {
        return directory + "/" + name;
    }

private:
    pair<string, string> parseNameAndContent(string rawNameAndContent) {
        int idx = rawNameAndContent.find("(", 0);
        string name = rawNameAndContent.substr(0, idx);
        string content = rawNameAndContent.substr(idx + 1, rawNameAndContent.size() - 2 - idx);
        return pair<string, string>{name, content};
    }
};

class Path {
public:
    vector<File> files;
    
    Path(string rawPath) {
        vector<string> words = splitString(rawPath, ' ');
        // TODO: add error handling, e.g. if words is empty;

        string directory = words[0];
        for (int i = 1; i < words.size(); i++) {
            string rawNameAndContent = words[i];
            File file = File(directory, rawNameAndContent);
            files.push_back(file);
        }
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
};

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> fileContents;

        for (string rawPath: paths) {
            Path path = Path(rawPath);

            for (File file: path.files) {
                fileContents[file.content].push_back(file.getFullPath());
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
};

int main () {
    Solution soln;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    soln.findDuplicate(paths);
    return 0;
}