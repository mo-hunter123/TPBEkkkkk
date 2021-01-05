#include <stdlib.h>
#include <stdlib.h>
#include "InsertARNO.c"





int main(int argc, char const *argv[])
{
    Noeud *Arbre = NULL;
    printf("\ninserer les valeurs de l'arbre\n");
    
    int optGen = 1;

    int val;

    while (optGen)
    {
        printf("\ninserer l'element\n");
        scanf("%d",&val);
        
        Arbre = Insert_val_Arbre_BNO(Arbre, val);
        printf("\nvoulez vous inserer une autre valeur\n");
        printf("1-0: ");
        
        scanf("%d",&optGen);
    }

    affichage_postfixe(Arbre);
    
    return 0;
}
