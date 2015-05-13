#ifndef __AGENDA__
#define __AGENDA__

#ifndef __DIAGRAMA__
#include <iostream>
#include <map>
#include <string>
#include <set>
#endif
#include "comanda.hh"
#include "Instant.hh"
#include "Tasca.hh"

using namespace std;

/** @class Agenda
    @brief Representa l'agenda i gestiona les interaccions amb les comandes
*/

typedef map<Instant,Tasca>::iterator tasques_it;

class Agenda {

    private:

        Instant r;
        map<Instant,Tasca> tasques;
        vector<tasques_it> menu;
        map<string,map<Instant,tasques_it> > etiquetes;
        void escriure_tasca(tasques_it it);
        bool comprovar_modificable(tasques_it it);
        void agenda_afegir_etiqueta(tasques_it it, const string &tag);
        
    public:
    
        //Constructors
        
        /** @brief
        \pre Cert.
        \post Es crea una agenda buida amb data d i hora h.
        */
        Agenda(const string &d, const string &h);
        
        //Modificadors
        
        /** @brief Canvia el valor del rellotge intern.
        \pre c es una comanda de modificar rellotge.
        \post S'actualitza el valor del rellotge amb les dades de la comanda si son valides (si en falten 
        s'utilitzen les actuals) i retorna true. Si no son valides no fa res i retorna false.
        */
        bool modificar_rellotge(const Comanda &c);

        /** @brief Insereix una nova tasca a l'agenda.
        \pre c es una comanda d'inserir tasca.
        \post Si la data i hora son al futur i no coincideixen amb una altra tasca, retorna true i s'insereix la tasca.
        Si no, retorna false i no es fa res. Si falten hora i/o data s'utilitzen les actuals.
        */
        bool inserir_tasca(const Comanda &c);

        /** @brief Modifica una tasca existent de la agenda que es trobi al menu.
        \pre c es una comanda de modificar tasca i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si les noves data i hora son al passat o coincideixen amb una altra tasca, si el numero  de tasca no es al menu,
        si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res. En cas contrari modifica la tasca i retorna true.
        */
        bool modificar_tasca(const Comanda &c);

        /** @brief Esborra una tasca de l'agenda.
        \pre c es una comanda d'esborrar tasca i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si el numero  de tasca no es al menu, si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res.
        En cas contrari retorna true i esborra la tasca.
        */
        bool esborrar_tasca(const Comanda &c);

        /** @brief Esborra una etiqueta d'una tasca.
        \pre c es una comanda d'esborrar etiqueta i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si la etiqueta no pertany a la tasca, el numero de tasca no es al menu, s'ha esborrat la tasca oja es al passat; 
        retorna fals i no fa res. En cas contrari retorna true i esborra l'etiqueta de la tasca.
        */
        bool esborrar_etiqueta(const Comanda &c);

        /** @brief Esborra totes les etqieutes d'una tasca.
        \pre c es una comanda d'esborrar totes les etiquetes i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si el numero  de tasca no es al menu, si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res.
        En cas contrari retorna true i esborra totes les etiquetes de la tasca.
        */
        bool esborrar_etiquetes(const Comanda &c);        
        
        //Consultores

        /** @brief Retorna el rellotge intern.
        \pre Cert.
        \post Retorna la data i l'hora actuals de l'agenda.
        */
        Instant consultar_rellotge() const;
        
        //Lectura
        
        //Escriptura
        
        /** @brief Escriu el rellotge intern.
        \pre Cert.
        \post S'ha escrit el rellotge (data i hora) al canal de sortida.
        */
        void escriure_rellotge() const;

        /** @brief Escriu les tasques especificades a la comanda i genera el menu pertinent
        \pre c conte una comnanda de consulta de tasques.
        \post Escriu les tasques futures a l'interval proporcionat (si no hi ha, al rellotge intern); o les que compleixin
        una expressio amb etiquetes; o ambdues. Esborra el menu anterior i en crea un de nou amb aquestes tasques.
        */
        void escriure_tasques_futures(const Comanda &c);

        /** @brief Escriu les tasques passades.
        \pre Cert.
        \post Escriu totes les tasques passades.
        */
        void escriure_tasques_passades() const;
        
};

#endif