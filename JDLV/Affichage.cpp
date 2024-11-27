#include "Affichage.h"

Affichage::Affichage(Grille& g) : grille(g) {
    window.create(sf::VideoMode(800, 600), "Jeu de la Vie");
}

void Affichage::afficher() {
    const auto& cellules = grille.getCellules();
    window.clear();
    for (int i = 0; i < cellules.size(); ++i) {
        for (int j = 0; j < cellules[i].size(); ++j) {
            sf::RectangleShape rectangle(sf::Vector2f(20, 20)); // Augmenter la taille des cellules
            rectangle.setPosition(j * 20, i * 20);
            rectangle.setFillColor(cellules[i][j].vivante ? sf::Color::Green : sf::Color::Black);
            rectangle.setOutlineThickness(1); // Ajouter des bordures
            rectangle.setOutlineColor(sf::Color::White);
            window.draw(rectangle);
        }
    }
    window.display();
}
