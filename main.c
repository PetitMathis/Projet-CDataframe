
/*
Un CDataframe
Viet-tien Tran
Mathis Petit
Fichier contenant le main
 */

#include "CDataframe.h"


int main() {
    int b = 0;
    CDataframe *mydf = create_dataframe();
    Remplissage_dur(mydf);
    while (b==0){
        printf("0--Quitter\n");
        printf("1--Reinitialiser le dataframe\n");
        printf("2--Ajouter une ligne.\n");
        printf("3--Suprimmer une ligne.\n");
        printf("4--Ajouter une colonne.\n");
        printf("5--Suprimmer une colonne.\n");
        printf("6--Renommer une colonne.\n");
        printf("7--Remplacer une valeur.\n");
        printf("8--Verifier l'existance d'une valeur.\n");
        printf("9--Afficher le nom des colonnes.\n");
        printf("10--Afficher le nombres de lignes.\n");
        printf("11--Afficher le nombres de colonnes.\n");
        printf("12--Afficher le nombres d'occurence d'une valeur.\n");
        printf("13--Afficher le nombres de valeur superieur a une valeur.\n");
        printf("14--Afficher le nombres de valeur inferieur a une valeur.\n");
        printf("15--Afficher le nombres de colonnes jusqu'a une limite.\n");
        printf("16--Afficher le nombres de lignes jusqu'a une limite.\n");
        printf("17--Afficher un dataframe.\n");
        printf("\n");
        int a = 0;
        printf("Que voulez vous faire :");
        scanf("%d",&a);
        switch (a) {
            case 0: {
                delete_dataframe(&mydf);
                b = 1;
                break;
            }
            case 1: {
                delete_dataframe(&mydf);
                CDataframe *mydf = create_dataframe();
                Remplissage_utilisateur(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 2: {
                ajouter_ligne(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 3: {
                supprimer_ligne(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 4: {
                ajouter_colonne(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 5: {
                supprimer_colonne(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 6: {
                renommer_colonne(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 7: {
                remplacer_valeur(mydf);
                afficher_dataframe(mydf);
                break;
            }
            case 8: {
                verif_valeur(mydf);
                break;
            }
            case 9: {
                afficher_noms_colonnes(mydf);
                break;
            }
            case 10: {
                nombres_lignes(mydf);
                break;
            }
            case 11: {
                nombres_colonnes(mydf);
                break;
            }
            case 12: {
                int value = 0;
                printf("Pour quelle valeur voulez avoir son nombre d'occurence :");
                scanf("%d", &value);
                int val = nb_valeur_egal(mydf, value);
                printf("Il y a %d occurence(s) de %d dans le dataframe.\n", val, value);
                break;
            }
            case 13: {
                int value = 0;
                printf("Pour quelle valeur voulez avoir le nombre de valeur superieur a elle :");
                scanf("%d", &value);
                int val = nb_valeur_sup(mydf, value);
                printf("Il y a %d valeur(s) superieur a %d dans le dataframe.\n", val, value);
                break;
            }
            case 14: {
                int value = 0;
                printf("Pour quelle valeur voulez avoir le nombre de valeur inferieur a elle :");
                scanf("%d", &value);
                int val = nb_valeur_inf(mydf, value);
                printf("Il y a %d valeur(s) inferieur a %d dans le dataframe.\n", val, value);
                break;
            }
            case 15: {
                int d = 0;
                printf("Combien de colonnes voulez vous afficher : ");
                scanf("%d", &d);
                afficher_colonne(mydf, d);
                break;
            }
            case 16: {
                int c = 0;
                printf("Combien de lignes voulez vous afficher : ");
                scanf("%d", &c);
                afficher_ligne(mydf, c);
                break;
            }
            case 17: {
                afficher_dataframe(mydf);
                break;
            }
            default : printf("Ce numero n'est pas attribue a une action.");
        }
        printf("\n");
    }

    return 0;
}