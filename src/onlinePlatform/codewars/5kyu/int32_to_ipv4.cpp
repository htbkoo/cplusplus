#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

std::string uint32_to_ip(uint32_t ip)
{
  // your code here
  int BASE = (int) std::pow(2, 8);
  
  std::string answer = std::to_string(ip % BASE);
  ip /= BASE;
  for (int i = 1; i < 4; i++) {
    answer = std::to_string(ip % BASE) + "." + answer;
    ip /= BASE;
  }
  
  return answer;
}
