#include "plummer.hpp"

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_real_distribution<double> distr(MIN, MAX);

particule generer_particule() {
    double X1 = distr(eng);
    double r = pow((pow(X1,-2/3)-1),-1/2);
    double X2 = distr(eng);
    double X3 = distr(eng);
    double z = (1 - 2*X2)*r;
    double x = pow(r*r-z*z,1/2)*cos(2*M_PI*X3);
    double y = pow(r*r-z*z,1/2)*sin(2*M_PI*X3);
    double X4 = distr(eng);
    double X5 = distr(eng);
    double Ve = sqrt(2)*pow(1+r*r,-1/4);
    double q;
    bool t = false;
    while (!t) {
        if (X5 < 10*X4*X4*pow(1-X4*X4,7/2)) {
            q = X4;
            t = true;
        }
        else {
            X4 = distr(eng);
            X5 = distr(eng);
        }
    }
    double V = q*Ve;
    double X6 = distr(eng);
    double X7 = distr(eng);
    double w = (1-2*X6)*V;
    double u = pow(V*V-w*w,1/2)*cos(2*M_PI*X7);
    double v = pow(V*V-w*w,1/2)*sin(2*M_PI*X7);

    particule p;
    p.x() = x;
    p.y() = y;
    p.z() = z;
    p.vx() = u;
    p.vy() = v;
    p.vz() = w;
    return(p);
}
