#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/* Default constructor */
PresidentialPardonForm::PresidentialPardonForm(void) :
    AForm("Presidential Pardon", signGrade, execGrade), _target("GenericTarget")
{
	if (SHOWALL)
		std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

/* Parametric constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("Presidential Pardon", signGrade, execGrade), _target(target)
{
	if (SHOWALL)
		std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

/* Copy constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other), _target(other._target)
{
	if (SHOWALL)
		std::cout << "PresidentialPardon Form copy constructor called" << std::endl;
}

/* Assignment constructor */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    this->_target = other._target;
    return (*this);
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (SHOWALL)
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/* Target getter */
std::string PresidentialPardonForm::getTarget(void) const
{
    return (_target);
}

/* Form execution */
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned())
        throw UnsignedForm();
    if (executor.getGrade() > this->getExecGrade())
        throw ExecutorGradeTooLow();
    pardon(this->getTarget());
}

/* Pardon execution */
void    PresidentialPardonForm::pardon(const std::string& target) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}