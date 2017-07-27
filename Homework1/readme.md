

# Homework 1

In this assignment, you will write a class that implements a contact book
entry. For example, my iPhone (and pretty much any smartphone) has a contacts
list app that allows you to store information about your friends, colleagues, and
businesses. In later assignments, you will have to implement this type of app (as a
command line program, of course.) For now, you will just have to implement the
building blocks for this app, namely, the Contact class. 

Your Contact class should have the following private data:
* The first name of the person
* The last name of the person
* The phone number of the person
* The street address of the person
* The city of the person
* The state of the person

Of course, you may implement private helper functions if it helps your implementation.
Your class should have the following public functions:
* A constructor that initializes all the fields with information.
* A constructor that initializes only the name and phone number.
* A default constructor that initializes the data to some programmer specified values. 

(Namely, you are free to initialize these variables to anything you choose
to be default, but it must make sense and not be totally arbitrary.)
(if you want to get fancy, you can use default arguments and write all 3 of the	above as only 1 constructor.)
* accessor (get) functions for all of the data members.
* an update function that allows the user to change all information. (They mustchange all of it). 

The following overloaded operators:
* an == operator that compares 2 contacts, and returns true if the last name and first name both match and false otherwise.
* a < operator that returns true if the first contact’s last name is lexicographically
before the second one and false otherwise. In other words, you return true if the
first contact would be listed before the second one in alphabetical order. If the last
names are the same, use the first name to break ties.
*Do the same thing for != and >.
* A stream insertion (<<) operator that prints out a contact in the following form:

` <First name> <last name> Phone number: <phone number> `

` <street address> `

` <city> , <state> `


For example my contact info would print out:

`Ari Mermelstein Phone number: (718) 111-1111`
`2900 Bedford Avenue`
`Brooklyn, NY`
`

You must also write a main program called useContact.cpp that tests each of
these functions and shows me that you understand how to use the Contact
class in a program.

## What to submit:
1. your Contact.h file.
2. your Contact.cpp file
3. your useContact.cpp file. 
