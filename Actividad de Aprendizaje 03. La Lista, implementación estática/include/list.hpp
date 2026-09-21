#ifndef __LIST_H__
#define __LIST_H__

#include "song.hpp"

#include <iostream>
#include <cstring>

#define MAX 50

template <class T>
class List
{
private:
    T data[MAX];
    int last = -1;

    bool isValidPos(const int &) const;
    void copyAll(const List &);

public:
    List(/* args */);
    List(const List &);

    bool isEmpty() const;

    bool isFull() const;

    void instData(const int &, const T &);

    void dellData(const int &);

    int getFirstPos() const;

    int getLastPos() const;

    int getPrevPos(const int &) const;

    int getNextPos(const int &) const;

    int findData(const T &) const;

    T &retrieve(const int &);

    void sortData();

    std::string toString() const;

    void delAll();

    List<T> &operator=(const List<T> &);

    template <class X>
    friend std::ostream &operator<<(std::ostream &, const List<X> &);

    template <class X>
    friend std::istream &operator>>(std::istream &, List<X> &);
};

template <class T>
bool List<T>::isValidPos(const int &p) const
{
    return p >= 0 && p <= this->last;
}

template <class T>
void List<T>::copyAll(const List<T> &other)
{
    this->last = other.last;

    int i(0);

    while (i <= this->last)
    {
        this->data[i] = other.data[i];
        i++;
    }
}

template <class T>
List<T>::List(/* args */)
{
}

template <class T>
List<T>::List(const List<T> &other)
{
    this->copyAll(other);
}

template <class T>
bool List<T>::isEmpty() const
{
    return this->last == -1;
}

template <class T>
bool List<T>::isFull() const
{
    return this->last == MAX - 1;
}

template <class T>
void List<T>::instData(const int &p, const T &e)
{
    if (this->isFull())
    {
        return;
    }

    int insertPos = p;
    if (insertPos < -1 || insertPos > this->last)
    {
        insertPos = this->last;
    }

    int i(this->last);

    while (i > insertPos)
    {
        this->data[i + 1] = this->data[i];
        --i;
    }

    this->data[insertPos + 1] = e;
    this->last++;
}

template <class T>
void List<T>::dellData(const int &p)
{
    if (!this->isValidPos(p))
    {
        return;
    }
    int i(p);

    while (i < this->last)
    {
        this->data[i] = this->data[i + 1];
        i++;
    }

    this->last--;
}

template <class T>
int List<T>::getFirstPos() const
{
    return this->isEmpty() ? -1 : 0;
}

template <class T>
int List<T>::getLastPos() const
{
    return this->last;
}

template <class T>
int List<T>::getPrevPos(const int &p) const
{
    return (p == 0 || !this->isValidPos(p)) ? -1 : p - 1;
}

template <class T>
int List<T>::getNextPos(const int &p) const
{
    return (p == this->last || !this->isValidPos(p)) ? -1 : p + 1;
}

template <class T>
int List<T>::findData(const T &e) const
{
    int i(0);
    while (i <= this->last)
    {
        if (this->data[i] == e)
        {
            return i;
        }
        i++;
    }
    return -1;
}

template <class T>
T &List<T>::retrieve(const int &p)
{
    return this->data[p];
}

template <class T>
void List<T>::sortData()
{

    for (int i = 0; i < this->last; i++)
    {
        for (int j = i + 1; j <= this->last; j++)
        {
            if (this->data[j] < this->data[i])
            {
                T temp = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = temp;
            }
        }
    }
}

template <class T>
std::string List<T>::toString() const
{
    std::string result;
    int i(0);

    while (i <= this->last)
    {
        result += this->data[i].toString() + "\n";
        i++;
    }

    return result;
}

template <class T>
void List<T>::delAll()
{
    this->last = -1;
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other)
{
    this->copyAll(other);
    return *this;
}

template <class X>
std::ostream &operator<<(std::ostream &os, const List<X> &l)
{
    int i(0);

    while (i <= l.last)
    {
        os << l.data[i] << "\n";
        i++;
    }

    return os;
}

template <class X>
std::istream &operator>>(std::istream &is, List<X> &l)
{
    X myObj;

    while (is >> myObj)
    {
        l.instData(l.getLastPos(), myObj);
    }

    return is;
}

#endif // __LIST_H__