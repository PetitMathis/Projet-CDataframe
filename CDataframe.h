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
CDataframe *create_dataframe(){
    CDataframe *new_cdata = (CDataframe*)malloc(sizeof(CDataframe));
    if (new_cdata == NULL){
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return 0;
    }
    new_cdata->column = NULL;
    new_cdata->taille_log = 0;
    new_cdata->taille_phy = 0;
    return new_cdata;
}


// Remplissage du CDataframe à partir de saisies utilisateurs
void Remplissage_utilisateur(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else{
        int c=0,l=0;
        printf("Combien de colonne voulez vous ajouter : ");
        scanf("%d",&c);
        getchar();
        printf("Combien de ligne voulez vous ajouter : ");
        scanf("%d",&l);
        getchar();

        for (int i = 0; i<c ; i++){

            if (df->taille_log == df->taille_phy) {
                df->taille_phy += 256;
                COLUMN **new_df = (COLUMN **) realloc(df->column, (df->taille_phy) * sizeof(COLUMN*));
                if (new_df == NULL) {
                    fprintf(stderr, "Erreur d'allocation de mémoire\n");
                }
                df->column = new_df;
            }
            char titre[256]; // Taille maximale du titre
            printf("Entrez le titre de la colonne %d : ", i );
            fgets(titre, sizeof(titre), stdin);
            titre[strcspn(titre, "\n")] = '\0';

            COLUMN *mycol = create_column(titre);

            for (int j = 0 ; j<l ; j++){
                int val = 0;
                printf("Veuillez saisir la valeur %d de la colonne %s :",j,mycol->titre);
                scanf("%d",&val);
                getchar();
                insert_value(mycol, val);
            }
            *(df->column + df->taille_log) = mycol;
            df->taille_log++ ;

        }
    }

}

// Remplissage en dur du CDataframe
void Remplissage_dur(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else{
        df->taille_log = 2;
        df->taille_phy = 256;
        COLUMN **new_df = (COLUMN **) realloc(df->column, (df->taille_phy) * sizeof(COLUMN*));
        if (new_df == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
        }
        df->column = new_df;
        COLUMN *mycol = create_column("gg");
        COLUMN *mcol = create_column("jjk");
        insert_value(mycol, 2);
        insert_value(mycol, 4);
        insert_value(mcol, 3);
        insert_value(mcol, 9);
        *(df->column) = mycol;
        *(df->column + 1) = mcol;
    }
}


// Afficher tout le CDataframe
void afficher_dataframe(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else{
        for (int k = 0 ; k < df->taille_log ; k++) {
            printf(" %s ",df->column[k]->titre);
        }
        printf("\n");
        int taille = (df->column[0])->taille_logique;
        for (int i = 0 ; i < taille ; i++){
            for (int j = 0 ; j < df->taille_log ; j++){

                printf(" %d ",((df->column[j])->donnees)[i]);
            }
            printf("\n");
        }
    }
}

// Afficher une partie des lignes du CDataframe selon une limite fournie par l'utilisateur
void afficher_ligne(const CDataframe *df, int limit){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else{

    }
}

// Afficher une partie des colonnes du CDataframe selon une limite fournie par l'utilisateur
void afficher_colonne(const CDataframe *df, int limit){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
}

// Ajouter une ligne de valeurs au CDataframe
void ajouter_ligne(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else{
        for (int i = 0;i<(df->taille_log);i++){
            int val = 0;
            printf("Veuillez saisir la valeur a ajouter a la colonne %s :",(df->column[i])->titre);
            scanf("%d",&val);
            getchar();
            insert_value(df->column[i], val);
        }
    }
}

// Supprimer une ligne de valeurs du CDataframe
void supprimer_ligne(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else {
        for (int i = 0; i < (df->taille_log); i++) {
            ((df->column[i])->taille_logique)--;
        }
    }
}

// Ajouter une colonne au CDataframe
void ajouter_colonne(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");    }
    else{
        if (df->taille_log == df->taille_phy) {
            df->taille_phy += 256;
            COLUMN **new_df = (COLUMN **) realloc(df->column, (df->taille_phy) * sizeof(COLUMN*));
            if (new_df == NULL) {
                fprintf(stderr, "Erreur d'allocation de mémoire\n");
            }
            df->column = new_df;
        }
        char titre[256]; // Taille maximale du titre
        printf("Entrez le titre de la colonne que vous voulez ajouter : " );
        fgets(titre, sizeof(titre), stdin);
        titre[strcspn(titre, "\n")] = '\0';

        COLUMN *mycol = create_column(titre);

        for (int j = 0 ; j< (df->column[0])->taille_logique; j++){
            int val = 0;
            printf("Veuillez saisir la valeur %d de la colonne %s :",j,mycol->titre);
            scanf("%d",&val);
            getchar();
            insert_value(mycol, val);
        }
        *(df->column + df->taille_log) = mycol;
        df->taille_log++ ;
    }
}

