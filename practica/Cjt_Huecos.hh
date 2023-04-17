/** @file Cjt_Huecos.hh
    @brief Especificació de la classe Cjt_Huecos
*/

#ifndef _CJT_HUECOS
#define _CJT_HUECOS

#include "Segmento.hh"

#ifndef NO_DIAGRAM
#include <set>
#endif 



using namespace std;

/** @class Cjt_Huecos
    @brief Representa un conjunt de Huecos
*/

class Cjt_Huecos{
public:
    
    //Constructores
    
    /** @brief Creadora sense arguments
        \pre <em>Cert<em>
        \post El resultat es un conjunt de Huecos buit  
    */
    Cjt_Huecos();
    
    /** @brief Creadora de còpia
        \pre <em>Cert<em>
        \post El resultat es un conjunt de Huecos amb els mateixos elements que <em>Cjt_H<em> 
    */
    Cjt_Huecos(const Cjt_Huecos& Cjt_Hue);
    
    //Destructora
    
    /** @brief Destructora
        \pre <em>Cert</em>
        \post Destrueix un objecte Cjt_Huecos
    */   
    ~Cjt_Huecos();
    
    //Consultores
    
    /** @brief Buscar un Hueco
        \pre <em>Cert</em>
        \post El resultat és un hueco amb la longitud l
    */  
    
    Segmento BuscaHueco(const int& l);
    
    //Modificadores
    
    /** @brief Afegeix un hueco al Conjunt
        \pre El Segmento S no està al conjunt
        \post El Segmento S passa a formar part del conjunt de Huecos
    */
    void AfegirHueco(const Segmento S);
    
    /** @brief Treu un hueco del Conjunt
        \pre El Segmento S està al conjunt
        \post El Segmento S queda eliminat del conjunt de Huecos
    */
    void TreureHueco(const Segmento S);
    
    /** @brief Actualitzar els Huecos del Conjunt
        \pre Cert
        \post Els huecos adjacents a <em>S<em> han quedat fusionats amb aquest
    */    
    void ActualizaHuecos(const Segmento S);
    
    /** @brief Divideix algun Hueco del Conjunt
        \pre <em>S<em> té una longitud més petita o igual que el huco que es vol dividir
        \post El hueco que contenia el segmento <em>S<em> ha quedat dividit (traient-li el segmento)
    */    
    void DivideHuecos(const Segmento S);
    
    //Entrada/Sortida
    
    /** @brief Operació d'escriptura del conjunt de Huecos
        \pre <em>Cert<em>
        \post S'han escrit les ubicacions i les longituds del p.i. pel canal estàndar de sortida en format (<em>u</em>,<em>l</em>)
    */
    
    void Escriure();
    
private:
    
    set<Segmento> Cjt_H;
    
};

#endif
