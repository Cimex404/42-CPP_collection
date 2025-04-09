#	CPP Collection 42

These is a collection of the cpp modules of the 42 common core. The cpp modules show the basics of the C++ language and how it differs from C, the langue, most 42 students are most familiar with at this point.

#	CPP Module 00
###	Megaphone
This is a simple program that replicates the `toupper` function in c. It takes an input string and turns all lowercase letters into upercase letters. It also outputs: "* LOUD AND UNBEARABLE FEEDBACK NOISE *", when no input is given.

###	Phonebook
This one is a little more complex. This is out introduction to classes, this program uses two: `PhoneBook` and `Contacts`. The user can input one of three commands, `ADD`, `SEARCH` and `EXIT`.
-	`EXIT`:	Is exactly as it sounds. It exits the program.
-	`ADD`:	Adds a contact to an array that holds a total of 8 contacts. When a 9th contact is added, the oldest one is overwritten.
-	`SEARCH`:	Lists all contacts in a table, with a maximum width of 10 characters per column. Additionally, the user can enter an index afterwards that displays all information of the contact with the provided index.

###	Account Log
This is more like a puzzle to figure out, that anything else. You are provided with the `Account.hpp`, the `tests.cpp` and the `.log` file. Your task is to create a `Account.cpp` file that can reproduce the behaviour of the `.log` file

#	CPP Module 01
###	BraiiiiiiinnnzzzZ
This is an introduction to the differences between a heap allocated and stack class. This program will simply create two Zombie objects, one allocated and one on the stack. They will announce themselves, and call their destructor, when they are no longer needed.

###	Moar BraiiiiiiinnnzzzZ
This builds on the previous task. You need to allocate N number of zombies that announce themselves and get destroyed after.

###	PtrRef
This task is a little different and shows the functionality of References and Pointers. You need three variables `str`, `strPTR`, `strREF`.
-	`str`:	Is a simple string.
-	`strPtr`:	Is a pointer to `str`.
-	`strRef`:	Is a reference to `str`.

Now you need to print the address and value of each of those variables.

###	Unnecessary violence
Here we have three classes: `Weapon`, `HumanA`, `HumanB`. `HumanA` gets a weapon in it's constructor, while `HumanB` does not get a weapon as long as there is not one asigned to it. The humans can then call the attack function to print their type of weapon.

###	Replacement
This one has a very simple concept. We give the program a file to read from and two strings. Another file is then created, and the entirety of the original file is written into the new file. However all instances of string1 are replaced by string2. The new file is called the same as the original, but with a `.replace` sufix.

###	Harl
This is an exercise focused on functions as parameters. This task needs to be accomplished without an if-else tree (Even though that might be less confusing).
Harl likes to complain, he has 4 Levels of complain-ness. Each of those levels is correspondant to a private function in the Harl class and this function will be called if one of those four keywords is given to Harls complain function: `DEBUG`, `INFO`, `WARNING`, `ERROR`.

###	Harl Filter
This is the same task as the previous one, but for all levels entered, the corresponding level, as well as all levels above it are printed.

<p>
	Example:
</p>

```bash
	./harlFilter WARNING
	[WARNING]
	[ERROR]

	./harlFilter DEBUG
	[DEBUG]
	[INFO]
	[WARNING]
	[ERROR]
```

#	CPP Module 02
###	Fixed Numbers
The entire CPP02 Module is about fixed numbers. We are creating our own data type called `Fixed` as a class. The class is written in the `Orthodox canonical` form. This means the class must contain:
-	A default constructor. (Sets the required values to a default value, in this case 0)
-	A default copy constructor. (Takes an already existing object of the class to get the values from)
-	A copy assingment operator. (Overrides the = assignment with a constructor that takes the values from an already existing object of the same class)
-	A destructor.

All tasks build upon each other so that at the end we have a fully functionning class, that can be used as most any other data type.
We add the comparison operators `==, !=, <, >, <=, >=`, then the arithmetic operators `+, -, *, /`, next the inc/-decrement operators `i++, ++i, i--, --i`, and lastly, two methods for the equivalent of `max` and `min` to fit our data type.


###	Barycentric Coordinates Method
The last task of this module is a little different and requires us to utilize the Fixed numbers we just created in a practical task. 
We need to create a class called `Point`, this class holds two variables `x` and `y`. If we create three of those, we have a triangle. Our task is to write a program that can determine whether the point `p` is inside or outside of the triangle.

