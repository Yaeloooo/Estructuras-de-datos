#include "song.hpp"

using namespace std;

Song::Song(/* args */) {}

Song::Song(const Song &other) : name(other.name), author(other.author), interpreter(other.interpreter), top(other.top)
{
}

Song::Song(std::string n, std::string a, std::string i, int t) : name(n), author(a), interpreter(i), top(t)
{
}

Song &Song::operator=(const Song &other)
{
    if (this != &other)
    {
        this->author = other.author;
        this->name = other.name;
        this->interpreter = other.interpreter;
        this->top = other.top;
    }

    return *this;
}

std::string Song::getName() const
{
    return this->name;
}

std::string Song::getAuthor() const
{
    return this->author;
}

std::string Song::getInterpreter() const
{
    return this->interpreter;
}

int Song::getTop() const
{
    return this->top;
}

std::string Song::toString() const
{
    return "Nombre: " + name + "\n" + "Autor: " + author + " \n" + "Interprete: " + interpreter + "\n" + "Top: " + to_string(top);
}

std::string Song::setName(const std::string &v)
{
    this->name = v;
}

std::string Song::setAuthor(const std::string &v)
{
    this->author = v;
}

std::string Song::setInterpreter(const std::string &v)
{
    this->interpreter = v;
}

int Song::setTop(const int &v)
{
    this->top = v;
}

std::istream &operator>>(std::istream &is, Song &s)
{

    string myStr;

    getline(is, s.name);
    getline(is, s.author);
    getline(is, s.interpreter);
    getline(is, myStr);

    if (!myStr.empty())
    {
        s.top = stoi(myStr);
    }
    else
    {
        s.top = 0;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, const Song &s)
{

    os << s.name << endl;
    os << s.author << endl;
    os << s.interpreter << endl;
    os << s.top;

    return os;
}
