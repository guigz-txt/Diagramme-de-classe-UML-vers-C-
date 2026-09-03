#include "Conducteur.hpp"
#include <algorithm>
#include <sstream>

Conducteur::Conducteur(const std::string& nom, const std::string& prenom, int anneeNaissance)
    : nom(nom), prenom(prenom), anneeNaissance(anneeNaissance) {}

Conducteur::~Conducteur() {
    // Agrégation : on ne détruit pas les motos, on vide juste la liste.
    mesMotos.clear();
}

std::string Conducteur::getNom() const {
    return nom;
}

std::string Conducteur::getPrenom() const {
    return prenom;
}

std::string Conducteur::getAnneeNaissance() const {
    return std::to_string(anneeNaissance);
}

void Conducteur::addMoto(Moto* newMoto) {
    if (newMoto != nullptr) {
        mesMotos.push_back(newMoto);
    }
}

void Conducteur::rmMoto(Moto* rmMoto) {
    mesMotos.erase(std::remove(mesMotos.begin(), mesMotos.end(), rmMoto), mesMotos.end());
}

std::string Conducteur::toString() const {
    std::ostringstream oss;
    oss << "Conducteur [nom=" << nom
        << ", prenom=" << prenom
        << ", anneeNaissance=" << anneeNaissance
        << ", nbMotos=" << mesMotos.size() << "]\n";
    for (const Moto* m : mesMotos) {
        oss << "    - " << (m ? m->toString() : "moto invalide") << "\n";
    }
    return oss.str();
}
