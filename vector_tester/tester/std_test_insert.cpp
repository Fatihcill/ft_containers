#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;
  
  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "size of myvector: " << myvector.size() << std::endl;
  std::cout << "capacity of myvector: " << myvector.capacity() << std::endl;
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
