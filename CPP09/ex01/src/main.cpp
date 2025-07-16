#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN [expression]" << std::endl;
        return -1;
    }

    (void)argv;
    RPN* rpn = NULL;
    try
    {
        rpn = new RPN(argv[1]);
        std::cout << rpn->getResult() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete rpn;

    return 0;
}
