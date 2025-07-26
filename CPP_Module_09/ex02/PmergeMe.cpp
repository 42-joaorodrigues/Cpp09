#include "PmergeMe.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

bool PmergeMe::isValidInput(const std::string& str) {
	// check for empty or over int_max size
	if (str.empty() || str.length() > 10)
		return false;
	// check if all chars are digits (since we are only parsing positive numbers)
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	// check for overflow on values above 2 000 000 000
	if (str.length() == 10 && str > "2147483647")
		return false;
	return true;
}

void PmergeMe::parseInput(const int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		if (!isValidInput(argv[i]))
			throw std::invalid_argument("Error");

		int num = atoi(argv[i]);
		_vector.push_back(num);
		_deque.push_back(num);
	}
}

template <typename T>
void PmergeMe::displaySequence(const std::string& prefix, T& container) {
	std::cout << prefix;

	int count = 0;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (count > 0)
			std::cout << " ";
		if (count < 15)
			std::cout << *it;
		else {
			std::cout << " [...]";
			break;
		}
		count++;
	}
	std::cout << std::endl;
}

template <typename T>
T PmergeMe::mergeInsertionSortRecursive(const T& container) {
	if (container.size() <= 1) // base case
		return container;

	// Step 1: pairing and internal sorting
	std::vector<std::pair<int, int> > pairs;
	T leftover;
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		int a = container[i];
		int b = container[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	if (container.size() % 2 != 0)
		leftover.push_back(container.back());

	// Step 2: Split into small and large
	T smalls, larges;
	for (size_t i = 0; i < pairs.size(); i++) {
		smalls.push_back(pairs[i].first);
		larges.push_back(pairs[i].second);
	}

	// Step 3: Recursively sort larges
	T sorted = mergeInsertionSortRecursive(larges);

	// Step 4: Insert smalls
	for (size_t i = 0; i < smalls.size(); i++) {
		typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), smalls[i]);
		sorted.insert(pos, smalls[i]);
	}

	// Step 5: Insert leftover, if any
	for (size_t i = 0; i < leftover.size(); i++) {
		typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), leftover[i]);
		sorted.insert(pos, leftover[i]);
	}

	return sorted;
}

std::vector<int> PmergeMe::vectorSort(const std::vector<int>& vec) {
	return mergeInsertionSortRecursive(vec);
}

std::deque<int> PmergeMe::dequeSort(const std::deque<int>& deq) {
	return mergeInsertionSortRecursive(deq);
}

// Default constructor
PmergeMe::PmergeMe() {}

// Destructor
PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char* argv[]) {
	try {
		parseInput(argc, argv);

		// Display before sorting
		displaySequence("Before: ", _vector);

		// Sort with vector and measure time
		clock_t	start_vec = clock();
		std::vector<int> sorted_vec = vectorSort(_vector);
		clock_t end_vec = clock();
		double vec_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

		// Sort with deque and measure time
		start_vec = clock();
		std::deque<int> deq_vec = dequeSort(_deque);
		end_vec = clock();
		double deq_time = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

		// Display sorted
		displaySequence("After: ", sorted_vec);

		// Display time information
		std::cout << "Time to process a range of " << _vector.size()
				  << " elements with std::vector: " << vec_time * 1000000 << " us" << std::endl;

		std::cout << "Time to process a range of " << _deque.size()
				  << " elements with std::deque: " << deq_time * 1000000 << " us" << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
