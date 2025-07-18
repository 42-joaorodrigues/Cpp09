# C++ Module 09

![42 Badge](https://img.shields.io/badge/42-CPP_Module_09-brightgreen)
![C++ Badge](https://img.shields.io/badge/Language-C++-blue)
![Status Badge](https://img.shields.io/badge/Status-In_Progress-yellow)

## Project Details

For full project requirements, see the [Subject File](./subject.md).

## Current Progress

### ✅ Exercise 00: Bitcoin Exchange (In Progress)
- **Container Used:** `std::map<std::string, float>` for storing exchange rates
- **Status:** Partially implemented
- **Completed Features:**
  - Database loading from CSV file
  - Date validation with comprehensive checks (format, year ≥ 2009, month/day validity, leap year support)
  - Input file parsing with pipe separator handling
  - Basic class structure with Orthodox Canonical Form

- **In Progress:**
  - Value validation function (currently incomplete)
  - Exchange rate calculation and output
  - Error handling for edge cases

### ⏳ Exercise 01: Reverse Polish Notation (Not Started)
- **Container Available:** `std::stack` or `std::deque` (since `std::map` used in ex00)
- **Status:** Planned

### ⏳ Exercise 02: PmergeMe (Not Started)
- **Containers Available:** Two remaining containers (e.g., `std::vector` + `std::list`)
- **Status:** Planned

## What I'm Learning

Through this advanced C++ project at 42 School, I'm developing expertise in:

- **STL Container Mastery** - Deep understanding of when and how to use different STL containers
- **Strategic Container Selection** - Planning container usage across multiple exercises with constraints
- **Advanced File Parsing** - Implementing robust CSV and custom format parsers
- **Data Validation** - Creating comprehensive input validation for dates, numbers, and formats
- **Algorithm Implementation** - Preparing to implement the Ford-Johnson merge-insert sort
- **Performance Analysis** - Learning to compare and benchmark different container performances
- **Error Handling** - Implementing detailed error messages and graceful failure handling
- **Memory Management** - Working with STL containers while maintaining good memory practices

This module challenges my understanding of C++ STL and algorithmic problem-solving skills essential for advanced software development.

## About the Project

C++ Module 09 is the final module in the 42 C++ curriculum, focusing on the **Standard Template Library (STL)**. This module consists of three progressive exercises that demonstrate mastery of:

- Container selection and usage
- Algorithm implementation
- Performance optimization
- Data structure manipulation

### Key Challenge: Container Constraint
Each STL container can only be used **once** across all exercises, requiring strategic planning and deep understanding of container characteristics.

## Current Implementation Details

### Exercise 00: Bitcoin Exchange

**Core Functionality:**
- Loads Bitcoin exchange rate database from CSV file
- Processes input file with date-value pairs
- Validates dates and values according to strict criteria
- Calculates Bitcoin values using historical exchange rates

**Technical Features Implemented:**
```cpp
class BitcoinExchange {
    std::map<std::string, float> _exchange_rates;  // Database storage
    void loadDatabase(const std::string& db_file); // CSV parser
public:
    BitcoinExchange(const std::string& db_file);   // Constructor loads DB
    void processInput(const std::string& input_file); // Main processing
};
```

**Validation Logic:**
- **Date Format:** YYYY-MM-DD with comprehensive format checking
- **Date Range:** Years must be ≥ 2009 (Bitcoin inception)
- **Calendar Validation:** Proper month/day validation including leap year support
- **Value Range:** Numbers between 0 and 1000 (implementation in progress)

## Usage

```bash
# Compile Exercise 00
cd CPP_Module_09/ex00
make

# Run the Bitcoin Exchange
./btc input.txt
```

## Implementation Highlights

### Robust Date Validation
```cpp
bool isValidDate(const std::string& date, const std::string& err_msg) {
    // Format validation (YYYY-MM-DD)
    // Year validation (≥ 2009)
    // Month validation (1-12)
    // Day validation with leap year support
}
```

### CSV Database Loading
- Efficient parsing using `std::stringstream`
- Automatic header skipping
- Key-value storage in `std::map` for O(log n) lookups

### Strategic Container Planning
- **Ex00:** `std::map` - Perfect for date-based lookups with automatic sorting
- **Ex01:** Planning `std::stack` for RPN expression evaluation
- **Ex02:** Planning `std::vector` + `std::deque` for merge-insert sort comparison

## Next Steps

1. **Complete Exercise 00:**
   - Finish value validation function
   - Implement exchange rate calculation
   - Add proper error handling and output formatting

2. **Exercise 01: RPN Calculator**
   - Implement stack-based expression evaluator
   - Handle mathematical operations: +, -, *, /
   - Parse and validate RPN expressions

3. **Exercise 02: Ford-Johnson Sort**
   - Implement merge-insert sort algorithm
   - Create dual container implementation
   - Add performance benchmarking

## Technical Challenges Addressed

- **Container Constraint Management** - Planning usage across exercises
- **Complex Date Validation** - Handling edge cases, leap years, and format validation
- **File Format Parsing** - Robust CSV and custom format handling
- **Memory Efficiency** - Using STL containers appropriately
- **Error Handling** - Comprehensive validation with clear error messages

---

*This project demonstrates advanced C++ programming skills and STL mastery as part of the 42 School curriculum.*

---

## License

This project is licensed under the [MIT License](./LICENSE).
