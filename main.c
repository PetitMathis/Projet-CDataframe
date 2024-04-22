#include "column.h"


int main() {
    COLUMN *mycol = create_column("My column");
    printf("Titre de la column: %s\n", mycol->titre);
    printf("Taille logique: %d\n", mycol->taille_logique);
    printf("Taille physique: %d\n", mycol->taille_physique);
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);
    printf("Titre de la column: %s\n", mycol->titre);
    printf("Taille logique: %d\n", mycol->taille_logique);
    printf("Taille physique: %d\n", mycol->taille_physique);
    printf("Le nombre d'occurence de %d est %d\n", 44,occurence(mycol, 44));
    printf("Le nombre d'occurence de %d est %d\n", 15,occurence(mycol, 15));
    printf("Le nombre d'occurence de %d est %d\n", 4,occurence(mycol, 4));
    printf("La valeur a l'indice %d est %d\n",1,recherche(mycol,1) );
    printf("La valeur a l'indice %d est %d\n",3,recherche(mycol,3) );
    printf("La valeur a l'indice %d est %d\n",15,recherche(mycol,15) );
    printf("Le nombre de valeur superieur a %d est %d\n",14,nb_val_sup(mycol, 14));
    printf("Le nombre de valeur superieur a %d est %d\n",40,nb_val_sup(mycol, 40));
    printf("Le nombre de valeur inferieur a %d est %d\n",14,nb_val_sup(mycol, 14));
    printf("Le nombre de valeur inferieur a %d est %d\n",45,nb_val_sup(mycol, 45));
    printf("Le nombre de valeur egal a %d est %d\n",14,nb_val_sup(mycol, 14));
    printf("Le nombre de valeur egal a %d est %d\n",5,nb_val_sup(mycol, 5));
    printf("Le nombre de valeur egal a %d est %d\n",44,nb_val_sup(mycol, 44));
    free(mycol->titre);
    free(mycol->donnees);
    free(mycol);
    return 0;
}//
// Created by Mathis on 22/04/2024.
//
