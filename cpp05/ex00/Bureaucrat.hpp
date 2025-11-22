#pragma once

#include <iostream>
#include <exception>

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

/* << overload operator */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
