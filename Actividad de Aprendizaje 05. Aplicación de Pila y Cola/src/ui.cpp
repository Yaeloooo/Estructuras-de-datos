#include "ui.hpp"
#include <iostream>

using namespace std;

Ui::Ui(/* args */)
{
}
void Ui::menu()
{

    char op;

    do
    {
        string myCadena;
        Queue<char, 50> myQueue;

        Convert myConvert;

        cout << "Ingresa la operacion infija: " << endl;
        getline(cin >> ws, myCadena);

        for (char c : myCadena)
        {
            if (c != ' ')
            {
                myQueue.enqueue(toupper(c));
            }
        }

        myConvert.receivesInfix(myQueue);

        Queue<char, 50> myQueueExit = myConvert.convertPosFix();

        cout << "Operacion posfija: ";

        while (!myQueueExit.isEmpy())
        {
            cout << myQueueExit.dequeue();
        }
        cout << endl << endl << endl;

        cout << "otro? Y/N" << endl;
        cin >> op;
        op = toupper(op);   

        



    } while (op != 'N');
}
