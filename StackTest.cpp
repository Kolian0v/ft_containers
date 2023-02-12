#include "stack.hpp"
#include <stack>

void testOtherMethods()
{
	ft::stack<std::string> str;

	str.push("link");
	str.push("mario");
	str.push("zelda");
	str.push("Bowser");
	str.push("Donkey kong");
	str.push("Bowsette");
	str.push("dark link");
	ft::stack<std::string> str2;
	str2 = str;
	while (str2.size() != 0){
		std::cout << str2.top() << std::endl;
		str2.pop();
		str2.size();
	}
	std::cout << str2.empty() << std::endl;
	std::cout << str.empty() << std::endl;
}

// Test Top and Size
void  testPushPop(){
	ft::stack<int> a;

	for (int i=0; i < 1000000; i++){
		a.push(i);
		std::cout << a.size() << std::endl;
	}

	while (a.size() != 0){
		std::cout << a.top() << std::endl;
		a.pop();
		a.size();
	}
}

void testOperators(){
	ft::stack<int> a;
	a.push(12);
	a.push(13);
	a.push(14);
	std::cout << a.top() << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.empty() << std::endl;

	ft::stack<int> b;
	b.push(12);
	b.push(13);
	b.push(14);
	std::cout << b.top() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << b.empty() << std::endl;

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
	b.push(14);
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
	a.push(14);
	if (a < b)
		std::cout << "a < b" << std::endl;
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


int main()
{
	testOperators();
	testPushPop();
	testOtherMethods();
}
