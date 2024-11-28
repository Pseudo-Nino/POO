#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

// Classe gérant l'affichage graphique de la grille
class Affichage {

private:
    sf::RenderWindow window; // Fenêtre de rendu SFML
    Grille& grille;          // Référence à la grille de cellules

public:
    // Constructeur initialisant l'affichage avec une grille donnée
    explicit Affichage(Grille& g);

    // Affiche l'état actuel de la grille dans la fenêtre graphique
    void afficher();
};

#endif
