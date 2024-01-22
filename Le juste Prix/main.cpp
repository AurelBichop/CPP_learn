#include <iostream>
#include <array>
#include "constante.h"
#include "jeu.h"
#include "menu.h"

using namespace std;


int main()
{
    cout << "Bienvenue au juste prix" << endl;

    auto scores = TableauDeScores{0,0,0};
    auto indiceCourant{0};

    bool continuer{true};
    while(continuer)
    {
        affciherMenu();
        auto choix{ChoixMenu::JOUER};
        choix = demanderChoixMenu();

        switch(choix)
        {
            case ChoixMenu::JOUER:
                scores[indiceCourant] = jouerPartie(3000);
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
