
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void fcnt(T arr_mmbr);

template <typename T>
void iter(T *arr_ptr, int arr_length, void (*fcnt_ptr)(T));

class MyClass
{
private:
	char	_a;
public:
	MyClass();
	MyClass(char a);
	char		getChar() const;
};

std::ostream&	operator<< (std::ostream &out, const MyClass &cx);

#endif