// Supprimer une colonne du CDataframe
void supprimer_colonne(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
    }
    else{
        char titre[256]; // Taille maximale du titre
        printf("Entrez le titre de la colonne que vous voulez supprimer : " );
        fgets(titre, sizeof(titre), stdin);
        titre[strcspn(titre, "\n")] = '\0';

        int trouver = 0;

        for (int i = 0; i < (df->taille_log); i++) {
            if (strcmp(titre, df->column[i]->titre) == 0){
                delete_column(&(df->column[i]));
                trouver = 1;
                for (int j = i; j < (df->taille_log)-1;j++){
                    df->column[j] = df->column[j+1];
                }
                df->taille_log--;
            }
        }
        if (!trouver){
            printf("La colonne %s n'existe pas.",titre);
        }
    }
}

// Renommer le titre d'une colonne du CDataframe
void renommer_colonne(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
    }
    else{
        int trouver = 0;
        printf("Quel est le titre de la colonne que vous voulez renommer : ");
        char titre[256];
        fgets(titre, sizeof(titre), stdin);
        titre[strcspn(titre, "\n")] = '\0';
        for (int i = 0; i < df->taille_log; i++){
            if (strcmp(df->column[i]->titre,titre)== 0 ){
                trouver = 1;
                printf("Quel est le nouveau nom de la colonne : " );
                char new_titre[256];
                fgets(new_titre, sizeof(new_titre), stdin);
                new_titre[strcspn(new_titre, "\n")] = '\0';
                free(df->column[i]->titre);
                strcpy(df->column[i]->titre,new_titre);
            }
        }
        if (!trouver){
            printf("La colonne %s n'existe pas.\n",titre);
        }
    }
}

// Vérifier l'existence d'une valeur (recherche) dans le CDataframe
int verif_valeur( CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
        return 0;
    }
    else{
        int trouver = 0;
        int val = 0;
        printf("Quelle valeur voulez-vous rechercher : ");
        scanf("%d",&val);
        for (int i = 0 ; i < df->taille_log ; i++) {
            for (int j = 0; j < df->column[i]->taille_logique; j++) {
                if (df->column[i]->donnees[j] == val){
                    trouver = 1;
                }
            }
        }
        return trouver;
    }

}

// Accéder/remplacer la valeur se trouvant dans une cellule du CDataframe
void remplacer_valeur(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
    }
    else{
        int c = 0, l = 0,val = 0;
        printf("Saisissez le numero de colonne de la valeur que vous voulez changer : ");
        scanf("%d",&c);
        while (c >= df->taille_log){
            printf("Vous avez saisie un numero de colonne supperieur au ombre de colonne.\n");
            printf("Resaisissez le numero de colonne de la valeur que vous voulez changer : ");
            scanf("%d",&c);
        }
        printf("Saisissez le numero de ligne de la valeur que vous voulez changer : ");
        scanf("%d",&l);
        while (l >= df->column[c]->taille_logique){
            printf("Vous avez saisie un numero de ligne supperieur au nombre de ligne.\n");
            printf("Resaisissez le numero de ligne de la valeur que vous voulez changer : ");
            scanf("%d",&l);
        }
        printf("Saisissez la nouvelle valeur : ");
        scanf("%d",&val);
        df->column[c]->donnees[l] = val;
    }
}

// Afficher les noms des colonnes
void afficher_noms_colonnes(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
    }
    else{
        for (int i = 0;i<df->taille_log;i++){
            printf("Titre de la colonne %d : %s\n",i,df->column[i]->titre);
        }
    }
}

// Afficher le nombre de lignes
void nombres_lignes(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
    }
    else{
        printf("Le Dataframe contient %d ligne(s).\n",df->column[0]->taille_logique);
    }
}

// Afficher le nombre de colonnes
void nombres_colonnes(CDataframe *df){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
    }
    else{
        printf("Le Dataframe contient %d colonne(s).\n",df->taille_log);
    }
}

// Nombre de cellules contenant une valeur égale à x (x donné en paramètre)
int nb_valeur_egal(CDataframe *df, int value){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
        return -1;
    }
    else{
        int occ = 0;
        for (int i = 0; i < df->taille_log;i++){
            occ += occurence(df->column[i],value);
        }
        return occ;
    }
}

// Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
int nb_valeur_sup(CDataframe *df, int value){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
        return -1;
    }
    else{
        int sup = 0;
        for (int i = 0; i < df->taille_log;i++){
            sup += nb_val_sup(df->column[i],value);
        }
        return sup;
    }
}

// Nombre de cellules contenant une valeur inférieure à x (x donné en paramètre)
int nb_valeur_inf(CDataframe *df, int value){
    if (df == NULL){
        fprintf(stderr, "Le Dataframe est NULL\n");
        return -1;
    }
    else{
        int inf = 0;
        for (int i = 0; i < df->taille_log;i++){
            inf += nb_val_inf(df->column[i],value);
        }
        return inf;
    }
}
