//
// Created by andre on 17/09/2024.
//

#pragma once

#include <string>

using namespace std;
struct compte {
    string id;
    int solde;
};

compte& find(compte* tab, const string& id, size_t tab_size);
int& operation(compte* tab, const string& id);
void essai_compte();
