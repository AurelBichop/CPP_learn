#include "jeu.h"
#include "constante.h"

#include <array>
#include <chrono>
#include <iostream>

using namespace std;


int jouerPartie(int leJustePrix,int max){
    auto proposition{0};
    auto nombreTentatives{0};

    using Duree = std::chrono::duration<double>;

    auto debutPartie = std::chrono::system_clock::now();

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

    auto finPartie = std::chrono::system_clock::now();
    auto duree = std::chrono::duration_cast<Duree>(finPartie - debutPartie);

    if(proposition == leJustePrix){
        cout << "Partie terminée ! " << "en " << nombreTentatives << " tentatives" << endl;
        cout << "Durée de la partie " << duree.count() << 's' <<endl;
        if(duree < 30s){
            cout << "Bravo vous avez gagné !!! " << endl;
        }
    }else{
        cout << "Partie abandonnée ..." << endl;
    }

    cout << endl;

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
