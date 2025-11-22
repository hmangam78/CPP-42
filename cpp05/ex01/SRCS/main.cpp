#include "Bureaucrat.hpp"
#include "Form.hpp"

void    printSeparator(void)
{
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int main(void)
{
    Bureaucrat  admin = Bureaucrat("Felipe", 43);
    Form        form1 = Form("42", 42, 42);
    printSeparator();
    try
    {
        Form        wrongForm = Form("Wrong", 151, 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << form1 << std::endl;
    admin.signForm(form1);
    std::cout << admin << std::endl;
    printSeparator();

    try
    {
        admin.increaseGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    admin.signForm(form1);
    printSeparator();
    std::cout << form1 << std::endl;
    printSeparator();

    return (0);
}