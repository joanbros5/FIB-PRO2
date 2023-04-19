/** @file Cjt_Contenedores.hh
    @brief Especificació de la classe Cjt_Contenedores
*/

#ifndef _CJT_CONTENEDORES
#define _CJT_CONTENEDORES

#include "Contenedor.hh"
#include "Ubicacion.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#endif 


using namespace std;

/** @class Cjt_Contenedores
    @brief Representa un conjunt de contenidors
*/

class Cjt_Contenedores {
public:
    
    //Constructores
    
    /** @brief Creadora sense arguments
        \pre <em>Cert<em>
        \post El resultat es un conjunt de contenidors buit  
    */
    Cjt_Contenedores();
    
    /** @brief Creadora de còpia
        \pre <em>Cert<em>
        \post El resultat es un conjunt de contenidors amb els mateixos elements que <em>Cjt_C<em> 
    */
    Cjt_Contenedores(const Cjt_Contenedores& Cjt_C);
    
    //Destructora
    
    /** @brief Destructora
        \pre <em>Cert</em>
        \post Destrueix un objecte Cjt_Contenedores
    */
    
    ~Cjt_Contenedores();
    
    //Consultores
    
    /** @brief Consultar el contenidor d'una ubicació
        \pre <em>Cert<em>
        \post El resultat es el contenidor que té ubicació <em>U<em>
    */
    Contenedor Cont(const Ubicacion& U);
    
    /** @brief Consultar el contenidor a partir de la matrícula
        \pre <em>Cert<em>
        \post El resultat es el contenidor que té matrícula <em>mat<em>
    */
    Contenedor Cont(const string& mat);
    
    /** @brief Consultar la ubicació d'un contenidor
        \pre El Contenedor amb matrícula <em>mat<em> Existeix
        \post El resultat és la ubicació del contenidor amb matrícula <em>mat<em>
    */
    Ubicacion Ubi(const string& mat);
    
    /** @brief Buscar si existeix un contenidor
        \pre Cert
        \post El resultat és true si hi ha un contenidor amb la matrícula <em>mat<em> al conjunt i false en cas contrari
    */
    bool Busca(const string& mat);
    
    //Modificadores
    
    /** @brief Afegir un contenidor al conjunt
        \pre El contenidor no està al conjunt
        \post El contenidor ha estat afegit al paràmetre implícit, ordenat per Matrícula en ordre alfabètic
    */
    void Afegeix(const Contenedor& C, const Ubicacion& U);
    
    /** @brief Treure un contenidor del conjunt
        \pre El contenidor està al conjunt
        \post El contenidor ha estat eliminat al paràmetre implícit
    */
    void Treu(const Contenedor& C);
    
    //Entrada/sortida
    
    /** @brief Operació d'escriptura dels contenidors de la terminal
        \pre <em>Cert<em>
        \post S'han escrit pel canal de sortida els contentenidors en format <em>mat<em>(<em>U<em>,<em>l<em>) i ordenats per matrícula
    */
    void Escriure();
    
private:
    
    map<Contenedor, Ubicacion> Cjt;
    
};

#endif
