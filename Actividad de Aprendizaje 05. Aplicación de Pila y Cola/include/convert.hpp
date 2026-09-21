#ifndef __CONVERT_H__
#define __CONVERT_H__

#include "stack.hpp"
#include "queue.hpp"

class Convert
{
private:
    Queue<char, 50> infix;
    Queue<char, 50> postFix;

    int valor(char op)
    {
        if (op == '^')
            return 3;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return 0;
    }

public:
    Convert(/* args */);
    Convert(const Convert &);

    void receivesInfix(const Queue<char, 50> &);
    Queue<char, 50> convertPosFix();
};

#endif // __CONVERT_H__