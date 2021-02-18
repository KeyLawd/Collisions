#ifndef DYNAMIQUE_H_INCLUDED
#define DYNAMIQUE_H_INCLUDED

double distance (double x1,double x2,double y1,double y2);
void force_brute(particule& p, std::list<particule> &liste_particules);
void dynamique(particule& p, std::list<particule> &liste_particules,int k);

#endif // DYNAMIQUE_H_INCLUDED
