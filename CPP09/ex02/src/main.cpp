#include "../include/PmergeMe.hpp"

clock_t  g_startTime = 0;

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

    // DEQUE
    {
        try
        {
            std::cout << BOLD "CONTAINER: DEQUE" RESET << std::endl;
            PmergeMe <std::deque<std::pair<size_t, int> > > sortDeque(concatSequence(argc, argv));
            sortDeque.printBefore();
            g_startTime = clock();
            sortDeque.mergeInsertSort(sortDeque.getSize());
            sortDeque.printAfter();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    // VECTOR
    {
        try
        {
            std::cout << BOLD "\nCONTAINER: VECTOR" RESET << std::endl;
            PmergeMe <std::vector<std::pair<size_t, int> > > sortVector(concatSequence(argc, argv));
            sortVector.printBefore();
			g_startTime = clock();
            sortVector.mergeInsertSort(sortVector.getSize());
            sortVector.printAfter();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
