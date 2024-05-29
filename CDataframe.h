#include "column.h"

typedef struct{
    COLUMN **column;
    int taille_log;
    int taille_phy;
}CDataframe;

// Création d'un CDataframe vide
CDataframe *create_dataframe();

// Remplissage du CDataframe à partir de saisies utilisateurs
void Remplissage_utilisateur(CDataframe *df);

// Remplissage en dur du CDataframe
void Remplissage_dur(CDataframe *df);
// Afficher tout le CDataframe

void afficher_dataframe(CDataframe *df);
// Afficher une partie des lignes du CDataframe selon une limite fournie par l'utilisateur
void afficher_ligne(CDataframe *df, int limit);

// Afficher une partie des colonnes du CDataframe selon une limite fournie par l'utilisateur
void afficher_colonne(CDataframe *df, int limit);

// Ajouter une ligne de valeurs au CDataframe
void ajouter_ligne(CDataframe *df);

// Supprimer une ligne de valeurs du CDataframe
void supprimer_ligne(CDataframe *df);

// Ajouter une colonne au CDataframe
void ajouter_colonne(CDataframe *df);

// Supprimer une colonne du CDataframe
void supprimer_colonne(CDataframe *df);

// Renommer le titre d'une colonne du CDataframe
void renommer_colonne(CDataframe *df);
// Vérifier l'existence d'une valeur (recherche) dans le CDataframe
int verif_valeur( CDataframe *df);

// Accéder/remplacer la valeur se trouvant dans une cellule du CDataframe
void remplacer_valeur(CDataframe *df);

// Afficher les noms des colonnes
void afficher_noms_colonnes(CDataframe *df);
// Afficher le nombre de lignes
void nombres_lignes(CDataframe *df);

// Afficher le nombre de colonnes
void nombres_colonnes(CDataframe *df);

// Nombre de cellules contenant une valeur égale à x (x donné en paramètre)
int nb_valeur_egal(CDataframe *df, int value);

// Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
int nb_valeur_sup(CDataframe *df, int value);

// Nombre de cellules contenant une valeur inférieure à x (x donné en paramètre)
int nb_valeur_inf(CDataframe *df, int value);

void delete_dataframe(CDataframe **df);