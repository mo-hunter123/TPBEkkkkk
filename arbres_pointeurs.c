#include<stdio.h>
#include<stdlib.h>



typedef struct noeud
{
    int val;            //etiquette de noeud
    struct noeud *fg;   //pointeur sur le fils gauche
    struct noeud *fd;   //pointeur sur le fils droit
    struct noeud *pere; //pointeur sur le pere
}Noeud;

/*------

Nom:            Creer_Noeud
Entree:         la valeur a inseree 
Sortie:         la cellule qui contient la valeur
Description:    une fonction qui permet la creation d'un element 

-------*/


Noeud* Creer_Noeud(int val)
{
    Noeud *NewNd;

    //Allocartion de la memoire 
    NewNd = (Noeud*)malloc(sizeof(Noeud));

    //Verification de l'allocation
    if (!NewNd)
    {
        printf("\nErreur d'allocation \n");
        exit(-1);
    }

    //initialisation des differents champs
    NewNd->val = val;
    NewNd->fg = NULL;
    NewNd->fd = NULL;
    NewNd->pere = NULL;

    //retour le pointeur sur la cellule cree 
    return ((Noeud*)NewNd);
}

/*------

Definition de chaque fonction 

-------*/


int Arb_est_vide(Noeud* Arb)
{
    if(!Arb)
        return ((int)1);    //arbre est vide
    
    return ((int)0);        //arbre n'est pas vide 
}


/*------

Nom:            Insert_val_Arbre_BOH
Entree:         la valeur a inseree 
Sortie:         la cellule qui contient la valeur
Description:    une fonction qui permet la creation d'un element 

-------*/


Noeud* Insert_val_Arbre_BOH(Noeud *Arb, int val)
{

    Noeud *ND;

    //si l'arbre est vide 
    if(Arb_est_vide(Arb))
    {
        ND = Creer_Noeud(val);
        return ((Noeud*)ND);
    }
        
    //si l'arbre n'est pas vide 
    if( val < Arb->val) // insertion a gauche
        Arb->fg = Insert_val_Arbre_BOH(Arb->fg, val);

    else                //insertion a droite
        Arb->fd = Insert_val_Arbre_BOH(Arb->fd, val);

    //retiurner a gauche
    return((Noeud*)Arb);
}

/*------

Definition de chaque fonction 

-------*/


Noeud* Insert_ND_Arbre_BOH(Noeud *Arb, Noeud *Nd)
{
    //si l'arbre est vide 
    if(Arb_est_vide(Arb))
        return ((Noeud*)Nd);

    if(Nd->val < Arb->val)
        Arb->fg = Insert_ND_Arbre_BOH(Arb->fg, Nd);

    else
        Arb->fd = Insert_ND_Arbre_BOH(Arb->fd, Nd);   

    return ((Noeud*)Arb);
}


/*------


-------*/

void traiter(Noeud *racine)
{
    printf("%d,", racine->val);
}

/*------


-------*/


void affichage_prefixe(Noeud *racine)
{
    if(!Arb_est_vide(racine))
    {
        traiter(racine);
        affichage_prefixe(racine->fg);
        affichage_prefixe(racine->fd);
    }
}

/*------


-------*/

void affichage_postfixe(Noeud *racine)
{
    if(!Arb_est_vide(racine))
    {
        affichage_postfixe(racine->fg);
        affichage_postfixe(racine->fd);
        traiter(racine);
        
    }
}

/*------


-------*/

void affichage_infixe(Noeud *racine)
{
    if(!Arb_est_vide(racine))
    {
        affichage_infixe(racine->fg);
        traiter(racine);
        affichage_infixe(racine->fd);        
    }
}

void minimum_Arbre(Noeud *Arb, int *min){
    
    if(!Arb_est_vide(Arb)){
        minimum_Arbre(Arb->fg, min);

        if(*min > Arb->val)
            *min = Arb->val;

        minimum_Arbre(Arb->fd, min);
    }
}

void maximum_Arbre(Noeud *Arb, int *max){
    
    if(!Arb_est_vide(Arb)){
        maximum_Arbre(Arb->fg, max);

        if(*max < Arb->val)
            *max = Arb->val;

        maximum_Arbre(Arb->fd, max);
    }
}

Noeud* Remplacer(Noeud* R, Noeud* Q){
    if(Q->fg)
    {
        Q->fg = Remplacer(R, Q->fg);
        
    }
    
    else{
        R->val = Q->val;
        // R = Q;
        Q = Q->fd;
    }


    return ((Noeud*)R);
}


Noeud* Suppression_ABOH(Noeud *Arb, int val, int trouve){
    
    if(Arb_est_vide(Arb)){
        trouve = 0;
        return ((Noeud*)Arb);
    }
        
    
    if(val < Arb->val)
        Arb->fg = Suppression_ABOH(Arb->fg, val, trouve);

    else if(val > Arb->val)
        Arb->fd = Suppression_ABOH(Arb->fd, val, trouve);

    else
    {
        trouve = 1;
        if(Arb_est_vide(Arb->fd))
            Arb = Arb->fg;
        
        else if(Arb_est_vide(Arb->fg))
            Arb = Arb->fd;
        
        else 
            Arb = Remplacer(Arb, Arb->fd);
    }


    return ((Noeud*)Arb);
    
}