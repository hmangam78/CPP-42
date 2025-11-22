#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;
        Form& operator=(const Form& other);
        static int          checkGrade(int grade);
    
    public:
    /*constructors and destructor*/
        Form(void);
        Form(const std::string _name, const int _signGrade, const int _execGrade);
        Form(const Form& other);
        ~Form(void);

    /*getters and setters*/
        std::string getFormName(void) const;
        bool        isSigned(void) const;
        int         getSignGrade(void) const;
        int         getExecGrade(void) const;
        void        beSigned(const Bureaucrat& bur);
    
    /*exceptions*/
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

/* << operator overload */
std::ostream& operator<<(std::ostream& os, const Form& obj);