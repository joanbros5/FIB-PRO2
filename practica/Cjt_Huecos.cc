#include "Cjt_Huecos.hh"
#include <iostream>
using namespace std;

Cjt_Huecos::Cjt_Huecos() {
    set<Segmento> aux;
    this->Cjt_H = aux;
}

Cjt_Huecos::Cjt_Huecos(const Cjt_Huecos& Cjt_Hue) {
    this->Cjt_H = Cjt_Hue.Cjt_H;
}

Cjt_Huecos::~Cjt_Huecos() {
}

Segmento Cjt_Huecos::BuscaHueco(const int& l) {
    Segmento S;
    for (set<Segmento>::iterator it = Cjt_H.begin(); it != Cjt_H.end(); ++it) {
        if ((*it).longitud() >= l) return (*it);
    }
    return S;
}

void Cjt_Huecos::AfegirHueco(const Segmento S) {
    Cjt_H.insert(S);
}

void Cjt_Huecos::TreureHueco(const Segmento S) {
    Cjt_H.erase(S);
}

void Cjt_Huecos::ActualizaHuecos(const Segmento S) {
    
    set<Segmento>::iterator it = Cjt_H.begin();   
    if (it == Cjt_H.end()) return;
    bool done = false;

    while (not done and it != Cjt_H.end()) {
                
        //Si els huecos estan a la mateixa hilera i piso
        if (S.ubic().hilera() == (*it).ubic().hilera() and S.ubic().piso() == (*it).ubic().piso()) {
            //Si el hueco toca S per l'esquerra
            if (S.ubic().plaza() == (*it).ubic().plaza() + (*it).longitud()) {
                Segmento S1((*it).ubic(), (*it).longitud() + S.longitud());
                Cjt_H.insert(S1);
                Cjt_H.erase(it);
                
                ActualizaHuecos(S1);
                it = Cjt_H.begin();
                done = true;
            }
            //Si el hueco toca S per la dreta
            else if (S.ubic().plaza() + S.longitud() == (*it).ubic().plaza()) {
                Segmento S2(S.ubic(), S.longitud() + (*it).longitud());
                Cjt_H.insert(S2);
                Cjt_H.erase(it);
                
                ActualizaHuecos(S2);
                it = Cjt_H.begin();

                done = true;
            }
        }
        ++it;
    }
    //Si el hueco no s'ha pogut fusionar amb cap existent
    if (done) TreureHueco(S);
}

void Cjt_Huecos::DivideHuecos(const Segmento S) {
    set<Segmento>::iterator it;
    for (it = Cjt_H.begin(); it != Cjt_H.end(); ++it) {
        
        //Si el Hueco que es vol dividir és igual a S, llavors s'elimina
        if ((*it).ubic() == S.ubic() and (*it).longitud() == S.longitud()) {
            Cjt_H.erase(it);
            return;
        }
        
        //Si estan a la mateixa hilera i piso (i S és més petit que el Hueco)
        else if (S.ubic().hilera() == (*it).ubic().hilera() and S.ubic().piso() == (*it).ubic().piso()) {
            
            //Cas 1: S i el hueco que es vol dividir estan en la mateixa ubicació (tocant l'extrem esquerre)
            if ((*it).ubic().plaza() == S.ubic().plaza()) {
                Ubicacion U2(S.ubic().hilera(), S.ubic().plaza() + S.longitud(), S.ubic().piso());
                Segmento S2(U2, (*it).longitud() - S.longitud());
                Cjt_H.insert(S2);
                Cjt_H.erase(it);
                return;
            }
            //Cas 2: S està dins del hueco que es vol dividir i tocant l'extrem dret
            else if (S.ubic().plaza() + S.longitud() == (*it).ubic().plaza() + (*it).longitud()) {
                Segmento S3((*it).ubic(), (*it).longitud() - S.longitud());
                Cjt_H.insert(S3);
                Cjt_H.erase(it);
                return;
            }
            //Cas 3: S està dins del hueco que es vol dividir i no toca cap extrem
            else if ((*it).ubic() < S.ubic() and (*it).ubic().plaza() + (*it).longitud() > S.ubic().plaza() + S.longitud()) {
                //Hueco nou esquerre
                Segmento S_E((*it).ubic(), (S).ubic().plaza() - (*it).ubic().plaza());
                //Hueco nou dreta
                Ubicacion U4(S.ubic().hilera(), S.ubic().plaza() + S.longitud() , S.ubic().piso());
                Segmento S_D(U4, (*it).longitud() - S_E.longitud() - S.longitud());
                Cjt_H.insert(S_E);
                Cjt_H.insert(S_D);
                Cjt_H.erase(it);
                return;
            }
        }
    }
}

void Cjt_Huecos::Escriure() {
    for (set<Segmento>::iterator it = Cjt_H.begin(); it != Cjt_H.end(); ++it) {
        (*it).print();
        cout << endl;
    }
}
