#ifndef MOTEUR_HPP
#define MOTEUR_HPP

#include <string>

/**
 * @file Moteur.hpp
 * @brief Déclaration de la classe de base Moteur.
 */

/**
 * @class Moteur
 * @brief Classe mère représentant un moteur générique de moto.
 *
 * Cette classe est la classe de base des moteurs Electrique et Thermique
 * (héritage). Elle est destinée à être utilisée de façon polymorphe :
 * une Moto détient un pointeur sur Moteur qui pointe en réalité vers
 * une instance concrète d'Electrique ou de Thermique.
 */
class Moteur {
protected:
    int puissance; ///< Puissance du moteur, exprimée en watts.

public:
    /**
     * @brief Construit un moteur avec une puissance donnée.
     * @param puissance Puissance initiale en watts (0 par défaut).
     */
    explicit Moteur(int puissance = 0);

    /**
     * @brief Destructeur virtuel.
     *
     * Virtuel car la classe est destinée à être héritée et manipulée
     * via des pointeurs de base (Moteur*), afin d'éviter les fuites
     * mémoire lors de la suppression polymorphe.
     */
    virtual ~Moteur();

    /**
     * @brief Récupère la puissance du moteur.
     * @return Puissance en watts.
     */
    int getPuissance() const;

    /**
     * @brief Modifie la puissance du moteur.
     * @param puissance Nouvelle puissance en watts.
     */
    void setPuissance(int puissance);

    /**
     * @brief Construit une représentation textuelle du moteur.
     * @return Chaîne de caractères décrivant le moteur.
     */
    virtual std::string toString() const;
};

#endif // MOTEUR_HPP
