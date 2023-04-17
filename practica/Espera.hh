/** @file Espera.hh
    @brief Especificació de la classe Espera
*/

#ifndef _ESPERA
#define _ESPERA

#include "Contenedor.hh"
#include "Ubicacion.hh"

#ifndef NO_DIAGRAM
#include <list>
#endif 

using namespace std;

/** @class Espera
    @brief Representa una zona d'espera amb contenidors
*/
class Espera {
public:
    //Constructores
    
    /** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és una zona d'espera buida
    */ 
    Espera();
    
    /** @brief Creadora de còpia
      \pre <em>Cert</em>
      \post El resultat es una zona d'espera amb els mateixos elements que <em>x<em>
    */ 
    Espera(const Espera& x);
    
    //Destructora
    
    /** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Zona d'espera
    */ 
    ~Espera();
    
    //Consultores
    
    /** @brief Consultora de buida
      \pre Cert
      \post El resultat es true si l'àrea d'espera està buida i false en cas contrari
    */ 
    bool empty();
    
    
    /** @brief Consultora de longitud
      \pre La zona d'espera no està buida
      \post El resultat es la longitud del primer contenidor de sortida del parametre implicit
    */ 
    int lon();
    
    /** @brief Consultora de matrícula
      \pre La zona d'espera no està buida
      \post El resultat es la matrícula del primer contenidor de sortida del parametre implicit
    */ 
    string mat();
    
    /** @brief Ubicacio de la zona d'espera
      \pre <em>Cert<em>
      \post El resultat es la ubicacio per defecte de la zona d'espera (-1,0,0)
    */ 
    Ubicacion U_espera();
    
    /** @brief Consulta si existeix un Contenidor en la Zon. Espera
      \pre <em>Cert<em>
      \post El resultat es true si hi ha un contenidor en la zona d'espera amb la matricula "mat" i false en cas contrari
    */ 
    bool existeix(const string mat);
    
    /** @brief Consulta el Contenidor de l'iterador
      \pre l'area d'espera no està buida
      \post El resultat és el contenidor al que apunta <em>it<em>
    */ 
    Contenedor Cont(const list<Contenedor>::iterator it);
    
    /** @brief Consulta un iterador a l'inici de la zona d'espera
      \pre <em>Cert<em>
      \post El resultat és un iterador que apunta al inici de la llista espera
    */
    list<Contenedor>::iterator begin();
    
    /** @brief Consulta un iterador al final de la zona d'espera
      \pre <em>Cert<em>
      \post El resultat és un iterador que apunta al final de la llista espera
    */
    list<Contenedor>::iterator end();
    
    //Modificadores
    
    /** @brief Afegir a la zona d'espera
      \pre <em>Cert<em>
      \post El contenidor C s'afegeix com a primer contenidor de sortida del parametre implicit
    */ 
    void afegeix(const Contenedor& C);
    
    /** @brief Treure de la zona d'espera
      \pre El Contenedor <em>C<em> està a l'àrea d'espera
      \post El contenidor C s'ha tret de l'area d'espera
    */ 
    void Treu(const Contenedor& C);
    
    /** @brief Treure de la zona d'espera
      \pre El Contenedor amb matrícula <em>mat<em> està a l'àrea d'espera
      \post El contenidor amb matrícula <em>mat<em> s'ha tret de l'area d'espera
    */ 
    void Treu(const string mat);
    
    //Entrada i Sortida
    
    /** @brief Escriu la zona d'espera
      \pre La zona d'espera no està buida
      \post S'han escrit pel canal de sortida els contenidors amb el format "matricula(longitud)"
    */ 
    void escriure();
    
private:
        
    list<Contenedor> espera;
    Ubicacion Uespera;
    
};
#endif
