/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:42:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/10 08:11:57 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\t---\tSubject test\t---\n" << std::endl;
	int		animal_cnt = 4;
	Animal *animals[animal_cnt];

	for (int i = 0; i < animal_cnt; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}

	//	Delete all animals
	for (int i = 0; i < animal_cnt; i++)
		delete animals[i];
	


	std::cout << "\n\t---\tFurther tests\t---\n" << std::endl;
	{
		//Animal	cat = new Cat();
		//Animal	cat;
		Cat cat;
		cat.getBrain()->setIdea(0, "I need to sniff it...");
		cat.getBrain()->setIdea(1, "I need to eat it...");
		cat.getBrain()->setIdea(999, "I need to berak the program...");
		std::cout << cat.getBrain()->getIdea(0) << std::endl;
		std::cout << cat.getBrain()->getIdea(1) << std::endl;
		std::cout << cat.getBrain()->getIdea(88) << std::endl;
		std::cout << cat.getBrain()->getIdea(999) << std::endl;

		Dog	dog;
		dog.getBrain()->setIdea(0, "I need to sniff it...");
		dog.getBrain()->setIdea(1, "I need to pee on it...");
		dog.getBrain()->setIdea(88, "I am going to eat it anyway...");
		std::cout << dog.getBrain()->getIdea(0) << std::endl;
		std::cout << dog.getBrain()->getIdea(1) << std::endl;
		std::cout << dog.getBrain()->getIdea(88) << std::endl;
		std::cout << dog.getBrain()->getIdea(4) << std::endl;
		std::cout << dog.getBrain()->getIdea(5) << std::endl;

		Cat tac;
		tac = cat;
		tac.getBrain()->setIdea(0, "I need to sniff it...");
		tac.getBrain()->setIdea(1, "I need to eat it...");
		std::cout << tac.getBrain()->getIdea(0) << std::endl;
		std::cout << tac.getBrain()->getIdea(1) << std::endl;
		std::cout << tac.getBrain()->getIdea(88) << std::endl;

		Dog	god(dog);
		god.getBrain()->setIdea(0, "I need to sniff it...");
		god.getBrain()->setIdea(1, "I need to pee on it...");
		god.getBrain()->setIdea(88, "I am going to eat it anyway...");
		std::cout << god.getBrain()->getIdea(0) << std::endl;
		std::cout << god.getBrain()->getIdea(1) << std::endl;
		std::cout << god.getBrain()->getIdea(88) << std::endl;
		std::cout << god.getBrain()->getIdea(4) << std::endl;
		std::cout << god.getBrain()->getIdea(5) << std::endl;
	}

	std::cout << "\n\t---\tDeep copy tests\t---\n" << std::endl;
	Cat	cat;
	cat.getBrain()->setIdea(0, "Chase the laser!");
	{
		Cat a;
		a = cat;
		Cat	b(cat);
		a.getBrain()->setIdea(1, "Destroy the toilet paper!");
		b.getBrain()->setIdea(1, "Puke on the floor!");
		std::cout << a.getBrain()->getIdea(0) << std::endl;
		std::cout << b.getBrain()->getIdea(0) << std::endl;
		std::cout << a.getBrain()->getIdea(1) << std::endl;
		std::cout << b.getBrain()->getIdea(1) << std::endl;
	}
	std::cout << cat.getBrain()->getIdea(0) << std::endl;
	std::cout << cat.getBrain()->getIdea(1) << std::endl;
}