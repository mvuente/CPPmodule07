#include <iostream>
#include "iter.hpp"

MyClass::MyClass()
{};

MyClass::MyClass(char a) : _a(a)
{};

char	MyClass::getChar() const
{
	return this->_a;
}

std::ostream&	operator<< (std::ostream &out, const MyClass &cx)
{
	out << cx.getChar();
	return out;
}

template <typename T>
void fcnt_ptr(T arr_mmbr)
{
	std::cout << arr_mmbr << std::endl;
}

template <typename T>
void iter(T *arr_ptr, int arr_length, void (*fcnt_ptr)(T))
{
	for (int i = 0; i < arr_length; ++i)
		fcnt_ptr(arr_ptr[i]);
}

int main()
{
	char		c[4] = {'A', 'B', 'X', 'Y'};
	int 		i[5] = {1, 22, 333, 4444, 55555};
	std::string s[3] = {"I", "am", "MUZZY"};
	iter(c, 0, fcnt_ptr);
	iter(i, 0, fcnt_ptr);
	iter(s, 0, fcnt_ptr);
	MyClass	*horde = new MyClass[2];
	MyClass ca('A');
	horde[0] = ca;
	MyClass cb('B');
	horde[1] = cb;
	iter(horde, 2, fcnt_ptr);
	delete[] horde;
	return 0;
}
