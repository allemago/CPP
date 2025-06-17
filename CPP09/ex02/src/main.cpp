#include "../include/PmergeMe.hpp"

static std::string  concatSequence(size_t size, char **argv)
{
	std::string sequence;
	for (size_t i = 1; i < size; i++)
	{
        sequence += argv[i];
        sequence += " ";
	}

    return sequence;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return std::cerr << USAGE << std::endl, -1;

    std::string sequence = concatSequence(argc , argv);
    PmergeMe* sort = NULL;

    try
    {
        sort = new PmergeMe(sequence);
        std::cout << *sort << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
