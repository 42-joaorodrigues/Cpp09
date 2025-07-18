#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

// Private helper function
void BitcoinExchange::loadDatabase(const std::string& db_file) {
	std::ifstream	file(db_file.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rate_str;
		if (std::getline(ss, date, ',') && std::getline(ss, rate_str))
			_exchange_rates[date] = std::atof(rate_str.c_str());
	}

	// Test Print
	// std::map<std::string, float>::const_iterator it;
	// for (it = _exchange_rates.begin(); it != _exchange_rates.end(); ++it) {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// }
}

// Constructors
BitcoinExchange::BitcoinExchange(const std::string& db_file) {
	loadDatabase(db_file);
}

BitcoinExchange::~BitcoinExchange() {}

bool	isValidDate(const std::string& date, const std::string& err_msg) {
	// date format
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << err_msg << "Invalid date format." << std::endl;
		return false;
	}
	for (size_t i = 0; i < date.length(); i++)
		if (i != 4 && i != 7 && !std::isdigit(date[i])) {
			std::cerr << err_msg << "Invalid date format." << std::endl;
			return false;
		}

	// year
	int y = std::atoi(date.substr(0, 4).c_str());
	if (y < 2009) {
		std::cerr << err_msg << "Year can't be lower than 2009." << std::endl;
		return false;
	}

	// month
	int m = std::atoi(date.substr(5, 2).c_str());
	if (m < 1 || m > 12) {
		std::cerr << err_msg << "Choose a valid month." << std::endl;
		return false;
	}

	// day
	int d = std::atoi(date.substr(8, 2).c_str());

	// days per month (non-leap year by default)
	static const int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	// Leap year adjustment
	bool is_leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	int max_day = days_in_month[m - 1];
	if (is_leap && m == 2)
		++max_day;
	if (d < 1 || d > max_day) {
		std::cerr << err_msg << "Choose a valid day." << std::endl;
		return false;
	}

	return true;
}

bool	isValidValue(const std::string& value_str, const std::string& err_msg) {
	try {
		size_t		idx;
		std::string	value = std::stod()
	}
}

void BitcoinExchange::processInput(const std::string& input_file) {
	std::ifstream	file(input_file.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line)) { // read input loop
		std::stringstream ss(line);

		// get seperator
		size_t pos = line.find('|');
		if (pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line
					  << ". No seperator '|' found." << std::endl;
			continue;
		}

		// get date
		std::string date;
		date = line.substr(0, pos);
		date.erase(0, date.find_first_not_of(" \t\r\n"));
		date.erase(date.find_last_not_of(" \t\r\n") + 1);
		if (!isValidDate(date, "Error: bad input => '" + line + "' => "))
			continue;

		// get value
		std::string value_str;
		value_str = line.substr(pos + 1);
		value_str.erase(0, value_str.find_first_not_of(" \t\r\n"));
		value_str.erase(value_str.find_last_not_of(" \t\r\n") + 1);
	}
}
