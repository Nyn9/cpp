#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    public:
		PmergeMe(char **av);
        PmergeMe(const PmergeMe &cp);

        virtual ~PmergeMe();

        PmergeMe &operator=(PmergeMe const &src);

		bool parsing(char **av);
		bool isSorted(const std::vector<int>& numbers);
		template <typename T>
		T& fordJohnson(T& n)
		{
			T min;
			T max;
			bool odd = false;
			if (n.size() % 2)
				odd = true;
			if (n.size() <= 2)
			{
				if (n.size() == 2 && n[0] > n[1])
					std::swap(n[0], n[1]);
				return n;
			}
			for (size_t i = 0; i < n.size() - 1; i += 2)
			{
				if (n[i] < n[i + 1])
				{
					min.push_back(n[i]);
					max.push_back(n[i + 1]);
				}
				else
				{
					min.push_back(n[i + 1]);
					max.push_back(n[i]);
				}
			}
			if (odd)
				min.push_back(n[n.size() - 1]);
			max = fordJohnson(max);
			for (size_t i = 0; i < min.size(); ++i)
			{
				typename T::iterator pos = std::lower_bound(max.begin(), max.end(), min[i]);
				max.insert(pos, min[i]);
			}
			n = max;
			return n;
		}

    private:
        PmergeMe();
		std::vector<int> m_vector;
		std::deque<int> m_deque;

};