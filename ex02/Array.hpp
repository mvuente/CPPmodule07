
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <class T>
class Array
{
private:
	unsigned int	_n;
	T				*_a;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &cpArray);
	Array			&operator=(const Array &cpArray);
	T				&getData(unsigned int i) const;
	void 			setData(T arr_mmbr, unsigned int i);
	unsigned int 	size() const;
	~Array();

	class OutOfArrayException : public std::exception
	{
	public:
		OutOfArrayException();
	};
};

#endif
