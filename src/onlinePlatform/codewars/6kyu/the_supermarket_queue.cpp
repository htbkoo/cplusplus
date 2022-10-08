#include <string>
#include <vector>
#include <queue>

long queueTime(std::vector<int> customers,int n){
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  
  for (int i = 0; i < n; i++) {
    pq.push(0);
  }
  
  for (int customer: customers) {
    int newTime = pq.top() + customer;
    pq.pop();
    pq.push(newTime);
  }
  
  while (pq.size() > 1) {
    pq.pop();
  }
  
  return pq.top();
}