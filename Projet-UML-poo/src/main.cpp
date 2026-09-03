/**
 * @file main.cpp
 * @brief Programme principal de démonstration.
 *
 * Scénario :
 *  1. Crée 1 conducteur et 2 motos (1 thermique, 1 électrique), les
 *     attribue au conducteur, puis affiche toutes ses informations.
 *  2. Crée 2 nouveaux conducteurs et 1 nouvelle moto, répartit les
 *     3 motos à raison d'une par conducteur, puis affiche les
 *     informations des 3 conducteurs.
 */

#include <iostream>
#include "Conducteur.hpp"
#include "Moto.hpp"
#include "Electrique.hpp"
#include "Thermique.hpp"

int main() {
    std::cout << "=== Etape 1 : un conducteur, deux motos ===\n\n";

    Conducteur alice("Dupont", "Alice", 1990);

    Moto* motoThermique = new Moto(new Thermique(45000, 650.0f), "Rouge", "Duke 690", 180);
    Moto* motoElectrique = new Moto(new Electrique(30000, 400.0f), "Bleue", "SR/F", 220);

    alice.addMoto(motoThermique);
    alice.addMoto(motoElectrique);

    std::cout << alice.toString() << std::endl;

    std::cout << "=== Etape 2 : repartition sur 3 conducteurs ===\n\n";

    Conducteur bob("Martin", "Bob", 1985);
    Conducteur chloe("Bernard", "Chloe", 1998);

    Moto* nouvelleMoto = new Moto(new Thermique(60000, 998.0f), "Noire", "R1", 200);

    // On retire les motos existantes du premier conducteur pour les
    // repartir : une moto par conducteur.
    alice.rmMoto(motoElectrique);

    bob.addMoto(motoElectrique);
    chloe.addMoto(nouvelleMoto);

    std::cout << alice.toString() << std::endl;
    std::cout << bob.toString() << std::endl;
    std::cout << chloe.toString() << std::endl;

    // Les motos sont en agregation avec Conducteur : c'est au code
    // appelant (ici main) de les detruire. Chaque Moto detruit ensuite
    // son propre moteur (composition).
    delete motoThermique;
    delete motoElectrique;
    delete nouvelleMoto;

    return 0;
}
