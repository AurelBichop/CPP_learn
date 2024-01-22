#include "jeu.h"
#include "constante.h"

#include <array>
#include <iostream>

using namespace std;


int jouerPartie(int leJustePrix,int max){
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

    return nombreTentatives;
}


void afficherScores(TableauDeScores& scores){
    cout << "Dernières parties : " << endl;
    for(auto score:scores){
        if(score == 0){
            cout << "-" << endl;
        }else{
            cout << score << " tentatives" << endl;
        }
    }
}
