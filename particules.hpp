//-----------------------------------------------------------------------------------------------------------
//particules.hpp
//-----------------------------------------------------------------------------------------------------------
#ifndef particule_H
#define particule_H

using namespace std;

#include <iostream>
#include <list>
#include <iterator>

//------------------------------------------------------------------------------------------------------------
//Classe position (stocke des vecteurs 3D)
//------------------------------------------------------------------------------------------------------------
class position {
public:
    double x,y,z;
    position(double a, double b, double c){x=a;y=b;z=c;}
    position(){x=0;y=0;z=0;}
};


//-----------------------------------------------------------------------------------------------------------
//Classe particule
//-----------------------------------------------------------------------------------------------------------
class particule {
//-----------------------------------------------------------------------------------------------------------
//                                              Variables
//-----------------------------------------------------------------------------------------------------------
public:
    //On aura besoin d’une classe particule pour stocker :

    //sa position instantanée
    position P;

    //sa vitesse instantanée
    position V;

    //la force gravitationnelle qui s'exerce
    position F;

    //la liste des positions successives pour réaliser des films
    std::list<position> Lp;
    /*Il s'agit d'une std::list, pour ajouter un item à la fin, on utilise Lp.push_back(item)
    Lp.size() pour avoir la taille, */

//------------------------------------------------------------------------------------------------------------
//                                              Méthodes
//------------------------------------------------------------------------------------------------------------
    //Constructeurs
    particule(position Q, position W) {
        P = Q;
        V = W;
        F.x = 0;
        F.y = 0;
        F.z = 0;
        Lp.push_back(Q);
    };//Initialise une particule avec P et V donnés, F et Lp sont vides
    particule();                            //Bah faut allouer de la place quoi
    //Accès rapide
    double& x() {
        return P.x;
    };
    double& y() {
        return P.y;
    };
    double& z() {
        return P.z;
    };
    double& vx() {
        return V.x;
    };
    double& vy() {
        return V.y;
    };
    double& vz() {
        return V.z;
    };
    double& fx() {
        return F.x;
    };
    double& fy() {
        return F.y;
    };
    double& fz() {
        return F.z;
    };
};

#endif // particule_H
