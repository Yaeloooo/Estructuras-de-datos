#include "product.hpp"
using namespace std;

#include <string>
#include <iostream>

Product::Product(/* args */)
{
}

Product::Product(const Product &other) : code(other.code), name(other.name), wheith(other.wheith), entryDate(other.entryDate), wholesalePrace(other.wholesalePrace), retailPrice(other.retailPrice), stock(other.stock) {}

Product &Product::operator=(const Product &other)
{
    if (this != &other)
    {
        this->code = other.code;
        this->name = other.name;
        this->wheith = other.wheith;
        this->entryDate = other.entryDate;
        this->wholesalePrace = other.wholesalePrace;
        this->retailPrice = other.retailPrice;
        this->stock = other.stock;
    }
    return *this;
}

void Product::setCode(const std::string &v)
{
    this->code = v;
}

void Product::setName(const std::string &v)
{
    this->name = v;
}

void Product::setWheith(const float &v)
{
    this->wheith = v;
}

void Product::setEntryDate(const Date &v)
{
    this->entryDate = v;
}

void Product::setWholesalePrice(const float &v)
{
    this->wholesalePrace = v;
}

void Product::setRetailPrice(const float &v)
{
    this->retailPrice = v;
}

void Product::setStock(const int &v)
{
    this->stock = v;
}

std::string Product::toString() const
{
    return "Codigo: " + code + "\n" + "Nombre: " + name + "\n" + "Peso: " + to_string(wheith) + "\n" + "Fecha de Entrada: " + entryDate.toString() + "\n" + "Precio Mayoreo: " + to_string(wholesalePrace) + "\n" + "Precio Menudeo: " + to_string(retailPrice) + "\n" + "Existencia: " + to_string(stock) + "\n";
}

std::string Product::getCode() const
{
    return this->code;
}

std::string Product::getName() const
{
    return this->name;
}

float Product::getWheith() const
{
    return this->wheith;
}

Date Product::getEntryDate() const
{
    return this->entryDate;
}

float Product::getWholesalePrice() const
{
    return this->wholesalePrace;
}

float Product::getRetailPrice() const
{
    return this->retailPrice;
}

int Product::getStock() const
{
    return this->stock;
}

std::istream &operator>>(std::istream &, const Product &)
{
}

std::ostream &operator<<(std::ostream &, const Product &)
{
}
