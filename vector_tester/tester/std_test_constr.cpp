#include <iostream>
#include <vector>

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (second);                       // a copy of third
  
  std::cout << "Size of first: " << int (first.size()) << "; capacity of first: " << int (first.capacity()) << '\n';
  std::cout << "The contents of first are:";
  for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "Size of second: " << int (second.size()) << "; capacity of second: " << int (second.capacity()) << '\n';
  std::cout << "The contents of second are:";
  for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "Size of third: " << int (third.size()) << "; capacity of third: " << int (third.capacity()) << '\n';
  std::cout << "The contents of third are:";
  for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "Size of fourth: " << int (fourth.size()) << "; capacity of fourth: " << int (fourth.capacity()) << '\n';
  std::cout << "The contents of fourth are:";
  for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
