#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	int					fp_number;
	static const int	bits_number;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int c_nbr);
		Fixed(const float cf_nbr);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif