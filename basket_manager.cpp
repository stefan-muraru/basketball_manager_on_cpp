#include "basket_manager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<iomanip>

void basket_manager::stampa_linea(int larghezza) const {
    std::cout << "+" << std::string(larghezza - 2, '-') << "+" << std::endl;
}

void basket_manager::add_giocatore(){
    string name;
    int number;
    int capitano = 0;
    bool cap = false;
    int points;
    int foults;
    cout<<"inserisci nome: ";
    cin>>name;
    cout<<endl<<"inserisci numero di maglia";
    cin>>number;
    cout<<endl<<"inserisci: se e\' capitano digita 1, se NON lo e\' inserisci 0: ";
    cin>>capitano;
    if(capitano == 1){
        cap = true;
    }
    cout<<endl<<"inserisci media dei punti: ";
    cin>>points;
    cout<<endl<<"inserisci media falli: ";
    cin>>foults;
    cout<<endl;

    giocatore nuovo(name, number, cap, points, foults);
    giocatori.push_back(nuovo);

    cout << "Giocatore aggiunto correttamente!" << endl;
}

void basket_manager::del_giocatore(){
    int n;
    cout<<"inserisci indice del giocatore da eliminare: ";
    cin>>n;
    if (n >= 0 && n < giocatori.size()){
        giocatori.erase(giocatori.begin()+n);
    }else{
        cout<<"indice non valido..."<<endl;
    }
}

void basket_manager::carica_da_file(){
    ifstream file("giocatori.txt");
    if (!file.is_open()) {
        cerr << "Errore: impossibile aprire il file giocatori.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nome, numero_str, k_str, punti_str, falli_str;

        // Legge i valori separati da ','
        if (getline(ss, nome, ',') &&
            getline(ss, numero_str, ',') &&
            getline(ss, k_str, ',') &&
            getline(ss, punti_str, ',') &&
            getline(ss, falli_str, ',')) {

            int numero = stoi(numero_str);
            bool k = (k_str == "1" || k_str == "true");
            int punti = stoi(punti_str);
            int falli = stoi(falli_str);

            giocatore g(nome, numero, k, punti, falli);
            giocatori.push_back(g);
        }
    }
}


void basket_manager::save_on_file(){
    ofstream file("giocatori.txt"); // apre in scrittura
    if (!file) {
        cerr << "Errore nell'aprire il file!" << endl;
        return;
    }

    for (auto &g : giocatori) {
        file << g.get_nome() << "," << g.get_numero()<< "," << g.get_k() << "," << g.get_punti() << "," << g.get_falli();
    }

    file.close();
    cout << "Dati salvati correttamente su giocatori.txt" << endl;
}

void basket_manager::stampa_tabella(){
    if (giocatori.empty()) {
        std::cout << "Il roster e' vuoto." << std::endl;
        return;
    }

    // Definizione larghezze colonne
    int w_nome = 18;
    int w_num = 6;
    int w_k= 4; // Colonna per il bool
    int w_punti = 7;
    int w_falli = 7;

    int w_totale = w_nome + w_num + w_k + w_punti + w_falli + 6;

    // Intestazione
    stampa_linea(w_totale);
    std::cout << "| " << std::left  << std::setw(w_nome)  << "NOME"
            << "| " << std::setw(w_num)   << "N."
            << "| " << std::setw(w_k)     << "K"
            << "| " << std::setw(w_punti) << "PUNTI"
            << "| " << std::setw(w_falli) << "FALLI" << " |" << std::endl;
    stampa_linea(w_totale);

    // Dati
    for (auto& g : giocatori) {
        std::cout << "| " << std::left << std::setw(w_nome) << g.get_nome()
                << "| " << std::setw(w_num)  << g.get_numero()
                  // Se k è true stampa 'K', altrimenti uno spazio vuoto
                << "| " << std::setw(w_k)    << (g.get_k() ? " K " : "   ") 
                << "| " << std::setw(w_punti) << g.get_punti()
                << "| " << std::setw(w_falli) << g.get_falli() << " |" << std::endl;
    }
    stampa_linea(w_totale);
}