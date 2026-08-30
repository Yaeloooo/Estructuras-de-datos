#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include "date.hpp"

class Product
{
private:

    std::string code;
    std::string name;
    float wheith;
    Date entryDate;
    float wholesalePrace;
    float retailPrice;
    int stock;
public:
    Product(/* args */);
    Product(const Product &other);
    Product &operator = (const Product &other);

    void setCode(const std::string&);
    void setName(const std::string&);
    void setWheith(const float&);
    void setEntryDate(const Date&);
    void setWholesalePrice(const float&);
    void setRetailPrice(const float&);
    void setStock(const int&);

    std::string toString() const;

    std::string getCode() const;
    std::string getName() const;
    float getWheith() const;
    Date getEntryDate()const;
    float getWholesalePrice() const;
    float getRetailPrice() const;
    int getStock() const;

    friend std::ostream &operator << (std::ostream&, const Product &);
    friend std::istream &operator >> (std::istream&, const Product &);
};

#endif // __PRODUCT_H__