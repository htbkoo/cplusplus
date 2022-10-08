#include <string>
#include <vector>
#include <queue>
#include <iostream>

// Returns number of complete beeramid levels
int beeramid(int bonus, double price)
{
  long numCan = (int) (bonus / price);
  
  long i = 1;
  for (;numCan >= i * i;i++) {
    numCan -= i * i;
  }
  
  return i - 1;
}

int main() {
  std::cout << beeramid(9, 2) << std::endl;
}