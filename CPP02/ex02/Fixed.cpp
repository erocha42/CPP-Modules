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

std::ostream&	operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return this->fp_number > other.getRawBits();
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->fp_number < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->fp_number >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->fp_number <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->fp_number == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->fp_number != other.getRawBits();
}

Fixed 	Fixed::operator+(const Fixed& other) const
{
	Fixed	tmp;

	tmp.setRawBits(this->fp_number + other.getRawBits());
	return tmp;
}

Fixed 	Fixed::operator-(const Fixed& other) const
{
	Fixed	tmp;

	tmp.setRawBits(this->fp_number - other.getRawBits());
	return tmp;
}

Fixed 	Fixed::operator*(const Fixed& other) const
{
	Fixed	tmp;

	tmp.setRawBits((this->fp_number * other.getRawBits()) / (1 << Fixed::bits_number));
	return tmp;
}

Fixed 	Fixed::operator/(const Fixed& other) const
{
	Fixed	tmp;

	tmp.setRawBits(((1 << Fixed::bits_number) * this->fp_number) / other.getRawBits());
	return tmp;
}

Fixed&	Fixed::operator++(void)
{
	this->fp_number = this->fp_number + 1;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->fp_number = this->fp_number + 1;
	return	tmp;
}

Fixed&	Fixed::operator--(void)
{
	this->fp_number = this->fp_number - 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	
	this->fp_number = this->fp_number - 1;
	return	tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}