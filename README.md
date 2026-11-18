*This project has been created as part of the 42 curriculum by erocha--.*

# C++ Modules (CPP00 – CPP07)

![Language](https://img.shields.io/badge/language-C++98-blue?style=flat-square) ![Flags](https://img.shields.io/badge/flags--Wall%20--Wextra%20--Werror-informational?style=flat-square)

## Description

The C++ modules are the 42 curriculum's introduction to object-oriented programming.
Each module focuses on one set of language features, and every exercise is a small,
self-contained program written in **C++98** with its own `Makefile`.

| Module | Topic | Exercises |
| :--- | :--- | :--- |
| **CPP00** | Namespaces, classes, member functions, `iostream` | `megaphone`, `PhoneBook` / `Contact` (a small interactive address book) |
| **CPP01** | Memory allocation, pointers vs references, `switch` | `Zombie` (stack vs heap), `Zombie` horde, pointer/reference demo, `Weapon` with `HumanA` / `HumanB`, `sed`-like `replace`, `Harl` (member-function pointers), `harlFilter` |
| **CPP02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | `Fixed` (fixed-point number class with arithmetic and comparison operators), `Point` + BSP (point-in-triangle test) |
| **CPP03** | Inheritance | `ClapTrap`, `ScavTrap`, `FragTrap` |
| **CPP04** | Subtype polymorphism, abstract classes, deep copy | `Animal` / `Dog` / `Cat` (with a `WrongAnimal` counter-example), `Brain` with deep copies, abstract `Animal` |
| **CPP05** | Exceptions | `Bureaucrat`, `Form`, abstract `AForm` with Shrubbery / Robotomy / Presidential forms, `Intern` (a form factory) |
| **CPP06** | C++ casts | `ScalarConverter` (char / int / float / double literal conversion), `Serializer` (`reinterpret_cast`), runtime type identification with `dynamic_cast` |
| **CPP07** | Templates | `swap` / `min` / `max` function templates, `iter`, `Array<T>` class template |

## Concepts covered

* **Orthodox Canonical Form**: default constructor, copy constructor, copy assignment operator, destructor
* **Inheritance and polymorphism**: virtual functions, virtual destructors, abstract classes, interfaces
* **Memory management**: `new` / `delete`, deep vs shallow copy, no leaks
* **Exceptions**: custom exception classes deriving from `std::exception`
* **Casts**: `static_cast`, `dynamic_cast`, `reinterpret_cast`
* **Templates**: function and class templates

## Instructions

Each exercise is built independently:

```bash
cd CPP05/ex03
make
./ex03
```

Every `Makefile` provides the usual `all`, `clean`, `fclean` and `re` rules and
compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

## Resources

* [cppreference.com](https://en.cppreference.com/) for the C++98 standard library
* [The Orthodox Canonical Class Form](https://www.francescmm.com/orthodox-canonical-class-form/)
