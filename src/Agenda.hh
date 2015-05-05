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

/** @class Agenda
	@brief Representa una agenda
*/

class Agenda {

  	private:

		Instant r;
		map<Instant,Tasca> tasques;
		vector<map<Instant,Tasca>::iterator> menu;
    
  	public:
    
		//Constructors
		
		/** @brief
		\pre Cert
		\post Es crea una agenda buida amb rellotge 'r'
		*/
		Agenda(string d, string h);
		
		//Modificadors
		
		// TODO: Potser retornar un bool si la funcio sha executat OK?

		/** @brief Canvia el valor del rellotge intern
		\pre cert
		\post el valor del rellotge del parametre implicit passa a ser el contingut de la comanda
		*/
		void modificar_rellotge(const Comanda &c);

		/** @brief Insereix una nova tasca a l'agenda
		\pre Pre ha de contenir una comanda d'inserir tasca
		\post s'afegeix una tasca espicificada a la comanda
		*/
		void inserir_tasca(const Comanda &c);

		/** @brief Modifica una tasca existent de la agenda que es trobi al menu
		\pre s'ha realitzat una consulta de tasques futures
		\post modifica la tasca espicificada o retorna error si aquesta no existeix
		*/
		void modificar_tasca(const Comanda &c);

		/** @brief Esborra una tasca de l'agenda
		\pre 
		\post 
		*/
		void esborrar_tasca(const Comanda &c);

		/** @brief Esborra una etiqueta d'una tasca
		\pre L'etiqueta existeix en la tasca
		\post S'ha esborrat l'etiqueta de la tasca
		*/
		void esborrar_etiqueta(const Comanda &c);

		/** @brief Esborra diverses etqieutes d'una tasca
		\pre Hi ha una o mes etiquetes en la tasca
		\post s'han esborrat totes les etiquetes de la tasca
		*/
		void esborrar_etiquetes(const Comanda &c);
		
		
		//Consultores

		/** @brief Retorna el rellotge intern
		\pre cert
		\post retorna la data i l'hora actuals de l'agenda
		*/
		Instant consultar_rellotge();
		
		//Lectura
		
		//Escriptura
		
		/** @brief Escriu el rellotge intern
		\pre cert
		\post s'ha escrit el rellotge (data i hora) al canal de sortida
		*/
		void escriure_rellotge();

		/** @brief Escriu les tasques especificades a la comanda i genera el menu pertinent
		\pre 
		\post 
		*/
		void escriure_tasques_futures(const Comanda &c);

		/** @brief Escriu les tasques passades
		\pre cert
		\post s'han escrit totes les tasques passades al canal de sortida
		*/
		void escriure_tasques_passades();
    
};

#endif