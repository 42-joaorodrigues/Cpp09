#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Insert positive int sequence." << std::endl;
		return 1;
	}

	PmergeMe pm;
	pm.run(argc, argv);

	return 0;
}