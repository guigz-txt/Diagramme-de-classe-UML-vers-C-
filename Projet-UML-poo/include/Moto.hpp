#ifndef MOTO_HPP
#define MOTO_HPP

#include <string>
#include "Moteur.hpp"

/**
 * @file Moto.hpp
 * @brief Déclaration de la classe Moto.
 */

/**
 * @class Moto
 * @brief Représente une moto, composée d'un moteur.
 *
 * La relation entre Moto et Moteur est une composition : une Moto
 * possède son moteur et est responsable de sa destruction. Le moteur
 * doit donc être alloué dynamiquement (new) avant d'être confié à la
 * Moto via son constructeur.
 */
class Moto {
private:
    int poids;           ///< Poids de la moto, en kilogrammes.
    std::string couleur; ///< Couleur de la moto.
    std::string nom;     ///< Nom / modèle de la moto.
    Moteur* moteur;      ///< Moteur de la moto (composition : possédé par la Moto).

public:
    /**
     * @brief Construit une moto à partir d'un moteur et d'une couleur.
     * @param moteur Pointeur vers un moteur alloué dynamiquement (la Moto
     *        en devient propriétaire et le détruira dans son destructeur).
     * @param couleur Couleur de la moto.
     * @param nom Nom / modèle de la moto (optionnel).
     * @param poids Poids de la moto en kg (optionnel, 0 par défaut).
     */
    Moto(Moteur* moteur, const std::string& couleur,
         const std::string& nom = "", int poids = 0);

    /**
     * @brief Destructeur : détruit le moteur possédé (composition).
     */
    ~Moto();

    // La Moto possède son moteur en propriété exclusive : on interdit la
    // copie implicite pour éviter une double destruction du moteur.
    Moto(const Moto& other) = delete;
    Moto& operator=(const Moto& other) = delete;

    /**
     * @brief Récupère le poids de la moto.
     * @return Poids en kilogrammes.
     */
    int getPoids() const;

    /**
     * @brief Modifie le poids de la moto.
     * @param poids Nouveau poids en kilogrammes.
     */
    void setPoids(int poids);

    /**
     * @brief Récupère la couleur de la moto.
     * @return Couleur de la moto.
     */
    std::string getCouleur() const;

    /**
     * @brief Récupère le moteur de la moto.
     * @return Pointeur vers le moteur (toujours valide, ne pas détruire
     *         en dehors de la Moto).
     */
    Moteur* getMoteur() const;

    /**
     * @brief Calcule l'accélération théorique de la moto à 50 km/h.
     *
     * Formule utilisée : a = P / (m * v), avec P la puissance du moteur
     * (W), m le poids de la moto (kg) et v = 50 km/h converti en m/s.
     *
     * @return Accélération théorique en m/s^2 (0 si le poids est nul).
     */
    float getAcceleration() const;

    /**
     * @brief Construit une représentation textuelle de la moto.
     * @return Chaîne décrivant la moto et son moteur.
     */
    std::string toString() const;
};

#endif // MOTO_HPP
