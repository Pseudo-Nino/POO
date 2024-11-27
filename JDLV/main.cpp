#include <iostream>
#include <fstream>
#include <vector>
#include "JeuDeLaVie.h"

void afficherGrille(const Grille& grille) {
    const auto& cellules = grille.getCellules();
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule.vivante ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // Pour séparer les itérations
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Veuillez fournir le chemin du fichier d'entrée." << std::endl;
        return 1;
    }

    std::ifstream fichier(argv[1]);
    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    int lignes, colonnes;
    fichier >> lignes >> colonnes;
    std::vector<std::vector<bool>> etats(lignes, std::vector<bool>(colonnes));

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            int etat;
            fichier >> etat;
            etats[i][j] = (etat == 1);
        }
    }

    JeuDeLaVie jeu(lignes, colonnes);
    jeu.initialiser(etats);

    // Affichage de l'état initial en mode console
    afficherGrille(jeu.getGrille());

    // Mode graphique
    jeu.afficher(100); // Afficher 100 itérations en mode graphique

    return 0;
}
