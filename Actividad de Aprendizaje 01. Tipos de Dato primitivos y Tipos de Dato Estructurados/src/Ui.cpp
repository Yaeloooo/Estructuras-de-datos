#include "Ui.hpp"
#include "Data.hpp"
#include "Matrix.hpp"
using namespace std;

Ui::Ui(/* args */)
{
}

void Ui::menu()
{
    Data data;
    int op = 0;

    do {
        std::cout << "\n=== BIENVENIDO ===" << std::endl;
        cout << "1) Tamaño y rangos de los Tipos de Dato Primitivos" << endl;
        cout << "2) Ejemplo de uso de Tipo de dato Estructurado" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresa una opcion: ";
        cin >> op;

        switch (op)
        {

        case 1:
            data.showData();
            break;

        case 2:
        {
            cout << "\nEjemplo de uso de Tipo de dato Estructurado:" << endl;
            int N;
            cout << "Ingrese el tamaño de la matriz (entre 3 y 10): ";
            cin >> N;

            if (N < 3 || N > 10)
            {
                cout << "Tamaño de matriz no válido. Debe estar entre 3 y 10." << endl;
                break;
            }

            Matrix A(N), B(N);
            A.fillMtrix();
            B.fillMtrix();

            Matrix C = A * B;
            Matrix D = A + B;

            cout << "\nMatriz A:" << endl;
            cout << "----------------------------------------------------" << endl;
            A.print();

            cout << "\nMatriz B:" << endl;
            cout << "----------------------------------------------------" << endl;
            B.print();

            cout << "\nMultiplicación: Matriz C" << endl;
            cout << "----------------------------------------------------" << endl;
            C.print();

            cout << "\nSuma: Matriz D" << endl;
            cout << "----------------------------------------------------" << endl;
            D.print();
            break;
        }

        case 3:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opción no válida. Intenta de nuevo." << endl;
            break;
        }
    } while (op != 3);
}
