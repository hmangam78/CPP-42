#pragma once
#include "Intern.h"
#include <string>
#include <iostream>
#include <exception>

class AForm;

class Intern
{
    public:
	/*constructors and destructor*/
        Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern(void);

    /*Form creator*/
        AForm*  makeForm(const std::string& type, const std::string& target);
        
    /*exception*/
        class UnknownFormRequestException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

t_formcode  find_form_code(const std::string& form_type);