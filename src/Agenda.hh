/** @file Agenda.hh
    @brief Classe Agenda
 */

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
/*  Invariants:
        - Les tasques estan ordenades per data i hora.
        - Si l'ultima consulta realitzada es de tasques futures, el menu conte iteradors als resultats en ordre.
        En cas contrari, el menu es buit.
*/

typedef map<Instant,Tasca> Tasques;
typedef map<Instant,Tasques::iterator> Tasques_ref;

class Agenda {

    private:

        Instant r;
        Tasques tasques;
        vector<Tasques::iterator> menu;	
        
	/** @brief Escriu la tasca.
        \pre it apunta a una tasca existent del mapa tasques.
        \post S'ha escrit pel canal estandard de sortida la tasca a la que apunta el iterador it.
        */
        void escriure_tasca(Tasques::const_iterator it) const;
	
	/** @brief Comprova si l'element i del menu existeix i es modificable
        \pre Cert.
        \post Retorna fals si i no compleix  0 < i <= menu.size(), si menu[i] == tasques.end() 
        o si la tasca apuntada per menu[i] es passada. Retorna cert altrament.
        */
        bool comprovar_modificable(int i) const;
	
	/** @brief Modifica el temps d'una tasca.
        \pre L'instant i es posterior al rellotge r, i l'iterador it apunta a una tasca existent i modificable.
        \post Modifica el temps, ja sigui data o hora, de la tasca apuntada per it.
        */
        void modificar_temps(Tasques::iterator &it, const Instant &i);
	
	/** @brief Obtenim iteradors a la primera i l'ultima tasca d'un interval.
        \pre c es una comanda d'escriure tasques futures.
        \post Si c no especifica cap data, l'interval es de la data actual fins a l'ultima tasca.
        Si especifica una sola data, l'interval son totes les tasques d'aquell dia.
        Si hi ha dues dates, l'interval conte totes les tasques entre els dos dies, ambdos inclosos;
        excepte si la primera data es posterior a la segona, aleshores l'interval es buit i ambdos iteradors apunten al final.
        */
        void obtenir_tasques_interval(Comanda &c,Tasques::iterator &begin, Tasques::iterator &end);
	
	/** @brief Escriu les tasques en un interval de temps.
        \pre Cert.
        \post S'han escrit pel canal estandard de sortida totes les tasques que esta entre els dos iteradors.
        */
        void escriure_tasques_interval(Tasques::iterator &begin, Tasques::iterator &end);
	
	/** @brief Escriu les tasques en un interval de temps que compleixen l'expressio o l'etiqueta.
        \pre c es una comanda de cerca amb etiqueta o expressio booleana.
        \post S'han escrit pel canal estandard de sortida totes les tasques que compleixen l'expressio
        booleana o l'etiqueta.
        */
        void escriure_tasques_expressio(Comanda &c, Tasques::iterator &begin, Tasques::iterator &end);

    public:
    
        //Constructors
        
        /** @brief Crea una agenda buida amb data d i hora h.
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
        bool modificar_rellotge(Comanda &c);

        /** @brief Insereix una nova tasca a l'agenda.
        \pre c es una comanda d'inserir tasca.
        \post Si la data i hora son al futur i no coincideixen amb una altra tasca, retorna true i s'insereix la tasca.
        Si no, retorna false i no es fa res. Si falten hora i/o data s'utilitzen les actuals.
        */
        bool inserir_tasca(Comanda &c);

        /** @brief Modifica una tasca existent de la agenda que es trobi al menu.
        \pre c es una comanda de modificar tasca i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si les noves data i hora son al passat o coincideixen amb una altra tasca, si el numero  de tasca no es al menu,
        si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res. En cas contrari modifica la tasca i retorna true.
        */
        bool modificar_tasca(Comanda &c);

        /** @brief Esborra una tasca de l'agenda.
        \pre c es una comanda d'esborrar tasca i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si el numero  de tasca no es al menu, si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res.
        En cas contrari retorna true i esborra la tasca.
        */
        bool esborrar_tasca(Comanda &c);

        /** @brief Esborra una etiqueta d'una tasca.
        \pre c es una comanda d'esborrar etiqueta i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si la etiqueta no pertany a la tasca, el numero de tasca no es al menu, s'ha esborrat la tasca oja es al passat; 
        retorna fals i no fa res. En cas contrari retorna true i esborra l'etiqueta de la tasca.
        */
        bool esborrar_etiqueta(Comanda &c);

        /** @brief Esborra totes les etqieutes d'una tasca.
        \pre c es una comanda d'esborrar totes les etiquetes i existeix un menu (s'ha realitzat una escriptura de tasques previament).
        \post Si el numero  de tasca no es al menu, si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res.
        En cas contrari retorna true i esborra totes les etiquetes de la tasca.
        */
        bool esborrar_etiquetes(Comanda &c);        
        
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
        void escriure_tasques_futures(Comanda &c);

        /** @brief Escriu les tasques passades.
        \pre Cert.
        \post Escriu totes les tasques passades.
        */
        void escriure_tasques_passades() const;
        
};

#endif