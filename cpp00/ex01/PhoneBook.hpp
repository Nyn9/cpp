#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();
		void addContact();
		void searchContact();

    private:
		Contact m_contacts[8];
		int		m_nbContact;
		int		m_contactIndex;
};

#endif