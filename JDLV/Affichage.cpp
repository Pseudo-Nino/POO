#include "Affichage.h"

Affichage::Affichage(Grille& g) : grille(g) {
    window.create(sf::VideoMode(800, 600), "Jeu de la Vie");
}

void Affichage::afficher() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        const auto& cellules = grille.getCellules();
        for (int i = 0; i < cellules.size(); ++i) {
            for (int j = 0; j < cellules[i].size(); ++j) {
                sf::RectangleShape rectangle(sf::Vector2f(10, 10));
                rectangle.setPosition(j * 10, i * 10);
                rectangle.setFillColor(cellules[i][j].vivante ? sf::Color::Green : sf::Color::Black);
                window.draw(rectangle);
            }
        }
        window.display();
    }
}

