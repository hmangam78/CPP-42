/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:05:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 15:21:07 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== TESTING FRAGTRAP INHERITANCE ===" << std::endl << std::endl;
    
    // Test 1: Default constructor
    std::cout << "--- Test 1: Default Constructor ---" << std::endl;
    FragTrap frag1;
    std::cout << "FragTrap stats - HP: " << frag1.getHitPoints() 
              << ", EP: " << frag1.getEnergyPoints() 
              << ", AD: " << frag1.getAttackDamage() << std::endl;
    std::cout << std::endl;
    
    // Test 2: Named constructor
    std::cout << "--- Test 2: Named Constructor ---" << std::endl;
    FragTrap frag2("Bomber");
    std::cout << "FragTrap stats - HP: " << frag2.getHitPoints() 
              << ", EP: " << frag2.getEnergyPoints() 
              << ", AD: " << frag2.getAttackDamage() << std::endl;
    std::cout << std::endl;
    
    // Test 3: Copy constructor
    std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
    FragTrap frag3(frag2);
    std::cout << "Copied FragTrap stats - HP: " << frag3.getHitPoints() 
              << ", EP: " << frag3.getEnergyPoints() 
              << ", AD: " << frag3.getAttackDamage() << std::endl;
    std::cout << std::endl;
    
    // Test 4: Assignment operator
    std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
    FragTrap frag4("Destroyer");
    frag1 = frag4;
    std::cout << "Assigned FragTrap name: " << frag1.getName() << std::endl;
    std::cout << std::endl;
    
    // Test 5: Comparing ClapTrap vs FragTrap values
    std::cout << "--- Test 5: ClapTrap vs FragTrap Values ---" << std::endl;
    ClapTrap clap("BasicBot");
    FragTrap frag("SuperBot");
    
    std::cout << "ClapTrap " << clap.getName() << " - HP: " << clap.getHitPoints() 
              << ", EP: " << clap.getEnergyPoints() 
              << ", AD: " << clap.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap " << frag.getName() << " - HP: " << frag.getHitPoints() 
              << ", EP: " << frag.getEnergyPoints() 
              << ", AD: " << frag.getAttackDamage() << std::endl;
    std::cout << std::endl;

    // Test 6: Inherited methods
    std::cout << "--- Test 6: Inherited Methods ---" << std::endl;
    frag.takeDamage(30);
    frag.beRepaired(10);
    std::cout << "After damage and repair - HP: " << frag.getHitPoints() << std::endl;
    std::cout << std::endl;

    // Test 7: FragTrap attack method
    std::cout << "--- Test 7: FragTrap Attack ---" << std::endl;
    frag.attack("Enemy");
    std::cout << "Energy after attack: " << frag.getEnergyPoints() << std::endl;
    std::cout << std::endl;

    // Test 8: High Five functionality
    std::cout << "--- Test 8: High Five Functionality ---" << std::endl;
    frag2.highFivesGuys();
    frag1.highFivesGuys();
    std::cout << std::endl;

    // Test 9: Polymorphism test (FragTrap can be used as ClapTrap)
    std::cout << "--- Test 9: Polymorphism Test ---" << std::endl;
    ClapTrap* ptr = &frag2;
    std::cout << "Polymorphic access - Name: " << ptr->getName() 
              << ", HP: " << ptr->getHitPoints() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 10: Destructors (automatic) ---" << std::endl;
    
    return 0;
}