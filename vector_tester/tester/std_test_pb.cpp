#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;

  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;
  
  std::cout << "The elements of myvector add up to " << sum << '\n';

  return 0;
}
