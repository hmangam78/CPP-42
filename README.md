# CPP-42
This `cpp` repository contains exercises and projects that are part of the C++ curriculum from School 42 (the "cpp" modules).
**C++ Curriculum — School 42 (cpp repository)**

- **Purpose**: This `cpp` repository contains exercises and projects that are part of the C++ curriculum from School 42 (the "cpp" modules). The exercises progress from very small programs that practice basic I/O and string manipulation to object-oriented design, resource management, and C++ core language features.

**Repository Structure**
- **`cpp00/`**: Introductory exercises. Examples: `ex00/`, `ex01/`, `ex02/`.
- **`cpp01/`**: Early object-oriented exercises (classes, dynamic allocation, memory management).
- **`cpp02/`**: Intermediate OOP: constructors, copy semantics, simple class hierarchies.
- **`cpp03/`**: Further OOP, operator overloading, and class design.
- **`cpp04/`**: Advanced class semantics: inheritance, polymorphism, abstract classes.
- **`cpp05/`**: Templates, generic programming, and utility patterns (where present).
- **`cpp06/`**: More advanced patterns and exercises (often includes projects using inheritance and polymorphism).

**Exercise Details and What You Practice**
- **`cpp00/ex00` — `megaphone.cpp`**:
  - **Focus**: Basic console I/O and string processing.
  - **What I've learned**: Reading command-line arguments, iterating strings, character operations (e.g., converting to uppercase), simple `main` program structure.
  - **Usage example**: Build with `make` inside the directory (if `Makefile` exists), then run:
    - `./megaphone "hello world"`  — prints an uppercase version of the passed arguments.

- **`cpp00/ex01` — PhoneBook (`Contact`, `PhoneBook`)**:
  - **Focus**: Basic OOP design, simple persistent in-memory data structures, user interaction loop.
  - **What I've learned**: Designing small classes with private attributes and public methods (`Contact`, `PhoneBook`), validating input, simple command dispatch (commands like `ADD`, `SEARCH`, `EXIT`).
  - **Typical files**: `Contact.cpp`, `Contact.hpp`, `PhoneBook.cpp`, `PhoneBook.hpp`, `main.cpp`, `aux.cpp`, `aux.hpp`.
  - **Usage example**:
    - `make` inside `ex01/` to build the executable (commonly named `phonebook` or as specified in the `Makefile`).
    - `./phonebook` then use interactive commands:
      - `ADD` to create a new contact
      - `SEARCH` to list/search saved contacts
      - `EXIT` to quit

- **`cpp00/ex02` — Account / tests**:
  - **Focus**: Implementing a small class with controlled interface and writing simple tests/driver programs.
  - **What I've learned**: Class methods, static members (if used for global counters or tracking), writing a small `tests.cpp` program to verify behavior.
  - **Usage example**: `make` then `./tests` to run the sample tests included.

-- Expanded per-module exercises --

- **`cpp01` (ex00 → ex06)**
  - **Overview**: This module focuses on fundamental object-oriented techniques and manual memory management in C++: creating classes, constructors/destructors, using `new`/`delete`, and simple ownership patterns.

  - **`ex00` — Zombies (`newZombie`, `randomChump`, `Zombie` class)**
    - **Focus**: Difference between stack and heap allocation, class construction/destruction, simple I/O.
    - **What I've learned**: Creating objects on stack vs heap, exposing small class interfaces, and ensuring cleanup in destructors.
    - **Typical files**: `Zombie.cpp`, `Zombie.hpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`, `Makefile`.
    - **Usage example**:
      - `cd cpp/cpp01/ex00 && make && ./zombie`

  - **`ex01` — Zombie horde**
    - **Focus**: Allocating arrays of objects on the heap and managing their lifetimes.
    - **What I've learned**: Allocating arrays with `new[]`/`delete[]`, iterating object collections, and designing a simple factory-like helper (`zombieHorde`).
    - **Typical files**: `zombieHorde.cpp`, `zombieHorde.hpp`, `Zombie.cpp`, `Zombie.hpp`, `main.cpp`, `Makefile`.

  - **`ex02` → `ex06`**
    - **Focus**: A set of small exercises (weapon/character demos, function dispatchers, simple class interactions) that emphasize class responsibilities and small APIs.
    - **What I've learned**: Encapsulation, passing objects by reference vs value, and building minimal, well-scoped interfaces across multiple small programs.
    - **Typical files**: examples include `HumanA.cpp`, `HumanB.cpp`, `Weapon.cpp`, `Harl.cpp`, `Fixed.cpp`, and various `main.cpp` drivers with `Makefile` scripts.

- **`cpp02` (ex00 → ex03)**
  - **Overview**: This module typically introduces precise class semantics such as fixed-point arithmetic, copy semantics, and other small class-focused exercises.

  - **`ex00` / `ex01` / `ex02` — Fixed / basic class exercises**
    - **Focus**: Implementing a class that manages an internal representation (for example, a `Fixed` class), and practicing constructors, conversions, and operator implementations.
    - **What I've learned**: Implementing constructors, copy constructor, copy assignment, and small conversion utilities while following a clear class interface.
    - **Typical files**: `Fixed.cpp`, `Fixed.hpp`, `main.cpp`, `Makefile`.

  - **`ex03` — Points / `bsp` (geometry helper)**
    - **Focus**: Small geometric utilities and functions that interact with class types (e.g., `Point`, `bsp` triangle tests).
    - **What I've learned**: Designing small value-type classes and free functions that operate on them, writing concise test harnesses (`main.cpp`).
    - **Typical files**: `Point.cpp`, `Point.hpp`, `bsp.cpp`, `bsp.hpp`, `main.cpp`, `Makefile`.

