# C++ Module 09

## 📘 Project Overview

**C++ Module 09** is the final module in the 42 C++ curriculum focused on the **Standard Template Library (STL)**. This module introduces students to C++ containers and algorithms, teaching efficient data structure usage and algorithmic problem-solving.

> **Disclaimer:**  
> This document is an unofficial summary written for educational and documentation purposes.  
> It is not affiliated with or endorsed by 42 or its partners.  
> All 42 students are responsible for adhering to the academic integrity policy.  
> You may **not** publish or share any part of the official subject PDF, evaluation scripts, or Moulinette content.

---

## Contents

- [Goals](#goals)
- [General Requirements](#general-requirements)
- [Module-Specific Rules](#module-specific-rules)
- [Exercise 00 – Bitcoin Exchange](#exercise-00--bitcoin-exchange)
- [Exercise 01 – Reverse Polish Notation](#exercise-01--reverse-polish-notation)
- [Exercise 02 – PmergeMe](#exercise-02--pmergeme)
- [Submission Guidelines](#submission-guidelines)

---

## Goals

- Master the use of STL containers and their characteristics.
- Implement algorithms using appropriate data structures.
- Understand performance differences between containers.
- Practice file parsing and data validation.
- Learn algorithmic problem-solving with C++.

---

## General Requirements

- Written in **C++98**, following **42 guidelines**.
- Compile with `c++` and flags `-Wall -Wextra -Werror`.
- Code must compile with `-std=c++98`.
- No memory leaks or undefined behavior.
- Classes must follow **Orthodox Canonical Form**.
- Global variables and `friend` keyword are **forbidden**.
- `using namespace` is **forbidden**.
- STL usage is **allowed** (containers and algorithms).

### Makefile

Must include rules:
- `all`, `clean`, `fclean`, `re`, `$(NAME)`
- Must not relink

---

## Module-Specific Rules

**Important Container Restrictions:**
- Must use **at least one container** per exercise.
- Exercise 02 requires **two different containers**.
- **Once a container is used, it cannot be reused** in subsequent exercises.
- Must handle **at least 3000 elements** in Exercise 02.

> **Strategy:** Plan your container usage carefully across all exercises before starting!

---

## Exercise 00 – Bitcoin Exchange

### Overview
Create a program that calculates Bitcoin values on specific dates using a CSV database.

### Requirements
- **Program name:** `btc`
- **Input:** File with format `"date | value"`
- **Database:** CSV file with Bitcoin prices over time
- **Date format:** `Year-Month-Day`
- **Value range:** Float or positive integer between 0 and 1000

### Key Features
- Parse and validate input data
- Handle date lookups (use closest lower date if exact match not found)
- Calculate value × exchange rate
- Comprehensive error handling

### Example Usage
```bash
./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
Error: not a positive number.
Error: bad input => 2001-42-42
Error: too large a number.
```

### Files to Submit
- `Makefile`
- `main.cpp`
- `BitcoinExchange.cpp`
- `BitcoinExchange.hpp`

---

## Exercise 01 – Reverse Polish Notation

### Overview
Implement a calculator for Reverse Polish Notation (RPN) mathematical expressions.

### Requirements
- **Program name:** `RPN`
- **Input:** Inverted Polish mathematical expression as argument
- **Numbers:** Always less than 10 (calculations can exceed this)
- **Operations:** `+ - / *`
- **Output:** Calculation result or error message

### Key Features
- Stack-based evaluation
- Token parsing and validation
- Mathematical operation handling
- Error management for invalid expressions

### Example Usage
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
./RPN "7 7 * 7 -"
42
./RPN "(1 + 1)"
Error
```

### Files to Submit
- `Makefile`
- `main.cpp`
- `RPN.cpp`
- `RPN.hpp`

---

## Exercise 02 – PmergeMe

### Overview
Implement the **Ford-Johnson merge-insert sort algorithm** using two different STL containers.

### Requirements
- **Program name:** `PmergeMe`
- **Input:** Sequence of positive integers as arguments
- **Algorithm:** Ford-Johnson (merge-insert sort)
- **Containers:** Must use **two different** STL containers
- **Capacity:** Handle at least 3000 integers

### Key Features
- Implement Ford-Johnson algorithm for each container
- Performance comparison between containers
- Time measurement and display
- Input validation and error handling

### Output Format
```bash
./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
```

### Files to Submit
- `Makefile`
- `main.cpp`
- `PmergeMe.cpp`
- `PmergeMe.hpp`

---

## Submission Guidelines

- Code must be submitted to the Git repository assigned by 42.
- Only repository contents will be evaluated.
- Evaluation includes peer reviews and automated testing.
- Norm errors result in immediate evaluation termination.
- Each exercise must be in its respective directory (`ex00/`, `ex01/`, `ex02/`).

---

## Container Strategy

Since containers cannot be reused, plan carefully:

**Suggested Container Usage:**
- **Ex00:** `std::map` (for date-price database)
- **Ex01:** `std::stack` (for RPN evaluation)
- **Ex02:** `std::vector` + `std::deque` (for Ford-Johnson comparison)

**Alternative combinations:**
- `std::map`, `std::stack`, `std::vector` + `std::list`
- `std::multimap`, `std::queue`, `std::vector` + `std::deque`

---

## Testing Recommendations

- Test with large datasets (3000+ elements for Ex02)
- Validate edge cases and error conditions
- Benchmark container performance differences
- Test with various input formats and invalid data
- Use provided examples as baseline tests

---

## Key Learning Outcomes

- **Container Selection:** Understanding when to use specific STL containers
- **Algorithm Implementation:** Ford-Johnson merge-insert sort
- **Performance Analysis:** Comparing container efficiency
- **Data Parsing:** File I/O and validation techniques
- **Error Handling:** Robust input validation and error reporting

---

## Final Note

This module concludes the 42 C++ curriculum by introducing the powerful STL.  
Understanding containers, algorithms, and their performance characteristics is essential for professional C++ development.

---
