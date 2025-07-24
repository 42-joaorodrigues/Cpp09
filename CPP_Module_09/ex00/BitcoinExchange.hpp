#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>

class BitcoinExchange {
    std::map<std::string, float>    _exchange_rates;
    void                            loadDatabase(const std::string& db_file); // Private helper function
public:
    // Constructors
    BitcoinExchange(const std::string& db_file);
    ~BitcoinExchange();

    // Actions
    float   getRate(const std::string& date);
    void    processInput(const std::string& input_file);
};

#endif // BITCOINEXCHANGE_HPP
