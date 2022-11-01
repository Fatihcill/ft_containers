#include <iostream>
#include "../../include/vector.hpp"

int main ()
{
  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (second);                       // a copy of third

  std::cout << "Size of first: " << int (first.size()) << "; capacity of first: " << int (first.capacity()) << '\n';
  std::cout << "The contents of first are:";
  for (size_t i = 0; i < first.size(); i++) std::cout << " " << first[i];
    std::cout << std::endl;

  std::cout << "Size of second: " << int (second.size()) << "; capacity of second: " << int (second.capacity()) << '\n';
  std::cout << "The contents of second are:";
  for (size_t i = 0; i < second.size(); i++) std::cout << " " << second[i];
    std::cout << std::endl;

  std::cout << "Size of third: " << int (third.size()) << "; capacity of third: " << int (third.capacity()) << '\n';
  std::cout << "The contents of third are:";
  for (size_t i = 0; i < third.size(); i++) std::cout << " " << third[i];
    std::cout << std::endl;

  std::cout << "Size of fourth: " << int (fourth.size()) << "; capacity of fourth: " << int (fourth.capacity()) << '\n';
  std::cout << "The contents of fourth are:";
  for (size_t i = 0; i < fourth.size(); i++) std::cout << " " << fourth[i];
    std::cout << std::endl;

  return 0;
}
