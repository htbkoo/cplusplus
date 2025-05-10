// https://www.codewars.com/kata/5263a84ffcadb968b6000513/train/cpp

#include <string>
#include <vector>

std::vector<std::vector<int>>
matrix_multiplication(const std::vector<std::vector<int>> &a,
                      const std::vector<std::vector<int>> &b, size_t n) {
    // TODO: Return the result of A × B in the form of an n × n matrix
    // NOTE: Please allocate and return matrix C
    std::vector<std::vector<int>> c(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}