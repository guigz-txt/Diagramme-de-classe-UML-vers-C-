#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP

#include "Moteur.hpp"

/**
 * @file Electrique.hpp
 * @brief Déclaration de la classe Electrique, dérivée de Moteur.
 */

/**
 * @class Electrique
 * @brief Moteur électrique, caractérisé par sa tension maximale.
 */
class Electrique : public Moteur {
private:
    float tensionMax; ///< Tension maximale supportée par le moteur, en volts.

public:
    /**
     * @brief Construit un moteur électrique.
     * @param puissance Puissance du moteur en watts.
     * @param tensionMax Tension maximale en volts.
     */
    Electrique(int puissance, float tensionMax);

    /**
     * @brief Destructeur.
     */
    ~Electrique() override;

    /**
     * @brief Récupère la tension maximale du moteur.
     * @return Tension maximale en volts.
     */
    float getTensionMax() const;

    /**
     * @brief Modifie la tension maximale du moteur.
     * @param tensionMax Nouvelle tension maximale en volts.
     */
    void setTensionMax(float tensionMax);

    /**
     * @brief Représentation textuelle du moteur électrique.
     * @return Chaîne décrivant le moteur.
     */
    std::string toString() const override;
};

#endif // ELECTRIQUE_HPP
