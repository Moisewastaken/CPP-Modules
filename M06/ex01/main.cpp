#include "Serializer.hpp"

int	main(void)
{
	Data	*d = new Data;

	std::cout << "Raw: " << d << std::endl;
	std::cout << "Serialized: " << Serializer::serialize(d) << std::endl;
	std::cout << "Deserialized: " << Serializer::deserialize(Serializer::serialize(d)) << std::endl;

	delete d;
}