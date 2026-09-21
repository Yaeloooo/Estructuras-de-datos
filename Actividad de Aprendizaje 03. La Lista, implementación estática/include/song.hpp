#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <string>

class Song
{
private:
    std::string name;
    std::string author;
    std::string interpreter;
    int top;

public:
    Song(/* args */);
    Song(std::string name, std::string author, std::string interpreter, int top);
    Song(const Song &);
    Song &operator=(const Song &other);

    std::string getName() const;
    std::string getAuthor() const;
    std::string getInterpreter() const;
    int getTop() const;

    std::string toString() const;

    std::string setName(const std::string &);
    std::string setAuthor(const std::string &);
    std::string setInterpreter(const std::string &);
    int setTop(const int &);

    friend std::ostream &operator<<(std::ostream &, const Song &);
    friend std::istream &operator>>(std::istream &, Song &);
};

#endif // __SONG_H__