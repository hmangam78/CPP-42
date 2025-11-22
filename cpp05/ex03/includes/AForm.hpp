#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;
        AForm& operator=(const AForm& other);
        static int          checkGrade(int grade);
    
    public:
    /*constructors and destructor*/
        AForm(void);
        AForm(const std::string& name, const int signGrade, const int execGrade);
        AForm(const AForm& other);
        virtual ~AForm(void);

    /*getters and setters*/
        std::string		getFormName(void) const;
        bool			isSigned(void) const;
        int				getSignGrade(void) const;
        int				getExecGrade(void) const;
        void        	beSigned(const Bureaucrat& bur);
        virtual void    execute(Bureaucrat const& executor) const = 0;

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
        class UnsignedForm : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class ExecutorGradeTooLow : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

/* << operator overload */
std::ostream& operator<<(std::ostream& os, const AForm& obj);