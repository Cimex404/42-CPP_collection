/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:42:02 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/10 07:57:24 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\t---\tCorrect Animal test\t---\n" << std::endl;
	{
		const Animal	*a = new Animal();
		const Animal	*d = new Dog();
		const Animal	*c = new Cat();

		std::cout << "I am an " << a->getType() << std::endl;
		a->makeSound();
		std::cout << "I am a " << d->getType() << std::endl;
		d->makeSound();
		std::cout << "I am a " << c->getType() << std::endl;
		c->makeSound();

		delete a;
		delete d;
		delete c;
	}

	std::cout << "\n\t---\tWrong Animal test\t---\n" << std::endl;
	{
		const WrongAnimal	*a = new WrongAnimal();
		const WrongAnimal	*c = new WrongCat();
		const WrongCat		*b = new WrongCat();

		std::cout << "I am a " << a->getType() << std::endl;
		a->makeSound();
		std::cout << "I am a " << c->getType() << std::endl;
		c->makeSound();
		std::cout << "I am a " << b->getType() << std::endl;
		b->makeSound();

		delete a;
		delete c;
		delete b;
	}

	std::cout << "\n\t---\tMixed Animal test\t---\n" << std::endl;
	{
		const Animal	*a = new Animal();
		const Animal	*c = new Cat();
		const Animal	*d = new Dog();
		const WrongAnimal	*wa = new WrongAnimal();
		const WrongAnimal	*wc = new WrongCat();

		std::cout << "I am a " << a->getType() << std::endl;
		a->makeSound();
		std::cout << "I am a " << c->getType() << std::endl;
		c->makeSound();
		std::cout << "I am a " << d->getType() << std::endl;
		d->makeSound();
		std::cout << "I am a " << wa->getType() << std::endl;
		wa->makeSound();
		std::cout << "I am a " << wc->getType() << std::endl;
		wc->makeSound();

		delete a;
		delete c;
		delete d;
		delete wa;
		delete wc;
	}
	return (0);
}