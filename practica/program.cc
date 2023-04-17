#ifndef NO_DIAGRAM
#include <iostream>
#endif 
#include "Area_Emmagatzematge.hh"
using namespace std;

/** @mainpage Pràctica sobre la terminal de contenidors i la estratègia BEST_FIT
*/

/**
    @file main.cc
    @brief Main de la pràctica
 */

int main() {
    string op;
    
    cin >> op;
    
    while (op != "fin") {
        
        //S'espera que la primera comanda de totes sigui "crea_terminal"
        int N,M,H;
        cin >> N >> M >> H;
        cout << "#" << op << " " << N << " " << M << " " << H << endl;
        Area_Emmagatzematge A(N,M,H);
        
        //Añadimos los huecos de la Terminal vacía al conjunto de huecos
        for (int i = 0; i < N; ++i) {
            Ubicacion U(i,0,0);
            Segmento S(U,M);
            A.InsertaHueco(S);
        }
        
        cin >> op;
        while (op != "fin" and op != "crea_terminal"){
            
            if (op == "inserta_contenedor" or op == "i"){
                string mat;
                int l;
                cin >> mat >> l;
                cout << "#" << op << " " << mat << " " << l << endl;
                Contenedor C(mat,l);
                
                //Si el contenidor ja existeix, no es pot afegir de nou
                if (A.existeix(mat)) cout << "error: el contenedor ya existe" << endl;
                
                else {
                    //Si el contenidor no existeix a la terminal i tampoc es pot afegir, s'envia a la zona d'espera
                    bool afegit = A.inserta(C, true);
                    if (not afegit) A.espera_afegeix(C);
                    else {
                        //Recorrer area espera para recolocar contenedores
                        A.recolocar_espera();
                    }
                }
            }
            
            else if (op == "retira_contenedor" or op == "r"){
                string mat;
                cin >> mat;
                cout << "#" << op << " " << mat << endl;
                
                //Si el contenidor no existeix
                if (not A.existeix(mat)) cout << "error: el contenedor no existe" << endl;
                
                else if (A.espera_existeix(mat)) A.retira(mat);
                
                else {
                    //Buscar si hay contenedores encima
                    A.retiraEncima(mat);
                    A.retira(mat);
                    //Despres de retirar el contenidor s'ha de tornar a colocar la zona d'espera
                    A.recolocar_espera();
                }
            }
            
            else if (op == "donde"){
                string mat;
                cin >> mat;
                cout << "#" << op << " " << mat << endl;
                
                //Si existeix a la terminal
                if (A.existeix(mat)) {
                    Ubicacion U(A.DondeCont(mat));
                    U.print();
                }
                
                //Si esta a la zona d'espera
                else if (A.espera_existeix(mat)) {
                    Ubicacion U(-1,0,0);
                    U.print();
                }
                
                //Si no esta
                else {
                    Ubicacion U;
                    U.print();
                }
                cout << endl;
            }
            
            else if (op == "longitud"){
                string mat;
                cin >> mat;
                cout << "#" << op << " " << mat << endl;
                
                //Si no existeix
                if (not A.existeix(mat)) cout << "error: el contenedor no existe" << endl;
                
                else cout << A.Cont(mat).longitud() << endl;
            }
            
            else if (op == "contenedor_ocupa"){
                int i, j, k;
                cin >> i >> j >> k;
                cout << "#" << op << " " << i << " " << j << " " << k << endl;
                
                //Si s'han introduït unes dades invàlides
                if (i > A.hileras() - 1 or j > A.plazas() - 1 or k > A.pisos() - 1) {
                    cout << "error: ubicacion fuera de rango" << endl;
                }
                                
                //Sinó, buscar la matrícula del contenidor
                else {
                    Ubicacion U(i,j,k);
                    Contenedor C = A.CualCont(U);
                    cout << C.matricula() << endl;
                }
            }
            
            else if (op == "num_hileras"){
                cout << "#" << op << endl;
                cout << A.hileras() << endl;
            }
            
            else if (op == "num_plazas"){
                cout << "#" << op << endl;
                cout << A.plazas() << endl;
            }
            
            else if (op == "num_pisos"){
                cout << "#" << op << endl;
                cout << A.pisos() << endl;
            }
            
            else if (op == "area_espera"){
                cout << "#" << op << endl;
                A.espera_escriure();
                cout << endl;
            }
            
            else if (op == "contenedores"){
                cout << "#" << op << endl;
               A.Escriure_C();
               cout << endl;
            }
            
            else if (op == "area_almacenaje"){
                cout << "#" << op << endl;
                A.AreaEmmagatzematge();
            }
            
            else if (op == "huecos"){
                cout << "#" << op << endl;
                A.Escriure_H();
                cout << endl;
            }
            
            cin >> op;
        }
    }
}
