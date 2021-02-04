#include <iostream>

const g=1;
double distance_carre (x1,x2,y1,y2)
{
    return(pow(x2-x1,2)+pow(y2-y1,2));
}
using namespace std;
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

