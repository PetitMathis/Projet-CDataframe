#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "column.h"

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char* title){
    COLUMN *new_column = (COLUMN*)malloc(sizeof(COLUMN));
    if (new_column == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return 0;
    }
    new_column->titre = (char*)malloc((strlen(title) + 1) * sizeof(char));
    strcpy(new_column->titre,title); // Copie de la chaîne de titre
    new_column->donnees = NULL; // Allocation initiale
    new_column->taille_logique = 0; // Initialisation de la taille logique à 0
    new_column->taille_physique = 0; // Initialisation de la taille physique
    return new_column;

}

/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN* col, int value){
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
        return 0;
    }
    if (col->taille_logique == col->taille_physique) {
        col->taille_physique += 256;
        int* new_donnees = (int *)realloc(col->donnees, (col->taille_physique) * sizeof(int));
        if (new_donnees == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
            return 0;
        }
        col->donnees = new_donnees;
    }
    *((col->donnees)+(col->taille_logique)) = value;
    col->taille_logique += 1;
    return 1;

}

/**
* Free allocated memory
* @param col : Pointer to a column
*/
void delete_column(COLUMN **col) {
    if (col == NULL || *col == NULL) {
        fprintf(stderr, "La colonne est NULL\n");
    }
    else{

        // Libérer le tableau de données
        free((*col)->donnees);
        (*col)->donnees = NULL;

        // Libérer le titre de la colonne
        free((*col)->titre);
        (*col)->titre = NULL;

        // Libérer la structure de la colonne
        free(*col);
        *col = NULL;
    }
}


/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN* col){
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
    }
    else{
        for (int i = 0; i < col->taille_logique;i++) {
            printf("[%d] %d\n", i, col->donnees[i]);
        }
    }
}

int occurence(COLUMN* col, int x){
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
        return -1;
    }
    int occ = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (col->donnees[i] == x){
            occ++;
        }
    }
    return occ;
}

int recherche(COLUMN* col, int indice) {
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
        return -1;
    }
    if (indice >= col->taille_logique){
        printf("La position %d est superieur a la taille du tableau",indice);
        return -1;
    }
    return col->donnees[indice];
}

int nb_val_sup(COLUMN* col, int val){
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
        return -1;
    }
    int nb = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (val < col->donnees[i]){
            nb++;
        }
    }
    return nb;
}

int nb_val_inf(COLUMN* col, int val){
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
        return -1;
    }
    int nb = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (val > col->donnees[i]) {
            nb++;
        }
    }
    return nb;
}

int nb_val_egal(COLUMN* col, int val){
    if (col == NULL){
        fprintf(stderr, "La colonne est NULL\n");
        return -1;
    }
    int nb = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (val == col->donnees[i]){
            nb++;
        }
    }
    return nb;
}