![Barycentric Triangle](https://github.com/Cimex404/42-CPP_collection/blob/master/barycentric_triangle.png)

<p>
When we draw a triangle between these points: Pab, Pac, Pbc we can get their area. If these three areas add up to exactly the size of the abc triangle, then P is inside the triangle.
</p>

#	CPP Module 03
###	ClapTrap
This is a simple task of creating a class called `ClapTrap`, this class has following attributes: `name`, `hit_points`, `attack_points`, `energy_points`. It also has these public methods: `attack`, `takeDamage`, `beRepaired`. ClapTrap can't attack and heal, when hit_points or energy_points are at 0. The default constructor must take a name and sets the default values for `hit_points`, `attack_points` and `energy_points`.

###	ScavTrap
This is the introduction to inheritance. The class `ScavTrap` is a child of the `ClapTrap` class, therefore the `ScavTrap` does only need a separate name and attack functions, as we want to be able to see, wheter a `ClapTrap` or a `ScavTrap` is attacking. This will also be true for all following classes. The `ScavTrap` will also have a new method called `guardGate`, calling this function will toggle the guardkeeping mode.

###	FragTrap
This is essentially the same the `ScavTrap`, but with a different special method: `giveHighfive`. This method will simply print a positive high-five message to the stdout.

###	Diamond Trap (Now this is tricky)
This is a double inheritance. Basically, the `DiamondTrap` is a child of both `ScavTrap` and `FragTrap`. It inherits the values of `hit_points` and `attack_points` from `FragTrap` and `energy_points` and the `attack` method from ScavTrap. In addition, the `DiamondTrap` must have a separate name from its `ClapTrap` grandfather, namely, the grandfather must have a `_clap_name` suffix as it's name. Lastly, the `DiamondTrap` must be able to use all methods, such as `attack`, `highFive` and `guardGate`. But also it's own special method called `whoAmI`, which prints its own name, but also the grandfather `ClapTrap` name. (That was a lot of `Traps`...)

#	CPP Module 04
###	Animals and Wrong Animals
This is an implementation of the most common example for polymorphism in c++. We have an animal class that has a public method called `makeSound()`, this will print a generic animal sound. In addition to that, there are `Cat` and `Dog` classes that inherit from `Animal` and override the `makeSound()` method to print the corresponding animals sound.
Lastly there are `WrongAnimal` and `WrongCat`. To confirm that we understood what we are doing, `WrongCat` should print the `WrongAnimal` sound, when instantiated as a WrongAnimal. Essentially to prove, that we can also do it wrong.

###	Animals have brains
Now we need to add a `Brain` class to the project and give each `Dog` and `Cat` a private Brain instance. We can assign a total of 100 ideas to each brain and have the owner of said brain display the contents at any time. We also need to make sure that the `Copy constructor` and `Copy assignment operator` create deep copies of the animals brain. This means that a copied Brain will contain the same ideas as the original, but be entirely indepented off the original.

###	Brainless task
<p>
	Turn `Animal` into an abstract class:
</p>

<table>
	<tr>
		<td style="border: none;"><img src="https://github.com/Cimex404/42-CPP_collection/blob/master/AnimalNonAbstact.png" alt="NonAbstract" width="400"></td>
    		<td style="border: none;"><img src="https://github.com/Cimex404/42-CPP_collection/blob/master/AnimalAbstact.png" alt="Abstract" width="400"></td>
	</tr>
</table>

<p>
	That's it...
</p>


#	CPP Module 05
###	Bureaucrats
This is an exercise on `Exceptions`. `Exceptions` are cases in which the program fails a specific task, but can be caught using a try-catch block. The Bureaucrats are assigned a grade between 1 (highest) and 150 (lowest). When a `Bureaucrat` is instantiated using a grade that is out of this range a `GradeTooLow` or `GradeTooLow` exception is thrown. This can be caught with a catch block. Same goes for the increase and decrease methods.

###	Form
This introduces `Forms`, forms are created with a sign- and execute-grade and only Bureaucrats with the same or higher grade than that of the form can sign a form. A form can also not be signed twice.

###	Forms that actually do something
Here we create children of the Form class:
-	`ShrubberyCreation`: Creates a file that draws an ascii-art tree.
-	`RobotomyRequest`: Performs a robotomization of a target that is successfull 50% of the time.
-	`PresidentialPardon`: A target recieves a pardon from the president

###	Interns
Now we have `Interns`. Interns are pretty useless, but they have one ability: They can create forms for Bureaucrat to sign. If the form that needs to be signed does not exist, the intern will fail to create one.


#	CPP Module 06
###	Scalar Converter
This is an exercise about `static_cast`. The program takes an input of a string and figures out which of these data type the input is supposed to be: `char`, `int`, `float`, `double`.
Next, the input is converted into it's real data type and lastly converted into the remaining three data types.<br><br>

```
./converter 42
Type:	INT

Char:	'*'
Int:	42
Float:	42.0f
Double:	42.0
```


###	Serializer
This time we need to convert a custom `Data` struct to a `uintptr_t` using `interpret_cast`.

###	Identifyier
This is about identifying specific data types. We have a `Base` class and three classes that inherit from it: `A`, `B`, `C`. These subclasses are created randomly on runtime and the program will need to identify which of these three it is. We do this by trying if conversions were successfull or not.


#	CPP Module 07
###	Just a few functions
This is a simple introduction to `templates`. You need to write templates for the following functions:<br>
-	min
-	max
-	swap
These templates need to be able to take and use any type you give it, even complex types like classes and structs.


###	Iter
This is a `template` that takes an `array of any type` and a `function of any type` and iterates through each element in the array while performing the function with the element as a parameter.


###	Array
Simply recreate the behaviour of an array through a `template array class` that can hold any data type (even complex ones).