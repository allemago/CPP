#include "../include/PmergeMe.hpp"

time_t  g_startTime = 0;

static std::string  concatSequence(size_t size, char **argv)
{
	std::string sequence;
	for (size_t i = 1; i < size; i++)
        sequence += argv[i] + std::string(" ");

    return sequence;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return std::cerr << USAGE << std::endl, -1;

    time(&g_startTime);
    std::string sequence = concatSequence(argc, argv);
    
    PmergeMe* sort = NULL;
    try
    {
        sort = new PmergeMe(sequence);
        sort->process();
        std::cout << *sort << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete sort;

    return (0);
}
