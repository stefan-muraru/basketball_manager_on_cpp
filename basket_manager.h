#ifndef BASKET_MANAGER_H
#define BASKET_MANAGER_H

#include <vector>

#include "giocatore.h"

using namespace std;

class basket_manager{
private:
    vector <giocatore> giocatori;
    void stampa_linea(int larghezza) const;
public:
    void add_giocatore();
    void del_giocatore();
    void carica_da_file();
    void save_on_file();
    void stampa_tabella();
};

#endif