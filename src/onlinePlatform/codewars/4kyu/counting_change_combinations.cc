// https://www.codewars.com/kata/5263a84ffcadb968b6000513/train/cpp

#include <vector>
#include <unordered_set>

using namespace std;

unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
    // your code here

    // TODO: is there duplicates in coins?

    std::unordered_set<unsigned int> uniqueCoins(begin(coins), end(coins));

    std::vector<long long> counts(money + 1);
    counts[0] = 1;
    for (auto coin: uniqueCoins) {
        std::vector<long long> prev(begin(counts), end(counts));
        counts = std::vector<long long>(money + 1);

        for (auto i = money; i >= coin; --i) {
            counts[i] += prev[i - coin];
        }
    }

    return counts[money];
}
