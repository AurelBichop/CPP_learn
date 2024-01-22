#include "jeu.h"
#include "constante.h"

#include <iostream>

using namespace std;


void jouerPartie(int leJustePrix,int max){
    auto proposition{0};
    auto nombreTentatives{0};

    do{
        cout << "Proposition ? ";
        demanderProposition(proposition);

        if(proposition >= BORNE_MIN && proposition < max){
            nombreTentatives++;
            if(proposition == leJustePrix){
                cout << "Bravo" << endl;
            }else if(proposition > leJustePrix){
                cout << "C'est moins" << endl;
            }else{
                cout << "C'est plus" << endl;
            }
        }
    } while(proposition != leJustePrix && proposition >= 0);

    if(proposition == leJustePrix){
        cout << "Partie terminée ! " << "en " << nombreTentatives << " tentatives" << endl;
    }else{
        cout << "Partie abandonnée ..." << endl;
    }
}


void jouerTroisParties(){
    cout << "C'est parti !" << endl;
    for(auto aDeviner: {2018, 42, 1984}){
        jouerPartie(aDeviner, BORNE_MAX);
    }
}
