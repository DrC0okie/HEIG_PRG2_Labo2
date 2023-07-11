/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : statistiques.c
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : Implémentation des fonctions de statistiques.h
Remarque(s)       :
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/

#include "statistiques.h"
#include <math.h>

double mediane(const double valeurs[], size_t n) {
    if (n % 2 == 0) {
        return (valeurs[n / 2] + valeurs[n / 2 - 1]) / 2;
    }
    return valeurs[n / 2];
}

double somme(const double valeurs[], size_t n) {
    double sommeTaxes = 0;
    for (size_t i = 0; i < n; ++i) {
        sommeTaxes += valeurs[i];
    }
    return sommeTaxes;
}

double moyenne(const double valeurs[], size_t n) {
    return somme(valeurs, n) / (double) n;
}

double variance(const double valeurs[], size_t n) {
    double variance = 0;
    double moy = moyenne(valeurs, n);
    for (size_t i = 0; i < n; ++i) {
        variance += pow(valeurs[i] - moy, 2.f);
    }
    variance /= (double) n;
    return variance;
}

double ecartType(const double valeurs[], size_t n) {
    return sqrt(variance(valeurs, n));
}
