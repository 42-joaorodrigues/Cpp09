#include <iostream>
#include "RPN.hpp"

int	main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Format: " << argv[0] << " <formula>" << std::endl;
		return 1;
	}
	RPN	rpn;
	try {
		int result = rpn.evaluate(argv[1]);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}
	return 0;
}