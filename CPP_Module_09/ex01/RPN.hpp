#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>

class RPN {
	std::stack<int> _stack;
public:
	// Orthodox Canonical Form
    RPN();
    ~RPN();

	// Actions
	int	evaluate(const std::string& input);
};

#endif // RPN_HPP
