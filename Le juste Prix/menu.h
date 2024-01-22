#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


enum class ChoixMenu{
  JOUER = 'a',
  AFFICHER_SCORES = 'b',
  QUITTER = 'q',
  INCORRECT
};

ChoixMenu demanderChoixMenu();
void affciherMenu();

#endif // MENU_H_INCLUDED
