#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <exception>
#include <string>

template <class T, int ARRAYSIZE>
class Queue
{
private:
    T data[ARRAYSIZE];
    int front = 0;
    int end = 1;

    void copyAll(const Queue<T, ARRAYSIZE> &);

public:
    class Exception : public std::exception
    {
    private:
        std::string msg;

    public:
        Exception() noexcept : msg("Error indefinido") {}
        Exception(const Exception &ex) noexcept : msg(ex.msg) {}
        Exception(const std::string &m) : msg(m) {}
        Exception &operator=(const Exception &ex) noexcept
        {
            msg = ex.msg;

            return *this;
        }

        virtual ~Exception() {}
        virtual const char *what() const noexcept
        {
            return msg.c_str();
        }
    };

    Queue(/* args */);
    Queue(const Queue<T, ARRAYSIZE> &);

    bool isEmpy() const;
    bool isFull() const;

    void enqueue(const T &);

    T dequeue();

    T &getFront();

    Queue<T, ARRAYSIZE> &operator=(const Queue<T, ARRAYSIZE> &);
};

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE> &other)
{
    this->front = other.front;
    this->end = other.end;

    for (int i = 0; i < ARRAYSIZE; i++)
    {
        this->data[i] = other.data[i];
    }
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(/* args */)
{
    this->front = 0;
    this->end = -1;
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE> &other)
{
    this->copyAll(other);
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpy() const
{
    return this->front == this->end + 1 or this->front == 0 and this->end == -1;
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull() const
{
    return this->front == this->end + 2 or (this->front == 0 and this->end == ARRAYSIZE - 2) or (this->front == 1 and this->end == ARRAYSIZE - 1);
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T &v)
{
    if (isFull())
    {
        throw Exception("La cola esta llena");
    }

    this->end = ++this->end == ARRAYSIZE ? 0 : end;

    this->data[this->end] = v;
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue()
{

    if (isEmpy())
    {
        throw Exception("La cola esta llena");
    }

    T result(this->data[this->front]);
    this->front++;

    if (this->front == ARRAYSIZE)
    {
        this->front = 0;
    }

    return result;
}

template <class T, int ARRAYSIZE>
T &Queue<T, ARRAYSIZE>::getFront()
{

    if (isEmpy())
    {
        throw Exception("La cola esta Vacia");
    }

    return this->data[this->front];
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE> &Queue<T, ARRAYSIZE>::operator=(const Queue<T, ARRAYSIZE> &other)
{
    this->copyAll(other);

    return *this;
}

#endif // __QUEUE_H__