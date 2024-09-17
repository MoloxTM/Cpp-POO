//
// Created by andre on 17/09/2024.
//

#include <iostream>
#include "fonction.h"

void init(point& pt, int _x, int _y, int _z) {
    pt.x=_x; pt.y=_y; pt.z=_z;
}

void point::init(int x, int y, int z) {
    this->x=x; this->y=y; this->z=z;
}


void essai_init() {
    point p;
    init(p);
    init(p,1);
    init(p,1,2);
    init(p,1,2,3);
}

void afficher(point& pt) {
    std::cout << "________________________________"<< std::endl;
    std::cout << pt.x << " " << pt.y << " " << pt.z << std::endl;
    std::cout << "________________________________"<< std::endl;
}