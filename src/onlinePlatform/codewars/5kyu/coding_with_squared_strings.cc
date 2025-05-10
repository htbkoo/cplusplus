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


    return std::accumulate(std::next(strings.begin()), strings.end(), strings[0],
                           [&](const std::string &a, const std::string &b) {
                               return a + delimiter + b;
                           });
}

char FILLER_CHAR = (char) 11;
std::string FILLER(1, FILLER_CHAR);

class CodeSqStrings {
public:
    static std::string code(const std::string &strng) {
        long n = std::ceil(std::sqrt(strng.length()));

        std::vector temp(n, std::vector(n, FILLER_CHAR));

        return joinStringVector(temp, "\n");
    }

    static std::string decode(const std::string &strng) {
        return "";
    }
};
