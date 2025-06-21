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
        PmergeMe< std::deque<int> >* sortDeque = NULL;
        try
        {
            std::cout << BOLD "CONTAINER: DEQUE" RESET << std::endl;
            sortDeque = new PmergeMe< std::deque<int> >(concatSequence(argc, argv));
			sortDeque->printBefore();
            g_startTime = clock();
            sortDeque->process();
            std::cout << *sortDeque << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete sortDeque;
    }

    // VECTOR
    {
        PmergeMe< std::vector<int> >* sortVector = NULL;
        try
        {
            std::cout << BOLD "\nCONTAINER: VECTOR" RESET << std::endl;
            sortVector = new PmergeMe< std::vector<int> >(concatSequence(argc, argv));
            sortVector->printBefore();
			g_startTime = clock();
            sortVector->process();
            std::cout << *sortVector << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        delete sortVector;
    }

    return (0);
}
