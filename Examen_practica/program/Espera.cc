#include "Espera.hh"
#include <iostream>
using namespace std;

Espera::Espera() {
    list<Contenedor> pila;
    this->espera = pila;
    Uespera = Ubicacion(-1,0,0);
}

Espera::Espera(const Espera& x) {
    list<Contenedor> pila(x.espera);
    this->espera = pila;
    Uespera = Ubicacion(-1,0,0);
}

Espera::~Espera() {
}

bool Espera::empty() {
    return espera.empty();
}

int Espera::lon() {
    return (*espera.begin()).longitud();
}

string Espera::mat() {
    return (*espera.begin()).matricula();
}

void Espera::afegeix(const Contenedor& C) {
    espera.insert(espera.begin(),C);
}

void Espera::Treu(const Contenedor& C) {
    list<Contenedor>::iterator it;
    for (it = espera.begin(); it != espera.end(); ++it) {
        if ((*it) == C) {
            espera.erase(it);
            return;
        }
    }
}

void Espera::Treu(const string mat) {
    list<Contenedor>::iterator it;
    for (it = espera.begin(); it != espera.end(); ++it) {
        if ((*it).matricula() == mat) {
            espera.erase(it);
            return;
        }
    }
}

Ubicacion Espera::U_espera() {
    return Uespera;
}

bool Espera::existeix(const string mat) {
    list<Contenedor>::iterator it = espera.begin();
    bool trobat = false;
    while (not trobat and it != espera.end()) {
        if ((*it).matricula() == mat) trobat = true;
        ++it;
    }
    return trobat;
}

Contenedor Espera::Cont(list<Contenedor>::iterator it) {
    return (*it);
}

list<Contenedor>::iterator Espera::begin() {
    return espera.begin();
}

list<Contenedor>::iterator Espera::end() {
    return espera.end();
}


void Espera::escriure() {
    list<Contenedor>::iterator it;
    for (it = espera.begin(); it != espera.end(); ++it) {
        (*it).print();
        cout << endl;
    }
}
