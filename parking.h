/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : parking.h
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : contient les fonctions d'affichage de l'ensemble des caractéristiques d'un véhicule
                    et des différentes taxes (la somme, la moyenne, la médiane et l'écart-type)
Remarque(s)       : 
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/
#ifndef TAXES_PARKING_H
#define TAXES_PARKING_H

#include <stdio.h>              //size_t
#include "vehicule.h"

// Trie un tableau de vehicules par ordre CAMIONNETTE puis VOITURE
void trierParkingParTypeVehicule(Vehicule* parking, size_t nbVehicules);

//comparaison de taxes entre chaque véhicule
int compTaxesVehicules(const void* v1, const void* v2);

void calculerStatistiques(Vehicule* v, size_t nbVehicules);

void trierParkingParTaxeDecroissante(Vehicule* parking, size_t nbVehicules);

void afficherParking(const Vehicule* parking, size_t nbVehicules);

#endif //TAXES_PARKING_H
