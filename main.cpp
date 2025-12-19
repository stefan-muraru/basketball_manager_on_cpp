#include<iostream> 
#include<string.h>//  stringhe
#include<vector>//    vettori
#include<limits>
#include<cstdlib>// funzionamento stringhe
#include<chrono> // tempo
#include<thread>//  funzione sleep
#include<fstream>// leggere e scrivere su file
#include<sstream>// X file
//                                           BASKETBALL MANAGER by MURARU STEFAN
#include "giocatore.h"
#include "basket_manager.h"

using namespace std;

//        CONTROLLO COMPATIBILITA' DI UNA FUNZIONE
#ifdef _WIN32 // WINDOWS 32 BIT
void pulisci(){
    system("cls");
}
#else
#ifdef _WIN64// WINDOWS 64 BIT
void pulisci(){
    system("cls");
}
#else
void pulisci(){//  TUTTO IL RESTO (LINUX, MACOS, ECC...)
    system("clear");
}
#endif
#endif

void uscita(){//        FUNZIONE USCITA DAL PROGRAMMA
    cout<<"uscita dal programma..."<<endl;
    exit(0);
}

void dormi(){
    this_thread::sleep_for(chrono::seconds(1));
}

void count(){
    cout<<"3..."<<endl;
    dormi();
    pulisci();
    cout<<"2..."<<endl;
    dormi();
    pulisci();
    cout<<"1..."<<endl;
    dormi();
    pulisci();
}

void titolo(){
    cout<<"=========================BASKET MANAGER================================"<<endl;
}

int main(){
    basket_manager manager;
    int scelta;
    scelta=0;
    while(scelta!=5){
        titolo();
        cout<<endl<<"         1. inserisci giocatori da file"<<endl;
        cout<<"         2. aggiungi giocatore"<<endl;
        cout<<"         3. elimina giocatore"<<endl;
        cout<<"         4. visualizza lista"<<endl;
        cout<<"         5. salva file prima di uscire dal programma"<<endl;
        cout<<"         6. esci dal programma"<<endl;
        cout<<"         inserisci azione:";
        cin>>scelta;

        switch(scelta){
            case 1: 
                manager.carica_da_file();
                pulisci();
                break;

            case 2: 
                manager.add_giocatore();
                pulisci();
                break;

            case 3: 
                manager.del_giocatore();
                pulisci();
                break;

            case 4: 
                manager.stampa_tabella();
                pulisci();
                break;

            case 5: 
                manager.save_on_file();
                pulisci();
                break;

            case 6:
                uscita();
                break;

            default:
                cout<<"scelta non valida...";
                pulisci();
        }
    }
}