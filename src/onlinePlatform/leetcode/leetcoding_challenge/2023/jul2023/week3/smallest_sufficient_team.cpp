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

const int UNINITIALIZED = -1;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {        
        memo = vector<vector<int>>();
        for (int i = 0; i < people.size(); ++i) {
            memo.push_back(vector<int>(getBitmaskSize(req_skills), UNINITIALIZED));
        }
        
        skillsIndices = unordered_map<string, int>();
        for (int i = 0; i < req_skills.size(); ++i) {
            string skill = req_skills[i];
            skillsIndices[skill] = i;
        }
        
        return toVector(findSmallest(0, 0, req_skills, people));
    }
    
private:
    unordered_map<string, int> skillsIndices;
    vector<vector<int>> memo;
    
    vector<int> toVector(long long peopleBitmask) {
        vector<int> answer;
        int currBit = 0;
        while (peopleBitmask > 0) {
            if (peopleBitmask % 2 == 1) {
                answer.push_back(currBit);
            }
            
            peopleBitmask /= 2;
            currBit++;
        }
        
        return answer;
    }
    
    long long findSmallest(int i, int bitmask, vector<string>& req_skills, vector<vector<string>>& people) {
        if (isSufficientTeam(bitmask, req_skills)) {
            return 0;
        }
        
        if (i == people.size()) {
            // throw invalid_argument("unable to form a sufficient team");
            return pow(2l, people.size()) - 1;
        }
        
        long long skipPerson = findSmallest(i + 1, bitmask, req_skills, people);
        long long includePerson = withPerson(i, findSmallest(i + 1, withPersonSkill(people[i], bitmask), req_skills, people));
        
        if (getNumPeople(skipPerson) <= getNumPeople(includePerson)) {
            cout << "skipPerson: " << i << endl;
            return skipPerson;
        } else {
            cout << "includePerson: " << i << endl;
            return includePerson;
        }
    }
    
    int getBitmaskSize(vector<string>& req_skills) {
        return pow(2, req_skills.size());
    }
    
    int withPersonSkill(vector<string>& person, int bitmask) {
        for (auto skill: person) {
            bitmask = withSkill(skill, bitmask);
        }
        return bitmask;
    }
    
    long long withPerson(int i, long long peopleBitmask) {
        return (long long) pow(2l, i) | peopleBitmask;
    }
    
    int withSkill(string skill, int bitmask) {
        int skillIdx = skillsIndices[skill];
        return bitmask | (int) pow(2, skillIdx);
    }
    
    bool isSufficientTeam(int bitmask, vector<string>& req_skills) {
        return bitmask == (getBitmaskSize(req_skills) - 1);
    }
    
    int getNumPeople(long long peopleBitmask) {
        int numPeople = 0;
        int currBit = 0;
        while (peopleBitmask > 0) {
            if (peopleBitmask % 2 == 1) {
                numPeople++;
            }
            
            peopleBitmask /= 2;
            currBit++;
        }
        
        return numPeople;
    }
};

/*
const int UNINITIALIZED = -1;

class WASolution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {        
        memo = vector<vector<int>>();
        for (int i = 0; i < people.size(); ++i) {
            memo.push_back(vector<int>(getBitmaskSize(req_skills), UNINITIALIZED));
        }
        
        skillsIndices = unordered_map<string, int>();
        for (int i = 0; i < req_skills.size(); ++i) {
            string skill = req_skills[i];
            skillsIndices[skill] = i;
        }
        
        return findSmallest(0, 0, req_skills, people);
    }
    
private:
    unordered_map<string, int> skillsIndices;
    vector<vector<int>> memo;
    
    int findSmallest(int i, int bitmask, vector<string>& req_skills, vector<vector<string>>& people) {
        if (isSufficientTeam(bitmask, req_skills)) {
            return 0;
        }
        
        if (i == people.size()) {
            // throw invalid_argument("unable to form a sufficient team");
            return people.size() + 1;
        }
        
        return min(
            findSmallest(i + 1, bitmask, req_skills, people),
            1 + findSmallest(i + 1, withPerson(people[i], bitmask), req_skills, people),
        );
    }
    
    int getBitmaskSize(vector<string>& req_skills) {
        return pow(2, req_skills.size());
    }
    
    int withPerson(vector<string>& person, int bitmask) {
        for (auto skill: person) {
            bitmask = withSkill(skill, bitmask);
        }
        return bitmask;
    }
    
    int withSkill(string skill, int bitmask) {
        int skillIdx = skillsIndices[skill];
        return bitmask | pow(2, skillIdx);
    }
    
    bool isSufficientTeam(int bitmask, vector<string>& req_skills) {
        return bitmask == (getBitmaskSize(req_skills) - 1);
    }
};
*/

int main () {
    Solution soln;

    // vector<string> req_skills = {"java","nodejs","reactjs"};
    // vector<vector<string>> people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};
    
    vector<string> req_skills     = {"hkyodbbhr","p","biflxurxdvb","x","qq","yhiwcn"};
    vector<vector<string>> people = {{"yhiwcn"},{},{},{},{"biflxurxdvb","yhiwcn"},{"hkyodbbhr"},{"hkyodbbhr","p"},{"hkyodbbhr"},{},{"yhiwcn"},{"hkyodbbhr","qq"},{"qq"},{"hkyodbbhr"},{"yhiwcn"},{},{"biflxurxdvb"},{},{"hkyodbbhr"},{"hkyodbbhr","yhiwcn"},{"yhiwcn"},{"hkyodbbhr"},{"hkyodbbhr","p"},{},{},{"hkyodbbhr"},{"biflxurxdvb"},{"qq","yhiwcn"},{"hkyodbbhr","yhiwcn"},{"hkyodbbhr"},{},{},{"hkyodbbhr"},{},{"yhiwcn"},{},{"hkyodbbhr"},{"yhiwcn"},{"yhiwcn"},{},{},{"hkyodbbhr","yhiwcn"},{"yhiwcn"},{"yhiwcn"},{},{},{},{"yhiwcn"},{},{"yhiwcn"},{"x"},{"hkyodbbhr"},{},{},{"yhiwcn"},{},{"biflxurxdvb"},{},{},{"hkyodbbhr","biflxurxdvb","yhiwcn"},{}};
    
    cout << req_skills.size() << endl;    
    cout << people.size() << endl;    
    cout << soln.smallestSufficientTeam(req_skills, people).size() << endl;    

    return 0;
}