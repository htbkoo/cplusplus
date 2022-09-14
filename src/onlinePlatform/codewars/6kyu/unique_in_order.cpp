#include <string>
#include <vector>
// #include <unordered_set>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  //your code here
  std::vector<T> v;

  for (T item: iterable) {
    if (v.size() == 0 || v.back() != item) {
      v.push_back(item);
    }
  }

  return v;
}

// template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
//   //your code here
//   std::unordered_set<T> appeared;

//   std::vector<T> v;

//   for (T item: iterable) {
//     bool hasItem = appeared.count(item) > 0;
//     if (!hasItem) {
//       appeared.insert(item);
//       v.push_back(item);
//     }
//   }

//   return v;
// }

std::vector<char> uniqueInOrder(const std::string& iterable){
  //your code here
  return uniqueInOrder(std::vector<char>(iterable.begin(), iterable.end()));
}