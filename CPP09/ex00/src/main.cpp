#include "../include/BitcoinExchangeBis.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error, try: ./btc <file.txt>" << std::endl;
    }

    BitcoinExchangeBis* btc;
    std::string file1 = "../data.csv";
    std::string file2 = argv[1];

    try
    {
        btc = new BitcoinExchangeBis(file1, file2);
        btc->scanExchangeRate();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete btc;

    return (0);
}
