// https://www.codewars.com/kata/5263a84ffcadb968b6000513/train/cpp

#include <string>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

vector< vector<long long> > getMinorMatrix(vector< vector<long long> > &m, int withoutY, int withoutX) {
    vector< vector<long long> > minor;

    int HEIGHT = m.size();
    if (HEIGHT <= 1) {
        // TODO: confirm this
        return minor;
    }

    int WIDTH = m[0].size();
    // TODO: validate input, e.g. withoutY and withoutX are within HEIGHT and WIDTH and are non-negative

    for (int y = 0; y < HEIGHT; ++y) {
        if (y == withoutY) {
            continue;
        }
        vector<long long> row;
        for (int x = 0; x < WIDTH; ++x) {
            if (x == withoutX) {
                continue;
            }
            row.push_back(m[y][x]);
        }
        minor.push_back(row);
    }

    return minor;
}

long long determinant(vector< vector<long long> > m) {
    // TODO: Return the determinant of the square matrix passed in

    // TODO:
    //  1. validate m is a square matrix
    //  2. handle when m.size() == 0
    int n = m.size();
    if (n == 1) {
        return m[0][0];
    }
    if (n == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    int d = 0;
    int sign = 1;
    int y = 0;
    for (int x = 0; x < n; ++x) {
        auto minor = getMinorMatrix(m, y, x);
        d += sign * m[y][x] * determinant(minor);
        sign *= -1;
    }

    return d;
}