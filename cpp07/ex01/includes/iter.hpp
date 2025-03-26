template <typename T>
void iter(T *array, int len, void (*f)(const T&))
{
	for (int i = 0; i < len; i++)
		(*f)(array[i]);
}

template <typename T>
void print(const T &c)
{
	std::cout << c << std::endl;
}

template <typename T>
void print_square(const T &c)
{
	std::cout << c * c << std::endl;
}

template <typename T>
void print_double(const T &c)
{
	std::cout << c * 2 << std::endl;
}
