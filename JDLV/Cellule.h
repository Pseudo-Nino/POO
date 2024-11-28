#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
public:
    // Constructeur avec initialisation de l'état de la cellule
    explicit Cellule(bool etat = false) : vivante(etat) {}

    // Getter (Accesseur) pour l'état de la cellule
    bool estVivante() const { return vivante; }

    // Setter (Mutateur) pour l'état de la cellule
    void definirEtat(bool etat) { vivante = etat; }

private:
    bool vivante; // État de la cellule : vivante ou morte
};

#endif
