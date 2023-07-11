/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : affichage.h
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : fichier contenant les fonctions permettant d'afficher les véhicules, les
                    caractéristiques des véhicules et les statistiques.
Remarque(s)       :
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/

#ifndef TAXES_AFFICHAGE_H
#define TAXES_AFFICHAGE_H

#include "vehicule.h"

// Permet d'aligner l'affichage des chiffres
void afficherAligner(const char* texte, int16_t espace);

void afficherTypeVehicule(const Vehicule* v);

void afficherSpecVoitureHg(const VoitureHautdeGamme* v);

void afficherSpecVoitureStd(const VoitureStandard* v);

void afficherSpecVoiture(const Voiture* v);

void afficherSpecCamionnette(const Camionnette* c);

void afficherVehicule(const Vehicule* v);

// Arrondi la valeur réelle à 5 centimes près
double arrondiCentimesPres(uint16_t centimes, double valeur);

void afficherStatistiques(double* taxes, size_t nbVehicules);

void afficherTaxeVehicule(const Vehicule* v);

#endif
