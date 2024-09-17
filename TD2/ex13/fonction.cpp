//
// Created by andre on 17/09/2024.
//

#include "fonction.h"

void raz(TD1::essai* str) {
    str->n = 0;
    str->x = 0.0f;
}

void raz(TD1::essai& str) {
    str.n = 0;
    str.x = 0.0f;
}

