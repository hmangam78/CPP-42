#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    printSeparator(void)
{
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int main(void)
{
    Bureaucrat				admin = Bureaucrat("Felipe", 20);
    Bureaucrat				admin2 = Bureaucrat("Miguel", 2);
    PresidentialPardonForm	form1 = PresidentialPardonForm("Andreas");
	RobotomyRequestForm		form2 = RobotomyRequestForm("Bender");
	ShrubberyCreationForm	form3 = ShrubberyCreationForm("Park");

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	printSeparator();
	std::cout << admin << std::endl;
	std::cout << admin2 << std::endl;
	printSeparator();

    admin.executeForm(form1);
	printSeparator();
    admin.signForm(form1);
	printSeparator();
    admin.executeForm(form1);
	printSeparator();
    admin2.executeForm(form1);
	printSeparator();
	admin.signForm(form2);
	admin2.executeForm(form2);
	printSeparator();
	admin.signForm(form3);
	admin2.executeForm(form3);
	printSeparator();
       
    return (0);
}