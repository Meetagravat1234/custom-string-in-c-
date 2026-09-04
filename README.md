# Custom String Implementation Using C++

## Project Overview

This project implements a custom `String` class in C++ without using the standard `std::string` class.

The string data is stored using a dynamically allocated character array. The project demonstrates how common string operations work internally and provides implementations for constructors, destructors, operator overloading, comparison operations, and various string manipulation functions.

The main purpose of this project is to understand **dynamic memory allocation, pointers, deep copying, friend functions, and operator overloading in C++**.

## Features

### String Class

The custom `String` class supports:

* Default Constructor
* Parameterized Constructor
* Copy Constructor
* Destructor
* Assignment Operator `=`
* Addition Operator `+`
* Subscript Operator `[]`
* Stream Insertion Operator `<<`
* Stream Extraction Operator `>>`

### Comparison Operators

The following comparison operators are implemented:

```text
>
<
>=
<=
==
!=
```

### Custom String Functions

The project also implements the following functions as friend functions:

```text
strcpy()
strncpy()
strcmp()
strncmp()
strcat()
strncat()
strrev()
strupr()
strlwr()
strchr()
strrchr()
strstr()
strlen()
```

These functions operate directly on objects of the custom `String` class.

## Concepts Used

This project covers the following C++ concepts:

* Classes and Objects
* Constructors
* Copy Constructor
* Destructor
* Dynamic Memory Allocation
* Character Arrays
* Pointers
* Deep Copy
* Operator Overloading
* Friend Functions
* Friend Operators
* String Manipulation
* Memory Management

## Dynamic Memory Allocation

The string is stored using a dynamically allocated character array instead of a fixed-size array.

Memory is allocated when a string object is created and released when the object is destroyed.

The project also uses deep copying so that different objects have their own separate memory.

For example:

```cpp
String s1("Hello");
String s2 = s1;
```

Here, `s2` gets its own copy of the string data instead of sharing the same memory with `s1`.

## Operator Overloading

Several operators are overloaded to make the custom class work similar to a normal string.

### Concatenation

```cpp
String s1("Hello");
String s2("World");

String s3 = s1 + s2;
```

### Character Access

```cpp
cout << s1[0];
```

### Comparison

```cpp
if(s1 == s2)
{
    cout << "Strings are equal";
}
```

### Stream Operators

The `<<` operator is used to display a `String` object and the `>>` operator is used to take string input.

```cpp
cin >> s1;
cout << s1;
```

## Deep Copy

Deep copying is implemented in:

* Copy Constructor
* Assignment Operator

This prevents multiple objects from pointing to the same dynamically allocated memory.

## Project Structure

```text
Custom-String-Implementation/
│
├── String.cpp
└── README.md
```

## Requirements

* C++ compiler
* Basic knowledge of C++
* Understanding of pointers and dynamic memory allocation
* Understanding of classes and operator overloading

## Restrictions

The project follows these restrictions:

* `std::string` is not used.
* Standard string functions are not directly used for implementing the required operations.
* String data is stored using dynamically allocated character arrays.
* Memory is properly allocated and released.

## Testing

The test program demonstrates:

* Default constructor
* Parameterized constructor
* Copy constructor
* Assignment operator
* String concatenation
* Character access
* Input and output
* All comparison operators
* All custom string functions
* Dynamic memory allocation
* Deep copying
* Memory deallocation

## Example

```cpp
String s1("Hello");
String s2("World");

String s3 = s1 + s2;

cout << s3;
```

Output:

```text
HelloWorld
```

## Learning Outcome

Through this project, I learned how strings can be implemented internally using character arrays and dynamic memory. It also helped me understand deep copying, constructors, destructors, friend functions, and operator overloading in C++.

## Author

**Meet Agravat**

C++ Project
