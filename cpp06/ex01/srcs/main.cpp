#include "Serializer.hpp"
#include "data.hpp"
#include <iostream>

int main() {
	Data *data = new Data;
	uintptr_t raw;

	data->name = "Tony";
	data->value = 42;
	std::cout << data << std::endl;
	std::cout << data->name << std::endl;
	std::cout << data->value << std::endl << std::endl;

	raw = Serializer::serialize(data);

	std::cout << raw << std::endl << std::endl;

	data = Serializer::deserialize(raw);

	std::cout << data << std::endl;
	std::cout << data->name << std::endl;
	std::cout << data->value << std::endl << std::endl;

	data->name = "Many";
	data->value = 21;

	std::cout << data->name << std::endl;
	std::cout << data->value << std::endl;

	delete data;
	return 0;
}