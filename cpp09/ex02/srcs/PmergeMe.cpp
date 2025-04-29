#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
	if (!parsing(av))
		exit(1);

	std::cout << "Before : ";
	for (size_t i = 0; i < m_vector.size(); ++i)
		std::cout << m_vector[i] << " ";
	std::cout << std::endl;

	clock_t startV = clock();
	m_vector = fordJohnson(m_vector);
	clock_t endV = clock();

	clock_t startD = clock();
	m_deque = fordJohnson(m_deque);
	clock_t endD = clock();

	std::cout << "After : ";
	for (size_t i = 0; i < m_deque.size(); ++i)
		std::cout << m_deque[i] << " ";
	std::cout << std::endl;

	double elapsed_time = static_cast<double>(endV - startV)  / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of : " << m_vector.size() << " elements with std::vector : " << std::fixed << elapsed_time << " s" << std::endl;
	elapsed_time = static_cast<double>(endD - startD)  / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of : " << m_deque.size() << " elements with std::deque : " << std::fixed << elapsed_time << " s" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &cp)
{
    *this = cp;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->m_vector = src.m_vector;
		this->m_deque = src.m_deque;
    }
	return *this;
}

bool PmergeMe::isSorted(const std::vector<int>& numbers)
{
	for (size_t i = 1; i < numbers.size(); ++i)
	{
		if (numbers[i - 1] > numbers[i])
			return false;
	}
	return true;
}

bool PmergeMe::parsing(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		int n = atoi(av[i]);
		if (n < 0 || (n == 0 && av[i][0] != '0'))
		{
			std::cerr << "Invalid argument: " << av[i] << std::endl;
			return (false);
		}
		m_vector.push_back(n);
		m_deque.push_back(n);
	}
	if (isSorted(m_vector))
	{
		std::cerr << "Array is already sorted" << std::endl;
		return (false);
	}
	return (true);
}

// template <typename T>
// T& PmergeMe::fordJohnson(T& n)
// {
// 	T min;
// 	T max;
// 	bool odd = false;
// 	if (n.size() % 2)
// 		odd = true;
// 	if (n.size() <= 2)
// 	{
// 		if (n.size() == 2 && n[0] > n[1])
// 			std::swap(n[0], n[1]);
// 		return n;
// 	}
// 	for (size_t i = 0; i < n.size() - 1; i += 2)
// 	{
// 		if (n[i] < n[i + 1])
// 		{
// 			min.push_back(n[i]);
// 			max.push_back(n[i + 1]);
// 		}
// 		else
// 		{
// 			min.push_back(n[i + 1]);
// 			max.push_back(n[i]);
// 		}
// 	}
// 	if (odd)
// 		min.push_back(n[n.size() - 1]);
// 	max = fordJohnson(max);
// 	for (size_t i = 0; i < min.size(); ++i)
// 	{
// 		T::iterator pos = std::lower_bound(max.begin(), max.end(), min[i]);
// 		max.insert(pos, min[i]);
// 	}
// 	n = max;
// 	return n;
// }

