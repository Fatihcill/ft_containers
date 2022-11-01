#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  // set some initial content:
  for (size_t i=1;i<10;i++) myvector.push_back(i);

  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;
  myvector.resize(5);
  
  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;
  myvector.resize(8,100);

  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;
  myvector.resize(12);

  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;
  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
