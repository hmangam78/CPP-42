#include "Form.hpp"
#include "Bureaucrat.hpp"

/*Default constructor*/
Form::Form(void) : _name("Unknown form"), _signed(false), _signGrade(1), _execGrade(1)
{
	if (SHOWALL)
		std::cout << "Default form constructor called" << std::endl;
}

/*Parametric constructor*/
Form::Form(const std::string name, const int signGrade, const int execGrade) :
    _name(name),
	_signed(false),
	_signGrade(checkGrade(signGrade)),
	_execGrade(checkGrade(execGrade)) 
{
	if (SHOWALL)
		std::cout << "Form constructor called" << std::endl;
}

/*Copy constructor*/
Form::Form(const Form& other) :
	_name(other._name),
	_signed(false),
	_signGrade(checkGrade(other._signGrade)),
	_execGrade(checkGrade(other._execGrade))
{
	if (SHOWALL)
		std::cout << "Copy Form constructor called" << std::endl;
}

/*Destructor*/
Form::~Form(void)
{
	if (SHOWALL)
		std::cout << "Form destructor called" << std::endl;
}

/* Checks grade before assignment and throws exception if out of range */
int Form::checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;
}

/* Form name getter */
std::string	Form::getFormName(void) const
{
	return _name;
}

/* Checks if the form is signed */
bool	Form::isSigned(void) const
{
	return _signed;
}

/* Returns the grade needed for signing */
int		Form::getSignGrade(void) const
{
	return _signGrade;
}

/* Returns the grade needed for execution */
int		Form::getExecGrade(void) const
{
	return _execGrade;
}

/* Signs a form if the Bureaucrat has the rights, exception otherwise */
void	Form::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

/* << operator overloader*/
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	std::string	is_signed;

	if (obj.isSigned())
		is_signed = "is signed.";
	else
		is_signed = "is unsigned.";
	return os << "Form " << obj.getFormName() << ">> execution grade needed: "
			  << obj.getExecGrade() << ". Sign grade needed: "
			  << obj.getSignGrade() << ", " << is_signed;
}

/* Too high exception */
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form: grade too high");
}

/* Too low exception */
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form: grade too low");
}
