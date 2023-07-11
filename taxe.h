/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : taxe.h
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : fonction permettant de calculer les taxes, soit annuelle ou spécifique
Remarque(s)       : 
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/
#ifndef TAXES_TAXE_H
#define TAXES_TAXE_H

#include "vehicule.h"

// Calcule la taxe de base d'un vehicule
uint16_t taxeBase(const Vehicule* v);

// Calcule la taxe spécifique d'une voiture haut de gamme
double taxeSpecifiqueVoitureHG(const VoitureHautdeGamme* v, uint16_t poids);

// Calcule la taxe spécifique d'une voiture standard
double taxeSpecifiqueVoitureStd(const VoitureStandard* v);

// Calcule la taxe spécifique d'une voiture
double taxeSpecifiqueVoiture(const Voiture* v);

// Calcule la taxe spécifique d'une camionnette
double taxeSpecifiqueCamionnette(const Camionnette* c);

// Calcule la taxe spécifique d'un véhicule
double taxeSpecifique(const Vehicule* v);

// Calcule la taxe annuelle d'un véhicule
double calculerTaxe(const Vehicule* v);

// Calcule la taxe annuelle d'un tableau de véhicules. Retourne un tableau de double
// Note : Ne pas oublier de libérer la mémoire allouée depuis l'extérieur de la fonction.
double* taxesParVehicule(Vehicule* v, size_t n);

#endif //TAXES_TAXE_H
