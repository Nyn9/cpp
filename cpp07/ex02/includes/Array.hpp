#pragma once

#include <iostream>

template <typename T>
class Array
{
    public:
        Array<T>() : m_array(NULL), m_size(0) {}

		Array<T>(unsigned int n)
		{
			if (static_cast<int>(n) < 0)
				n = 0;
			if (n == 0)
				m_array = NULL;
			else
				m_array = new T[n];
			m_size = n;
		}

        Array<T>(const Array &cp)
		{
			m_array = NULL;
			*this = cp;
		}

        virtual ~Array<T>()
		{
			if (m_array)
				delete [] m_array;
		}

        Array<T> &operator=(Array const &src)
		{
			if (this != &src)
			{
				if (m_array)
					delete [] m_array;
				m_size = src.size();
				m_array = new T[m_size];
				for (unsigned int i = 0; i < m_size; i++)
				{
					m_array[i] = src[i];
				}
			}
			return *this;
		}

		T& operator[](unsigned int n)
		{
			if (n < m_size)
				return m_array[n];
			throw OOR();
		}

		const T& operator[](unsigned int n) const
		{
			if (n < m_size)
				return m_array[n];
			throw OOR();
		}

		unsigned int size() const
		{
			return m_size;
		}

		class OOR : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index hors limites";
				}
		};

    private:
		T *m_array;
		unsigned int m_size;

};