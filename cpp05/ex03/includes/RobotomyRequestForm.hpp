#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string     _target;
        void        drill(const std::string& target) const;
        static int const signGrade = 72;
        static int const execGrade = 45;

    public:
    /*constructors and destructor*/
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string& _target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    /*getter*/
        std::string getTarget(void) const;
    
    /*form manager*/
        void execute(Bureaucrat const& executor) const;
        
};
