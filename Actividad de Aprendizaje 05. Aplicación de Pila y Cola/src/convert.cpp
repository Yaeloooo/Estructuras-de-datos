#include "convert.hpp"
#include <cctype>

using namespace std;

Convert::Convert(/* args */)
{
}

void Convert::receivesInfix(const Queue<char, 50> &v)
{
    this->infix = v;
}

Queue<char, 50> Convert::convertPosFix()
{
    Queue<char, 50> postFix;
    Stack<char, 50> operators;

    while (!this->infix.isEmpy())
    {
        char character = this->infix.dequeue();

        if ((character >= 'A' and character <= 'Z') or (character >= '0' and character <= '9'))
        {
            postFix.enqueue(character);
        }
        else if (character == '(')
        {
            operators.push(character);
        }
        else if (character == ')')
        {

            while (!operators.isEmpy() and operators.getTop() != '(')
            {
                postFix.enqueue(operators.pop());
            }

            if (!operators.isEmpy())
            {
                operators.pop();
            }
        }
        else
        {
            while (!operators.isEmpy() and valor(operators.getTop()) >= valor(character))
            {
                if (character == '^' and operators.getTop() == '^')
                {
                    break;
                }
                postFix.enqueue(operators.pop());
            }
            operators.push(character);
        }
    }

    while (!operators.isEmpy())
    {
        postFix.enqueue(operators.pop());
    }

    return postFix;
}
