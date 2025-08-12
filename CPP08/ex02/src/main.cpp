#include "../include/MutantStack.hpp"
#include <iostream>
#include <stack>
#include <string>
#include <list>

int main()
{
    // Various tests
    {
        std::cout << BOLD "VARIOUS TESTS" RESET << std::endl;

        MutantStack<int> a, b;
        a.push(1);
        a.push(2);
        b.push(1);
        b.push(2);
        std::cout << "a == b? " << (a == b ? "yes" : "no") << std::endl;

        b.push(3);
        std::cout << "a < b? " << (a < b ? "yes" : "no") << std::endl;

        while (!a.empty())
        {
            std::cout << "pop: " << a.top() << std::endl;
            a.pop();
        }
        std::cout << "is a empty? " << (a.empty() ? "yes" : "no") << std::endl;
        MutantStack<int> s1;
        std::cout << "is s1 empty? " << (s1.empty() ? "yes" : "no") << std::endl;

        s1.push(10);
        s1.push(20);
        s1.push(30);
        std::cout << "\ns1 top is: " << s1.top() << std::endl;
        std::cout << "s1 size: " << s1.size() << std::endl;

        s1.pop();
        std::cout << "after pop, s1 top is: " << s1.top() << std::endl;
        std::cout << "s1 size after pop: " << s1.size() << std::endl;

        MutantStack<int> s2(s1);
        std::cout << "\ns2 (copy of s1), top: " << s2.top() << std::endl;

        MutantStack<int> s3;
        s3 = s2;
        std::cout << "\ns3 (s3 = s2), top: " << s3.top() << std::endl;

        MutantStack<std::string> s4;
        s4.push("hello");
        s4.push("world!");
        s4.push("How");
        s4.push("are");
        s4.push("you?");
        std::cout << CYAN "\ns4 (iterator):" RESET << std::endl;
        for (MutantStack<std::string>::iterator it = s4.begin(); it != s4.end(); ++it)
            std::cout << *it << std::endl;
        std::cout << CYAN "\ns4 (const_iterator):" RESET << std::endl;
        for (MutantStack<std::string>::const_iterator cit = s4.cbegin(); cit != s4.cend(); ++cit)
            std::cout << *cit << std::endl;
        std::cout << CYAN "\ns4 (reverse_iterator):" RESET << std::endl;
        for (MutantStack<std::string>::reverse_iterator rit = s4.rbegin(); rit != s4.rend(); ++rit)
            std::cout << *rit << std::endl;
        std::cout << CYAN "\ns4 (const_reverse_iterator):" RESET << std::endl;
        for (MutantStack<std::string>::const_reverse_iterator crit = s4.crbegin(); crit != s4.crend(); ++crit)
            std::cout << *crit << std::endl;
    }

    // FROM SUBJECT - MutantStack
    std::cout << BOLD "\n⬇️ FROM SUBJECT⬇️" RESET << std::endl;
    {
        std::cout << BOLD "\nMutantStack" RESET << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);

        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    // FROM SUBJECT - std::list
    {   
        std::cout << BOLD "\nstd::list" RESET << std::endl;
        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        std::cout << mstack.back() << std::endl;

        mstack.pop_back();

        std::cout << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }

    return (0);
}
