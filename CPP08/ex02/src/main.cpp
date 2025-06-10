#include "../include/MutantStack.hpp"
#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<int> s1;
    std::cout << "is s1 empty? " << (s1.empty() ? "yes" : "no") << std::endl;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    std::cout << "s1 top is: " << s1.top() << std::endl;
    std::cout << "s1 size: " << s1.size() << std::endl;

    s1.pop();
    std::cout << "after pop, s1 top is: " << s1.top() << std::endl;
    std::cout << "s1 size after pop: " << s1.size() << std::endl;

    std::stack<int> s2(s1);
    std::cout << "s2 (copy of s1), top: " << s2.top() << std::endl;

    std::stack<int> s3;
    s3 = s2;
    std::cout << "s3 (s3 = s2), top: " << s3.top() << std::endl;

    std::stack<std::string> s4;
    s4.push("hello");
    s4.push("world");
    std::cout << "s4 top: " << s4.top() << std::endl;

    std::stack<int> a, b;
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

    return (0);
}
