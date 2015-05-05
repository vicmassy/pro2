#ifndef __TASCA__
#define __TASCA__

#include <iostream>
#include <map>

using namespace std;

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
        Tasca(string n);
        
        //Modificadores
        
        /** @brief Afegeix una etiqueta a la tasca.
        \pre Cert.
        \post S'ha afegit l'etiqueta al p.i., si ja hi era no fa res.
        */
        void afegir_etiqueta(string tag);
        
        /** @brief Esborra una etiqueta de la tasca.
        \pre Cert.
        \post Si tag pertany a la tasca, es esborrada.
        */
        void esborrar_etiqueta(string tag);
        
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
        bool te_etiqueta(string tag) const;
        
        //IO
    
        /** @brief Escriu la tasca
        \pre El p.i. no es buit.
        \post S'ha escrit la tasca.
        */
        void escriure_tasca() const;

};

#endif