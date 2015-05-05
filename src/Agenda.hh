#ifndef __AGENDA__
#define __AGENDA__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "comanda.hh"
#include "Instant.hh"
#include "Tasca.hh"

using namespace std;

typedef map<Instant,Tasca> Tasques;
typedef vector<Tasques::iterator> Menu;
typedef map<string,Menu> Mapa_Etiquetes;

/** @class Agenda
	@brief Representa una agenda
*/

class Agenda {

  	private:

		Instant r;
		Tasques tasques;
		Menu menu;
		Mapa_Etiquetes etiquetes;
    
  	public:
    
		//Constructors
		
		/** @brief
		\pre Cert
		\post Es crea una agenda buida amb rellotge 'r'.
		*/
		Agenda(string d, string h);
		
		//Modificadors
		
		/** @brief Canvia el valor del rellotge intern.
		\pre Cert.
		\post El valor del rellotge del parametre implicit passa a ser el contingut de la comanda.
		*/
		void modificar_rellotge(const Comanda &c);

		/** @brief Insereix una nova tasca a l'agenda.
		\pre Pre ha de contenir una comanda d'inserir tasca.
		\post S'afegeix una tasca espicificada a la comanda.
		*/
		void inserir_tasca(const Comanda &c);

		/** @brief Modifica una tasca existent de la agenda que es trobi al menu.
		\pre S'ha realitzat una consulta de tasques futures.
		\post Modifica la tasca espicificada o retorna error si aquesta no existeix.
		*/
		void modificar_tasca(const Comanda &c);

		/** @brief Esborra una tasca de l'agenda.
		\pre Existeix la tasca en el parametre implicit.
		\post Sha esborrat la tasca del parametre implicit.
		*/
		void esborrar_tasca(const Comanda &c);

		/** @brief Esborra una etiqueta d'una tasca.
		\pre L'etiqueta existeix en la tasca.
		\post S'ha esborrat l'etiqueta de la tasca.
		*/
		void esborrar_etiqueta(const Comanda &c);

		/** @brief Esborra diverses etqieutes d'una tasca.
		\pre Hi ha una o mes etiquetes en la tasca.
		\post S'han esborrat totes les etiquetes de la tasca.
		*/
		void esborrar_etiquetes(const Comanda &c);
		
		
		//Consultores

		/** @brief Retorna el rellotge intern.
		\pre Cert.
		\post Retorna la data i l'hora actuals de l'agenda.
		*/
		Instant consultar_rellotge();
		
		//Lectura
		
		//Escriptura
		
		/** @brief Escriu el rellotge intern.
		\pre Cert.
		\post S'ha escrit el rellotge (data i hora) al canal de sortida.
		*/
		void escriure_rellotge();

		/** @brief Escriu les tasques especificades a la comanda i genera el menu pertinent
		\pre Cert.
		\post Escriu les tasques futures al instant proporcionat o bé al rellotge intern.
		*/
		void escriure_tasques_futures(const Comanda &c);

		/** @brief Escriu les tasques passades.
		\pre Cert.
		\post S'han escrit totes les tasques passades al canal de sortida.
		*/
		void escriure_tasques_passades();
    
};

#endif