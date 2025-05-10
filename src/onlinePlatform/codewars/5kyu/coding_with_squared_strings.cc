// https://www.codewars.com/kata/56fcc393c5957c666900024d/train/cpp

#include <string>
#include <vector>

#include <cmath>
#include <numeric> // For std::accumulate

std::string joinStringVector(const std::vector<std::string> &strings, const std::string &delimiter) {
    if (strings.empty()) {
        return "";
    }
    return std::accumulate(std::next(strings.begin()), strings.end(), strings[0],
                           [&](const std::string &a, const std::string &b) {
                               return a + delimiter + b;
                           });
}

std::string joinVectorCharVector(const std::vector<std::vector<char> > &strings, const std::string &delimiter) {
    if (strings.empty()) {
        return "";
    }

    std::vector<std::string> v;
    for (auto &chars: strings) {
        std::string char_string(chars.begin(), chars.end());
        v.push_back(char_string);
    }



    return joinStringVector(v, delimiter);
}


char FILLER_CHAR = (char) 11;
std::string FILLER(1, FILLER_CHAR);

class CodeSqStrings {
public:
    static std::string code(const std::string &strng) {
        long n = std::ceil(std::sqrt(strng.length()));

        std::vector temp(n, std::vector<char>(n, FILLER_CHAR));

        for (int i = 0; i < strng.length(); ++i) {
            int y = i / n;
            int x = i % n;
            temp[y][x] = strng[i];
        }


        return joinVectorCharVector(temp, "\n");
    }

    static std::string decode(const std::string &strng) {
        return "";
    }
};
