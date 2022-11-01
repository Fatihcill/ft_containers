#include <iostream>
#include <vector>

int main()
{
  std::vector<int> first;
  std::vector<int> second;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it = first.begin() + 1; // the second element of first

  second.assign ( it, first.end() - 1 ); // the 5 central values of first

  std::cout << "Size of first: " << int (first.size()) << "; capacity of first: " << int (first.capacity()) << '\n';
  std::cout << "first contains:";
  for (unsigned i=0; i<first.size(); i++)
    std::cout << ' ' << first.at(i);
  std::cout << '\n';
  
  std::cout << "Size of second: " << int (second.size()) << "; capacity of second: " << int (second.capacity()) << '\n';
  std::cout << "second contains:";
  for (unsigned i=0; i<second.size(); i++)
    std::cout << ' ' << second.at(i);
  std::cout << '\n';
  return 0;
}
