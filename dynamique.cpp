#include "particules.hpp"
#include <math.h>

const double h=0.1;
const int M=1;
const int g=1;
const double epsilon=0.01;

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

void force_brute(particule& p, std::list<particule> &liste_particules)
{
    int module_force;
    for (std::list<particule>::iterator it = liste_particules.begin(); it !=liste_particules.end(); it++)
    {
        if(&(*it)!=&p)
        {
            double x_part= it->x();
            double y_part= it->y();
            //double z_part= it->z();
            double r=distance(x_part,p.x(),y_part,p.y());
            // double r=distance(x_part,p.x(),y_part,p.y(),z_part,p.z()); //en 3D
            module_force=(M*g)/(pow(r,2)+pow(epsilon,2));
            p.F.x=p.F.x+module_force*(x_part-p.x())/r;
            p.F.y=p.F.y+module_force*(y_part-p.y())/r;
            //p.F.z=p.F.z+module_force*(z_part-p.z())/r;
        }
    }
}

void dynamique(particule& p, std::list<particule> &liste_particules, int k) //k poour détecter si on est sur la première itération
{
    //-------------emier instant (k=0) ----------
    if(k==0)
    {
    //Recuperer les composantes des vecteurs position, vitesse et force
    double x_init=p.x();
    double y_init=p.y();
    //double z_init=p.z();
    double vx_init=p.vx();
    double vy_init=p.vy();
    //double vz_init=p.vz();
    force_brute(p, liste_particules);
    double fx_init=p.fx();
    double fy_init=p.fy();
    //double fz_init=p.fz();

    //Calculer la nouvelle position et vitesse
    double vx_instant=vx_init+h/(2*M)*fx_init;
    double vy_instant=vy_init+h/(2*M)*fy_init;
    //double vz_instant=vz_init+h/(2*M)*fz_init;
    double x_instant=x_init+h*vx_instant;
    double y_instant=y_init+h*vy_instant;
    //double z_instant=z_init+h*vz_instant;

    //if (p.x()!=x_instant) || (p.y()!=y_instant) || (p.z()!=z_instant)
    //{
    //   B.supprimer_part(p);
    //}

    //Mettre à jour la particule
    p.P.x=x_instant;
    p.P.y=y_instant;
    //p.P.z=z_instant;
    p.V.x=vx_instant;
    p.V.y=vy_instant;
    //p.V.z=vz_instant;

    //Initialiser la liste des positions
    position pinit;
    pinit.x = x_init;
    pinit.y = y_init;
    //pinit.z = z_init;
    p.Lp.push_back(pinit);

    //mise à jour de la boite
    //B.ajout_part(p);
    return;
    }


    //Recuperer les composantes des vecteurs position, vitesse et force
    double x_instant=p.x();
    double y_instant=p.y();
    //double z_instant=p.z();
    double vx_instant=p.vx();
    double vy_instant=p.vy();
    //double vz_instant=p.vz();
    force_brute(p, liste_particules);
    double fx_instant=p.fx();
    double fy_instant=p.fy();
    //double fz_instant=p.fz();


    //calculer la position et vitesse
    vx_instant=vx_instant+(h*fx_instant)/M;
    vy_instant=vy_instant+(h*fy_instant)/M;
    //vz_instant=vz_instant+(h*fz_instant)/M;
    x_instant=x_instant+h*vx_instant;
    y_instant=y_instant+h*vy_instant;
    //z_instant=z_instant+h*vz_instant;

    //if (p.x()!=x_instant) || (p.y()!=y_instant) || (p.z()!=z_instant)
    //{
    //   B.supprimer_part(p);
    //}


    //Mettre à jour la particule
    p.P.x=x_instant;
    p.P.y=y_instant;
    //p.P.z=z_instant;
    p.V.x=vx_instant;
    p.V.y=vy_instant;
    //p.V.z=vz_instant;


    p.F.x=fx_instant;
    p.F.y=fy_instant;

    //mise à jour de la boite
    //B.ajout_part(p);

    //Mettre à jour la liste des positions
    position pcourante;
    pcourante.x = x_instant;
    pcourante.y = y_instant;
    //pcourante.z = z_instant;
    p.Lp.push_back(pcourante);
}
