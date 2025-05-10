// https://www.codewars.com/kata/56fcc393c5957c666900024d/train/cpp

#include <string>
#include <vector>

#include <cmath>
#include <numeric> // For std::accumulate

char FILLER_CHAR = (char) 11;
std::string FILLER(1, FILLER_CHAR);
auto LINE_SEPARATOR = "\n";

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

void rotateClockwise(std::vector<std::vector<char> > &v, int layer) {
    // TODO: assume v is square-shaped
    int n = v.size();
    int top = layer;
    int bottom = n - 1 - layer;
    int left = layer;
    int right = n - 1 - layer;

    if (left >= right) {
        return;
    }

    int d = 0;
    while (left + d < right) {
        auto t = v[top][left + d];
        v[top][left + d] = v[bottom - d][left];
        v[bottom - d][left] = v[bottom][right - d];
        v[bottom][right - d] = v[top + d][right];
        v[top + d][right] = t;

        d++;
    }
    rotateClockwise(v, layer + 1);
}

void rotateCounterClockwise(std::vector<std::vector<char> > &v, int layer) {
    // TODO: assume v is square-shaped
    int n = v.size();
    int top = layer;
    int bottom = n - 1 - layer;
    int left = layer;
    int right = n - 1 - layer;

    if (left >= right) {
        return;
    }

    int d = 0;
    while (left + d < right) {
        auto t = v[top][left + d];
        v[top][left + d] = v[top + d][right];
        v[top + d][right] = v[bottom][right - d];
        v[bottom][right - d] = v[bottom - d][left];
        v[bottom - d][left] = t;

        d++;
    }
    rotateClockwise(v, layer + 1);
}

std::vector<std::vector<char> > toCharsVectors(const std::string &s) {
    int n = (int) std::sqrt(s.length());

    std::vector<std::vector<char> > v;
    for (auto i = 0; i < s.length(); i += n) {
        auto ss = s.substr(i, n);
        std::vector<char> chars(ss.begin(), ss.end());
        v.push_back(chars);
    }

    return v;
}

class CodeSqStrings {
public:
    static std::string code(const std::string &strng) {
        long n = std::ceil(std::sqrt(strng.length()));

        std::vector temp(n, std::vector<char>(n, FILLER_CHAR));

        // fill strng into temp
        for (auto i = 0; i < strng.length(); ++i) {
            int y = i / n;
            int x = i % n;
            temp[y][x] = strng[i];
        }

        // rotate 90 degrees clockwise
        rotateClockwise(temp, 0);

        return joinVectorCharVector(temp, LINE_SEPARATOR);
    }

    static std::string decode(const std::string &strng) {
        auto temp = toCharsVectors(strng);

        // rotate 90 degrees counter-clockwise
        rotateCounterClockwise(temp, 0);

        auto s = joinVectorCharVector(temp, "");

        std::string::size_type loc = s.find(FILLER, 0);
        if (loc != std::string::npos) {
            return s;
        } else {
            return s.substr(0, loc);
        }
    }
};
