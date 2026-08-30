#include "coleccion.hpp"
#include <string>

using namespace std;

Coleccion::Coleccion(/* args */)
{
    count = 0;
}

void Coleccion::setProduct(const Product &v)
{
    if (count < 20)
    {
        stockProducts[count] = v;
        count++;
    }
}

void Coleccion::increase()
{
    string myStr;
    int myInt;

    cout << "Ingresa el codigo del producto a aumentar: ";
    getline(cin >> ws, myStr);

    for (int i = 0; i < count; i++)
    {

        if (myStr == stockProducts[i].getCode())
        {
            cout << "Producto: " << stockProducts[i].getName() << endl;
            cout << "Stock actual: " << stockProducts[i].getStock() << endl;
            cout << "Ingresa la cantidad a aumentar: ";
            cin >> myInt;

            int newStock = stockProducts[i].getStock() + myInt;
            stockProducts[i].setStock(newStock);

            cout << "Stock actualizado con exito: " << newStock << endl
                 << endl;
        }
    }
}

void Coleccion::sell()
{
    string myStr;
    int myInt;

    cout << "Codigo Producto a Vender" << endl;
    getline(cin >> ws, myStr);

    for (int i = 0; i < count; i++)
    {

        if (myStr == stockProducts->getCode())
        {
            cout << "Cantidad a Vender: " << endl;
            cin >> myInt;
            cin.ignore();

            int newStock = stockProducts[i].getStock() - myInt;
            stockProducts[i].setStock(newStock);

            cout << "Venta creada correctamente   Stock: " << newStock << endl
                 << endl;
        }
    }
}

void Coleccion::newProduct()
{
    Product newProduct;
    string str;
    int myInt;
    float myFloat;
    Date date;

    cout << "Codigo del Producto" << endl;
    getline(cin >> ws, str);
    newProduct.setCode(str);

    cout << "Nombre del Producto" << endl;
    getline(cin >> ws, str);
    newProduct.setName(str);

    cout << "Peso del Producto" << endl;
    cin >> myFloat;
    newProduct.setWheith(myFloat);
    cin.ignore();

    cout << "Precio Mayoreo" << endl;
    cin >> myFloat;
    newProduct.setWholesalePrice(myFloat);
    cin.ignore();

    cout << "Precio Menudeo" << endl;
    cin >> myFloat;
    newProduct.setRetailPrice(myFloat);
    cin.ignore();

    cout << "Cantidad Productos" << endl;
    cin >> myInt;
    newProduct.setStock(myInt);
    cin.ignore();

    cout << "===============================" << endl;
    cout << "Fecha de ingreso del Producto" << endl;
    cout << "===============================" << endl;

    cout << "Dia" << endl;
    cin >> myInt;
    date.setDay(myInt);
    cin.ignore();

    cout << "Mes" << endl;
    cin >> myInt;
    date.setMonth(myInt);
    cin.ignore();

    cout << "Anio" << endl;
    cin >> myInt;
    date.setYear(myInt);
    cin.ignore();

    newProduct.setEntryDate(date);

    setProduct(newProduct);

    cout << endl
         << endl;
}
