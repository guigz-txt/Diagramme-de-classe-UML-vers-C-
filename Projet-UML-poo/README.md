# TP UML vers C++ — Conducteur / Moto / Moteur

Implémentation C++ du diagramme de classe du TP (BTS CIEL2 IR, école Brocéliande).

## Structure

```
include/       Fichiers d'en-tête (.hpp)
src/           Fichiers source (.cpp), dont main.cpp
Doxyfile       Configuration Doxygen
```

## Modélisation

- **Composition** Moto ↔ Moteur : une `Moto` possède son `Moteur` (alloué
  avec `new` puis confié au constructeur de `Moto`) et le détruit dans son
  destructeur.
- **Agrégation** Conducteur ↔ Moto : un `Conducteur` référence des `Moto*`
  sans en être propriétaire ; c'est à l'appelant (`main`) de les détruire.
- **Héritage** Moteur → Electrique / Thermique, avec destructeur virtuel et
  `toString()` polymorphe.

## Compiler et exécuter

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o main
./main
```

## Générer la documentation Doxygen

```bash
doxygen Doxyfile
# ouvrir docs/html/index.html dans un navigateur
```

## Mettre le projet sur GitHub

1. Créer un dépôt vide sur GitHub (sans README, sans licence).
2. Depuis ce dossier :

```bash
git init                              # si pas déjà fait
git add .
git commit -m "Initial commit : structure du projet"
git branch -M main
git remote add origin <URL_DE_VOTRE_DEPOT>
git push -u origin main
```

3. Pour le travail en groupe (dépôt partagé) :

```bash
git clone <URL_DU_DEPOT>   # récupérer le dépôt en local
git pull                   # récupérer + fusionner les modifications
git fetch                  # récupérer sans fusionner
git add <fichiers>
git commit -m "Message clair et précis"
git push                   # envoyer vos commits
```

Pensez à faire des commits fréquents et bien décrits (c'est noté),
et à répartir le travail équitablement entre les membres du groupe.
