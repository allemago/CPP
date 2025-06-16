#include "../include/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN [expression]" << std::endl;
        return (-1);
    }

    RPN* rpn = NULL;
    try
    {
        rpn = new RPN(argv[1]);
        rpn->computeExpression();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete rpn;

    return (0);
}
