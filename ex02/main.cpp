#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_a = nullptr;
	this->_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
	if (this->_n > 0)
		this->_a = new T[this->_n];
	else
		this->_a = nullptr;
}

template <typename T>
Array<T>::Array(const Array &cpArray)
{
	*this = cpArray;
	return ;
}

template <typename T>
Array<T>			&Array<T>::operator=(const Array &cpArray)
{
	if (this != &cpArray)
	{
		delete (this->_a);
		this->_n = cpArray._n;
		if (this->_n)
		{
			this->_a = new T[this->_n];
			for (unsigned int i = 0; i < this->_n; ++i)
				this->_a[i] = cpArray._a[i];
		}
		else
			this->_a = cpArray._a;
	}
	return (*this);
}

template <typename T>
T				&Array<T>::getData(unsigned int i) const
{
	if (i >= this->_n)
		throw Array::OutOfArrayException();
	return (this->_a[i]);
}

template <typename T>
void 			Array<T>::setData(T arr_mmbr, unsigned int i)
{
	if (i >= this->_n)
		throw Array::OutOfArrayException();
	this->_a[i] = arr_mmbr;
	return ;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_n);
}

template <typename T>
Array<T>::~Array()
{ delete[] this->_a; }

template <typename T>
Array<T>::OutOfArrayException::OutOfArrayException()
{
	std::cout << "Member you're asking to is out of the array" << std::endl;
}

int main()
{
	try
	{
		Array<int>			intArray0;
		Array<int>			intArray3(3);
		intArray3.setData(1, 0);
		intArray3.setData(22, 1);
		intArray3.setData(333, 2);
		intArray3.setData(4444, 3);
		intArray0 = intArray3;
		std::cout << "Array size is " << intArray0.size() << std::endl;
		for (unsigned int i = 0; i < 5; ++i)
			std::cout << intArray0.getData(i) << std::endl;
		Array<std::string>	strArray0;
		Array<std::string>	strArray4(4);
		strArray4.setData("make", 0);
		strArray4.setData("love", 1);
		strArray4.setData("no", 2);
		strArray4.setData("war", 3);
		strArray0 = strArray4;
		std::cout << "Array size is " << strArray0.size() << std::endl;
		for (unsigned int i = 0; i < 5; ++i)
			std::cout << strArray0.getData(i) << std::endl;
	}
	catch (std::exception &e)
	{}
	return 0;
}
