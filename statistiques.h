/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : statistiques.h
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : fonctions permettant de calculer les statistiques
Remarque(s)       : les fonctions n'ont pas besoin d'utiliser un objet de type vehicule, ce qui les
                    permets d'être génériques
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/

#ifndef TAXES_STATISTIQUES_H
#define TAXES_STATISTIQUES_H

#include <stdio.h> //size_t

//***********************************************************************************
// Fonctions générales de calcul statistique à partir d'un tableau de double
//***********************************************************************************

double mediane(const double valeurs[], size_t n);

double somme(const double valeurs[], size_t n);

double moyenne(const double valeurs[], size_t n);

double variance(const double valeurs[], size_t n);

double ecartType(const double valeurs[], size_t n);

#endif //TAXES_STATISTIQUES_H
