#include <iostream>
#include <array>
#include <random>
#include <chrono>
#include "constante.h"
#include "jeu.h"
#include "menu.h"

using namespace std;


int main()
{
    cout << "Bienvenue au juste prix" << endl;

    auto scores = TableauDeScores{0,0,0};
    auto indiceCourant{0};

    auto temps = chrono::high_resolution_clock::now().time_since_epoch();
    auto ns = chrono::duration_cast<std::chrono::nanoseconds>(temps).count();
    auto generateur = mt19937{static_cast<unsigned long>(ns)};

    auto distribution = std::uniform_int_distribution<int>{BORNE_MIN, BORNE_MAX};


    bool continuer{true};
    while(continuer)
    {
        affciherMenu();
        auto choix{ChoixMenu::JOUER};
        choix = demanderChoixMenu();

        switch(choix)
        {
            case ChoixMenu::JOUER:
                scores[indiceCourant] = jouerPartie(distribution(generateur));
                indiceCourant = (indiceCourant + 1) % NOMBRE_SCORES;
                break;

            case ChoixMenu::AFFICHER_SCORES:
                afficherScores(scores);
                break;

            case ChoixMenu::QUITTER:
                cout << "Au revoir !" << endl;
                continuer = false;
                break;
            case ChoixMenu::INCORRECT:
            default:
                return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
