#include "particules.hpp"
#include "boite.hpp"
#include <random>

using namespace std;

const double G = 1;
const double M = 1;
const double R = 1;

constexpr int MIN = 0;
constexpr int MAX = 1;
const int N = 10; //Nombre de particules dans l'univers

particule generer_particule();
