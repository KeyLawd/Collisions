#include <iostream>
using namespace std;

const g=1;

double distance_carre (double x1,double x2,double y1,double y2)
{
    return(pow(x2-x1,2)+pow(y2-y1,2));
}

int force ()
{
    int somme =0;
    boite *suivant=boite_soeur;
    while (boite_soeur!=NULL)
    {
        somme=somme+(suivant->masse*g)/distance_carre(xmass,ymass,suivant->xmass,suivant->ymass));
        suivant=boite_soeur->boite_soeur;
    }
    return(somme);
}

void ajout_part(boite * B, particule * p)
{
    boite * F=B->boite_fille; //on parcours les boites
    while( abs(p->xpos-F->xpos)>1/(F->niveau+1)||abs(p->ypos-F->ypos)>1/(F->niveau+1))//on trouve le bon carré a niveau constant.
    {
        F=F->boite_soeur;
    }
    if (F->boite_fille==NULL && F->part==0)//si la boite est terminale et vide, on ajoute.
    {
        F->part=p;
        F->xmass=(F->masse*F->xmass+p->xpos*p->masse)/(F->masse+p->masse);
        F->ymass=(F->masse*F->ymass+p->ypos*p->masse)/(F->masse+p->masse);
    }
    if (F->boite_fille==NULL && F->part!=0)// boite terminale mais non vide.
    {
        particule* occupante=F->part;
        boite * sous_boite_1;
        sous_boite_1->xpos=F->xpos-(0.25*(1/(F->niveau+1)));
        sous_boite_1->ypos=F->ypos-(0.25*(1/(F->niveau+1)));
        F->boite_fille=sous_boite_1;
        boite * sous_boite_2;
        sous_boite_2->xpos=F->xpos+(0.25*(1/(F->niveau+1)));
        sous_boite_2->ypos=F->ypos+(0.25*(1/(F->niveau+1)));
        sous_boite_1->boite_soeur=sous_boite_2;
        boite * sous_boite_3;
        sous_boite_3->xpos=F->xpos-(0.25*(1/(F->niveau+1)));
        sous_boite_3->ypos=F->ypos+(0.25*(1/(F->niveau+1)));
        sous_boite_2->boite_soeur=sous_boite_3;
        boite * sous_boite_4;
        sous_boite_4->xpos=F->xpos+(0.25*(1/(F->niveau+1)));
        sous_boite_4->ypos=F->ypos-(0.25*(1/(F->niveau+1)));
        sous_boite_3->boite_soeur=sous_boite_4;

        ajout_part(F,occupante);
        ajout_part(F,p);
    }
    else //boite non terminale
        ajout_part(F->boite_fille,p);
}
