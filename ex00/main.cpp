#include <iostream>
#include "whatever.hpp"

MyClass::MyClass(char a) : _a(a)
{};

char	MyClass::getChar() const
{
	return this->_a;
}

bool 			operator>(MyClass const & a, MyClass const & b)
{
	return (a.getChar() > b.getChar());
}

bool 			operator<(MyClass const & a, MyClass const & b)
{
	return (a.getChar() < b.getChar());
}

std::ostream&	operator<< (std::ostream &out, const MyClass &cx)
{
	out << cx.getChar();
	return out;
}

template <typename T>
T const &	whatever::max(T const & a, T const & b)
{
	return (a > b) ? a : b;
}

template <typename T>
T const &	whatever::min(T const & a, T const & b)
{
	return (a < b) ? a : b;
}

template <typename T>
void 		whatever::swap(T & a, T & b)
{
	T	c(a);

	a = b;
	b = c;
	return ;
}

int main()
{
	int a = -30;
	int b = 30;
	whatever::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << whatever::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << whatever::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	whatever::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << whatever::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << whatever::max( c, d ) << std::endl;
	MyClass ca('A');
	MyClass cb('B');
	whatever::swap(ca, cb);
	std::cout << "ca = " << ca << ", cb = " << cb << std::endl;
	std::cout << "min( ca, cb ) = " << whatever::min( ca, cb ) << std::endl;
	std::cout << "max( ca, cb ) = " << whatever::max( ca, cb ) << std::endl;
	return 0;
}
