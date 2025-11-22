/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:37:01 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/29 17:07:39 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printSeparator(const std::string& title) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void printStatus(const ClapTrap& clap) {
	std::cout << "[" << clap.getName() << "] HP: " << clap.getHitPoints() 
			  << " | Energy: " << clap.getEnergyPoints() 
			  << " | Attack: " << clap.getAttackDamage() << std::endl;
}

int	main(void)
{
	printSeparator("CONSTRUCTOR TESTS");
	
	// Test constructors
	std::cout << "\n1. Default constructor:" << std::endl;
	ClapTrap defaultClap;
	printStatus(defaultClap);
	
	std::cout << "\n2. Parameterized constructor:" << std::endl;
	ClapTrap mike("Mike");
	ClapTrap jack("Jack");
	printStatus(mike);
	printStatus(jack);
	
	std::cout << "\n3. Copy constructor:" << std::endl;
	ClapTrap mikeCopy(mike);
	printStatus(mikeCopy);
	
	printSeparator("ASSIGNMENT OPERATOR TEST");
	
	std::cout << "\n4. Assignment operator:" << std::endl;
	ClapTrap assigned;
	std::cout << "Before assignment:" << std::endl;
	printStatus(assigned);
	assigned = jack;
	std::cout << "After assignment (= jack):" << std::endl;
	printStatus(assigned);
	
	printSeparator("ATTACK FUNCTIONALITY TESTS");
	
	std::cout << "\n5. Normal attacks:" << std::endl;
	printStatus(mike);
	mike.attack("Jack");
	mike.attack("Enemy1");
	mike.attack("Enemy2");
	printStatus(mike);
	
	std::cout << "\n6. Attack until energy depleted:" << std::endl;
	mike.attack("Target1");
	mike.attack("Target2");
	mike.attack("Target3");
	mike.attack("Target4");
	mike.attack("Target5");
	mike.attack("Target6");
	mike.attack("Target7");
	mike.attack("Target8");
	printStatus(mike);
	
	std::cout << "\n7. Attack with no energy left:" << std::endl;
	mike.attack("ShouldFail");
	printStatus(mike);
	
	printSeparator("DAMAGE AND REPAIR TESTS");
	
	std::cout << "\n8. Taking damage:" << std::endl;
	printStatus(jack);
	jack.takeDamage(3);
	printStatus(jack);
	jack.takeDamage(5);
	printStatus(jack);
	
	std::cout << "\n9. Repairing:" << std::endl;
	jack.beRepaired(2);
	printStatus(jack);
	jack.beRepaired(3);
	printStatus(jack);
	
	std::cout << "\n10. Repair with no energy:" << std::endl;
	std::cout << "Current energy before depleting: " << jack.getEnergyPoints() << std::endl;
	// Agotamos la energía restante de jack (ya gastó 2 en reparaciones)
	jack.attack("Target1");
	jack.attack("Target2");
	jack.attack("Target3");
	jack.attack("Target4");
	jack.attack("Target5");
	jack.attack("Target6");
	jack.attack("Target7");
	jack.attack("Target8");
	std::cout << "After depleting attacks:" << std::endl;
	printStatus(jack);
	jack.beRepaired(5); // Debería fallar
	std::cout << "After failed repair attempt:" << std::endl;
	printStatus(jack);
	
	printSeparator("EDGE CASES");
	
	std::cout << "\n11. Excessive damage (more than HP):" << std::endl;
	ClapTrap victim("Victim");
	printStatus(victim);
	victim.takeDamage(999);
	printStatus(victim);
	victim.attack("ShouldFail"); // Debería fallar (HP = 0)
	victim.beRepaired(5); // Debería fallar (HP = 0)
	
	std::cout << "\n12. Self-assignment test:" << std::endl;
	ClapTrap selfTest("SelfTest");
	printStatus(selfTest);
	selfTest = selfTest; // Auto-asignación
	printStatus(selfTest);
	
	std::cout << "\n13. Zero damage test:" << std::endl;
	ClapTrap zeroDmg("ZeroDmg");
	printStatus(zeroDmg);
	zeroDmg.takeDamage(0);
	printStatus(zeroDmg);
	
	printSeparator("SIMULATION: COMPLETE BATTLE");
	
	std::cout << "\n14. Complete battle simulation:" << std::endl;
	ClapTrap warrior1("Warrior1");
	ClapTrap warrior2("Warrior2");
	
	std::cout << "Initial status:" << std::endl;
	printStatus(warrior1);
	printStatus(warrior2);
	
	std::cout << "\nBattle begins!" << std::endl;
	warrior1.attack("Warrior2");
	warrior2.takeDamage(0); // ClapTrap attack damage is 0
	
	warrior2.attack("Warrior1");
	warrior1.takeDamage(0);
	
	// Simulamos daño real
	std::cout << "\nDirect damage simulation:" << std::endl;
	warrior1.takeDamage(6);
	warrior2.takeDamage(4);
	
	printStatus(warrior1);
	printStatus(warrior2);
	
	std::cout << "\nHealing phase:" << std::endl;
	warrior1.beRepaired(3);
	warrior2.beRepaired(2);
	
	printStatus(warrior1);
	printStatus(warrior2);
	
	printSeparator("END OF TESTS");
	std::cout << "All tests completed successfully!" << std::endl;
	
	return (0);
}