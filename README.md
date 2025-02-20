#	CPP 42

These is a collection of the cpp modules of the 42 common core. The cpp modules show the basics of the C++ language and how it differs from C, the langue, most 42 students are most familiar with at this point.

##	CPP Module 00
###	Megaphone
This is a simple program that replicates the **toupper** function in c. It takes an input string and turns all lowercase letters into upercase letters. It also outputs: "* LOUD AND UNBEARABLE FEEDBACK NOISE *", when no input is given.

###	Phonebook
This one is a little more complex. This is out introduction to classes, this program uses two: **PhoneBook** and **Contacts**. The user can input one of three commands, **ADD**, **SEARCH** and **EXIT**.
-	**EXIT**:	Is exactly as it sounds. It exits the program.
-	**ADD**:	Adds a contact to an array that holds a total of 8 contacts. When a 9th contact is added, the oldest one is overwritten.
-	**SEARCH**:	Lists all contacts in a table, with a maximum width of 10 characters per column. Additionally, the user can enter an index afterwards that displays all information of the contact with the provided index.

###	Account Log
This is more like a puzzle to figure out, that anything else. You are provided with the **Account.hpp**, the **tests.cpp** and the **.log** file. Your task is to create a **Account.cpp** file that can reproduce the behaviour of the **.log** file

##	CPP Module 01
###	BraiiiiiiinnnzzzZ
This is an introduction to the differences between a heap allocated and stack class. This program will simply create two Zombie objects, one allocated and one on the stack. They will announce themselves, and call their destructor, when they are no longer needed.

###	Moar BraiiiiiiinnnzzzZ
This builds on the previous task. You need to allocate N number of zombies that announce themselves and get destroyed after.

###	PtrRef
This task is a little different and shows the functionality of References and Pointers. You need three variables **str**, **strPTR**, **strREF**.
-	**str**:	Is a simple string.
-	**strPtr**:	Is a pointer to **str**.
-	**strRef**:	Is a reference to **str**.
Now you need to print the address and value of each of those variables.

###	Unnecessary violence
Here we have three classes: **Weapon**, **HumanA**, **HumanB**. **HumanA** gets a weapon in it's constructor, while **HumanB** does not get a weapon as long as there is not one asigned to it. The humans can then call the attack function to print their type of weapon.

###	Replacement
This one has a very simple concept. We give the program a file to read from and two strings. Another file is then created, and the entirety of the original file is written into the new file. However all instances of string1 are replaced by string2. The new file is called the same as the original, but with a **.replace** sufix.

###	Harl
This is an exercise focused on functions as parameters. This task needs to be accomplished without an if-else tree (Even though that might be less confusing).
Harl likes to complain, he has 4 Levels of complain-ness. Each of those levels is correspondant to a private function in the Harl class and this function will be called if one of those four keywords is given to Harls complain function: **DEBUG**, **INFO**, **WARNING**, **ERROR**.

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