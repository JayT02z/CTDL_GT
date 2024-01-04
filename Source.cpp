#include <iostream>

using namespace std;

class Base
{

public:

	int b;

};


class inherit :public Base
{

public:

	int i;

};

int main()
{
	Base obj1;
	obj1.i = 1;
	obj1.b = 2;
	cout << obj1.i << obj1.b;
	return 0;
}