#include "JeuDeLaVie.h"
#include <iostream>

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

void JeuDeLaVie::jouerUneIteration() {
    grille.mettreAJour();
}

const Grille& JeuDeLaVie::getGrille() const {
    return grille;
}

void JeuDeLaVie::afficher(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Afficher l'état actuel dans la console
        const auto& cellules = grille.getCellules();
        for (const auto& ligne : cellules) {
            for (const auto& cellule : ligne) {
                std::cout << (cellule.vivante ? "1 " : "0 ");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl; // Pour séparer les itérations

        affichage.afficher(); // Mettre à jour l'affichage graphique
        grille.mettreAJour();
        sf::sleep(sf::milliseconds(1000)); // Pause entre les itérations pour voir les changements
    }
}
