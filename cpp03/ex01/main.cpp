/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:05:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 13:05:00 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== TESTING SCAVTRAP INHERITANCE ===" << std::endl << std::endl;

    // Test 1: Constructor default
    std::cout << "--- Test 1: Default Constructor ---" << std::endl;
    ScavTrap scav1;
    std::cout << "ScavTrap stats - HP: " << scav1.getHitPoints() 
              << ", EP: " << scav1.getEnergyPoints() 
              << ", AD: " << scav1.getAttackDamage() << std::endl;
    std::cout << std::endl;

    // Test 2: Constructor with name
    std::cout << "--- Test 2: Named Constructor ---" << std::endl;
    ScavTrap scav2("Guardian");
    std::cout << "ScavTrap stats - HP: " << scav2.getHitPoints() 
              << ", EP: " << scav2.getEnergyPoints() 
              << ", AD: " << scav2.getAttackDamage() << std::endl;
    std::cout << std::endl;

    // Test 3: Copy constructor
    std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
    ScavTrap scav3(scav2);
    std::cout << "Copied ScavTrap stats - HP: " << scav3.getHitPoints() 
              << ", EP: " << scav3.getEnergyPoints() 
              << ", AD: " << scav3.getAttackDamage() << std::endl;
    std::cout << std::endl;

    // Test 4: Assignment operator
    std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
    ScavTrap scav4("Defender");
    scav1 = scav4;
    std::cout << "Assigned ScavTrap name: " << scav1.getName() << std::endl;
    std::cout << std::endl;

    // Test 5: Comparing ClapTrap vs ScavTrap values
    std::cout << "--- Test 5: ClapTrap vs ScavTrap Values ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("SuperBot");
    
    std::cout << "ClapTrap " << clap.getName() << " - HP: " << clap.getHitPoints() 
              << ", EP: " << clap.getEnergyPoints() 
              << ", AD: " << clap.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap " << scav.getName() << " - HP: " << scav.getHitPoints() 
              << ", EP: " << scav.getEnergyPoints() 
              << ", AD: " << scav.getAttackDamage() << std::endl;
    std::cout << std::endl;

    // Test 6: Inherited methods work
    std::cout << "--- Test 6: Inherited Methods ---" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(10);
    std::cout << "After damage and repair - HP: " << scav.getHitPoints() << std::endl;
    std::cout << std::endl;

    // Test 7: ScavTrap specific attack method
    std::cout << "--- Test 7: ScavTrap Attack (overridden) ---" << std::endl;
    scav.attack("Enemy");
    std::cout << "Energy after attack: " << scav.getEnergyPoints() << std::endl;
    std::cout << std::endl;

    // Test 8: GuardGate functionality
    std::cout << "--- Test 8: GuardGate Functionality ---" << std::endl;
    scav2.guardGate();
    scav1.guardGate();  // This one should be unnamed originally but was assigned
    std::cout << std::endl;

    // Test 9: Polymorphism test (ScavTrap can be used as ClapTrap)
    std::cout << "--- Test 9: Polymorphism Test ---" << std::endl;
    ClapTrap* ptr = &scav2;
    std::cout << "Polymorphic access - Name: " << ptr->getName() 
              << ", HP: " << ptr->getHitPoints() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 10: Destructors (automatic) ---" << std::endl;
    return 0;
}