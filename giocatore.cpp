#include "giocatore.h"

#include <iostream>

giocatore::giocatore(string name, int number, bool cap, int points, int foults){
    nome=name;
    numero=number;
    k=cap;
    punti=points;
    falli=foults;
}

void giocatore::new_giocatore(){
    string name;
    int number;
    int capitano=0;
    bool cap;
    int points;
    int foults;
    cout<<"inserisci nome: ";
    cin>>name;
    cout<<endl<<"inserisci numero di maglia";
    cin>>number;
    cout<<endl<<"inserisci: se e\' capitano digita 1, se NON lo e\' inserisci 0: ";
    cin>>capitano;
    if(capitano == 1){
        cap=true;
    }
    cout<<endl<<"inserisci media dei punti: ";
    cin>>points;
    cout<<endl<<"inserisci media falli: ";
    cin>>foults;
    
}

string giocatore::get_nome(){
    return nome;
};

int giocatore::get_numero(){
    return numero;
};

bool giocatore::get_k(){
    return k;
};

int giocatore::get_punti(){
    return punti;
};

int giocatore::get_falli(){
    return falli;
};