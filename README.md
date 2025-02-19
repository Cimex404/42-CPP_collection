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
