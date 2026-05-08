# Library Management System Project in C++

## Project Title

**Library Management System using C++**

---

# Project Overview

This project is a console-based Library Management System developed using C++ and Object Oriented Programming concepts. The system allows users to add books, DVDs, and magazines, display item details, check out items, and return items.

The project demonstrates real-world library operations using concepts like inheritance, abstraction, polymorphism, exception handling, constructors, and dynamic memory allocation.

---

# Features

* Add Book
* Add DVD
* Add Magazine
* Display All Library Items
* Check Out Items
* Return Items
* Exception Handling
* Menu Driven System

---

# OOP Concepts Used

## 1. Class and Object

Used to create different library items.

## 2. Inheritance

* Book inherits LibraryItem
* DVD inherits LibraryItem
* Magazine inherits LibraryItem

## 3. Polymorphism

Used virtual functions and function overriding.

## 4. Abstraction

Implemented using pure virtual functions.

## 5. Encapsulation

Private data members with getter and setter functions.

## 6. Exception Handling

Used try-catch blocks for validation.

## 7. Dynamic Memory Allocation

Used `new` and `delete` operators.

---

# Classes Used

## LibraryItem

Base abstract class for all library items.

### Functions

* checkOut()
* returnItem()
* displayDetails()
* Getter and Setter Functions

---

## Book

Derived class for book items.

### Features

* Stores total pages
* Displays book details

---

## DVD

Derived class for DVD items.

### Features

* Stores duration in minutes
* Displays DVD details

---

## Magazine

Derived class for magazine items.

### Features

* Stores issue number
* Displays magazine details

---

# Menu Options

1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit

---

# Sample Output

```text
========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter Choice: 1

Book Added Successfully!
```

---

# Advantages of Project

* Easy to understand
* Uses real-world library management logic
* Good practice for OOP concepts
* Beginner-friendly project
* Includes exception handling

---

# Requirements

* C++ Compiler
* OnlineGDB / VS Code / CodeBlocks

---

# Online GDB Link

https://onlinegdb.com/-dAm5mbXa
---




# Conclusion

The Library Management System project was implemented successfully using C++ Object Oriented Programming concepts. The project helps in understanding inheritance, abstraction, polymorphism, encapsulation, exception handling, and real-world library operations.
