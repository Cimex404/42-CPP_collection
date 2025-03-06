/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:04:38 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/06 14:23:08 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "\t---\tCLAP TRAP\t---\n" << std::endl;
	{
		ClapTrap	a("Cody");
		ClapTrap	b("Clover");

		a.takeDamage(5);
		b.takeDamage(5);
		a.status();
		b.status();

		a.takeDamage(7);
		b.beRepaired(12);
		a.status();
		b.status();

		a.attack("a shadow monster");
		b.attack("a shadow monster");

		a.beRepaired(7);
		b.takeDamage(12);
		a.status();
		b.status();
	}
	std::cout << "\n\n\t---\tSCAV TRAP\t---\n" << std::endl;
	{
		ScavTrap	a("Beast");
		ScavTrap	b("Savage");

		a.takeDamage(5);
		b.takeDamage(5);
		a.status();
		b.status();

		a.takeDamage(7);
		b.beRepaired(12);
		b.guardGate();
		a.status();
		b.status();

		a.attack("a robot foe");
		b.attack("a robot foe");

		a.takeDamage(999);
		a.status();
		b.status();
		
		b.guardGate();
		a.guardGate();
		b.takeDamage(12);
		a.status();
		b.status();
	}
	std::cout << "\n\n\t---\tFRAG TRAP\t---\n" << std::endl;
	{
		FragTrap a("Giga");
		FragTrap b("Chadd");

		a.highFiveGuys();
		a.attack("a civilian");
		a.takeDamage(101);
		a.status();
		a.takeDamage(1);
		a.status();
		a.attack("a civilian");
		a.highFiveGuys();
		b.highFiveGuys();
	}
	std::cout << "\n\n\t---\tDIAMOND TRAP\t---\n" << std::endl;
	{
		DiamondTrap a("Brute");
		DiamondTrap b("Zombie");

		a.status();
		a.takeDamage(13);
		a.whoAmI();
		a.attack("the innocent");
		b.whoAmI();
		b.attack("innocent bystanders");
		a.whoAmI();
		a.status();
		b.status();
	}
	return (0);
}