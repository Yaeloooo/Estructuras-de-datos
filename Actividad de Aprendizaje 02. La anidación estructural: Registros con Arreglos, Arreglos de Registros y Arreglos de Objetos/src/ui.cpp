#include "ui.hpp"
#include <iostream>
#include "date.hpp"
#include "product.hpp"
#include "coleccion.hpp"

using namespace std;

Ui::Ui(/* args */)
{
}

void Ui::menu()
{
    int op;
    Coleccion coleccion;

    while (op != 4)
    {

        cout << "Bienvenido a Abarrotes Don Lalo" << endl;

        cout << "1) Ingresar Nuevo Producto" << endl;
        cout << "2) Aumentar Existencia De Producto" << endl;
        cout << "3) Vender Producto" << endl;
        cin >> op;

        switch (op)
        {

        case 1:

            coleccion.newProduct();
            break;

        case 2:
            coleccion.increase();
            break;

        case 3:
            coleccion.sell();
            break;

        case 4:
            cout << "Gracias por usar mi programa" << endl
                 << endl;

            break;
        }
    }
}
