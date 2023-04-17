#include "Area_Emmagatzematge.hh"
#include <iostream>
using namespace std;

typedef vector<Contenedor> Piso;
typedef vector<Piso> Plaza;
typedef vector<Plaza> Hilera;

Area_Emmagatzematge::Area_Emmagatzematge(){
    this->N = 0;
    this->M = 0;
    this->H = 0;
}

Area_Emmagatzematge::Area_Emmagatzematge(const int N, const int M, const int H) {
    this->N = N;
    this->M = M;
    this->H = H;
    Hilera Hi(N, Plaza(M, Piso(H)));
    this->Area = Hi;
}

Area_Emmagatzematge::~Area_Emmagatzematge(){
}

int Area_Emmagatzematge::hileras() {
    return N;
}

int Area_Emmagatzematge::plazas() {
    return M;
}

int Area_Emmagatzematge::pisos() {
    return H;
}

bool Area_Emmagatzematge::existeix(const string& mat) {
    return CjtCont.Busca(mat);
}

Contenedor Area_Emmagatzematge::CualCont(const Ubicacion& U) {
    return Area[U.hilera()][U.plaza()][U.piso()];
}

Ubicacion Area_Emmagatzematge::DondeCont(const string& mat) {
    return CjtCont.Ubi(mat);
}

Contenedor Area_Emmagatzematge::Cont(const string& mat) {
    return CjtCont.Cont(mat);
}

bool Area_Emmagatzematge::espera_existeix(const string& mat){
    return espera.existeix(mat);
}


bool Area_Emmagatzematge::inserta(const Contenedor& C, bool mostra_ubi) {
    Ubicacion U;
    
    //Busquem un possible Hueco del conjunt de huecos
    Segmento S = CjtHuec.BuscaHueco(C.longitud());
    
    //Si no s'ha trobat ubicació possible
    if (S.ubic() == U) return false;
    
    else {
        if (mostra_ubi) {
            S.ubic().print();
            cout << endl;
        }
        
        //Afegim el contenidor al conjunt i a l'àrea d'emmagatzematge
        CjtCont.Afegeix(C, S.ubic());
        for (int i = S.ubic().plaza(); i < S.ubic().plaza() + C.longitud(); ++i) {
            Area[S.ubic().hilera()][i][S.ubic().piso()] = C;
        }
        
        //Actualitzem els huecos
        CjtHuec.TreureHueco(S);
        //Afegim un hueco a sobre del contenidor si no està a dalt de tot
        if (S.ubic().piso() + 1 < H) {
            Ubicacion U2(S.ubic().hilera(),S.ubic().plaza(),S.ubic().piso()+1);
            Segmento S2(U2, C.longitud());
            
            CjtHuec.AfegirHueco(S2);
            CjtHuec.ActualizaHuecos(S2);
        }
        //Si el Contenidor és més petit que el hueco on s'ha posat, aquest es fa més petit
        if (S.longitud() > C.longitud()) {
            Ubicacion U3(S.ubic().hilera(),S.ubic().plaza() + C.longitud(),S.ubic().piso());
            Segmento S3(U3, S.longitud() - C.longitud());
            CjtHuec.AfegirHueco(S3);
        }
    }
    
    return true;
}

void Area_Emmagatzematge::retira(const string mat) {
    Contenedor C = CjtCont.Cont(mat);
    Contenedor Buit;
    Ubicacion U = CjtCont.Ubi(mat);
    
    if (U.hilera() == -1 and C.matricula() == mat) {
        CjtCont.Treu(C);
        espera.Treu(mat);
        return;
    }
    
    //Hueco que es crea al retirar el contenidor
    Segmento S(U, C.longitud());

    
    //Treu el contenidor de l'area d'emmagatzematge i del conjunt
    CjtCont.Treu(C);
    for (int i = U.plaza(); i < U.plaza() + C.longitud(); ++i) {
        Area[U.hilera()][i][U.piso()] = Buit;
    }
    
    //Actualitzem els huecos

    Ubicacion U2(U.hilera(), U.plaza(), U.piso()+1);
    Segmento S2(U2, C.longitud());                  //Hueco que hi havia a sobre del contenidor

    CjtHuec.DivideHuecos(S2);
    
    CjtHuec.AfegirHueco(S);    
    CjtHuec.ActualizaHuecos(S);

}

void Area_Emmagatzematge::retiraEncima(const string mat) {
    //Ubicación del que es vol retirar a espera (la mateixa que el contenidor amb matrícula mat però un pis més)
    Ubicacion U (CjtCont.Ubi(mat).hilera(), CjtCont.Ubi(mat).plaza(), CjtCont.Ubi(mat).piso() + 1);
    
    //Contenedor Buit auxiliar
    Contenedor Buit;
    
    //Si estem al tope és impossible que hi hagi alguna cosa a sobre
    if (U.piso() == H) return;
    
    for (int i = U.plaza(); i < U.plaza() + CjtCont.Cont(mat).longitud(); ++i) {
        //Si té alguna cosa a sobre
        if (Area[U.hilera()][i][U.piso()] != Buit) {
            Contenedor C = Area[U.hilera()][i][U.piso()];
            retiraEncima(C.matricula());
            //Afegim el contenidor que hi havia a sobre a espera i el traiem de l'àrea d'emmagatzematge
            retira(C.matricula());
            CjtCont.Afegeix(C,espera.U_espera());
            espera.afegeix(C);
        }
    }
}


void Area_Emmagatzematge::InsertaHueco(const Segmento S) {
    CjtHuec.AfegirHueco(S);
}

void Area_Emmagatzematge::QuitaHueco(const Segmento S) {
    CjtHuec.TreureHueco(S);
}

void Area_Emmagatzematge::espera_afegeix(const Contenedor C) {
    CjtCont.Afegeix(C, espera.U_espera());
    espera.afegeix(C);
    espera.U_espera().print();
    cout << endl;
}

void Area_Emmagatzematge::recolocar_espera() {
    list<Contenedor>::iterator it;
    if (espera.empty()) return;
    else {
        for (it = espera.begin(); it != espera.end(); ++it) {
            bool afegit = inserta(espera.Cont(it), false);
            if (afegit) {
                espera.Treu((*it));
                
                recolocar_espera();
                return;
            }
        }
    }
}

void Area_Emmagatzematge::Escriure_C() {
    CjtCont.Escriure();
}

void Area_Emmagatzematge::Escriure_H() {
    CjtHuec.Escriure();
}

void Area_Emmagatzematge::espera_escriure() {
    espera.escriure();
}

void Area_Emmagatzematge::AreaEmmagatzematge() {
    //Imprime hileras
    for (int i = 0; i < N; ++i) {
        cout << "hilera " << i << endl;
        
        //Imprime pisos
        for (int j = H - 1; j >= 0; --j) {
            cout << j % 10 << " ";
            //Imprime contenedores
            for (int k = 0; k < M; ++k) {
                if (Area[i][k][j].matricula() == "") cout << " ";
                else cout << Area[i][k][j].matricula()[0];
            }
            cout << endl;
        }
        cout << "  ";
        //Imprime Plazas
        for (int q = 0; q < M; ++q) cout << q%10;
        cout << endl;
        cout << endl;
    }
}
