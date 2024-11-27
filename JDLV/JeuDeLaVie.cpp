#include "JeuDeLaVie.h"

JeuDeLaVie::JeuDeLaVie(int lignes, int colonnes) : grille(lignes, colonnes), affichage(grille) {}

void JeuDeLaVie::initialiser(const std::vector<std::vector<bool>>& etats) {
    grille.initialiser(etats);
}

void JeuDeLaVie::jouer(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        grille.afficher();
        grille.mettreAJour();
        // Pause ou contrôle de la durée entre les itérations peut être ajouté ici
    }
}

