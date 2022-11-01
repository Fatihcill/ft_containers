#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  
  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector size is :" << myvector.size() << std::endl;
  std::cout << "myvector size is :" << myvector.capacity() << std::endl;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
