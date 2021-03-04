#include <iostream>
#include <fstream>
#include "particules.hpp"
#include "plummer.hpp"
#include "dynamique.h"

using namespace std;

int main()
{
    /*
    cout << "Tests de la classe particule" << endl;
    position X1(1,2,3);
    position V1(4,5,6);
    particule P1(X1,V1);
    cout << "Hello world!" << endl;
    cout << "x="<<P1.x() << endl;
    cout << "vx="<<P1.vx() << endl;
    P1.x() = 50;
    cout <<"x="<<P1.x()<<endl;
    P1.Lp.push_back(X1);
    cout << "Tests de la fonction de génération de Plummer" << endl;
    particule p1 = generer_particule();
    cout << "x = " << p1.x() <<endl;
    cout << "y = " << p1.y() <<endl;
    cout << "z = " << p1.z() <<endl;
    cout << "u = " << p1.vx() <<endl;
    cout << "v = " << p1.vy() <<endl;
    cout << "w = " << p1.vz() <<endl;
    */

//Boucle dynamique + exportation
    int N = 2;//Nombre de particules
    cout << "Nombre de particules" << endl << "np = ";
    cin >> N;
    int nt = 10000; //Nombre de pas de temps
    cout << "Nombre de pas de temps" << endl << "nt = ";
    cin >> nt;
    std::list<particule> liste_particules;
    for (int i = 0; i < N; i++) {
        particule P = generer_particule();
        liste_particules.push_back(P);
    }
    //On initialise la liste de particules
    for (int i = 0; i < nt; i++) {
        for (std::list<particule>::iterator p = liste_particules.begin(); p != liste_particules.end(); p++) {
            //Update la position de la particule et stocke la nouvelle position
            dynamique((*p), liste_particules,i);
        }
        //A la fin de cette boucle, on a update chaque particule
        //et chaque position est sotckee dans la liste de la classe
        //cout << i <<endl;

    }
    //A la fin de cette boucle, chaque particule conntient une lsite
    //de toutes les positions qu'elle occupe entre 0 et tfinal
    string const dimension("dimension.txt");
    ofstream fluxdim(dimension.c_str());
    if(fluxdim){
        fluxdim << nt << endl;//nombre de pas de temps
        fluxdim << N << endl;//nombre de particules

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    string const resultat("resultat.txt");
    ofstream fluxresultat(resultat.c_str());

    if(fluxresultat)
    {

        for (std::list<particule>::iterator particulecourante = liste_particules.begin(); particulecourante != liste_particules.end(); particulecourante++) {
            for (std::list<position>::iterator positioncourante = particulecourante->Lp.begin(); positioncourante!= particulecourante->Lp.end(); positioncourante++) {
                fluxresultat << positioncourante->x << ";";
                fluxresultat << positioncourante->y << ";";
                fluxresultat << positioncourante->z << ";";
                //A chaque pas de temps, on inscrit les 3 coordonnées
            }
            //A la fin de Lp, on saute une ligne
            fluxresultat <<endl;
            // CHAQUE LIGNE EST UNE P A R T I C U L E, *****PAS**** UN PAS DE TEMPS!!!!
        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    return 0;
}
