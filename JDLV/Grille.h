#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"
#include <string>

// Classe représentant la grille de cellules pour le jeu de la vie
class Grille {

private:
    std::vector<std::vector<Cellule>> cellules; // Matrice de cellules
    int lignes;    // Nombre de lignes de la grille
    int colonnes;  // Nombre de colonnes de la grille

public:
    // Constructeur initialisant la grille avec un nombre de lignes et de colonnes donné
    Grille(int l, int c);

    // Initialise la grille avec un état initial donné
    void initialiser(const std::vector<std::vector<bool>>& etats);

    // Met à jour l'état de la grille selon les règles du jeu de la vie
    void mettreAJour();

    // Affiche l'état actuel de la grille dans la console
    void afficher() const;

    // Compte le nombre de voisins vivants d'une cellule donnée
    int compterVoisinsVivants(int x, int y) const;

    // Retourne la matrice de cellules actuelle (const pour indiquer que la méthode ne modifie pas l'objet)
    const std::vector<std::vector<Cellule>>& getCellules() const;

    // Enregistre l'état actuel de la grille dans un fichier
    void enregistrerEtat(const std::string& nomFichier) const;
};

#endif
