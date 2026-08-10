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

Fixed::Fixed(const int c_nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp_number = c_nbr * (1 << Fixed::bits_number);
}

Fixed::Fixed(const float cf_nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp_number = roundf(cf_nbr * (1 << Fixed::bits_number));
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

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->fp_number) / (1 << Fixed::bits_number);
}

int	Fixed::toInt(void) const
{
	return (this->fp_number) / (1 << Fixed::bits_number);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}