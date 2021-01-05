#include "arbres_pointeurs.c"

int main(int argc, char const *argv[])
{
    Noeud *Arbre = NULL;
    Arbre = Insert_val_Arbre_BOH(Arbre, 5);
    Arbre = Insert_val_Arbre_BOH(Arbre, 10);
    Arbre = Insert_val_Arbre_BOH(Arbre, 3);
    Arbre = Insert_val_Arbre_BOH(Arbre, 8);
    Arbre = Insert_val_Arbre_BOH(Arbre, 9);
    Arbre = Insert_val_Arbre_BOH(Arbre, 4);
    Arbre = Insert_val_Arbre_BOH(Arbre, 2);
    Arbre = Insert_val_Arbre_BOH(Arbre, 15);
    Arbre = Insert_val_Arbre_BOH(Arbre, 14);
    Arbre = Insert_val_Arbre_BOH(Arbre, 20);

    affichage_prefixe(Arbre);

    // int min = Arbre->val;
    // int max = Arbre->val;
    // maximum_Arbre(Arbre, &max);
    // minimum_Arbre(Arbre, &min);
    // printf("\nvoila le min: %d\n", min);
    // printf("\nvoila le max: %d\n", max);

    int trouve;

    Arbre = Suppression_ABOH(Arbre, 9, trouve);
    printf("\n\n");
    affichage_prefixe(Arbre);
    printf("\n\n");
    Arbre = Insert_val_Arbre_BOH(Arbre, 9);
    printf("\n\n");
    affichage_infixe(Arbre);
    printf("\n\n");
    return 0;
}
