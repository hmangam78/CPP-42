#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string     _target;
        void    plant_tree(const std::string& target) const;
    /*form default values*/
        static int const signGrade = 145;
        static int const execGrade = 137;

    public:
    /*constructors and destructor*/
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string& _target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    /*getter*/
        std::string getTarget(void) const;
    
    /*form manager*/
        void    execute(Bureaucrat const& executor) const;
    
};
