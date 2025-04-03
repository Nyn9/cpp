#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
		std::cout << "numbers[5] = " << numbers[5] << " / tmp[5] = " << tmp[5] << std::endl;
		tmp[5] = 42;
		std::cout << "numbers[5] = " << numbers[5] << " / tmp[5] = " << tmp[5] << std::endl;
		tmp[5] = numbers[5];
		std::cout << "numbers[5] = " << numbers[5] << " / tmp[5] = " << tmp[5] << std::endl;
		numbers[5] = 42;
		std::cout << "numbers[5] = " << numbers[5] << " / tmp[5] = " << tmp[5] << std::endl;
		numbers[5] = tmp[5];
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	{
		std::string str = "Hello World !";
		Array<char> arr(13);

		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = str[i];
		for (size_t i = 0; i < arr.size(); i++)
			std::cout << arr[i];
		std::cout << std::endl;
	}
    return 0;
}