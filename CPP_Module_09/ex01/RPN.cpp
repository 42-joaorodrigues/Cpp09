#include "RPN.hpp"

#include <cstdlib>
#include <sstream>

// Default constructor
RPN::RPN() {}

// Destructor
RPN::~RPN() {}

// Helpers
static bool isNumber(std::string& str) {
	return str.length() == 1 && std::isdigit(str[0]);
}

static bool	isOperator(std::string& str) {
	return str == "+" || str == "-" || str == "*" || str == "/";
}

static int applyOperator(int a, int b, std::string& op) {
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/") {
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		return a / b;
	}
	throw std::runtime_error("Error: invalid operator");
}

// Actions
int RPN::evaluate(const std::string& input) {
	std::istringstream iss(input);
	std::string token;

	// loop through input
	while (iss >> token) {
		if (isNumber(token))
			_stack.push(std::atoi(token.c_str()));
		else if (isOperator(token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error: not enough operands");
			}

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int result = applyOperator(a, b, token);
			_stack.push(result);
		}
		else
			throw std::runtime_error("Error: invalid token");
	}

	// check if we are just left with the result
	if (_stack.size() != 1)
		throw std::runtime_error("Error: malformed expression");
	// return result
	return _stack.top();
}
