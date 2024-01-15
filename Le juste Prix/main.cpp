#include <iostream>

using namespace std;

enum class ChoixMenu{
  JOUER = 'j',
  QUITTER = 'q',
  INCORRECT
};

int main()
{
    const auto BORNE_MIN{0};
    const auto BORNE_MAX{10'000};


    cout << "Bienvenue au juste prix" << endl;
    cout << static_cast<char>(ChoixMenu::JOUER) << " : pour jouer" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << " : pour quitter" << endl;
    auto choix{ChoixMenu::JOUER};
    char saisieChoix;
    cin >> saisieChoix;

    if(saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::QUITTER))
    {
        choix = static_cast<ChoixMenu>(saisieChoix);
    }else{
        choix = ChoixMenu::INCORRECT;
    }


    switch(choix){
        case ChoixMenu::JOUER:
            cout << "C'est parti !" << endl;
            for(auto aDeviner: {2018, 42, 1984}){
                auto proposition{0};
                auto nombreTentatives{0};

                do{
                    cin >> proposition;

                    if(proposition >= BORNE_MIN && proposition < BORNE_MAX){
                        nombreTentatives++;
                        if(proposition == aDeviner){
                            cout << "Bravo" << endl;
                        }else if(proposition > aDeviner){
                            cout << "C'est moins" << endl;
                        }else{
                            cout << "C'est plus" << endl;
                        }
                    }
                } while(proposition != aDeviner && proposition >= 0);

                if(proposition == aDeviner){
                    cout << "Partie terminée ! " << "en " << nombreTentatives << " tentatives" << endl;
                }else{
                    cout << "Partie abandonnée ..." << endl;
                }
            }
            break;
        case ChoixMenu::QUITTER:
            cout << "Au revoir !" << endl;
            break;
        case ChoixMenu::INCORRECT:
            cout << "Incorrect !" << endl;
            break;
        default:
            cout << "Au revoir !" << endl;
            break;
    }
}
