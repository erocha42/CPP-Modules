#pragma once

#include <exception>

template <typename T>
class	Array
{
	T				*elements;
	unsigned int	_size;

	class	IndexOutOfBound : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	public:
		Array();
		Array(unsigned int n);
		Array(Array const& other);
		~Array();
		Array&	operator=(Array const& other);
		unsigned int	size() const;
		T	operator[](const unsigned int n) const;
		T&	operator[](const unsigned int n);
};

template <typename T>
Array<T>::Array(void) : elements(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const& other) : elements(new T[other.size()]), _size(other.size()) 
{
	for (unsigned int i = 0; i < other.size(); i++)
	{
		elements[i] = other.elements[i];
	}
}

template <typename T>
Array<T>::~Array() 
{
	delete[] elements;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const& other)
{
	if (this != &other)
	{
		delete[] elements;
		elements = new T[other.size()];
		for (unsigned int i = 0; i < other.size(); i++)
		{
			elements[i] = other.elements[i];
		}
		this->_size = other.size();
	}
	return *this;
}

template <typename T>
const char* Array<T>::IndexOutOfBound::what() const throw()
{
	return "Exception: IndexOutOfBound";
}

template <typename T>
T	Array<T>::operator[](const unsigned int n) const
{
	if (n >= this->size())
		throw IndexOutOfBound();
	return elements[n];
}

template <typename T>
T&	Array<T>::operator[](const unsigned int n)
{
	if (n >= this->size())
		throw IndexOutOfBound();
	return elements[n];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}