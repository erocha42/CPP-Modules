#include "Fixed.hpp"

const int Fixed::bits_number = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_number = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp_number = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fp_number = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fp_number;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_number = raw;	
}