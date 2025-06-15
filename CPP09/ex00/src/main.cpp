#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc file.txt" << std::endl;
        return (-1);
    }

    BitcoinExchange* btc = NULL;
    std::string file1 = "data.csv";
    std::string file2 = argv[1];

    try
    {
        btc = new BitcoinExchange(file1, file2);
        btc->convertBitcoinValue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete btc;

    return (0);
}
