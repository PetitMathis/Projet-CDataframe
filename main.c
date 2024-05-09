#include "CDataframe.h"


int main() {
    CDataframe *mydf = create_dataframe();
    Remplissage_dur(mydf);
    afficher_dataframe(mydf);
    afficher_noms_colonnes(mydf);
    /*
    remplacer_valeur(mydf);
    afficher_dataframe(mydf);

    renommer_colonne(mydf);
    afficher_dataframe(mydf);

    ajouter_ligne(mydf);
    afficher_dataframe(mydf);

    supprimer_ligne(mydf);
    afficher_dataframe(mydf);

    supprimer_colonne(mydf);
    afficher_dataframe(mydf);

    ajouter_colonne(mydf);
    afficher_dataframe(mydf);
    */
    return 0;
}
// Created by Mathis on 22/04/2024.
//
