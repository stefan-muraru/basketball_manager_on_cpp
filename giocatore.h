#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <string>
using namespace std;

struct giocatore {
private:
    string nome;
    int numero;
    bool k;
    int punti;
    int falli;
public:
    void new_giocatore();
    string get_nome();
    int get_numero();
    bool get_k();
    int get_punti();
    int get_falli();

    giocatore(string name, int number, bool cap, int points, int foults);
};

#endif