#include "Serializer.hpp"

int	main()
{
	Data	data;
	Data	*result;
	uintptr_t raw;
	data.i = 5;
	data.s = "Test";

	raw = Serializer::serialize(&data);
	result = Serializer::deserialize(raw);
	std::cout << "data: " << data.i << " " << data.s << "\n"
	<< "ptr: " << result->i << " " << result->s << "\n";
	if (&data == result)
		std::cout << "data = result\n";
	return 0;
}