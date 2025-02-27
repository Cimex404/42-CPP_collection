#	CPP Collection 42

These is a collection of the cpp modules of the 42 common core. The cpp modules show the basics of the C++ language and how it differs from C, the langue, most 42 students are most familiar with at this point.

#	CPP Module 00
###	Megaphone
This is a simple program that replicates the **toupper** function in c. It takes an input string and turns all lowercase letters into upercase letters. It also outputs: "* LOUD AND UNBEARABLE FEEDBACK NOISE *", when no input is given.

###	Phonebook
This one is a little more complex. This is out introduction to classes, this program uses two: **PhoneBook** and **Contacts**. The user can input one of three commands, **ADD**, **SEARCH** and **EXIT**.
-	**EXIT**:	Is exactly as it sounds. It exits the program.
-	**ADD**:	Adds a contact to an array that holds a total of 8 contacts. When a 9th contact is added, the oldest one is overwritten.
-	**SEARCH**:	Lists all contacts in a table, with a maximum width of 10 characters per column. Additionally, the user can enter an index afterwards that displays all information of the contact with the provided index.

###	Account Log
This is more like a puzzle to figure out, that anything else. You are provided with the **Account.hpp**, the **tests.cpp** and the **.log** file. Your task is to create a **Account.cpp** file that can reproduce the behaviour of the **.log** file

#	CPP Module 01
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
