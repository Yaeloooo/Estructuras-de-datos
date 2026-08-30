#ifndef __COLECCION_H__
#define __COLECCION_H__

#include "product.hpp"


class Coleccion
{
private:

    Product stockProducts[500];
    int count;


public:
    Coleccion(/* args */);
    void setProduct(const Product&);
    void increase();
    void sell();
    void newProduct();

};




#endif // __COLECCION_H__