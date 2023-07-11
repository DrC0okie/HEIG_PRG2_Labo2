/*
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------

Nom du fichier    : main.c
Auteur(s)         : Émilie Bressoud, Olin Bourquin, Timothée Van Hove
Date création     : 23.05.22
Description       : programme principal qui crée le parking contenant des voitures
                    de luxe, voitures standards et des camionnettes.
                    Les véhicules sont triés par ordre décroissant de taxe.
                    Premier affichage dans la console des caractéristiques et de la taxe annuelle chaque
                    véhicule. Second affichage dans la console des statistiques du parking, (pour
                    chaque type de véhicule: la somme, la moyenne, la médiane et l'écart-type des
                    taxes annuelles dues).

Remarque(s)       : le parking contient intentionnellement un nombre de véhicules de même type
                    différent (pair et impair), ce qui permet de tester les deux calculs de la
                    fonction médiane.
                    Le programme se termine automatiquement apres l'affichage des statistiques

Compilateurs      : Apple clang 13.0.0 et MinGW-W64 11.2.0

−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------------------------------------
*/
#include "vehicule.h"
#include "parking.h"
#include <stdlib.h> //EXIT_SUCCESS

//taille du parking défini ici pour pouvoir connaître la taille du tableau lors de sa compilation
#define TAILLE_MAX_TABLEAU 9

int main(void) {

    //création du parking
    Vehicule parking[TAILLE_MAX_TABLEAU] = {
            voitureStandard("Peugeot", "VD 123456", 1200, 1720, 155),
            voitureHautDeGamme("Rolls-Royce", "ZH 12345", 389, 2150),
            camionnette("Renault", "VS 1234", 15.99),
            voitureHautDeGamme("Audi", "GE 1234", 322, 1750),
            voitureStandard("Citroen", "GR 1234", 1099, 1199, 120),
            voitureHautDeGamme("BMW", "UR 1234", 285, 1885),
            camionnette("Opel", "FR 1234", 12.5),
            voitureStandard("Fiat", "GL 1234", 1130, 1589, 130),
            voitureStandard("Seat", "JU 1234", 1220, 1679, 145),
    };

    trierParkingParTaxeDecroissante(parking, TAILLE_MAX_TABLEAU);
    afficherParking(parking, TAILLE_MAX_TABLEAU);
    calculerStatistiques(parking, TAILLE_MAX_TABLEAU);

    return EXIT_SUCCESS;
}
