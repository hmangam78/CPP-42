#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string     _target;
        void    	pardon(const std::string& target) const;
    /*form default values*/
        static int const signGrade = 25;
        static int const execGrade = 5;

    public:
    /*constructors and destructor*/
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string& _target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    /*getter*/    
        std::string getTarget(void) const;

	/*form manager*/
        void		execute(Bureaucrat const& executor) const;
    
};