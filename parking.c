/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : parking.c
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : Implémentation des fonctions de parking.h
Remarque(s)       : 
Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/
#include "parking.h"
#include "statistiques.h"
#include "taxe.h"
#include "affichage.h"
#include <stdlib.h> //qsort()

int compTaxesVehicules(const void* v1, const void* v2) {
    double taxeV1 = calculerTaxe((Vehicule*) v1);
    double taxeV2 = calculerTaxe((Vehicule*) v2);
    if (taxeV1 < taxeV2)
        return 1;
    else if (taxeV1 == taxeV2)
        return 0;
    else return -1;
}

void trierParkingParTaxeDecroissante(Vehicule* parking, size_t nbVehicules) {
    qsort(parking, nbVehicules, sizeof(Vehicule), compTaxesVehicules);
}

void trierParkingParTypeVehicule(Vehicule* parking, size_t nbVehicules) {
    qsort(parking, nbVehicules, sizeof(Vehicule), compTypeVehicules);
}
void trierParkingParTypeVoiture(Vehicule* parking, size_t nbVoitures) {
    qsort(parking, nbVoitures, sizeof(Vehicule), compTypeVoitures);
}

void afficherParking(const Vehicule* parking, size_t nbVehicules) {
    for (size_t i = 0; i < nbVehicules; ++i) {
        printf("Vehicule no %zd \n", i + 1);
        afficherVehicule(parking + i);
        afficherTaxeVehicule(parking + i);
        printf("\n");
    }
}


void calculerStatistiques(Vehicule* v, size_t nbVehicules) {

    //Trier pour mettre les camionnettes au début
    trierParkingParTypeVehicule(v, nbVehicules);

    //Compter le nombre de voitures et camionnettes
    size_t nbCamionettes = compterTypeVehicule(v, nbVehicules, CAMIONNETTE);
    size_t nbVoitures = compterTypeVehicule(v, nbVehicules, VOITURE);

    trierParkingParTypeVoiture(v + nbCamionettes, nbVoitures);

    //Compter ne nombre de voitures haut de gamme et voitures standard
    size_t nbVoituresStandard = compterTypeVoiture(v + nbCamionettes, nbVoitures, STANDARD);
    size_t nbVoituresHautDeGamme = compterTypeVoiture(v + nbCamionettes, nbVoitures, HAUT_DE_GAMME);

    double* taxesCamionettes = taxesParVehicule(v, nbCamionettes);
    double* taxesVoituresStandard = taxesParVehicule(v + nbCamionettes, nbVoituresStandard);
    double* taxesVoituresHautDeGamme = taxesParVehicule(v + nbCamionettes, nbVoituresHautDeGamme);

    printf("Camionettes\n");
    afficherStatistiques(taxesCamionettes, nbCamionettes);
    printf("\n");

    printf("Voitures standard\n");
    afficherStatistiques(taxesVoituresStandard, nbVoituresStandard);
    printf("\n");

    printf("Voitures haut de gamme\n");
    afficherStatistiques(taxesVoituresHautDeGamme, nbVoituresHautDeGamme);
    printf("\n");

    //Libérer la mémoire allouée dans taxesParVehicule()
    free(taxesCamionettes);
    free(taxesVoituresStandard);
    free(taxesVoituresHautDeGamme);
}
