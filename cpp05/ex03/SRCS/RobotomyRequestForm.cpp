#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"

/* Default constructor */
RobotomyRequestForm::RobotomyRequestForm(void) :
    AForm("Robotomy Request", signGrade, execGrade), _target("GenericTarget")
{
	if (SHOWALL)
		std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

/* Parametric constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request", signGrade, execGrade), _target(target)
{
	if (SHOWALL)
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other), _target(other._target)
{
	if (SHOWALL)
		std::cout << "RobotomyRequest Form copy constructor called" << std::endl;
}

/* Assignment constructor */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    this->_target = other._target;
    return (*this);
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (SHOWALL)
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/* Target getter */
std::string RobotomyRequestForm::getTarget(void) const
{
    return (_target);
}

/* Form execution */
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned())
        throw UnsignedForm();
    if (executor.getGrade() > this->getExecGrade())
        throw ExecutorGradeTooLow();
    drill(this->getTarget());
}

/* drill execution */
void    RobotomyRequestForm::drill(const std::string& target) const
{
    std::cout << "LOUD DRILLING NOISE" << std::endl << std::endl;
    std::cout << "EVEN LOUDER DRILLING NOISE" << std::endl << std::endl;
    srand(time(0));
    int randomNum = rand() % 101;
    if (randomNum <= 50)
        std::cout << target << " has been succesfully robotimized" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}