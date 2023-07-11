/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : affichage.c
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : Implémentation des fonctions de affichage.h
Remarque(s)       :
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/

#include "affichage.h"
#include <inttypes.h>   //PRIu16
#include <stdio.h>      //printf()
#include <math.h>       //round()
#include "taxe.h"
#include "statistiques.h"

const char* const   UNITE_PUISSANCE     = "[CV]";
const char* const   UNITE_POIDS         = "[kg]";
const char* const   UNITE_VOLUME        = "[m3]";
const char* const   UNITE_POLLUTION     = "[g/km]";
const char* const   UNITE_CYLINDREE     = "[cm3]";
const char* const   DEVISE              = "CHF";
const char* const   TYPE_VEHICULE[]     = {"Voiture", "Camionnette"};
const char* const   TYPE_VOITURE[]      = {"Standard", "Haut de gamme"};
const uint16_t      CENTIMES            = 5;
const int16_t       ESPACE_AFFICHAGE    = -24; //alignement gauche

void afficherAligner(const char* texte, int16_t espace) {
    printf("%*s : ", espace, texte);
}

void afficherTypeVehicule(const Vehicule* v) {
    afficherAligner("Type de vehicule", ESPACE_AFFICHAGE);
    printf("%s ", TYPE_VEHICULE[v->typeVehicule]);
    if (v->typeVehicule == CAMIONNETTE)
        printf("\n");
    else
        printf("%s\n", TYPE_VOITURE[v->specificitesVehicule.voiture.typeVoiture]);
}

void afficherSpecVoitureHg(const VoitureHautdeGamme* v) {
    afficherAligner("Puissance", ESPACE_AFFICHAGE);
    printf("%"PRIu16" %s\n", v->puissance, UNITE_PUISSANCE);
}

void afficherSpecVoitureStd(const VoitureStandard* v) {
    afficherAligner("Cylindree", ESPACE_AFFICHAGE);
    printf("%"PRIu16" %s\n", v->cylindree, UNITE_CYLINDREE);

    afficherAligner("CO2", ESPACE_AFFICHAGE);
    printf("%"PRIu16" %s\n", v->co2, UNITE_POLLUTION);
}

void afficherSpecVoiture(const Voiture* v) {
    if (v->typeVoiture == STANDARD) {
        afficherSpecVoitureStd(&v->specificitesVoiture.standard);
    } else {
        afficherSpecVoitureHg(&v->specificitesVoiture.hautDeGamme);
    }
    afficherAligner("Poids", ESPACE_AFFICHAGE);
    printf("%"PRIu16" %s\n", v->poids, UNITE_POIDS);
}

void afficherSpecCamionnette(const Camionnette* c) {
    afficherAligner("Volume", ESPACE_AFFICHAGE);
    printf("%.2f %s\n", c->volume, UNITE_VOLUME);
}

void afficherVehicule(const Vehicule* v) {
    afficherTypeVehicule(v);

    afficherAligner("Immatriculation", ESPACE_AFFICHAGE);
    printf("%s\n", v->immatriculation);

    afficherAligner("Marque", ESPACE_AFFICHAGE);
    printf("%s\n", v->marque);

    if (v->typeVehicule == VOITURE)
        afficherSpecVoiture(&v->specificitesVehicule.voiture);
    else
        afficherSpecCamionnette(&v->specificitesVehicule.camionnette);
}

double arrondiCentimesPres(uint16_t centimes, double valeur) {
    //arrondi au centime près (2 chiffres après la virgule)
    valeur = valeur * 100 / centimes;
    valeur = round(valeur);
    valeur = valeur * centimes / 100;
    return valeur;
}

void afficherStatistiques(double* taxes, size_t nbVehicules) {
    double SommeArrondie = arrondiCentimesPres(CENTIMES, somme(taxes, nbVehicules));
    afficherAligner("Somme", ESPACE_AFFICHAGE);
    printf("%.2f\n", SommeArrondie);

    double moyenneArrondie = arrondiCentimesPres(CENTIMES, moyenne(taxes, nbVehicules));
    afficherAligner("Moyenne", ESPACE_AFFICHAGE);
    printf("%.2f\n", moyenneArrondie);

    double medianeArrondie = arrondiCentimesPres(CENTIMES, mediane(taxes, nbVehicules));
    afficherAligner("Mediane", ESPACE_AFFICHAGE);
    printf("%.2f\n", medianeArrondie);

    double ecartTypeArrondi = arrondiCentimesPres(CENTIMES, ecartType(taxes, nbVehicules));
    afficherAligner("Ecart-type", ESPACE_AFFICHAGE);
    printf("%.2f\n", ecartTypeArrondi);
}

void afficherTaxeVehicule(const Vehicule* v) {
    double taxe = arrondiCentimesPres((int) CENTIMES, calculerTaxe(v));
    afficherAligner("Taxe du vehicule", ESPACE_AFFICHAGE);
    printf("%.2f %s\n", taxe, DEVISE);
}
