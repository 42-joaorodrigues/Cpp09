#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
    std::vector<int>	_vector;
    std::deque<int>		_deque;

    bool isValidInput(const std::string& str);
    void parseInput(int argc, char* argv[]);

    template <typename T>
    void displaySequence(const std::string& prefix, T& container);

    template <typename T>
    T mergeInsertionSortRecursive(const T& container);

    std::vector<int> vectorSort(const std::vector<int>& vec);
    std::deque<int>  dequeSort(const std::deque<int>& deq);
public:
    PmergeMe();
    ~PmergeMe();

    void run(int argc, char* argv[]);
};

#endif // PMERGEME_HPP
