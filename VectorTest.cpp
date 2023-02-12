#include "vector.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

void testConstructors(){
	ft::vector<int> int_vector;

	ft::vector<int> fill_wout_value(10);
	for (ft::vector<int>::iterator it = fill_wout_value.begin(); it != fill_wout_value.end(); it++)
		std::cout << *it << " ";

	ft::vector<int> fill_with_value(20, 12);
	for (ft::vector<int>::iterator it = fill_with_value.begin(); it != fill_with_value.end(); it++)
		std::cout << *it << " ";


	std::cout << std::endl;

	ft::vector<int>::iterator it_begin = fill_with_value.begin();
	ft::vector<int>::iterator it_end = fill_with_value.end();
	it_begin++;
	it_begin++;
	it_begin++;

	ft::vector<int> fill_with_range(it_begin, it_end);
	std::cout << "Size: " << fill_with_range.size() << ", Capacity: " << fill_with_range.capacity() << std::endl;
	for (ft::vector<int>::iterator it = fill_with_range.begin(); it != fill_with_range.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	ft::vector<int> copy_vector(fill_with_range);
	ft::vector<int>::iterator it = copy_vector.begin();
	while ( it != copy_vector.end())
	{
		std::cout << *it << " ";
		it++;
	}

	std::cout << std::endl;
}

void testIterators(){

	ft::vector<int> a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(90);
	a.push_back(34);
	a.push_back(12);
	a.push_back(545);
	a.push_back(781);
	a.push_back(67);
	a.push_back(93);
	a.push_back(25);
	a.push_back(89);
	a.push_back(6321);
	a.push_back(88);

	ft::vector<int>::iterator beginIt = a.begin();
	ft::vector<int>::iterator endIt = a.end();

	ft::vector<int>::iterator copyBeg = beginIt;
	ft::vector<int>::iterator copyEnd(endIt);
	ft::vector<int>::iterator it = copyBeg;
	while(it != copyEnd)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	int *base = beginIt.base();
	std::cout << *base << std::endl;


	std::cout << *(beginIt++) << std::endl;
	std::cout << *(++beginIt) << std::endl;
	std::cout << *(beginIt--) << std::endl;
	std::cout << *(--beginIt) << std::endl;
	std::cout << *(beginIt + 2) << std::endl;
	std::cout << *(2 + beginIt) << std::endl;
	std::cout << *(beginIt - 1) << std::endl;
	beginIt -= 1;
	std::cout << *(beginIt) << std::endl;
	beginIt += 3;
	std::cout << *(beginIt) << std::endl;
	std::cout << endIt - beginIt << std::endl;
	std::cout << beginIt[1] << std::endl;

	std::cout << endIt - beginIt << std::endl;

	if (beginIt > endIt)
		std::cout << "begin > end" << std::endl;
	if (beginIt >= endIt)
		std::cout << "begin >= end" << std::endl;
	if (beginIt < endIt)
		std::cout << "begin < end" << std::endl;
	if (beginIt <= endIt)
		std::cout << "begin <= end" << std::endl;
	if (beginIt == endIt)
		std::cout << "begin == end" << std::endl;
	if (beginIt != endIt)
		std::cout << "begin != end" << std::endl;
	beginIt += 3;
	if (beginIt > endIt)
		std::cout << "begin > end" << std::endl;
	if (beginIt >= endIt)
		std::cout << "begin >= end" << std::endl;
	if (beginIt < endIt)
		std::cout << "begin < end" << std::endl;
	if (beginIt <= endIt)
		std::cout << "begin <= end" << std::endl;
	if (beginIt == endIt)
		std::cout << "begin == end" << std::endl;
	if (beginIt != endIt)
		std::cout << "begin != end" << std::endl;
	it = a.begin();

	while(it != a.end()){
		std::cout << *(it) << std::endl;
		it++;
	}


	ft::vector<int>::reverse_iterator reverseBeginIt = a.rbegin();
	ft::vector<int>::reverse_iterator reverseEndIt = a.rend();
	ft::vector<int>::reverse_iterator rIt = a.rbegin();
	while( rIt != a.rend())
	{
		std::cout << *rIt << " " << std::endl;
		rIt++;
	}

	std::cout << std::endl;

	std::cout << *(reverseBeginIt++) << std::endl;
	std::cout << *(++reverseBeginIt) << std::endl;
	std::cout << *(reverseBeginIt + 2) << std::endl;
	std::cout << *(reverseBeginIt - 1) << std::endl;
	std::cout << *(2 + reverseBeginIt) << std::endl;
	std::cout << *reverseBeginIt++ << std::endl;

	if (reverseBeginIt > reverseEndIt)
		std::cout << "begin > end" << std::endl;
	if (reverseBeginIt >= reverseEndIt)
		std::cout << "begin >= end" << std::endl;
	if (reverseBeginIt < reverseEndIt)
		std::cout << "begin < end" << std::endl;
	if (reverseBeginIt <= reverseEndIt)
		std::cout << "begin <= end" << std::endl;
	if (reverseBeginIt == reverseEndIt)
		std::cout << "begin == end" << std::endl;
	if (reverseBeginIt != reverseEndIt)
		std::cout << "begin != end" << std::endl;

	std::cout << *(2 + reverseBeginIt) << std::endl;
	if (reverseBeginIt > reverseEndIt)
		std::cout << "begin > end" << std::endl;
	if (reverseBeginIt >= reverseEndIt)
		std::cout << "begin >= end" << std::endl;
	if (reverseBeginIt < reverseEndIt)
		std::cout << "begin < end" << std::endl;
	if (reverseBeginIt <= reverseEndIt)
		std::cout << "begin <= end" << std::endl;
	if (reverseBeginIt == reverseEndIt)
		std::cout << "begin == end" << std::endl;
	if (reverseBeginIt != reverseEndIt)
		std::cout << "begin != end" << std::endl;
	if (reverseBeginIt > reverseEndIt)
		std::cout << "begin > end" << std::endl;
	if (reverseBeginIt >= reverseEndIt)
		std::cout << "begin >= end" << std::endl;
	if (reverseBeginIt < reverseEndIt)
		std::cout << "begin < end" << std::endl;
	if (reverseBeginIt <= reverseEndIt)
		std::cout << "begin <= end" << std::endl;
	if (reverseBeginIt == reverseEndIt)
		std::cout << "begin == end" << std::endl;
	if (reverseBeginIt != reverseEndIt)
		std::cout << "begin != end" << std::endl;
	std::cout << reverseEndIt - reverseBeginIt << std::endl;
	std::cout << *reverseBeginIt << std::endl;
	std::cout << *reverseEndIt << std::endl;
	std::cout << reverseBeginIt[2] << std::endl;
	std::cout << reverseBeginIt[4] << std::endl;
	std::cout << reverseEndIt[1] << std::endl;
	std::cout << reverseBeginIt[1] << std::endl;
	std::cout << reverseEndIt[4] << std::endl;
	std::cout << reverseEndIt[2] << std::endl;
	std::cout << reverseEndIt[0] << std::endl;
	std::cout << *reverseEndIt.base().base() << std::endl;

	ft::vector<int>::const_reverse_iterator constRevIt = a.rbegin();
	while( constRevIt != a.rend()) {
		std::cout << *constRevIt << " ";
		constRevIt++;
	}
	std::cout << std::endl;
}

void testPushBack(){
	ft::vector<int> a;

	int i = 0;
	while (i < 10000000)
		a.push_back(i);

	ft::vector<int>::iterator it = a.begin();
	while(it != a.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void testElementAcess(){

	ft::vector<std::string> strs;
	strs.push_back("kek");
	strs.push_back("world");
	strs.push_back("hello");
	strs.push_back("test");
	strs.push_back("ofasodf");
	strs.push_back("anj");

	std::cout << strs.at(0) << std::endl;
	std::cout << strs.at(1) << std::endl;
	std::cout << strs.at(2) << std::endl;
	std::cout << strs.at(3) << std::endl;
	std::cout << strs.at(4) << std::endl;
	std::cout << strs.at(5) << std::endl;
	std::cout << strs.at(5) << std::endl;
	std::cout << strs.at(5) << std::endl;
	try{
		std::cout << strs.at(6) << std::endl;
	}catch (std::exception &ex){

	}

	const ft::vector<int> a(10);
	const int const_ref = a.at(2);
	std::cout << const_ref << std::endl;


	strs[2] = "modified";
	for (ft::vector<std::string>::iterator it = strs.begin(); it != strs.end(); it++)
		std::cout << *it << std::endl;

	std::cout << strs[0] << std::endl;
	std::cout << strs[1] << std::endl;
	std::cout << strs[2] << std::endl;
	std::cout << strs[3] << std::endl;
	std::cout << strs[4] << std::endl;
	std::cout << strs[5] << std::endl;
	std::cout << strs[5] << std::endl;
	std::cout << strs[5] << std::endl;
	std::cout << strs[5] << std::endl;

	std::cout << strs.front() << std::endl;
	std::cout << a.front() << std::endl;
	std::cout << strs.back() << std::endl;
	std::cout << a.back() << std::endl;


	std::cout << *strs.data() << std::endl;
	std::cout << *a.data()<< std::endl;

	ft::vector<int> empty;
	std::cout << empty.data() << std::endl;


}

void testCapacity(){

	ft::vector<int> a;
	ft::vector<int> b;
	ft::vector<int> c(100);
	a.push_back(1);
	std::cout << a.empty() << std::endl;
	std::cout << b.empty() << std::endl;
	std::cout << c.empty() << std::endl;


	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << b.max_size() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << c.size() << std::endl;
	std::cout << c.max_size() << std::endl;
	std::cout << c.capacity() << std::endl;
	a.reserve(100);
	std::cout << a.capacity() << std::endl;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	b.push_back(40);
	b.reserve(2);
	ft::vector<int>::iterator it = b.begin();
	while ( it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	b.reserve(200);
	it = b.begin();
	while ( it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}


}

void testModifiers(){

	int i;
	ft::vector<int> a;
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);
	a.push_back(321);
	a.push_back(312);
	a.push_back(21);
	a.push_back(111);
	a.push_back(115);
	a.push_back(2223);

	a.clear();

	ft::vector<int>::iterator it = a.begin();
	while (it != a.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << a.size() << std::endl;


	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);

	it = a.begin();
	it += 2;

	std::cout << a.capacity() << std::endl;
	std::cout << *a.insert(it, 90) << std::endl;
	std::cout << a.capacity() << std::endl;
	it = a.begin();
	while ( it != a.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	ft::vector<int> b(1000);
	i = 0;
	while( i < 1000)
		b.push_back(i++);

	ft::vector<int>::iterator itB = b.begin();
	itB += 400;
	std::cout << *b.insert(itB, 9999) << std::endl;
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;


	//count
	ft::vector<int>::iterator itB2 = b.begin();

	b.insert(itB2, 5, 20);
	it = b.begin();
	while(it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;


	//range
	a.clear();
	i = 0;
	while(i < 250)
		a.push_back(i++);

	b.clear();
	i = 300;
	while(i < 500)
		b.push_back(i++);

	ft::vector<int>::iterator first = b.begin();
	ft::vector<int>::iterator last = b.end();
	ft::vector<int>::iterator pos = a.begin();

	a.insert(pos+4, first + 10, last);

	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << *a.erase(a.begin() + 10) << std::endl;
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << *a.erase(a.begin() + 10, a.end() - 100) << std::endl;
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << *a.erase(a.begin(), a.end()) << std::endl;
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	//push back
	ft::vector<int> y;
	i = 0;
	while (i < 1000){
		y.push_back(i);
		std::cout << y.size() << " ";
		std::cout << y.capacity() << std::endl;
		i++;
	}

	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}


	i = 0;
	while(i < 400)
	{
		y.pop_back();
		std::cout << y.size() << " ";
		std::cout << y.capacity() << std::endl;
		i++;
	}
	while(i < 400)
	{
		y.pop_back();
		std::cout << y.size() << " ";
		std::cout << y.capacity() << std::endl;
		i++;
	}

	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	// resize
	y.resize(10, 777);
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	y.resize(100, 777);
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	// assign
	y.assign(10, 90);
	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	ft::vector<int> x;
	i = 0;
	while(i < 1000)
		x.push_back(i++);

	y.assign(x.begin() + 100, x.end() - 100);

	it = b.begin();
	while (it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void 	testOperators(){
	ft::vector<int> a;
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);

	ft::vector<int> b;
	b.push_back(13);
	b.push_back(14);
	b.push_back(15);

	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);

	b.push_back(1);
	b.push_back(5);
	b.push_back(6);
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);

	b.push_back(12);
	b.push_back(53);
	b.push_back(64);
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	b.push_back(53);
	b.push_back(64);
	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;

}

int main() {
	testConstructors();
	testIterators();
	testElementAcess();
	testCapacity();
	testModifiers();
	testOperators();
}
