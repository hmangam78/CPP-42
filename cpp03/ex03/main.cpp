/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:05:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 17:22:27 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== TESTING DIAMONDTRAP - DIAMOND INHERITANCE ===" << std::endl << std::endl;
    
    // Test 1: Default constructor
    std::cout << "--- Test 1: DiamondTrap Default Constructor ---" << std::endl;
    DiamondTrap diamond1;
    std::cout << "DiamondTrap stats - HP: " << diamond1.getHitPoints() 
              << ", EP: " << diamond1.getEnergyPoints() 
              << ", AD: " << diamond1.getAttackDamage() << std::endl;
    diamond1.whoAmI();
    std::cout << std::endl;
    
    // Test 2: Named constructor
    std::cout << "--- Test 2: DiamondTrap Named Constructor ---" << std::endl;
    DiamondTrap diamond2("Destroyer");
    std::cout << "DiamondTrap stats - HP: " << diamond2.getHitPoints() 
              << ", EP: " << diamond2.getEnergyPoints() 
              << ", AD: " << diamond2.getAttackDamage() << std::endl;
    diamond2.whoAmI();
    std::cout << std::endl;
    
    // Test 3: Verify correct inheritance values
    std::cout << "--- Test 3: Verify Inheritance Values ---" << std::endl;
    std::cout << "Expected values:" << std::endl;
    std::cout << "  - Hit Points: 100 (from FragTrap)" << std::endl;
    std::cout << "  - Energy Points: 50 (from ScavTrap)" << std::endl;
    std::cout << "  - Attack Damage: 30 (from FragTrap)" << std::endl;
    std::cout << "Actual values:" << std::endl;
    std::cout << "  - Hit Points: " << diamond2.getHitPoints() << std::endl;
    std::cout << "  - Energy Points: " << diamond2.getEnergyPoints() << std::endl;
    std::cout << "  - Attack Damage: " << diamond2.getAttackDamage() << std::endl;
    std::cout << std::endl;
    
    // Test 4: Copy constructor
    std::cout << "--- Test 4: DiamondTrap Copy Constructor ---" << std::endl;
    DiamondTrap diamond3(diamond2);
    diamond3.whoAmI();
    std::cout << std::endl;
    
    // Test 5: Assignment operator
    std::cout << "--- Test 5: DiamondTrap Assignment Operator ---" << std::endl;
    DiamondTrap diamond4("Terminator");
    diamond1 = diamond4;
    diamond1.whoAmI();
    std::cout << std::endl;
    
    // Test 6: Attack method (should use ScavTrap's attack)
    std::cout << "--- Test 6: DiamondTrap Attack (ScavTrap version) ---" << std::endl;
    diamond2.attack("Enemy Robot");
    std::cout << "Energy after attack: " << diamond2.getEnergyPoints() << std::endl;
    std::cout << std::endl;
    
    // Test 7: Inherited special abilities
    std::cout << "--- Test 7: Inherited Special Abilities ---" << std::endl;
    diamond2.guardGate();      // From ScavTrap
    diamond2.highFivesGuys();  // From FragTrap
    std::cout << std::endl;
    
    // Test 8: Inherited basic methods
    std::cout << "--- Test 8: Inherited Basic Methods ---" << std::endl;
    diamond2.takeDamage(25);
    std::cout << "HP after damage: " << diamond2.getHitPoints() << std::endl;
    diamond2.beRepaired(15);
    std::cout << "HP after repair: " << diamond2.getHitPoints() << std::endl;
    std::cout << "Energy after repair: " << diamond2.getEnergyPoints() << std::endl;
    std::cout << std::endl;
    
    // Test 9: Demonstrate name difference
    std::cout << "--- Test 9: Name Management ---" << std::endl;
    DiamondTrap diamond5("UltraBot");
    std::cout << "DiamondTrap name: " << diamond5.getName() << std::endl;  // Should be ClapTrap name
    diamond5.whoAmI();  // Should show both names
    std::cout << std::endl;
    
    // Test 10: Polymorphism tests
    std::cout << "--- Test 10: Polymorphism Tests ---" << std::endl;
    ClapTrap* clapPtr = &diamond2;
    FragTrap* fragPtr = &diamond2;
    ScavTrap* scavPtr = &diamond2;
    
    std::cout << "As ClapTrap: " << clapPtr->getName() << std::endl;
    std::cout << "As FragTrap: " << fragPtr->getName() << std::endl;
    std::cout << "As ScavTrap: " << scavPtr->getName() << std::endl;
    std::cout << std::endl;
    
    // Test 11: Compare with base classes
    std::cout << "--- Test 11: Compare with Base Classes ---" << std::endl;
    FragTrap pureFragTrap("PureFraggy");
    ScavTrap pureScavTrap("PureScavvy");
    
    std::cout << "Pure FragTrap - HP: " << pureFragTrap.getHitPoints() 
              << ", EP: " << pureFragTrap.getEnergyPoints() 
              << ", AD: " << pureFragTrap.getAttackDamage() << std::endl;
    
    std::cout << "Pure ScavTrap - HP: " << pureScavTrap.getHitPoints() 
              << ", EP: " << pureScavTrap.getEnergyPoints() 
              << ", AD: " << pureScavTrap.getAttackDamage() << std::endl;
    
    std::cout << "DiamondTrap   - HP: " << diamond2.getHitPoints() 
              << ", EP: " << diamond2.getEnergyPoints() 
              << ", AD: " << diamond2.getAttackDamage() << std::endl;
    std::cout << std::endl;
    
    std::cout << "--- Test 12: Final whoAmI() test ---" << std::endl;
    diamond2.whoAmI();
    
    std::cout << std::endl << "--- Destructors will be called automatically ---" << std::endl;
    
    return 0;
}