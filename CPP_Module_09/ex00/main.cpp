#include "BitcoinExchange.hpp"

int main() {
	BitcoinExchange be("data.csv");
	be.processInput("input.txt");
	return 0;
}
