#include "Grille.h"
#include <iostream>
#include <fstream>

Grille::Grille(int l, int c) : lignes(l), colonnes(c) {
    cellules.resize(lignes, std::vector<Cellule>(colonnes));
}

void Grille::initialiser(const std::vector<std::vector<bool>>& etats) {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            cellules[i][j].definirEtat(etats[i][j]);
        }
    }
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int ni = (x + i + lignes) % lignes;
            int nj = (y + j + colonnes) % colonnes;
            if (cellules[ni][nj].estVivante()) count++;
        }
    }
    return count;
}

void Grille::mettreAJour() {
    std::vector<std::vector<Cellule>> nouvellesCellules = cellules;
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j);
            if (cellules[i][j].estVivante()) {
                nouvellesCellules[i][j].definirEtat(voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvellesCellules[i][j].definirEtat(voisinsVivants == 3);
            }
        }
    }
    cellules = nouvellesCellules;
}

void Grille::afficher() const {
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule.estVivante() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

const std::vector<std::vector<Cellule>>& Grille::getCellules() const {
    return cellules;
}

void Grille::enregistrerEtat(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'enregistrement." << std::endl;
        return;
    }
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            fichier << (cellule.estVivante() ? "1 " : "0 ");
        }
        fichier << std::endl;
    }
}
