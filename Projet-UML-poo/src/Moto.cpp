#include "Moto.hpp"
#include <sstream>

namespace {
    constexpr float VITESSE_REF_KMH = 50.0f;
    constexpr float KMH_EN_MS = 3.6f; // 1 m/s = 3.6 km/h
}

Moto::Moto(Moteur* moteur, const std::string& couleur,
           const std::string& nom, int poids)
    : poids(poids), couleur(couleur), nom(nom), moteur(moteur) {}

Moto::~Moto() {
    delete moteur; // composition : la Moto est propriétaire de son moteur
}

int Moto::getPoids() const {
    return poids;
}

void Moto::setPoids(int poids) {
    this->poids = poids;
}

std::string Moto::getCouleur() const {
    return couleur;
}

Moteur* Moto::getMoteur() const {
    return moteur;
}

float Moto::getAcceleration() const {
    if (poids <= 0 || moteur == nullptr) {
        return 0.0f;
    }
    float vitesseMs = VITESSE_REF_KMH / KMH_EN_MS; // 50 km/h -> m/s
    if (vitesseMs <= 0.0f) {
        return 0.0f;
    }
    // a = P / (m * v)
    return static_cast<float>(moteur->getPuissance()) / (poids * vitesseMs);
}

std::string Moto::toString() const {
    std::ostringstream oss;
    oss << "Moto [nom=" << nom
        << ", couleur=" << couleur
        << ", poids=" << poids << "kg"
        << ", acceleration@50km/h=" << getAcceleration() << "m/s^2"
        << ", " << (moteur ? moteur->toString() : "aucun moteur") << "]";
    return oss.str();
}
