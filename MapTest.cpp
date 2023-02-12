#include "map.hpp"
#include <map>
#include <iostream>


struct mycomp{
	bool operator()(const int &x, const int &y) const{
		return x > y;
	}
};


void testElementAccess(){
	ft::map<int, int> a;
	a.insert(ft::pair<int, int>(20,12));
	a.insert(ft::pair<int, int>(3,6212));
	a.insert(ft::pair<int, int>(10,1));
	a.insert(ft::pair<int, int>(220,1262));
	a.insert(ft::pair<int, int>(13,89237));
	a.insert(ft::pair<int, int>(184,2113));

	std::cout << a[20] << std::endl;
	ft::map<int, int>::iterator it = a.begin();
	while (it != a.end()){
		std::cout << it->first << std::endl;
		it++;
	}
	it = a.begin();
	std::cout << it->second << std::endl;

	ft::map<char, std::string> b;
	b.insert(ft::pair<char, std::string>('z', "hello"));
	b.insert(ft::pair<char, std::string>('x', "mummy"));
	b.insert(ft::pair<char, std::string>('t', "oh my god"));
	b.insert(ft::pair<char, std::string>('y', "key"));

	std::cout << a[319] << std::endl;
	while(it != a.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}


	std::cout << b['x'] << std::endl;
	for (ft::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::cout << b['v'] << std::endl;
	for (ft::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}

	b['b'] = "blablavlablalbal";
	for (ft::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}
}

void testCapacity(){
	ft::map<int, int> a;
	std::cout << a.empty() <<std::endl;
	a.insert(ft::pair<int, int>(21,55));
	std::cout << a.empty() <<std::endl;

	std::cout << a.size() << std::endl;
	a.insert(ft::pair<int, int>(21,55));
	a.insert(ft::pair<int, int>(21,55));
	std::cout << a.size() << std::endl;

	std::cout << a.max_size() << std::endl;
}

void testModifiers(){

	ft::map<int, int> a;
	a.insert(ft::pair<int, int>(1,2));
	a.insert(ft::pair<int, int>(52,612));
	a.insert(ft::pair<int, int>(231,1));

	ft::map<int, int>::iterator it = a.begin();
	while (it != a.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}
	a.clear();
	it = a.begin();
	while (it != a.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}
	std::cout << a.size() << std::endl;
}

void testDelete(){
	ft::map<int, int> b;
	for (int i = 0; i < 1000000; i++){
		b.insert(ft::make_pair(i, i+10));
	}
	ft::map<int,int>::iterator firstIt = b.begin();
	ft::map<int,int>::iterator  lastIt  = b.end();
	b.erase(858585);
	int i = 0;
	while ( i < 1000000){
		b.insert(ft::make_pair(i, i+10));
		i++;
	}

	while (firstIt != lastIt){
		std::cout << firstIt->first << " - " << firstIt->second << std::endl;
		firstIt++;
	}


	ft::map<int, int> a;

	a.insert(ft::pair<int, int>(10,3));
	a.insert(ft::pair<int, int>(5,632));
	a.insert(ft::pair<int, int>(20,2));
	a.insert(ft::pair<int, int>(1,2));
	a.insert(ft::pair<int, int>(18,192));
	a.insert(ft::pair<int, int>(128,1932));

	ft::map<int, int>::iterator first = a.begin();
	ft::map<int, int>::iterator  last = a.end();
	last--;
	a.erase(first, last);

	ft::map<int, int>::iterator it = a.begin();
	while(it != a.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}

	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(3,2));
	a.insert(ft::pair<int, int>(4,2));

	it = a.begin();
	while (it != a.end())
	{
		std::cout << it->first << std::endl;
		it++;
	}
}

void testComparators(){
	ft::map<int, int, mycomp> a;
	a.insert(ft::pair<int, int>(5, 7));
	a.insert(ft::pair<int, int>(10, 23));
	a.insert(ft::pair<int, int>(56, 741));
	a.insert(ft::pair<int, int>(2, 0));
	a.insert(ft::pair<int, int>(708, -454));
	a.insert(ft::pair<int, int>(5656, 6));
	a.insert(ft::pair<int, int>(1, 987));
	a.insert(ft::pair<int, int>(-1001, 0));
	a.insert(ft::pair<int, int>(12, 36));

	ft::map<int, int>::iterator  it = a.begin();
	while (it != a.end()){
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
		it++;
	}
}

