#ifndef THERMIQUE_HPP
#define THERMIQUE_HPP

#include "Moteur.hpp"

/**
 * @file Thermique.hpp
 * @brief Déclaration de la classe Thermique, dérivée de Moteur.
 */

/**
 * @class Thermique
 * @brief Moteur thermique, caractérisé par sa cylindrée.
 */
class Thermique : public Moteur {
private:
    float cylindree; ///< Cylindrée du moteur, en cm3.

public:
    /**
     * @brief Construit un moteur thermique.
     * @param puissance Puissance du moteur en watts.
     * @param cylindree Cylindrée en cm3.
     */
    Thermique(int puissance, float cylindree);

    /**
     * @brief Destructeur.
     */
    ~Thermique() override;

    /**
     * @brief Récupère la cylindrée du moteur.
     * @return Cylindrée en cm3.
     */
    float getCylindree() const;

    /**
     * @brief Modifie la cylindrée du moteur.
     * @param newCylindree Nouvelle cylindrée en cm3.
     */
    void setCylindree(float newCylindree);

    /**
     * @brief Représentation textuelle du moteur thermique.
     * @return Chaîne décrivant le moteur.
     */
    std::string toString() const override;
};

#endif // THERMIQUE_HPP
