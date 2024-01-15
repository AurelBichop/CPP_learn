#include <iostream>

using namespace std;

int main()
{
    cout << "Bienvenue au juste prix" << endl;
    cout << "j: pour jouer" << endl;
    cout << "q: pour quitter" << endl;
    auto choix{'j'};
    cin >> choix;


    switch(choix){
    case 'j':
        cout << "C'est parti !" << endl;
        for(auto aDeviner: {2018, 42, 1984}){
            auto proposition{0};
            auto nombreTentatives{0};

            do{
                cin >> proposition;

                if(proposition >= 0 && proposition < 10'000){
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
    case 'q':
        cout << "Au revoir !" << endl;
        break;
    default:
        cout << "Au revoir !" << endl;
        break;
    }
}
