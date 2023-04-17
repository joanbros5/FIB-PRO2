/** @file Area_Emmagatzematge.hh
    @brief Especificació de la classe Area_Emmagatzematge
*/

#ifndef _AREA_EMMAGATZEMATGE
#define _AREA_EMMAGATZEMATGE

#include "Cjt_Contenedores.hh"
#include "Cjt_Huecos.hh"
#include "Espera.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

using namespace std;

/** @class Area_Emmagatzematge
    @brief Representa l'àrea d'emmagatzematge de la Terminal
*/

class Area_Emmagatzematge{
public:
    //Constructores
    
    /** @brief Creadora sense arguments
        \pre <em>Cert<em>
        \post El resultat es una àrea d'emmagatzematge buida
    */
    Area_Emmagatzematge();
    
    /** @brief Creadora amb arguments
        \pre <em>Cert<em>
        \post El resultat es una àrea d'emmagatzematge amb <em>N<em> hileres, <em>M<em> places i <em>H<em> pisos
    */

    Area_Emmagatzematge(const int N, const int M, const int H);
    
    //Destructora
    
    /** @brief Destructora
        \pre <em>Cert<em>
        \post Destrueix un objecte àrea d'emmagatzematge
    */
    ~Area_Emmagatzematge();
    //Destrueix un objecte àrea d'emmagatzematge
    
    //Consultores
    
    /** @brief Consultar nombre de hileres
        \pre <em>Cert<em>
        \post El resultat es el nombre de hileres del parametre implicit  
    */
    int hileras();
    
    /** @brief Consultar nombre de places
        \pre <em>Cert<em>
        \post El resultat es el nombre de places del parametre implicit  
    */
    int plazas();
    
    /** @brief Consultar nombre de pisos
        \pre <em>Cert<em>
        \post El resultat es el nombre de pisos del parametre implicit  
    */
    int pisos();
    
    /** @brief Consultar si existeix un contenidor
        \pre <em>Cert<em>
        \post El resultat és true si existeix un contenidor amb la matrícula <em>mat<em> a la àrea d'emmagatzematge i false si no existeix
    */
    bool existeix(const string& mat);
    
    /** @brief Consultar la ubicació d'un contenidor
        \pre Existeix un contenidor amb la matrícula <em>mat<em>
        \post El resultat es la ubicació del contenidor de l'àrea d'emmagatzematge amb la matrícula <em>mat<em>
    */
    Ubicacion DondeCont(const string& mat);
    
    /** @brief Consultar el contenidor d'una ubicació
        \pre <em>U<em> està dins de l'àrea d'emmagatzematge
        \post El resultat és el contenidor amb ubicació <em>U<em> del Conjunt
    */
    Contenedor CualCont(const Ubicacion& U);
    
    /** @brief Consultar el contenidor a partir de la matrícula
        \pre <em>U<em> està dins de l'àrea d'emmagatzematge
        \post El resultat és el contenidor amb matrícula <em>mat<em> del conjunt
    */
    Contenedor Cont(const string& mat);
    
    /** @brief Consultar si existeix un contenidor a la zona d'espera
        \pre <em>Cert<em>
        \post el resultat és true si hi ha un contenidor amb la matrícula <em>mat<em> a l'àrea d'espera i false en cas contrari
    */
    bool espera_existeix(const string& mat);
    
    //Modificadores
    
    /** @brief Insertar un contenidor amb BEST_FIT
        \pre <em>Cert<em>
        \post El resultat es true si el contenidor C s'ha pogut afegir a la àrea d'emmagatzematge i false en cas contrari
    */
    bool inserta(const Contenedor& C, bool mostra_ubi);
    
    /** @brief Retirar un contenidor de l'àrea d'emmagatzematge
        \pre El contenidor C esta en la terminal
        \post S'ha retirat el contenidor C del parametre implicit
    */
    void retira(const string mat);
    
    /** @brief Buscar contenidors a sobre de un altre
        \pre El contenidor amb matrícula <em>mat<em> esta en la terminal
        \post S'ha retirat el contenidor de sobre del de la matrícula mat a l'àrea d'espera (Si n'hi havia)
    */
    void retiraEncima(const string mat);
    
    /** @brief Afegir un hueco al conjunt de huecos
        \pre El hueco "Segment" S no està al conjunt
        \post S'ha afegit el Hueco S al conjunt
    */
    void InsertaHueco(const Segmento S);
    
    /** @brief Treure un hueco del conjunt de huecos
        \pre El hueco "Segment" S està al conjunt
        \post S'ha tret el Hueco S del conjunt
    */
    void QuitaHueco(const Segmento S);
    
    /** @brief Afegir un contenidor a l'àrea d'espera
        \pre <em>Cert<em>
        \post S'ha afegit el contenidor <em>C<em> a l'àrea d'espera com a primer paràmetre de sortida
    */
    void espera_afegeix(const Contenedor C);
    
    /** @brief Recolocar l'àrea d'espera
        \pre <em>Cert<em>
        \post Els contenidors de l'àrea d'espera que es poden afegir a la zona d'emmagatzematge s'han col·locat per ordre de prioritat
    */
    void recolocar_espera();
    
    //Entrada/Sortida
    
    /** @brief Operació d'escriptura dels contenidors de l'àrea d'emmagatzematge
        \pre <em>Cert<em>
        \post S'han escrit pel canal de sortida els contentenidors en format <em>mat<em>(<em>U<em>,<em>l<em>) i ordenats per matrícula
    */
    void Escriure_C();
    
    /** @brief Operació d'escriptura dels Huecos de l'àrea d'emmagatzematge
        \pre <em>Cert<em>
        \post S'han escrit pel canal de sortida els Huecos en format (<em>U<em>,<em>l<em>) i ordenats per ubicació
    */
    void Escriure_H();
    
    /** @brief Operació d'escriptura de l'àrea d'espera
        \pre <em>Cert<em>
        \post S'han escrit pel canal de sortida l'àrea d'espera
    */
    void espera_escriure();
    
    /** @brief Operació d'escriptura de l'area d'emmagatzematge
        \pre <em>Cert<em>
        \post S'ha escrit pel canal de sortida l'area d'emmagatzematge tal com diu l'enunciat de la practica
    */
    void AreaEmmagatzematge();
    
private:
    
    Cjt_Contenedores CjtCont;
    Cjt_Huecos CjtHuec;
    Espera espera;
    int N,M,H;    //Hileras, Plazas, Pisos
    
    vector<vector<vector<Contenedor>>> Area;
    
};

#endif
