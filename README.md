# C++ Module 09

![42 Badge](https://img.shields.io/badge/42-CPP_Module_09-brightgreen)
![C++ Badge](https://img.shields.io/badge/Language-C++-blue)
![Status Badge](https://img.shields.io/badge/Status-Completed-success)

## Project Completion Status

### ✅ Exercise 00: Bitcoin Exchange (Completed)
- **Container Used:** `std::map<std::string, float>` for storing exchange rates
- **Status:** Fully implemented and tested
- **Key Features:**
  - Complete database loading from CSV file
  - Comprehensive date validation (format, year ≥ 2009, leap year support)
  - Input file parsing with pipe separator handling
  - Value validation (0-1000 range)
  - Exchange rate calculation with historical data lookup
  - Robust error handling for all edge cases

### ✅ Exercise 01: Reverse Polish Notation (Completed)
- **Container Used:** `std::stack<float>` for RPN expression evaluation
- **Status:** Fully implemented and tested
- **Key Features:**
  - Stack-based RPN expression evaluator
  - Support for all basic operations: +, -, *, /
  - Comprehensive input validation and error handling
  - Division by zero protection
  - Clean expression parsing and result calculation

### ✅ Exercise 02: PmergeMe (Completed)
- **Containers Used:** `std::vector<int>` and `std::deque<int>` for performance comparison
- **Status:** Fully implemented and tested
- **Key Features:**
  - Complete Ford-Johnson merge-insertion sort algorithm implementation
  - Dual container implementation for performance benchmarking
  - Handles 3000+ integers efficiently
  - Accurate timing measurements using `clock()` (C++98 compliant)
  - Performance comparison showing expected container characteristics

## What I've Learned

Through this advanced C++ project at 42 School, I've mastered:

- **STL Container Expertise** - Deep understanding of container performance characteristics and optimal usage
- **Strategic Container Selection** - Successfully planned and utilized different containers across exercises
- **Algorithm Implementation** - Implemented complex algorithms like Ford-Johnson merge-insertion sort
- **Performance Analysis** - Benchmarked and compared container performance in real-world scenarios
- **Advanced File Parsing** - Created robust parsers for CSV and custom input formats
- **Comprehensive Validation** - Implemented thorough input validation for dates, numbers, and expressions
- **Error Handling Mastery** - Developed detailed error reporting and graceful failure handling
- **C++98 Compliance** - Worked within language constraints while achieving optimal performance

This module has significantly enhanced my C++ STL knowledge and algorithmic problem-solving capabilities.

## About the Project

C++ Module 09 is the final module in the 42 C++ curriculum, focusing on the **Standard Template Library (STL)**. This module consists of three progressive exercises that demonstrate complete mastery of:

- Container selection and usage strategies
- Complex algorithm implementation
- Performance optimization and analysis
- Advanced data structure manipulation

### Key Challenge: Container Constraint ✅
Each STL container can only be used **once** across all exercises. Successfully completed with strategic planning:
- **Exercise 00:** `std::map` - Optimal for date-based lookups
- **Exercise 01:** `std::stack` - Perfect for RPN evaluation
- **Exercise 02:** `std::vector` + `std::deque` - Ideal for performance comparison

## Implementation Details

### Exercise 00: Bitcoin Exchange

**Core Functionality:**
- Loads Bitcoin exchange rate database from CSV file
- Processes input file with date-value pairs
- Validates dates and values according to strict criteria
- Calculates Bitcoin values using historical exchange rates

**Technical Implementation:**
```cpp
class BitcoinExchange {
    std::map<std::string, float> _exchange_rates;
    
    bool isValidDate(const std::string& date);
    bool isValidValue(float value);
    void loadDatabase(const std::string& db_file);
    float findRate(const std::string& date);
    
public:
    BitcoinExchange(const std::string& db_file);
    void processInput(const std::string& input_file);
};
```

**Validation Features:**
- **Date Format:** YYYY-MM-DD with comprehensive format checking
- **Date Range:** Years ≥ 2009 (Bitcoin inception)
- **Calendar Validation:** Proper month/day validation including leap year support
- **Value Range:** Numbers between 0 and 1000

### Exercise 01: Reverse Polish Notation

**Core Functionality:**
- Evaluates mathematical expressions in RPN format
- Uses stack-based algorithm for efficient calculation
- Supports +, -, *, / operations with comprehensive error handling

**Technical Implementation:**
```cpp
class RPN {
    std::stack<float> _stack;
    
    bool isOperator(const std::string& token);
    void processOperator(const std::string& op);
    bool isValidNumber(const std::string& token);
    
public:
    float evaluate(const std::string& expression);
};
```

### Exercise 02: PmergeMe (Ford-Johnson Algorithm)

**Core Functionality:**
- Implements the Ford-Johnson merge-insertion sort algorithm
- Compares performance between `std::vector` and `std::deque`
- Handles large datasets (3000+ integers) efficiently

**Technical Implementation:**
```cpp
class PmergeMe {
    std::vector<int> _vector;
    std::deque<int> _deque;
    
    template <typename T>
    T mergeInsertionSortRecursive(const T& container);
    
    std::vector<int> vectorSort(const std::vector<int>& vec);
    std::deque<int> dequeSort(const std::deque<int>& deq);
    
public:
    void run(int argc, char* argv[]);
};
```

**Performance Results:**
- Successfully demonstrates container performance differences
- Vector typically 3-4x faster than deque for this algorithm
- Accurate timing measurements show expected STL container characteristics

## Usage

```bash
# Exercise 00: Bitcoin Exchange
cd CPP_Module_09/ex00
make
./btc input.txt

# Exercise 01: RPN Calculator  
cd CPP_Module_09/ex01
make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

# Exercise 02: PmergeMe Sorter
cd CPP_Module_09/ex02
make
./PmergeMe 3 5 9 7 4
```

## Technical Achievements

- **✅ Container Constraint Management** - Successfully planned and used different containers
- **✅ Complex Algorithm Implementation** - Ford-Johnson sort with recursive approach
- **✅ Performance Benchmarking** - Real-world container performance comparison
- **✅ Advanced Date Validation** - Comprehensive edge case handling including leap years
- **✅ Robust File Parsing** - Multiple input format support with error handling
- **✅ Memory Efficiency** - Optimal STL container usage throughout
- **✅ C++98 Compliance** - Full compatibility with C++98 standard

---

*This project demonstrates complete mastery of advanced C++ programming and STL expertise as part of the 42 School curriculum.*

---

## License

This project is licensed under the [MIT License](./LICENSE).
