*This project has been created as part of the 42 curriculum by mcaro-ro*

# CPP Module 06 – C++ Casts
## 📖 Description
CPP Module 06 introduces the different types of C++ casts and how to use them safely and correctly within the C++98 standard.
Across three exercises, you will work with:
 - Scalar type conversion
 - Pointer serialization
 - Runtime type identification
The module focuses on understanding static_cast, reinterpret_cast, and dynamic_cast, and applying each one in the correct context.
You will also practice type detection, pointer manipulation, and polymorphism.

## ⚙️ Instructions
1. Clone the repository from your Git workspace.
2. Navigate into the exercise folder (ex00, ex01, ex02, or ex03).
3. Compile the project using make.
4. Each exercise has its own main.cpp to test the required functionality.
5. Clean build artifacts with:
	```
	make clean
	```
	```
	make fclean
	```
	```
	make re
	```
## 📚 Concepts Covered
1. C++ Casts
 - static_cast  
	Used for safe, well‑defined conversions between compatible types.
	Required in ex00.

 - reinterpret_cast  
 	Used for low‑level, bitwise reinterpretation of data (e.g., pointer ↔ integer).
 	Required in ex01.
 
 - dynamic_cast  
 	Used for runtime type identification in polymorphic hierarchies.
 	Required in ex02.

2. Literal Parsing & Type Detection (ex00)
 - Identifying whether a string represents:
  - char
  - int
  - float
  - double
  - pseudo‑literals (nan, inf, -inff, etc.)
 - Handling non‑displayable or impossible conversions.
 - Using <limits> to detect overflows.

3. Pointer Serialization (ex01)
 - Converting a pointer to an integer (uintptr_t) and back.
 - Demonstrating that the deserialized pointer matches the original.
 - Understanding that a pointer is fundamentally just a number.

4. Runtime Type Identification (ex02)
 - Using dynamic_cast with pointers and references.
 - Handling failed casts:
 	- Pointer version returns NULL
 	- Reference version throws an exception
 - Generating random derived types.
 - Identifying the real type without using typeinfo.

5. Orthodox Canonical Form
 - Required for classes unless explicitly stated otherwise.
 - Ensures proper copying, assignment, and destruction.

## 🧱 Exercises
- ex00 – ScalarConverter
 - A non‑instantiable class with a static method convert().
 - Detects the literal type and converts it to:
  - char
  - int
  - float
  - double
 - Handles pseudo‑literals and impossible conversions.
 - Uses static_cast for all conversions.
 Focus: type detection, numeric limits, safe casting.

- ex01 – Serializer
 - A non‑instantiable class with:
  - serialize(Data*) → uintptr_t
  - deserialize(uintptr_t) → Data*
 - Converts a pointer to an integer and back.
 - Uses reinterpret_cast.
 Focus: pointer manipulation and low‑level casting.

- ex02 – Identify real type
 - Base class with virtual destructor.
 - Derived classes: A, B, C.
 - generate() returns a random instance.
 - identify(Base*) and identify(Base&) print the real type.
 - Uses dynamic_cast.
 Focus: RTTI, polymorphism, and safe downcasting.
