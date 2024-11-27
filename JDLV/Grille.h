#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"
#include <string> // Ajouté pour std::string

class Grille {
private:
    std::vector<std::vector<Cellule>> cellules;
    int lignes;
    int colonnes;

public:
    Grille(int l, int c);
    void initialiser(const std::vector<std::vector<bool>>& etats);
    void mettreAJour();
    void afficher();
    int compterVoisinsVivants(int x, int y);
    const std::vector<std::vector<Cellule>>& getCellules() const;
    void enregistrerEtat(const std::string& nomFichier) const; // Ajouté
};

#endif
