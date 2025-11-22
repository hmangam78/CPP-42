#pragma once

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
	/*constructors and destructor*/
		Bureaucrat(void);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

	/*getters and grade managers*/
		int			getGrade(void) const;
		std::string	getName(void) const;
		void		increaseGrade(void);
		void		decreaseGrade(void);

	/*form managers*/
		void		executeForm(AForm const & form) const;
		void		signForm(AForm& form);
	
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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
