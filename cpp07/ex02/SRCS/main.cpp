#include <iostream>
#include "../includes/Array.hpp"

void    displaySeparator(void)
{
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

template <typename T>
void    displayArray(const Array<T>& ar)
{
    std::cout << "{";
    for (size_t i = 0; i < ar.size(); i++)
    {
        std::cout << ar[i];
        if (i < (ar.size() - 1))
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

int main(void)
{
    Array<int>          my_int_array(5);
    Array<std::string>  my_string_array(3);
    Array<int>          empty_array;

    std::cout << "Default int array" << std::endl;
    displayArray(my_int_array);
    std::cout << "Default string array" << std::endl;
    displayArray(my_string_array);

    displaySeparator();

    for (size_t i = 0; i < my_int_array.size(); i++)
        my_int_array[i] = i;
    std::cout << "Int array after assignment" << std::endl;
    displayArray(my_int_array);
    my_string_array[0] = "Hello";
    my_string_array[1] = "world";
    my_string_array[2] = "!";
    std::cout << "String array after assignment" << std::endl;
    displayArray(my_string_array);

    displaySeparator();

    std::string a_string = my_string_array[1];
    std::cout << "String at array position 1: " << a_string << std::endl;

    displaySeparator();

    std::cout << "Elements in empty array: " << empty_array.size() << std::endl;
    empty_array = my_int_array;
    std::cout << "Empty array after assigning 'my_int_array'" << std::endl;
    displayArray(empty_array);

    displaySeparator();

    std::cout << "Trying to access an element out of range" << std::endl;
    try
    {
        std::cout << my_string_array[4] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught excepction: " << e.what() << std::endl;
    }    
    return 1;
}