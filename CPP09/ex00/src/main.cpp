#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << USAGE << std::endl;
        return (-1);
    }

    BitcoinExchange* btc = NULL;
    try
    {
        btc = new BitcoinExchange("data.csv", argv[1]);
        btc->convertBitcoinValue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete btc;

    return (0);
}
