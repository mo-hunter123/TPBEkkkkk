#include<stdio.h>
#include<stdlib.h>
#include "arbres_pointeurs.c"

char optionChoix(){
    char opt;

    do
    {
        printf("\nInsertion gauche (g), droite (d)\n");
        scanf(" %c",&opt);
    } while ((opt != 'g') && (opt != 'd'));
    
    return opt;
}


Noeud* Insert_val_Arbre_BNO(Noeud *Arb, int val){
    Noeud *ND;

    if(Arb_est_vide(Arb)){
        ND = Creer_Noeud(val);
        return ((Noeud*)ND);
    }

    char choix = optionChoix();
    switch (choix)
    {
        case 'd':
            Arb->fd = Insert_val_Arbre_BNO(Arb->fd, val);
            break;

        case 'g':
            Arb->fg = Insert_val_Arbre_BNO(Arb->fg, val);
            break;
        
    }

    return ((Noeud*)Arb);
}

