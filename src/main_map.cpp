


	// {
	// 	ft::map<char, int> first;
	// 	ft::map<char, int> second;
	// 	first['x'] = 8;
	// 	first['y'] = 16;
	// 	first['z'] = 32;
	// 	second = first;				  // second now contains 3 ints
	// 	first = ft::map<char, int>(); // and first is now empty
	// 	std::cout << "Size of first: " << first.size() << '\n';
	// 	std::cout << "Size of second: " << second.size() << '\n';
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> mymap;
	// 	mymap['b'] = 100;
	// 	mymap['a'] = 200;
	// 	mymap['c'] = 300;
	// 	// show content:
	// 	for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	std::cout << "mymap.size() is " << mymap.size() << '\n';
	// }
	// NEXTD;
	// {
	// 	ft::map<char, std::string> mymap;
	// 	mymap['a'] = "an element";
	// 	mymap['b'] = "another element";
	// 	mymap['c'] = mymap['b'];
	// 	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	// 	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	// 	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	// 	std::cout << "mymap['d'] is " << mymap['d'] << '\n';
	// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	// 	std::cout << "mymap.size() is " << mymap.size() << '\n';
	// 	// mymap.prettyPrint();
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> mymap;
	// 	// first insert function version (single parameter):
	// 	mymap.insert(ft::pair<char, int>('a', 100));
	// 	mymap.insert(ft::pair<char, int>('z', 200));
	// 	ft::pair<ft::map<char, int>::iterator, bool> ret;
	// 	ret = mymap.insert(ft::pair<char, int>('z', 500));
	// 	if (ret.second == false)
	// 	{
	// 		std::cout << "element 'z' already existed";
	// 		std::cout << " with a value of " << ret.first->second << '\n';
	// 	}
	// 	else
	// 	{
	// 		std::cout << "element 'z' created";
	// 		std::cout << " with a value of " << ret.first->second << '\n';
	// 	}
	// 	// second insert function version (with hint position):
	// 	ft::map<char, int>::iterator it = mymap.begin();
	// 	mymap.insert(it, ft::pair<char, int>('b', 300)); // max efficiency inserting
	// 	mymap.insert(it, ft::pair<char, int>('c', 400));
	// 	// third insert function version (range insertion):
	// 	ft::map<char, int> anothermap;
	// 	anothermap.insert(mymap.begin(), mymap.find('c'));
	// 	std::cout << mymap.size() << std::endl;
	// 	// showing contents:
	// 	std::cout << "mymap contains:\n";
	// 	for (it = mymap.begin(); it != mymap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	std::cout << "anothermap contains:\n";
	// 	for (it = anothermap.begin(); it != anothermap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	// mymap.prettyPrint();
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> mymap;
	// 	ft::map<char, int>::iterator it;
	// 	mymap['a'] = 50;
	// 	mymap['b'] = 100;
	// 	mymap['c'] = 150;
	// 	mymap['d'] = 200;
	// 	// mymap.print();
	// 	it = mymap.find('b');
	// 	if (it != mymap.end())
	// 		mymap.erase(it);
	// 	// mymap.print();
	// 	// print content:
	// 	std::cout << "elements in mymap:" << '\n';
	// 	std::cout << "a => " << mymap.find('a')->second << '\n';
	// 	std::cout << "c => " << mymap.find('c')->second << '\n';
	// 	std::cout << "d => " << mymap.find('d')->second << '\n';
	// 	// std::cout << "d => " << mymap.find('b')->second << '\n';
	// }
	// NEXTD;
	// {
	// 	ft::map<int, int> mymap;
	// 	ft::map<int, int>::iterator it;
	// 	// insert some values:
	// 	mymap[1] = 10;
	// 	mymap[7] = 20;
	// 	mymap[8] = 30;
	// 	mymap[10] = 40;
	// 	mymap[77] = 50;
	// 	mymap[6] = 60;
	// 	// mymap.print();
	// 	NEXTD;
	// 	it = mymap.find(6);
	// 	mymap.erase(it);	// erasing by iterator
	// 	mymap.erase(10);	// erasing by key
	// 	// mymap.print();
	// 	it = mymap.find(8);
	// 	mymap.erase(it, mymap.end()); // erasing by range
	// 	// show content:
	// 	for (it = mymap.begin(); it != mymap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> foo, bar;
	// 	foo['x'] = 100;
	// 	foo['y'] = 200;
	// 	bar['a'] = 11;
	// 	bar['b'] = 22;
	// 	bar['c'] = 33;
	// 	foo.swap(bar);
	// 	std::cout << "foo contains:\n";
	// 	for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	std::cout << "bar contains:\n";
	// 	for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> mymap;
	// 	mymap['x'] = 1001;
	// 	mymap['y'] = 2002;
	// 	mymap['z'] = 3003;
	// 	std::cout << "mymap contains:\n";
	// 	ft::pair<char, int> highest = *mymap.rbegin(); // last element
	// 	ft::map<char, int>::iterator it = mymap.begin();
	// 	do
	// 	{
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	} while (mymap.value_comp()(*it++, highest));
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> mymap;
	// 	ft::map<char, int>::iterator itlow, itup;
	// 	mymap['a'] = 20;
	// 	mymap['b'] = 40;
	// 	mymap['c'] = 60;
	// 	mymap['d'] = 80;
	// 	mymap['f'] = 100;
	// 	itlow = mymap.lower_bound('f'); // itlow points to b
	// 	itup = mymap.upper_bound('d');	// itup points to e (not d!)

	// 	std::cout << itlow->first << std::endl;
	// 	std::cout << itup->first << std::endl;
	// 	mymap.erase(itlow, itup); // erases [itlow,itup)
	// 	// print content:
	// 	for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	// 		std::cout << it->first << " => " << it->second << '\n';
	// }
	// NEXTD;
	// {
	// 	ft::map<char, int> mymap;
	// 	mymap['a'] = 10;
	// 	mymap['b'] = 20;
	// 	mymap['c'] = 30;
	// 	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
	// 	ret = mymap.equal_range('b');
	// 	std::cout << "lower bound points to: ";
	// 	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	// 	std::cout << "upper bound points to: ";
	// 	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	// }
	// NEXTD;
	// {
	// 	int psize;
	// 	ft::map<char, int> mymap;
	// 	ft::pair<const char, int> *p;

	// 	// allocate an array of 5 elements using mymap's allocator:
	// 	p = mymap.get_allocator().allocate(5);

	// 	// assign some values to array
	// 	psize = sizeof(ft::map<char, int>::value_type) * 5;

	// 	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	// 	mymap.get_allocator().deallocate(p, 5);
	// }
	// NEXTD;
	// {
	// 	std::map<char, int> foo, bar;
	// 	foo['a'] = 100;
	// 	foo['b'] = 200;
	// 	bar['a'] = 10;
	// 	bar['z'] = 1000;

	// 	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	// 	if (foo == bar)
	// 		std::cout << "foo and bar are equal\n";
	// 	if (foo != bar)
	// 		std::cout << "foo and bar are not equal\n";
	// 	if (foo < bar)
	// 		std::cout << "foo is less than bar\n";
	// 	if (foo > bar)
	// 		std::cout << "foo is greater than bar\n";
	// 	if (foo <= bar)
	// 		std::cout << "foo is less than or equal to bar\n";
	// 	if (foo >= bar)
	// 		std::cout << "foo is greater than or equal to bar\n";
	// }
	// NEXTD;
	// {
	// 	ft::map<int, int> mp;
	// 	for (int i = 0; i < 5; i++)
	// 	{
	// 		mp.insert(ft::make_pair(i, i * 2));
	// 	}
	// 	// mp.print();
	// 	ft::map<int, int>::iterator it = mp.begin();
	// 	mp.insert(ft::make_pair(-1, 2));
	// 	std::cout << it->first << " " << it->second <<  std::endl;
	// 	// mp.print();
	// 	for (; it != mp.end(); it++)
	// 	{
	// 		std::cout << it->first << " " << it->second << std::endl;
	// 	}
	// }
