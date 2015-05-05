#ifndef __TASCA__
#define __TASCA__

#ifndef __DIAGRAMA__
#include <iostream>
#include <map>
#endif

using namespace std;

/** @class Tasca
	@brief Representa una tasca i les seves etiquetes
*/

class Tasca {
  
    private:
    
        string nom;
        map<string,bool> etiquetes;

    public:

        //Constructors

        /** @brief
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

        //Consultores
        
        /** @brief Retorna si la etiqueta pertany a la tasca.
        \pre Cert.
        \post Retorna true si tag pertany al p.i.
        */
        bool te_etiqueta(const string &tag) const;
        
        //IO
    
        /** @brief Escriu la tasca
        \pre El p.i. no es buit.
        \post S'ha escrit la tasca.
        */
        void escriure_tasca() const;

};

#endif