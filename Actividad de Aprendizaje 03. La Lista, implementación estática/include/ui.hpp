#ifndef __UI_H__
#define __UI_H__

#include "list.hpp"
#include "song.hpp"

class Ui
{
private:
    List<Song>* myListRef;
    
    void menu();
    void cargarDesdeDisco();
    void guardarEnDisco();

public:
    Ui(List<Song>&);
    Ui();
};

#endif // __UI_H__