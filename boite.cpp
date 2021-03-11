#include <iostream>
#include <math.h>
#include "boite.hpp"
using namespace std;

const double g=1;

double distance_carre (double x1,double x2,double y1,double y2)
{
    return(pow(x2-x1,2)+pow(y2-y1,2));
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

const double g=1;

//calculer la distance entre deux particules en 2D
double distance (double x1,double x2,double y1,double y2)
{
    return(sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
}


//calculer la distance entre deux particules en 3D
//double distance (double x1,double x2,double y1,double y2, double z1, double z2)
//{
//    return(sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
//}

void force(particule *part_courante)
{
    if (part_courante==NULL)
    {
        return();
    }

    int indic=1; //indice de parcours des 4 boites soeurs
    boite *suivant=boite_soeur;
    while (indic<4)
    {
    indic=indic+1; //On passe à la boite voisine
    double r=distance(part_courante.x(),suivant->centre_masse.x,part_courante.y(),suivant->centre_masse.y);
    // double r=distance(part_courante.x(),suivant->centre_masse.x,part_courante.y(),suivant->centre_masse.y,part_courante.z(),suivant->centre_masse.z); //en 3D
    module_force=(suivant->masse*g)/(pow(r,2)+pow(epsilon,2));
    part_courante.F.x=part_courante.F.x+module_force*(part_courante.x()-centre_masse.x))/r;
    part_courante.F.y=part_courante.F.y+module_force*(part_courante.y()-suivant->centre_masse.y)/r;
    //part_courante.F.z=part_courante.F.z+module_force*(part_courante.z()-suivant->centre_masse.z)/r;
    suivant=suivant->boite_soeur;
    }

    if(boite_mere!=NULL)
    {
        boite_mere.force(part_courante);
    }
}