// First-second testing
void testLookUp(){

	ft::map<int, int> a;

	a.insert(ft::pair<int, int>(10,3));
	a.insert(ft::pair<int, int>(5,632));
	a.insert(ft::pair<int, int>(20,2));
	a.insert(ft::pair<int, int>(1,2));
	a.insert(ft::pair<int, int>(18,192));
	a.insert(ft::pair<int, int>(12,12900));
	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(3,2));
	a.insert(ft::pair<int, int>(4,2));

	std::cout << a.count(4545) << std::endl;
	std::cout << a.count(1) << std::endl;

	std::cout << a.lower_bound(10)->first << std::endl;
	std::cout << a.lower_bound(5)->first << std::endl;
	std::cout << a.lower_bound(20)->first << std::endl;
	std::cout << a.lower_bound(1)->first << std::endl;
	std::cout << a.lower_bound(18)->first << std::endl;
	std::cout << a.lower_bound(12)->first << std::endl;
	std::cout << a.lower_bound(3)->first << std::endl;
	std::cout << a.lower_bound(4)->first << std::endl;

	std::cout << a.upper_bound(10)->first << std::endl;
	std::cout << a.upper_bound(5)->first << std::endl;
	std::cout << a.upper_bound(20)->first << std::endl;
	std::cout << a.upper_bound(1)->first << std::endl;
	std::cout << a.upper_bound(18)->first << std::endl;
	std::cout << a.upper_bound(12)->first << std::endl;
	std::cout << a.upper_bound(3)->first << std::endl;
	std::cout << a.upper_bound(4)->first << std::endl;


	std::cout << a.equal_range(10).first->first << std::endl;
	std::cout << a.equal_range(10).first->second << std::endl;

	std::cout << a.equal_range(5).first->first << std::endl;
	std::cout << a.equal_range(5).first->second << std::endl;

	std::cout << a.equal_range(20).first->first << std::endl;
	std::cout << a.equal_range(20).first->second << std::endl;

	std::cout << a.equal_range(1).first->first << std::endl;
	std::cout << a.equal_range(1).first->second << std::endl;

	std::cout << a.equal_range(18).first->first << std::endl;
	std::cout << a.equal_range(18).first->second << std::endl;

	std::cout << a.equal_range(12).first->first << std::endl;
	std::cout << a.equal_range(12).first->second << std::endl;


	std::cout << a.equal_range(3).first->first << std::endl;
	std::cout << a.equal_range(3).first->second << std::endl;
	std::cout << a.equal_range(1).first->first << std::endl;
	std::cout << a.equal_range(1).first->second << std::endl;

	std::cout << a.equal_range(18).first->first << std::endl;
	std::cout << a.equal_range(18).first->second << std::endl;

	std::cout << a.equal_range(12).first->first << std::endl;
	std::cout << a.equal_range(12).first->second << std::endl;


	std::cout << a.equal_range(3).first->first << std::endl;
	std::cout << a.equal_range(3).first->second << std::endl;

	std::cout << a.equal_range(1).first->first << std::endl;
	std::cout << a.equal_range(1).first->second << std::endl;

	std::cout << a.equal_range(18).first->first << std::endl;
	std::cout << a.equal_range(18).first->second << std::endl;

	std::cout << a.equal_range(12).first->first << std::endl;
	std::cout << a.equal_range(12).first->second << std::endl;


	std::cout << a.equal_range(3).first->first << std::endl;
	std::cout << a.equal_range(3).first->second << std::endl;

	std::cout << a.equal_range(1).first->first << std::endl;
	std::cout << a.equal_range(1).first->second << std::endl;

	std::cout << a.equal_range(18).first->first << std::endl;
	std::cout << a.equal_range(18).first->second << std::endl;

	std::cout << a.equal_range(12).first->first << std::endl;
	std::cout << a.equal_range(12).first->second << std::endl;


	std::cout << a.equal_range(3).first->first << std::endl;
	std::cout << a.equal_range(3).first->second << std::endl;

	std::cout << a.equal_range(1).first->first << std::endl;
	std::cout << a.equal_range(1).first->second << std::endl;

	std::cout << a.equal_range(18).first->first << std::endl;
	std::cout << a.equal_range(18).first->second << std::endl;

	std::cout << a.equal_range(12).first->first << std::endl;
	std::cout << a.equal_range(12).first->second << std::endl;


	std::cout << a.equal_range(3).first->first << std::endl;
	std::cout << a.equal_range(3).first->second << std::endl;


	std::cout << a.equal_range(4).first->first << std::endl;
	std::cout << a.equal_range(4).first->second << std::endl;

	ft::pair<ft::map<int,int>::const_iterator , ft::map<int,int>::const_iterator> pr =  a.equal_range(4);
	std::cout << pr.first->first << std::endl;

	const ft::pair<ft::map<int,int>::const_iterator , ft::map<int,int>::const_iterator> pr2 =  a.equal_range(4);
	std::cout << pr2.first->first << std::endl;


}


int main(){
	testElementAccess();
	testCapacity();
	testModifiers();
	testLookUp();
	testDelete();
	testComparators();
}
