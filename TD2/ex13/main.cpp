//
// Created by andre on 17/09/2024.
//

#include <iostream>
#include "fonction.h"

int main() {
    using namespace std;
    TD1::essai str{};
    str.n = 5;
    str.x = 1.1f;

    cout << str.n << endl;
    cout << str.x << endl;

    raz(&str);

    cout << str.n << endl;
    cout << str.x << endl;

    return 0;
}
