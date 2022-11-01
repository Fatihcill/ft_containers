/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:35:47 by mbari             #+#    #+#             */
/*   Updated: 2022/11/01 11:45:01 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <stack>
#include <iomanip>

void	print_vector(ft::vector<int> ft, std::vector<int> std)
{
	ft::vector<int>::iterator itft = ft.begin();
	std::vector<int>::iterator itstd = std.begin();
	
	std::cout << std::setw(10) << "ft_vector" << "|" << std::setw(10) << "std_vector" << std::endl;
	while (itft != ft.end() || itstd != std.end())
	{
		std::cout <<  std::setw(10) << *itft << "|" << std::setw(10) << *itstd << std::endl;

		if(itft != ft.end())
			++itft;
		if(itstd != std.end())
			++itstd;
	}
	std::cout << std::endl;
}

void	rprint_vector(ft::vector<int> ft, std::vector<int> std)
{
	ft::vector<int>::reverse_iterator itft = ft.rbegin();
	std::vector<int>::reverse_iterator itstd = std.rbegin();
	
	std::cout << std::setw(10) << "ft_vector" << "|" << std::setw(10) << "std_vector" << std::endl;
	while (itft != ft.rend() || itstd != std.rend())
	{
		std::cout <<  std::setw(10) << *itft << "|" << std::setw(10) << *itstd << std::endl;

		if(itft != ft.rend())
			itft++;
		if(itstd != std.rend())
			itstd++;
	}
	std::cout << std::endl;
}

int main(){
	{
		std::cout << "================== Vector EXAMPLES ==================" << std::endl;
	{
		std::cout << "------------- Constructor  -------------" << std::endl;
		ft::vector<int> first_ft;
		std::vector<int> first_std;
		print_vector(first_ft, first_std);
		
		ft::vector<int> second_ft (2,50);
		std::vector<int> second_std (2,50);
		print_vector(second_ft, second_std);
		
		ft::vector<int> third_ft (second_ft.begin(),second_ft.end());
		std::vector<int> third_std (second_std.begin(),second_std.end());
		print_vector(third_ft, third_std);
		
		ft::vector<int> fourth_ft (third_ft);
		std::vector<int> fourth_std (third_std);
		print_vector(fourth_ft, fourth_std);
	
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth_ft (myints, myints + sizeof(myints) / sizeof(int));
		std::vector<int> fifth_std (myints, myints + sizeof(myints) / sizeof(int));
		print_vector(fifth_ft, fifth_std);
		std::cout << "---------------------------------" << std::endl;
	}
	{
		std::cout << "------------- Assign Operators -------------" << std::endl;
		ft::vector<int> foo1 (3,0);
		ft::vector<int> bar1 (5,0);
		std::vector<int> foo2 (3,0);
		std::vector<int> bar2 (5,0);
		
		std::cout << std::setw(10) << "ft_vector" << "|" << std::setw(10) << "std_vector" << std::endl;
		std::cout << std::setw(10) << int(bar1.size()) << "|" << std::setw(10) << int(bar2.size()) << std::endl;
		bar1 = foo1;
		bar2 = foo2;
		std::cout << std::setw(10) << int(bar1.size()) << "|" << std::setw(10) << int(bar2.size()) << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
	{

		std::cout << "------------- iterators -------------" << std::endl;
		ft::vector<int> vector_ft;
		for (int i=1; i<=3; i++) vector_ft.push_back(i);
		std::vector<int> vector_std;
		for (int i=1; i<=3; i++) vector_std.push_back(i);
		print_vector(vector_ft, vector_std);
		rprint_vector(vector_ft, vector_std);
		std::cout << "---------------------------------" << std::endl;
	}	
	{
		// NOTE - Return size
		std::cout << "------------- size -------------" << std::endl;
		std::cout << std::setw(10) << "ft_vector" << "|" << std::setw(10) << "std_vector" << std::endl;

		ft::vector<int> vector_ft;
		std::vector<int> vector_std;
		std::cout << std::setw(10) << int(vector_ft.size()) << "|" << std::setw(10) << int(vector_std.size()) << std::endl;

		for (int i=0; i<10; i++) vector_ft.push_back(i);
		for (int i=0; i<10; i++) vector_std.push_back(i);
		std::cout << std::setw(10) << int(vector_ft.size()) << "|" << std::setw(10) << int(vector_std.size()) << std::endl;

		vector_ft.insert(vector_ft.end(),10,100);
		vector_std.insert(vector_std.end(),10,100);
		std::cout << std::setw(10) << int(vector_ft.size()) << "|" << std::setw(10) << int(vector_std.size()) << std::endl;

		vector_ft.pop_back();
		vector_std.pop_back();
		std::cout << std::setw(10) << int(vector_ft.size()) << "|" << std::setw(10) << int(vector_std.size()) << std::endl;
		vector_ft.clear();
		vector_std.clear();
		std::cout << std::setw(10) << int(vector_ft.size()) << "|" << std::setw(10) << int(vector_std.size()) << std::endl;

		std::cout << "---------------------------------" << std::endl;
	}
	{
		// NOTE - Return maximum size
		std::cout << "------------- maxsize -------------" << std::endl;
		std::cout << std::setw(35) << "ft_vector" << "|" << std::setw(35) << "std_vector" << std::endl;

		ft::vector<int> vector_ft;
		std::vector<int> vector_std;

		for (int i=0; i<100; i++) vector_ft.push_back(i);
		for (int i=0; i<100; i++) vector_std.push_back(i);
		std::cout << std::setw(10) << "size: " <<  std::setw(25) << int(vector_ft.size()) << "|"
			<< std::setw(10) << "size: " << std::setw(25) << int(vector_std.size()) << std::endl;

		std::cout << std::setw(10) << "capacity: " <<  std::setw(25) << vector_ft.capacity() << "|"
			<< std::setw(10) << "capacity: " << std::setw(25) << vector_std.capacity() << std::endl;
		
		std::cout << std::setw(10) << "max_size: " <<  std::setw(25) << vector_ft.max_size() << "|"
			<< std::setw(10) << "max_size: " << std::setw(25) << vector_std.max_size() << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
	{
		std::cout << "------------- resize -------------" << std::endl;
		ft::vector<int> vector_ft;
		std::vector<int> vector_std;
		for (int i=1;i<5;i++) vector_ft.push_back(i);
		for (int i=1;i<5;i++) vector_std.push_back(i);

		vector_ft.resize(2);
		vector_std.resize(2);
		print_vector(vector_ft, vector_std);
		vector_ft.resize(6,100);
		vector_std.resize(6,100);
		print_vector(vector_ft, vector_std);
		std::cout << "---------------------------------" << std::endl;
	}

	{

		std::cout << "------------- empty -------------" << std::endl;
		ft::vector<int> myvector1;
		int sum1(0);
		for (int i=1;i<=3;i++) myvector1.push_back(i);
		while (!myvector1.empty())
		{
			sum1 += myvector1.back();
			myvector1.pop_back();
		}
		std::cout << "total: " << sum1 << '\n';
		std::cout << "---------------------------------" << std::endl;
	}
	{

		// NOTE - Request a change in capacity
		std::cout << "------------- change capacity -------------" << std::endl;
		ft::vector<int>::size_type sz1;
		ft::vector<int> foo1;
		sz1 = foo1.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i)
		{
			foo1.push_back(i);
			if (sz1!=foo1.capacity())
			{
				sz1 = foo1.capacity();
				std::cout << "capacity changed: " << sz1 << '\n';
			}
		}
		ft::vector<int> bar1;
		sz1 = bar1.capacity();
		bar1.reserve(100);
		for (int i=0; i<100; ++i)
		{
			bar1.push_back(i);
			if (sz1!=bar1.capacity())
			{
				sz1 = bar1.capacity();
				std::cout << "capacity changed: " << sz1 << '\n';
			}
		}
		std::cout << "---------------------------------" << std::endl;
	}
	{
		// NOTE - Access first element
		std::cout << "------------- Access -------------" << std::endl;
		std::cout << std::setw(10) << "ft_vector" << "|" << std::setw(10) << "std_vector" << std::endl;
		ft::vector<int> vector_ft;
		std::vector<int> vector_std;
		vector_ft.push_back(10);
		vector_ft.push_back(3);
		vector_std.push_back(10);
		vector_std.push_back(3);

		vector_ft.front() -= vector_ft.back();
		vector_std.front() -= vector_std.back();
		std::cout << std::setw(10) << vector_ft.front() << "|" << std::setw(10) << vector_std.front() << std::endl;
		std::cout << std::setw(10) << vector_ft.at(1) << "|" << std::setw(10) << vector_std.at(1) << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
	{
		// NOTE - Assign vector content
		std::cout << "------------- Library -------------" << std::endl;
		std::cout << std::setw(10) << "ft_vector" << "|" << std::setw(10) << "std_vector" << std::endl;
		ft::vector<int> first_ft;
		ft::vector<int> second_ft;
		ft::vector<int> third_ft;
		std::vector<int> first_std;
		std::vector<int> second_std;
		std::vector<int> third_std;
		
		first_ft.assign (7,100);
		first_std.assign (7,100);
		std::cout << std::setw(10) << first_ft.size() << "|" << std::setw(10) << first_std.size() << std::endl;

		ft::vector<int>::iterator it_ft = first_ft.begin() + 1;
		std::vector<int>::iterator it_std = first_std.begin() + 1;
		second_ft.assign (it_ft, first_ft.end()-1);
		second_std.assign (it_std, first_std.end()-1);
		std::cout << std::setw(10) << second_ft.size() << "|" << std::setw(10) << second_std.size() << std::endl;

		int myints[] = {1776,7,4};
		third_ft.assign (myints, myints+3);
		third_std.assign (myints, myints+3);
		std::cout << std::setw(10) << third_ft.size() << "|" << std::setw(10) << third_std.size() << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}

	{

		// NOTE - Insert elements
		std::cout << "------------- Library -------------" << std::endl;
		ft::vector<int> myvector1(3, 100);
		myvector1.insert(it1, 2, 300);
		it1 = myvector1.begin();
		ft::vector<int> anothervector1 (2,400);
		std::cout << "myvector size : " << myvector1.size() << std::endl;
		std::cout << "myvector capacity : " << myvector1.capacity() << std::endl;
		myvector1.insert (it1+2,anothervector1.begin(),anothervector1.end());
		std::cout << "myvector size : " << myvector1.size() << std::endl;
		std::cout << "myvector capacity : " << myvector1.capacity() << std::endl;
		int myarray1 [] = { 501,502,503 };
		myvector1.insert (myvector1.begin(), myarray1, myarray1+3);
		std::cout << "myvector contains:";
		for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
			std::cout << ' ' << *it1;
		std::cout << '\n';
	}
	{
		ft::vector<int> vec1;
		vec1.push_back(10);
		vec1.push_back(20);
		vec1.push_back(30);
		vec1.push_back(40);
		ft::vector<int>::iterator it1 = vec1.insert(vec1.begin(), 3);
		vec1.insert(it1, 2);
		int i1 = 2;
		it1 = vec1.insert(vec1.begin() + i1, 7);
		std::cout << "The vector elements are: ";
		for (ft::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
			std::cout << *it1 << " ";
	}
	// {
	// 	// NOTE - Erase elements
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> myvector1;
	// 	for (int i=1; i<=10; i++) myvector1.push_back(i);
	// 	std::cout << myvector1.size() << std::endl;
	// 	std::cout << myvector1.capacity() << std::endl;
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector1.size(); ++i)
	// 		std::cout << ' ' << myvector1[i];
	// 	std::cout << std::endl;
	// 	myvector1.erase (myvector1.begin() - 1);
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector1.size(); ++i)
	// 		std::cout << ' ' << myvector1[i];
	// 	std::cout << std::endl;
	// 	myvector1.erase (myvector1.begin(),myvector1.begin()+3);
	// 	std::cout << myvector1.size() << std::endl;
	// 	std::cout << myvector1.capacity() << std::endl;
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector1.size(); ++i)
	// 		std::cout << ' ' << myvector1[i];
	// 	std::cout << std::endl;
	// }
	// {
	// 	// NOTE - Erase elements
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	std::vector<int> myvector1;
	// 	for (int i=1; i<=10; i++) myvector1.push_back(i);
	// 	std::cout << myvector1.size() << std::endl;
	// 	std::cout << myvector1.capacity() << std::endl;
	// 	myvector1.erase (myvector1.begin() - 1);
	// 	myvector1.erase (myvector1.begin(),myvector1.begin()+3);
	// 	std::cout << myvector1.size() << std::endl;
	// 	std::cout << myvector1.capacity() << std::endl;
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector1.size(); ++i)
	// 		std::cout << ' ' << myvector1[i];
	// 	std::cout << std::endl;
	// }
	// {


	// 	// NOTE - Swap content
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> foo1(3, 100);   // three ints with a value of 100
	// 	ft::vector<int> bar1(5, 200);   // five ints with a value of 200
	// 	std::cout << "Size foo1 before " << foo1.size() << std::endl;
	// 	std::cout << "Capa foo1 before " << foo1.capacity() << std::endl;
	// 	std::cout << "Size bar1 before " << bar1.size() << std::endl;
	// 	std::cout << "Capa bar1 before " << bar1.capacity() << std::endl;
	// 	foo1.swap(bar1);
	// 	std::cout << "Size foo1 after " << foo1.size() << std::endl;
	// 	std::cout << "Capa foo1 after " << foo1.capacity() << std::endl;
	// 	std::cout << "Size bar1 after " << bar1.size() << std::endl;
	// 	std::cout << "Capa bar1 after " << bar1.capacity() << std::endl;
	// 	std::cout << "foo contains:";
	// 	for (unsigned i=0; i<foo1.size(); i++)
	// 		std::cout << ' ' << foo1[i];
	// 	std::cout << '\n';
	// 	std::cout << "bar contains:";
	// 	for (unsigned i=0; i<bar1.size(); i++)
	// 		std::cout << ' ' << bar1[i];
	// 	std::cout << '\n';
	// }
	// {


	// 	// NOTE - Get allocator
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> myvector;
	// 	int * p;
	// 	unsigned int i;
	// 	p = myvector.get_allocator().allocate(5);
	// 	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	// 	std::cout << "The allocated array contains:";
	// 	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// 	std::cout << '\n';
	// 	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// 	myvector.get_allocator().deallocate(p,5);
	// }
	// {

	// 	// NOTE - Relational operators for vector
	// 	ft::vector<int> foo (1,200);
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> bar (0);
	// 	if (foo==bar) std::cout << "foo and bar are equal\n";
	// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// 	if (foo< bar) std::cout << "foo is less than bar\n";
	// 	if (foo> bar) std::cout << "foo is greater than bar\n";
	// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	// }
	// {


	// 	// NOTE - Exchange contents of vectors
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> foo (3,100);   // three ints with a value of 100
	// 	ft::vector<int> bar (5,200);   // five ints with a value of 200
	// 	// foo(bar);//NOTE:
	// 	std::cout << "foo contains:";
	// 	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// 	std::cout << "bar contains:";
	// 	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// {
	// 	//NOTE - compare it and const-it
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> foo (3,100);   // three ints with a value of 100
	// 	ft::vector<int> bar (5,200);   // five ints with a value of 200
	// 	std::cout << "foo contains:";
	// 	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// 	std::cout << "bar contains:";
	// 	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// 	{
    //     std::cout << "~~~~~~~~~~ Get allocator ~~~~~~~~~~" << std::endl;
	// 	ft::vector<int> myvector;
	// 	int * p;
	// 	unsigned int i;
	// 	p = myvector.get_allocator().allocate(5);
	// 	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	// 	std::cout << "The allocated array contains:";
	// 	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// 	std::cout << '\n';
	// 	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// 	myvector.get_allocator().deallocate(p,5);
	// }
	// {
	// 	ft::vector<int> foo (1,200);
	// 	std::cout << "------------- Library -------------" << std::endl;
	// 	ft::vector<int> bar (0);
	// 	if (foo==bar) std::cout << "foo and bar are equal\n";
	// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// 	if (foo< bar) std::cout << "foo is less than bar\n";
	// 	if (foo> bar) std::cout << "foo is greater than bar\n";
	// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	// }
		std::cout << "================== STACK EXAMPLES ==================" << std::endl;
		{
			try
			{
				std::cout << "------------ STD:STACK ------------" << std::endl;
				std::stack<int> st;
				std::stack<int> st2;

				std::cout << st.empty() << std::endl;
				std::cout << st.size() << std::endl;
				st.push(10);
				std::cout << st.top() << std::endl;
				st.push(20);
				std::cout << st.top() << std::endl;
				st.pop();
				std::cout << st.top() << std::endl;
				std::cout << st.empty() << std::endl;
				std::cout << st.size() << std::endl;
				std::cout << "comp : " << (st == st2) << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		{
			try
			{
				std::cout << "------------ FT:STACK ------------" << std::endl;
				ft::stack<int>    st;
				ft::stack<int>    st2;

				std::cout << st.empty() << std::endl;
				std::cout << st.size() << std::endl;
				st.push(10);
				std::cout << st.top() << std::endl;
				st.push(20);
				std::cout << st.top() << std::endl;
				st.pop();
				std::cout << st.top() << std::endl;
				std::cout << st.empty() << std::endl;
				std::cout << st.size() << std::endl;
				std::cout << "comp : " << (st == st2) << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
}
