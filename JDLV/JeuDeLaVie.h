#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "Grille.h"
#include "Affichage.h"

class JeuDeLaVie {
private:
    Grille grille;
    Affichage affichage;

public:
    JeuDeLaVie(int lignes, int colonnes);
    void initialiser(const std::vector<std::vector<bool>>& etats);
    void jouer(int iterations);
};

#endif

