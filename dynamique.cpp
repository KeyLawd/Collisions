#include "particules.hpp"
#include <math.h>

const double h=0.1;
const int M=1;
const int g=1;
const double epsilon=0.1;

double distance (double x1,double x2,double y1,double y2)
{
    return(sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
}

void force_brute(particule& p, std::list<particule> &liste_particules)
{
    int module_force;
    for (std::list<particule>::iterator it = liste_particules.begin(); it !=liste_particules.end(); it++)
    {
        if(&(*it)!=&p)
        {
            double x_part= it->x();
            double y_part= it->y();
            double r=distance(x_part,p.x(),y_part,p.y());

            module_force=(M*g)/(pow(r,2)+pow(epsilon,2));
            p.F.x=p.F.x+module_force*(x_part-p.x())/r;
            p.F.y=p.F.y+module_force*(y_part-p.y())/r;
        }
    }
}

void dynamique(particule& p, std::list<particule> &liste_particules)
{
    //Recuperer les composantes des vecteurs position, vitesse et force
    double x_init=p.x();
    double y_init=p.y();
    double vx_init=p.vx();
    double vy_init=p.vy();
    double fx_init=p.fx();
    double fy_init=p.fy();
    // !!!!!!!! initialiser la liste des positions


    //------------- premier instant (k=0) ----------
    double vx_instant=vx_init+h/(2*M)*fx_init;
    double vy_instant=vy_init+h/(2*M)*fy_init;
    double x_instant=x_init+h*vx_instant;
    double y_instant=y_init+h*vy_instant;
    // !!!!!!!! la liste des positions

    //Mettre à jour la particule
    p.P.x=x_instant;
    p.P.y=y_instant;
    p.V.x=vx_instant;
    p.V.y=vy_instant;
    // !!!!!liste des positions

    //mise à jour de la boite
    //B.supprimer_part(p);
    //B.ajout_part(p);

    //calculer la position et vitesse après t=k*delta t

    force_brute(p, liste_particules);
    double fx_instant=p.fx();
    double fy_instant=p.fy();
    vx_instant=vx_instant+(h*fx_instant)/M;
    vy_instant=vy_instant+(h*fy_instant)/M;
    x_instant=x_instant+h*vx_instant;
    y_instant=y_instant+h*vy_instant;
    // !!!!!!!! la liste des positions

    //Mettre à jour la particule
    p.P.x=x_instant;
    p.P.y=y_instant;
    p.V.x=vx_instant;
    p.V.y=vy_instant;
    p.F.x=fx_instant;
    p.F.y=fy_instant;
    position pcourante;
    pcourante.x = p.x();
    pcourante.y = p.y();
    pcourante.z = p.z();
    p.Lp.push_back(pcourante);
    //mise à jour de la boite
    //B.supprimer_part(p);
    //B.ajout_part(p);

}
