#include "Cjt_Contenedores.hh"
#include <iostream>
using namespace std;

Cjt_Contenedores::Cjt_Contenedores() {
    map<Contenedor,Ubicacion> aux;
    this->Cjt = aux;
}

Cjt_Contenedores::Cjt_Contenedores(const Cjt_Contenedores& Cjt_C) {
    this->Cjt = Cjt_C.Cjt;
}

Cjt_Contenedores::~Cjt_Contenedores() {
}

Contenedor Cjt_Contenedores::Cont(const Ubicacion& U) {
    map<Contenedor,Ubicacion>::iterator it = Cjt.begin();
    Contenedor aux;
    bool trobat = false;
    while (not trobat and it != Cjt.end()) {
        if (it->second == U) {
            aux = it->first;
            trobat = true;
        }
        ++it;
    }
    return aux;
}

Contenedor Cjt_Contenedores::Cont(const string& mat) {
    map<Contenedor,Ubicacion>::iterator it = Cjt.begin();
    Contenedor aux;
    bool trobat = false;
    while (not trobat and it != Cjt.end()) {
        if (it->first.matricula() == mat) {
            aux = it->first;
            trobat = true;
        }
        ++it;
    }
    return aux;
}

Ubicacion Cjt_Contenedores::Ubi(const string& mat) {
    map<Contenedor,Ubicacion>::iterator it = Cjt.begin();
    Ubicacion aux;
    bool trobat = false;
    while (not trobat and it != Cjt.end()) {
        if (it->first.matricula() == mat) {
            aux = it->second;
            trobat = true;
        }
        ++it;
    }
    return aux;
}

bool Cjt_Contenedores::Busca(const string& mat) {
    bool trobat = false;
    map<Contenedor,Ubicacion>::iterator it = Cjt.begin();
    
    while (not trobat and it != Cjt.end()) {
        if (it->first.matricula() == mat) trobat = true;
        ++it;
    }
    
    return trobat;
}

void Cjt_Contenedores::Afegeix(const Contenedor& C, const Ubicacion& U) {
    //Només afegirem el contenidor al conjunt si no està
    if (not Busca(C.matricula())) Cjt.insert(pair<Contenedor,Ubicacion>(C,U));
    //Si ja estava, li canviem la ubicació per la nova U
    else {
        Cjt[C] = U;
    }
}

void Cjt_Contenedores::Treu(const Contenedor& C) {
    Cjt.erase(C);
}

void Cjt_Contenedores::Escriure() {
    for (map<Contenedor,Ubicacion>::iterator it = Cjt.begin(); it != Cjt.end(); ++it) {
        cout << it->first.matricula() << "(";
        it->second.print();
        cout << "," << it->first.longitud() << ")" << endl;
    }
}
