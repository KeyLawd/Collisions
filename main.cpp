#include <iostream>
#include "particules.hpp"

using namespace std;

int main()
{
    position X1(1,2,3);
    position V1(4,5,6);
    particule P1(X1,V1);
    cout << "Hello world!" << endl;
    cout << "x="<<P1.x() << endl;
    cout << "vx="<<P1.vx() << endl;
    P1.x() = 50;
    cout <<"x="<<P1.x()<<endl;
    P1.Lp.push_back(X1);

    return 0;
}
