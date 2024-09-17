//
// Created by andre on 14/09/2024.
//

#include "fonction.h"

void inverse(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inverse(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
