/** @file Tasca.hh
    @brief Classe Tasca
 */

#ifndef __TASCA__
#define __TASCA__

#ifndef __DIAGRAMA__
#include <iostream>
#include <set>
#endif

using namespace std;

/** @class Tasca
    @brief Representa una tasca i les seves etiquetes
*/

class Tasca {
  
    private:
    
        string nom;
        set<string> etiquetes;
	
	/** @brief Funció d'immersió per a avaluar si una tasca compleix una expressió.
	 \pre El parametre s conte una expressio, i es el limit esquerre i j el dret de la part de s que sera avaluada.
	 \post Retorna cert si la tasca compleix l'expressió entre i i j i fals en els altres casos.
	 */
        bool compleix_expressio_i(const string &s, int i, int j) const;

    public:

        //Constructors

        /** @brief Crea una tasca amb titol n.
        \pre Cert.
        \post Crea una tasca amb titol n.
        */
        Tasca(const string &n);
        
        //Modificadores
        
        /** @brief Afegeix una etiqueta a la tasca.
        \pre Cert.
        \post S'ha afegit l'etiqueta al p.i., si ja hi era no fa res.
        */
        void afegir_etiqueta(const string &tag);
        
        /** @brief Esborra una etiqueta de la tasca.
        \pre Cert.
        \post Si tag pertany a la tasca, es esborrada i retorna true. Si no, no fa res i retorna false.
        */
        bool esborrar_etiqueta(const string &tag);
        
        /** @brief Esborra totes les etiquetes de la tasca.
        \pre Cert.
        \post S'han esborrat totes les etiquetes del p.i.
        */
        void esborrar_totes_etiquetes();
    
        /** @brief Canvia el titol del parametre implicit.
        \pre Cert.
        \post El titol del parametre implicit queda modificat amb el valor de s.
        */
        void modificar_titol(const string &s);


        //Consultores
        
        /** @brief Retorna si la etiqueta pertany a la tasca.
        \pre Cert.
        \post Retorna true si tag pertany al p.i.
        */
        bool te_etiqueta(const string &tag) const;

        /** @brief Comprova si el p.i. compleix l'expressio d'etiquetes corresponent.
        \pre L'expressio te el format correcte d'una expressio booleana d'etiquetes.
        \post Retorna true si les etiquetes de la tasca compleixen les condicions de l'expressio.
        */
        bool compleix_expressio(const string &expressio) const;
        
        //IO
    
        /** @brief Escriu el nom de la tasca.
        \pre El p.i. no es buit.
        \post S'ha escrit el nom de la tasca.
        */
        void escriure_nom() const;
        
        /** @brief Escriu la tasca.
        \pre El p.i. no es buit.
        \post S'han escrit les etiquetes en ordre lexicografic.
        */
        void escriure_etiquetes() const;

};

#endif