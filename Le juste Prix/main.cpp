#include <iostream>
#include "constante.h"
#include "jeu.h"
#include "menu.h"

using namespace std;


int main()
{
    cout << "Bienvenue au juste prix" << endl;

    bool continuer{true};
    while(continuer)
    {
        affciherMenu();
        auto choix{ChoixMenu::JOUER};
        choix = demanderChoixMenu();

        switch(choix)
        {
            case ChoixMenu::JOUER:
                jouerPartie(3000);
                break;
            case ChoixMenu::JOUER_FACILE:
                jouerPartie(250, BORNE_MAX_FACILE);
                break;
            case ChoixMenu::JOUER_TROIS_PARTIES:
                jouerTroisParties();
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
