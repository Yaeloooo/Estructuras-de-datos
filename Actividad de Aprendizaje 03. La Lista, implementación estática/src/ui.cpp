#include "ui.hpp"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

Ui::Ui()
{
}

Ui::Ui(List<Song> &list)
{
    this->myListRef = &list;
    this->menu();
}

void Ui::cargarDesdeDisco()
{

    string myStr;
    cout << "Escribe el nombre del archivo: " << endl;
    getline(cin >> ws, myStr);

    ifstream archivo(myStr);
    if (archivo.is_open())
    {

        archivo >> (*myListRef);
        archivo.close();
    }
}

void Ui::guardarEnDisco()
{
    string myStr;

    cout << "Escribe el nombre del archivo: " << endl;
    getline(cin >> ws, myStr);

    ofstream archivo(myStr);
    if (archivo.is_open())
    {

        archivo << (*myListRef);
        archivo.close();
    }
}

void Ui::menu()
{
    int opcion = 0;

    do
    {
        cout << "\n========================================" << endl;
        cout << "            MENU DE LISTA               " << endl;
        cout << "========================================" << endl;
        cout << "1. Inserta" << endl;
        cout << "2. Elimina" << endl;
        cout << "3. Recupera" << endl;
        cout << "4. Primero" << endl;
        cout << "5. Ultimo" << endl;
        cout << "6. Anterior" << endl;
        cout << "7. Siguiente" << endl;
        cout << "8. Eliminar Todo" << endl;
        cout << "9. Mostrar Lista Completa" << endl;
        cout << "10. Leer del Disco" << endl;
        cout << "11. Escribir al Disco" << endl;
        cout << "0. Salir" << endl;
        cout << "========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
        {
            if (myListRef->isFull())
            {
                cout << "\n[Error] La lista está llena." << endl;
                break;
            }

            int pos;
            cout << "\nIngrese la posicion de insercion ";
            cin >> pos;
            cin.ignore();

            Song nuevaCancion;
            cout << "\n--- Captura de Cancion ---" << endl;
            cin >> nuevaCancion;

            myListRef->instData(pos, nuevaCancion);
            guardarEnDisco();
            cout << "\nElemento insertado y guardado en disco." << endl;
            break;
        }

        case 2:
        {
            if (myListRef->isEmpty())
            {
                cout << "\n[Error] La lista está vacía." << endl;
                break;
            }

            int pos;
            cout << "\nIngrese la posicion a eliminar ";
            cin >> pos;

            myListRef->dellData(pos);
            guardarEnDisco();
            cout << "\nElemento eliminado y archivo actualizado." << endl;
            break;
        }

        case 3:
        {
            if (myListRef->isEmpty())
            {
                cout << "\n[Error] La lista está vacía." << endl;
                break;
            }

            int pos;
            cout << "\nIngrese la posicion a recuperar: ";
            cin >> pos;

            cout << "\n--- Elemento Recuperado ---" << endl;
            cout << myListRef->retrieve(pos).toString() << endl;
            break;
        }

        case 4:
        {
            int pos = myListRef->getFirstPos();
            if (pos == -1)
            {
                cout << "\nLa lista está vacía." << endl;
            }
            else
            {
                cout << "\n--- Primer Elemento (Posicion " << pos << ") ---" << endl;
                cout << myListRef->retrieve(pos).toString() << endl;
            }
            break;
        }

        case 5:
        {
            int pos = myListRef->getLastPos();
            if (pos == -1)
            {
                cout << "\nLa lista está vacía." << endl;
            }
            else
            {
                cout << "\n--- Ultimo Elemento (Posicion " << pos << ") ---" << endl;
                cout << myListRef->retrieve(pos).toString() << endl;
            }
            break;
        }

        case 6:
        {
            if (myListRef->isEmpty())
            {
                cout << "\nLa lista está vacía." << endl;
                break;
            }

            int pos;
            cout << "\nIngrese la posicion base: ";
            cin >> pos;

            int prev = myListRef->getPrevPos(pos);
            if (prev == -1)
            {
                cout << "\nNo existe posicion anterior válida." << endl;
            }
            else
            {
                cout << "\n--- Elemento Anterior (Posicion " << prev << ") ---" << endl;
                cout << myListRef->retrieve(prev).toString() << endl;
            }
            break;
        }

        case 7:
        {
            if (myListRef->isEmpty())
            {
                cout << "\nLa lista está vacía." << endl;
                break;
            }

            int pos;
            cout << "\nIngrese la posicion base: ";
            cin >> pos;

            int next = myListRef->getNextPos(pos);
            if (next == -1)
            {
                cout << "\nNo existe posicion siguiente válida." << endl;
            }
            else
            {
                cout << "\n--- Elemento Siguiente (Posicion " << next << ") ---" << endl;
                cout << myListRef->retrieve(next).toString() << endl;
            }
            break;
        }

        case 8:
        {
            myListRef->delAll();
            guardarEnDisco();
            cout << "\nLista anulada. Se han borrado todos los elementos." << endl;
            break;
        }

        case 9:
        {
            if (myListRef->isEmpty())
            {
                cout << "\nLa lista está vacía." << endl;
            }
            else
            {
                cout << "\n========== CONTENIDO DE LA LISTA ==========" << endl;
                cout << *myListRef;
            }
            break;
        }

        case 10:
        {

            cout << "Leyendo del Disco..." << endl;
            cargarDesdeDisco();
            break;
        }

        case 11:
        {

            cout << "\n Escribiendo al disco..." << endl;
            guardarEnDisco();
            break;
        }

        case 0:
        {
            cout << "Saliendo..." << endl;
            cin.get();
        }

        default:
            cout << "\nOpción inválida." << endl;
            break;
        }

    } while (opcion != 0);
}