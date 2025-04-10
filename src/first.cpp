#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

class Person {
  friend bool operator<(Person const &p, Person const &other) {
    return p.surname < other.surname;
  }

public:
  std::string firstname;
  std::string surname;
};

template <class Type> bool isLessThan(Type left, Type right) {
  return left < right;
}

template <class Type> bool isGreaterThan(Type left, Type right) {
  return left > right;
}

int main() {
  using namespace std;

  vector<double> vec = {1.1, 3, 2, 4, 8, 6, 7};
  vec.push_back(5);

  auto lessSort = [&vec]() {
    sort(vec.begin(), vec.begin() + vec.size() / 2, isLessThan<double>);
  };
  auto greaterSort = [&vec]() {
    sort(vec.begin() + vec.size() / 2, vec.end(), isGreaterThan<double>);
  };

  thread lessSorter(lessSort);
  thread greaterSorter(greaterSort);

  lessSorter.join();
  greaterSorter.join();

  for (double item : vec) {
    cout << item << " ";
  }

  return 0;
}
