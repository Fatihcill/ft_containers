#include <vector>
#include <map>
#include <stack>
#include <exception>
#include <utility>
#include <iomanip>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#define NEXTD std::cout << "<---------- ---------- ---------- ---------- ---------- ----------|---------- ---------- ---------- ---------- ---------- ----------|" << std::endl

void print_keys(char key1, char key2, int value1, int value2)
{
	if (value1 == 0)
		key1 = '-';	
	std::cout <<  std::setw(5) << key1 <<  std::setw(5) << value1 << "|" << std::setw(5) << key2 << std::setw(5) << value2 ;
}

void	print_map(ft::map<char, int> ft, std::map<char, int> std)
{
	ft::map<char, int>::iterator itft = ft.begin();
	std::map<char, int>::iterator itstd = std.begin();
	
	std::cout << std::setw(10) << "ft_map" << "|" << std::setw(10) << "std_map" << std::endl;
	while (itft != ft.end() || itstd != std.end())
	{
		print_keys(itft->first, itstd->first, itft->second, itstd->second);
		std::cout << std::endl;
		if(itft != ft.end())
			itft++;
		if(itstd != std.end())
			itstd++;
	}
	std::cout << "---------------------------------" << std::endl;
}


int main()
{
	{
		std::cout << "CONTRUCTOR TESTS...." << std::endl;
		ft::map<char,int> first_ft;
		std::map<char,int> first_std;

		first_ft['a']=10;
		first_ft['b']=30;
		first_ft['c']=50;

		first_std['a']=10;
		first_std['b']=30;
		first_std['c']=50;
		print_map(first_ft, first_std);
		
		ft::map<char,int> second_ft (first_ft.begin(), first_ft.end());
		std::map<char,int> second_std (first_std.begin(), first_std.end());
		print_map(second_ft, second_std);

		ft::map<char,int> third_ft (second_ft);
		std::map<char,int> third_std (second_std);
		print_map(third_ft, third_std);

		ft::map<char,int, std::greater<char> > forth_ft(first_ft.begin(), first_ft.end());
		std::map<char,int, std::greater<char> > forth_std(first_std.begin(), first_std.end());
		std::cout << forth_ft.begin()->first << "->" << (++forth_ft.begin())->first << std::endl;
		std::cout << forth_std.begin()->first << "->" << (++forth_std.begin())->first << std::endl;
		
	}
	{
		ft::map<char, int> first;
		ft::map<char, int> second;
		first['x'] = 8;
		first['y'] = 16;
		first['z'] = 32;
		second = first;				  // second now contains 3 ints
		first = ft::map<char, int>(); // and first is now empty
		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	NEXTD;
	{
		ft::map<char, int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "mymap.size() is " << mymap.size() << '\n';
	}
	NEXTD;
	{
		ft::map<char, std::string> mymap;
		mymap['a'] = "an element";
		mymap['b'] = "another element";
		mymap['c'] = mymap['b'];
		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';
		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
		std::cout << "mymap.size() is " << mymap.size() << '\n';
		// mymap.prettyPrint();
	}
	NEXTD;
	{
		ft::map<char, int> mymap;
		// first insert function version (single parameter):
		mymap.insert(ft::pair<char, int>('a', 100));
		mymap.insert(ft::pair<char, int>('z', 200));
		ft::pair<ft::map<char, int>::iterator, bool> ret;
		ret = mymap.insert(ft::pair<char, int>('z', 500));
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		else
		{
			std::cout << "element 'z' created";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		// second insert function version (with hint position):
		ft::map<char, int>::iterator it = mymap.begin();
		mymap.insert(it, ft::pair<char, int>('b', 300)); // max efficiency inserting
		mymap.insert(it, ft::pair<char, int>('c', 400));
		// third insert function version (range insertion):
		ft::map<char, int> anothermap;
		anothermap.insert(mymap.begin(), mymap.find('c'));
		std::cout << mymap.size() << std::endl;
		// showing contents:
		std::cout << "mymap contains:\n";
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "anothermap contains:\n";
		for (it = anothermap.begin(); it != anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		// mymap.prettyPrint();
	}
	NEXTD;
	{
		ft::map<char, int> mymap;
		ft::map<char, int>::iterator it;
		mymap['a'] = 50;
		mymap['b'] = 100;
		mymap['c'] = 150;
		mymap['d'] = 200;
		// mymap.print();
		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase(it);
		// mymap.print();
		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
		// std::cout << "d => " << mymap.find('b')->second << '\n';
	}
	NEXTD;
	{
		ft::map<int, int> mymap;
		ft::map<int, int>::iterator it;
		// insert some values:
		mymap[1] = 10;
		mymap[7] = 20;
		mymap[8] = 30;
		mymap[10] = 40;
		mymap[77] = 50;
		mymap[6] = 60;
		// mymap.print();
		NEXTD;
		it = mymap.find(6);
		mymap.erase(it);	// erasing by iterator
		mymap.erase(10);	// erasing by key
		// mymap.print();
		it = mymap.find(8);
		mymap.erase(it, mymap.end()); // erasing by range
		// show content:
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	NEXTD;
	{
		ft::map<char, int> foo, bar;
		foo['x'] = 100;
		foo['y'] = 200;
		bar['a'] = 11;
		bar['b'] = 22;
		bar['c'] = 33;
		foo.swap(bar);
		std::cout << "foo contains:\n";
		for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "bar contains:\n";
		for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	NEXTD;
	{
		ft::map<char, int> mymap;
		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;
		std::cout << "mymap contains:\n";
		ft::pair<char, int> highest = *mymap.rbegin(); // last element
		ft::map<char, int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mymap.value_comp()(*it++, highest));
	}
	NEXTD;
	{
		ft::map<char, int> mymap;
		ft::map<char, int>::iterator itlow, itup;
		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['f'] = 100;
		itlow = mymap.lower_bound('f'); // itlow points to b
		itup = mymap.upper_bound('d');	// itup points to e (not d!)

		std::cout << itlow->first << std::endl;
		std::cout << itup->first << std::endl;
		mymap.erase(itlow, itup); // erases [itlow,itup)
		// print content:
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	NEXTD;
	{
		ft::map<char, int> mymap;
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
		ret = mymap.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	NEXTD;
	{
		int psize;
		ft::map<char, int> mymap;
		ft::pair<const char, int> *p;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(ft::map<char, int>::value_type) * 5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p, 5);
	}
	NEXTD;
	{
		std::map<char, int> foo, bar;
		foo['a'] = 100;
		foo['b'] = 200;
		bar['a'] = 10;
		bar['z'] = 1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo == bar)
			std::cout << "foo and bar are equal\n";
		if (foo != bar)
			std::cout << "foo and bar are not equal\n";
		if (foo < bar)
			std::cout << "foo is less than bar\n";
		if (foo > bar)
			std::cout << "foo is greater than bar\n";
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar\n";
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar\n";
	}
	NEXTD;
	{
		ft::map<int, int> mp;
		for (int i = 0; i < 5; i++)
		{
			mp.insert(ft::make_pair(i, i * 2));
		}
		// mp.print();
		ft::map<int, int>::iterator it = mp.begin();
		mp.insert(ft::make_pair(-1, 2));
		std::cout << it->first << " " << it->second <<  std::endl;
		// mp.print();
		for (; it != mp.end(); it++)
		{
			std::cout << it->first << " " << it->second << std::endl;
		}
	}
}