- **`cpp03` (ex00 → ex03)**
  - **Overview**: Operator overloading, richer class hierarchies, and building slightly larger examples (the ClapTrap family is a common series here).

  - **`ex00` — `ClapTrap`**
    - **Focus**: A simple class with methods, state, and interactions (attack/repair/damage semantics).
    - **What I've learned**: Designing clear method contracts and state transition logic inside a class.
    - **Typical files**: `ClapTrap.cpp`, `ClapTrap.hpp`, `main.cpp`, `Makefile`.

  - **`ex01` — `ScavTrap` extends `ClapTrap`**
    - **Focus**: Inheritance basics and extending base-class behavior.
    - **What I've learned**: How to extend functionality safely in derived classes and how to call base-class constructors.
    - **Typical files**: `ScavTrap.cpp`, `ScavTrap.hpp`, plus `ClapTrap` files and `main.cpp`.

  - **`ex02` — `FragTrap` and friends**
    - **Focus**: Additional derived classes that introduce new behavior.
    - **What I've learned**: Handling multiple derived classes and keeping interfaces consistent.

  - **`ex03` — `DiamondTrap` (combining behaviors)**
    - **Focus**: Multiple inheritance patterns (diamond-shaped inheritance) and method resolution concerns.
    - **What I've learned**: How to manage constructors and ambiguous base members when combining multiple base classes.

- **`cpp04` (ex00 → ex03)**
  - **Overview**: This module deepens inheritance and polymorphism, with canonical examples such as `Animal`, `Cat`, `Dog`, and `WrongAnimal` to show virtual vs non-virtual behavior.

  - **`ex00` — Animal hierarchy**
    - **Focus**: Abstract base classes, virtual destructors, and runtime polymorphism.
    - **What I've learned**: Designing safe polymorphic hierarchies and the importance of virtual destructors to avoid leaks or undefined behavior.
    - **Typical files**: `Animal.cpp`, `Animal.hpp`, `Cat.cpp`, `Cat.hpp`, `Dog.cpp`, `Dog.hpp`, `WrongAnimal.cpp`, `WrongAnimal.hpp`, `WrongCat.cpp`, `WrongCat.hpp`, `main.cpp`, `Makefile`.

  - **Other exercises (ex01..ex03)**
    - **Focus**: A variety of OOP challenges, including more formal projects such as `Bureaucrat` that exercise exceptions, access control, and operator overloads.
    - **What I've learned**: Exception-safe code patterns, defining strong class invariants, and writing clear error handling paths.

- **`cpp05` (ex00 → ex03)**
  - **Overview**: This module often includes more advanced C++ language features such as templates, generic utilities, and sometimes STL practice. Several exercise folders contain `SRCS/` and `includes/` layout for slightly bigger projects.

  - **Focus**: Templates, generic data structures, and utility components.
  - **What I've learned**: Using templates to write generic code, designing header/source layouts (`includes/`, `SRCS/`), and separating interface from implementation for reusable components.
  - **Typical files**: `Makefile`, `SRCS/`, and `includes/` subdirectories containing headers and implementation files.

- **`cpp06` (ex00 → ex02)**
  - **Overview**: This module typically collects higher-level design exercises that combine polymorphism, resource management, and more complete small applications. In this workspace some exercises mirror earlier examples (Zombies, small demos) and others are small drivers.

  - **What I've learned**: Combining many small skills into coherent example programs — designing small APIs, writing test drivers, and using `Makefile`s to produce concise demos.
  - **Typical files**: `Makefile`, `main.cpp`, and exercise-specific `.cpp` / `.hpp` files.


**Build & Run (general)**
- **Build**: If a `Makefile` is present in a given exercise directory, run:
  - `cd path/to/exX` then `make`
- **Clean**: `make clean` or `make fclean` if provided.
- **Run**: execute the produced binary (common names: `megaphone`, `phonebook`, `tests`, `zombie`, etc.).

**Examples**
- Build and run the megaphone example:
  - `cd cpp/cpp00/ex00`
  - `make`
  - `./megaphone "hello"`
- Build and run PhoneBook example:
  - `cd cpp/cpp00/ex01`
  - `make`
  - `./phonebook`
  - Then type `ADD`, `SEARCH`, and `EXIT` as interactive commands.

**Author**
Hector Gamiz (hgamiz-g)

**Notes**
- This `cpp` repository is organized by module and exercise number (`cppNN/exXX`). Each `exXX` folder normally includes a `Makefile` and the `.cpp`/`.hpp` sources for that exercise.
- The exact exercise content may vary slightly between different School 42 campuses or personal forks; the descriptions above reflect standard objectives and the files present in this workspace.

**Attribution**
- These exercises are part of the C++ training curriculum from School 42 (the "cpp" modules). They are meant for pedagogical practice in C++ language fundamentals, object oriented programming, and resource management.
