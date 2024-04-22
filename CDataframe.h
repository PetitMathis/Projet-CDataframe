#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "column.h"

typedef struct{
    COLUMN **column;
    int taille_log;
    int taille_phy;
}CDataframe;

// Création d'un CDataframe vide
CDataframe* create_dataframe();

// Remplissage du CDataframe à partir de saisies utilisateurs
void Remplissage_utilisateur(CDataframe *df);

// Remplissage en dur du CDataframe
void Remplissage_dur(CDataframe *df);

// Afficher tout le CDataframe
void afficher_dataframe(const CDataframe *df);

// Afficher une partie des lignes du CDataframe selon une limite fournie par l'utilisateur
void afficher_ligne(const CDataframe *df, int limit);

// Afficher une partie des colonnes du CDataframe selon une limite fournie par l'utilisateur
void afficher_colonne(const CDataframe *df, int limit);

// Ajouter une ligne de valeurs au CDataframe
void ajouter_ligne(CDataframe *df, int *values, int num_values);

// Supprimer une ligne de valeurs du CDataframe
void supprimer_ligne(CDataframe *df, int row_index);

// Ajouter une colonne au CDataframe
void ajouter_colonne(CDataframe *df, const char *title);

// Supprimer une colonne du CDataframe
void supprimer_colonne(CDataframe *df, const char *title);

// Renommer le titre d'une colonne du CDataframe
void renommer_colonne(CDataframe *df, const char *old_title, const char *new_title);

// Vérifier l'existence d'une valeur (recherche) dans le CDataframe
int verif_valeur(const CDataframe *df, int value);

// Accéder/remplacer la valeur se trouvant dans une cellule du CDataframe
void remplacer_valeur(CDataframe *df, int row_index, const char *column_title, int new_value);

// Afficher les noms des colonnes
void afficher_noms_colonnes(const CDataframe *df);

// Afficher le nombre de lignes
int nombres_lignes(const CDataframe *df);

// Afficher le nombre de colonnes
int nombres_colonnes(const CDataframe *df);

// Nombre de cellules contenant une valeur égale à x (x donné en paramètre)
int nb_valeur_egal(const CDataframe *df, int value);

// Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
int nb_valeur_sup(const CDataframe *df, int value);

// Nombre de cellules contenant une valeur inférieure à x (x donné en paramètre)
int nb_valeur_inf(const CDataframe *df, int value);
