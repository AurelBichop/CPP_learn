#include <iostream>

using namespace std;

enum class ChoixMenu{
  JOUER = 'a',
  JOUER_FACILE = 'b',
  JOUER_TROIS_PARTIES = 'c',
  QUITTER = 'q',
  INCORRECT
};

const auto BORNE_MIN{0};
const auto BORNE_MAX{10'000};
const auto BORNE_MAX_FACILE{1'000};


ChoixMenu demanderChoixMenu(){
    char saisieChoix;
    cin >> saisieChoix;

    if(saisieChoix == static_cast<char>(ChoixMenu::JOUER) || static_cast<char>(ChoixMenu::JOUER_FACILE) || static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        return static_cast<ChoixMenu>(saisieChoix);
    }else{
        return ChoixMenu::INCORRECT;
    }
}

void jouerPartie(int leJustePrix,int max){
    auto proposition{0};
    auto nombreTentatives{0};

    do{
        cout << "Proposition ? ";
        cin >> proposition;

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

void affciherMenu(){
    cout << static_cast<char>(ChoixMenu::JOUER) << " : pour jouer" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_FACILE) << " : pour jouer (facile)" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER_TROIS_PARTIES) << " : pour jouer 3 parties" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << " : pour quitter" << endl;
}

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
                jouerPartie(3000, BORNE_MAX);
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
