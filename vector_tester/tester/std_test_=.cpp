#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int (foo.size()) << "; capacity of foo: " << int (foo.capacity()) << '\n';
  std::cout << "The contents of foo are:";
  for (size_t i = 0; i < foo.size(); i++) std::cout << " " << foo[i];
    std::cout << std::endl;

  std::cout << "Size of bar: " << int (bar.size()) << "; capacity of bar: " << int (bar.capacity()) << '\n';
  std::cout << "The contents of bar are:";
  for (size_t i = 0; i < bar.size(); i++) std::cout << " " << bar[i];
    std::cout << std::endl;

  return 0;
}
