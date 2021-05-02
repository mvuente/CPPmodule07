
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

namespace whatever
{
	template <typename T>
	T const & max(T const & a, T const & b);

	template <typename T>
	T const & min(T const & a, T const & b);

	template <typename T>
	void swap(T & a, T & b);
}

class MyClass
{
private:
	char	_a;
public:
	MyClass(char a);
	char		getChar() const;
};

bool 			operator>(MyClass const & a, MyClass const & b);
bool 			operator<(MyClass const & a, MyClass const & b);
std::ostream&	operator<< (std::ostream &out, const MyClass &cx);

#endif
