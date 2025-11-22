#include "Bureaucrat.hpp"
#include "Form.hpp"

/* Default constructor */
Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(150)
{
	if (SHOWALL)
		std::cout << "Default Bureaucrat constructor called" << std::endl;
}

/* Parametric constructor */
Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
	
    if (SHOWALL)
		std::cout << "Parametrized constructor called" << std::endl;
}

/* Copy constructor */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	if (SHOWALL)
		std::cout << "Copy constructor called" << std::endl;
}

/* Assignment constructor */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Assignment constructor called" << std::endl;
    this->_grade = other._grade;
    return (*this);
}

/* Destructor */
Bureaucrat::~Bureaucrat(void)
{
	if (SHOWALL)
		std::cout << "Bureaucrat destructor called" << std::endl;
}

/* Grade getter */
int    Bureaucrat::getGrade(void) const
{
    return (_grade);
}

/* Name getter */
std::string Bureaucrat::getName(void) const
{
    return(_name);
}

/* Grade increaser */
void    Bureaucrat::increaseGrade(void)
{
    std::cout << "Trying to increase grade for bureaucrat: " << _name << std::endl;
    if (_grade == 1)
        throw GradeTooHighException();
    else
    {
        _grade--;
        std::cout << _name << "'s new grade is " << _grade << std::endl;
    }
}

/* Grade decreaser */
void    Bureaucrat::decreaseGrade(void)
{
    std::cout << "Trying to decrease grade for bureaucrat: " << _name << std::endl;
    if (_grade == 150)
        throw GradeTooLowException();
    else
    {
        _grade++;
        std::cout << _name << "'s new grade is " << _grade << std::endl;
    }
}

/* Too high exception */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Attempted to instantiate with a too high grade");
}

/* Too low exception */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Attempted to instantiate with a too low grade");
}

/* << overload */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    return os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
}

/* If the Bureaucrat has the rights, signs a Form. Exception otherwise */
void    Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << "Excepcion caught: " << e.what() << std::endl;
        std::cout << getName() << " couldn't sign form " << form.getFormName()
                  << " because their grade is not high enough" << std::endl;
        return ;
    }
    std::cout << "Bureaucrat " << getName() << " signed form "
              << form.getFormName() << std::endl;
}