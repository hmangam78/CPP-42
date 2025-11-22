#include "Intern.hpp"
#include "Intern.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* Default constructor */
Intern::Intern(void)
{
	if (SHOWALL)
		std::cout << "Intern constructor called" << std::endl;
}

/* Copy constructor */
Intern::Intern(const Intern& other)
{
    (void)other;
	if (SHOWALL)
		std::cout << "Intern copy constructor called" << std::endl;
}

/* Assignment constructor */
Intern& Intern::operator=(const Intern& other)
{
	if (SHOWALL)
		std::cout << "Intern copy assignment called" << std::endl;
    if (this == &other)
        return (*this);
    *this = other;
    return (*this);
}

/* Destructor */
Intern::~Intern(void)
{
	if (SHOWALL)
		std::cout << "Intern destructor called" << std::endl;
}

/* if type matches a known form, creates an instance of the corresponding form*/
AForm* Intern::makeForm(const std::string& type, const std::string& target)
{
    int form_code;
    try
    {
        form_code = find_form_code(type);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return NULL;
    }
    switch (form_code)
    {
        case 0:
            return (new ShrubberyCreationForm(target));
        case 1:
            return (new RobotomyRequestForm(target));
        case 2:
            return (new PresidentialPardonForm(target));
        default:
            return NULL;
    }
}

/* Unknown form exception */
const char* Intern::UnknownFormRequestException::what() const throw()
{
    return ("Intern tried to create an unknown form");
}

t_formcode  find_form_code(const std::string& form_type)
{
    if (form_type == "shrubbery creation") return SHRUBBERY;
    if (form_type == "robotomy request") return ROBOTOMY;
    if (form_type == "presidential pardon") return PARDON;
    throw Intern::UnknownFormRequestException();
}
