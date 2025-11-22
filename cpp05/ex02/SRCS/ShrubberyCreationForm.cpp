#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* Default constructor */
ShrubberyCreationForm::ShrubberyCreationForm(void) :
    AForm("Shrubbery Creation", signGrade, execGrade), _target("GenericTarget")
{
	if (SHOWALL)
		std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

/* Parametric constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation", signGrade, execGrade), _target(target)
{
	if (SHOWALL)
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target)
{
	if (SHOWALL)
		std::cout << "ShrubberyCreation Form copy constructor called" << std::endl;
}

/* Assignment constructor */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    this->_target = other._target;
    return (*this);
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (SHOWALL)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/* Target getter */
std::string ShrubberyCreationForm::getTarget(void) const
{
    return (_target);
}

/* Form execution */
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned())
        throw UnsignedForm();
    if (executor.getGrade() > this->getExecGrade())
        throw ExecutorGradeTooLow();
    plant_tree(this->getTarget());
}

/* Tree creation execution */
void    ShrubberyCreationForm::plant_tree(const std::string& target) const
{
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    std::ifstream template_tree("tree_template");

    if (!outfile.is_open())
    {
        std::cout << "Error creating file" << std::endl;
        return ;
    }
    if (!template_tree.is_open())
    {
        std::cout << "Error opening template file" << std::endl;
        return ;
    }
    outfile << template_tree.rdbuf();
    template_tree.close();
    outfile.close();
}