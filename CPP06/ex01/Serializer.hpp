#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class	Serializer
{
	Serializer();
	Serializer(Serializer const& other);
	~Serializer();
	Serializer&	operator=(Serializer const& other);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};