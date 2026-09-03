#ifndef CONDUCTEUR_HPP
#define CONDUCTEUR_HPP

#include <string>
#include <vector>
#include "Moto.hpp"

/**
 * @file Conducteur.hpp
 * @brief Déclaration de la classe Conducteur.
 */

/**
 * @class Conducteur
 * @brief Représente un conducteur pouvant posséder plusieurs motos.
 *
 * La relation entre Conducteur et Moto est une agrégation : le
 * Conducteur référence des Moto sans en être propriétaire. Une même
 * Moto pourrait donc, en théorie, survivre à son Conducteur ; c'est
 * pourquoi le destructeur de Conducteur ne détruit pas les motos.
 */
class Conducteur {
private:
    std::string nom;             ///< Nom du conducteur.
    std::string prenom;          ///< Prénom du conducteur.
    int anneeNaissance;          ///< Année de naissance du conducteur.
    std::vector<Moto*> mesMotos; ///< Motos du conducteur (agrégation : non possédées).

public:
    /**
     * @brief Construit un conducteur.
     * @param nom Nom du conducteur.
     * @param prenom Prénom du conducteur.
     * @param anneeNaissance Année de naissance du conducteur.
     */
    Conducteur(const std::string& nom, const std::string& prenom, int anneeNaissance);

    /**
     * @brief Destructeur.
     *
     * N'entraîne pas la destruction des motos (agrégation) : celles-ci
     * doivent être détruites par leur propriétaire réel (typiquement le
     * code appelant / main, qui les a créées avec new).
     */
    ~Conducteur();

    /**
     * @brief Récupère le nom du conducteur.
     * @return Nom du conducteur.
     */
    std::string getNom() const;

    /**
     * @brief Récupère le prénom du conducteur.
     * @return Prénom du conducteur.
     */
    std::string getPrenom() const;

    /**
     * @brief Récupère l'année de naissance du conducteur.
     * @return Année de naissance.
     */
    std::string getAnneeNaissance() const;

    /**
     * @brief Ajoute une moto au conducteur.
     * @param newMoto Pointeur vers la moto à ajouter (non possédée).
     */
    void addMoto(Moto* newMoto);

    /**
     * @brief Retire une moto du conducteur.
     * @param rmMoto Pointeur vers la moto à retirer.
     */
    void rmMoto(Moto* rmMoto);

    /**
     * @brief Construit une représentation textuelle du conducteur.
     *
     * Inclut les informations de toutes les motos possédées.
     *
     * @return Chaîne décrivant le conducteur et ses motos.
     */
    std::string toString() const;
};

#endif // CONDUCTEUR_HPP
