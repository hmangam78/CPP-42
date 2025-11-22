#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void    printSeparator(void)
{
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int main(void)
{
    Intern becario = Intern();
    AForm*  form1 = becario.makeForm("presidential pardon", "Hector");
    AForm*  form2 = becario.makeForm("robotomy request", "Bender");
    AForm*  form3 = becario.makeForm("shrubbery creation", "Park");
    AForm*  form4 = becario.makeForm("form 42", "Paperwork");

    if (form1)
        std:: cout << *form1 << std::endl;
    if (form2)
        std:: cout << *form2 << std::endl;
    if (form3)
        std:: cout << *form3 << std::endl;
    if (form4)
        std:: cout << *form4 << std::endl;
    delete form1;
    delete form2;
    delete form3;
    delete form4;
    return (0);
}