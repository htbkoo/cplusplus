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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        const int MIN_SPACE_SIZE = 1;
        
        vector<vector<string>> lines = {{}};
        int currLineLength = 0;
        
        for (auto word: words) {
            if (willExceedLine(word, currLineLength, maxWidth)) {
                currLineLength = 0;
                lines.push_back({});
            }
            
            lines.back().push_back(word);
            currLineLength += word.size() + MIN_SPACE_SIZE;
        }

        // format the lines
        vector<string> answer;
        for (int i = 0; i < lines.size(); ++i) {
            bool isLeftJustified = i == lines.size() - 1;
            
            string line = formatLine(lines[i], isLeftJustified, maxWidth);
            answer.push_back(line);
        } 
        
        return answer;
    }
    
private:
    bool willExceedLine(string& word, int currLineLength, int maxWidth) {
        return currLineLength + word.size() > maxWidth;
    } 
    
    string formatLine(vector<string>& line, bool isLeftJustified, int maxWidth) {
        int wordsLength = 0;        
        for (auto word: line) {
            wordsLength += word.size();
        }
        
        int spaceSize = maxWidth - wordsLength;
        int numSpaces = line.size() - 1;
        
        string answer;
        answer.reserve(maxWidth);
        for (int i = 0; i < line.size(); ++i) {
            answer += line[i];
            
            if (i > 0) {
                int space = 1;
                if (!isLeftJustified) {
                    space = spaceSize / numSpaces;
                    if (i <= spaceSize % numSpaces) {
                        space++;
                    }
                }
                
                for (int s = 0; s < space; s++) {
                    answer += " ";
                }
            }
        }
        
        while (answer.size() < maxWidth) {
            answer += " ";
        }
        
        return answer;
    }
};