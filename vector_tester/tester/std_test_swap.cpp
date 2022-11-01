#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  std::cout << "Size of foo: " << int (foo.size()) << "; capacity of foo: " << int (foo.capacity()) << "\n";
  std::cout << "Size of bar: " << int (bar.size()) << "; capacity of bar: " << int (bar.capacity()) << "\n\n";

  foo.swap(bar);

  std::cout << "Size of foo: " << int (foo.size()) << "; capacity of foo: " << int (foo.capacity()) << '\n';
  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "Size of bar: " << int (bar.size()) << "; capacity of bar: " << int (bar.capacity()) << '\n';
  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}
