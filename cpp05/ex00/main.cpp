#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  admin = Bureaucrat("Antonio", 1);

    try
    {
        admin.increaseGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat intern = Bureaucrat("Miguel", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << admin << std::endl;
    return (0);
}