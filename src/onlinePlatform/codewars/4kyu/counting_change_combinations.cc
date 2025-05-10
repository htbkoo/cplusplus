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
        for (auto i = coin; i <= money; ++i) {
            counts[i] += counts[i - coin];
        }
    }

    return counts[money];
}
