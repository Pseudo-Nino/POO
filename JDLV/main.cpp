#include <iostream>
#include <fstream>
#include <vector>
#include "JeuDeLaVie.h"

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
    jeu.jouer(10); // Nombre d'itérations

    return 0;
}

