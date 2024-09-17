//
// Created by andre on 17/09/2024.
//
#include "fonction.h"

void inverse(int *a, int *b) {
    const int temp = *b;
    *b = *a;
    *a = temp;
}

void inverse2(int& a, int& b) {
    const int tmp = b;
    b = a;
    a = tmp;
}