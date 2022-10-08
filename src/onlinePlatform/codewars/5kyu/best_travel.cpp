#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

class BestTravel
{
public:
    static inline std::unordered_map<std::string, int> memo;
  
    static int chooseBestSum(int t, int k, std::vector<int>& ls) {
      memo = std::unordered_map<std::string, int>();
      if (k > ls.size()) {
        return -1;
      }
      
      return dp(t, k, ls, 0);
    }
  
    static int dp(int t, int k, std::vector<int> ls, int i) {
      if (k == 0) {
        return 0;
      }
      if (i >= ls.size()) {
        return -1;
      }
      
      std::string key = std::to_string(t) + "_" + std::to_string(k) + "_" + std::to_string(i);
      
      if (memo.count(key) > 0) {
        return memo[key];
      }
      
      memo[key] = dp(t, k, ls, i + 1);      
      if (ls[i] <= t) {
        int remain = dp(t - ls[i], k - 1, ls, i + 1);
        if (remain != -1) {
          memo[key] = std::max(
            memo[key],
            ls[i] + remain
          );
        }
      }
      
      return memo[key];
    }
};

int main() {
    // std::vector<int> ts = {50, 55, 56, 57, 58};
    // std::cout << BestTravel::chooseBestSum(163, 3, ts) << std::endl;
    std::vector<int> ts = {91, 74, 73, 85, 73, 81, 87};
    std::cout << BestTravel::chooseBestSum(331, 5, ts) << std::endl;
}