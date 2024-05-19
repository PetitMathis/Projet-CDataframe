#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *titre;
    int taille_physique;
    int taille_logique;
    int *donnees;
} COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN* col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int occurence(COLUMN* col, int x);

int recherche(COLUMN* col, int indice);

int nb_val_sup(COLUMN* col, int val);

int nb_val_inf(COLUMN* col, int val);

int nb_val_egal(COLUMN* col, int val);