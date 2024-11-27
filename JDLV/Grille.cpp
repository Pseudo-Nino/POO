#include "Grille.h"
#include <iostream>
#include <fstream> // Ajouté pour std::ofstream

Grille::Grille(int l, int c) : lignes(l), colonnes(c) {
    cellules.resize(lignes, std::vector<Cellule>(colonnes));
}

void Grille::initialiser(const std::vector<std::vector<bool>>& etats) {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            cellules[i][j] = Cellule(etats[i][j]);
        }
    }
}

int Grille::compterVoisinsVivants(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Ignorer la cellule elle-même
            int ni = (x + i + lignes) % lignes; // Gestion torique
            int nj = (y + j + colonnes) % colonnes; // Gestion torique
            if (cellules[ni][nj].vivante) count++;
        }
    }
    return count;
}

void Grille::mettreAJour() {
    std::vector<std::vector<Cellule>> nouvellesCellules = cellules;
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j);
            if (cellules[i][j].vivante) {
                nouvellesCellules[i][j].vivante = (voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                nouvellesCellules[i][j].vivante = (voisinsVivants == 3);
            }
        }
    }
    cellules = nouvellesCellules;
}

void Grille::afficher() {
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule.vivante ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // Pour séparer les itérations
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
            fichier << (cellule.vivante ? "1 " : "0 ");
        }
        fichier << std::endl;
    }
}
