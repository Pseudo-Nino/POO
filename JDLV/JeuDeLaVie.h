#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "Grille.h"
#include "Affichage.h"

// Classe représentant le jeu de la vie de Conway
class JeuDeLaVie {

private:
    Grille grille;       // Grille de cellules
    Affichage affichage; // Gestion de l'affichage graphique

public:
    // Constructeur initialisant la grille et l'affichage
    JeuDeLaVie(int lignes, int colonnes);

    // Initialise la grille avec un état initial donné
    void initialiser(const std::vector<std::vector<bool>>& etats);

    // Joue le jeu pour un nombre donné d'itérations
    void jouer(int iterations);

    // Joue une seule itération du jeu
    void jouerUneIteration();

    // Retourne la grille actuelle (const pour indiquer que la méthode ne modifie pas l'objet)
    const Grille& getGrille() const;

    // Affiche la grille pour un nombre donné d'itérations
    void afficher(int iterations);
};

#endif
