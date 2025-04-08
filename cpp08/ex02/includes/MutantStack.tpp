template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &cp) : std::stack<T>(cp)
{
    *this = cp;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src)
{
	if (this != &src)
	{
		std::stack<T>::operator=(src);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}
