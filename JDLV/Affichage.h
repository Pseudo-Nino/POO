#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class Affichage {
private:
    sf::RenderWindow window;
    Grille& grille;

public:
    Affichage(Grille& g);
    void afficher();
};

#endif

