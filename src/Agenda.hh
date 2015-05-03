#ifndef __AGENDA__
#define __AGENDA__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Instant.hh"
#include "comanda.hh"

using namespace std;

class Agenda {

  	private:

		Instant r;
    
  	public:
    
		//Constructors
		
		//Pre: cert
		//Post: es crea una agenda buida amb rellotge 'r'
		Agenda(string d, string h);
		
		//Modificadors
		
		//Pre: cert
		//Post: el valor del rellotge del parametre implicit passa a ser el contingut de la comanda
		void modificar_rellotge(const Comanda &c);
		
		//Pre: cert
		//Post: s'afegeix una tasca espicificada a la comanda
		void inserir_tasca(const Comanda &c);
		
		//Pre: s'ha realitzat una consulta de tasques futures
		//Post: modifica la tasca espicificada o retorna error si aquesta no existeix
		void modificar_tasca(const Comanda &c);
		
		//Pre: s'ha realitzat una consulta de tasques
		//Post: s'ha esborrat la tasca especificada o retorna error si aquesta no existeix
		void esborrar_tasca(const Comanda &c);
		
		
		// TODO: Potser retornar un bool si la funcio sha executat OK?
		
		void interpretar_modificar_rellotge(const Comanda &c);
		
		void interpretar_inserir_tasca(const Comanda &c);
		
		void interpretar_escriure_tasques(const Comanda &c);
		
		void interpretar_modificar_tasca(const Comanda &c);

		void interpretar_esborrar_tasca(const Comanda &c);
		
		void interpretar_esborrar_etiqueta(const Comanda &c);
		
		void interpretar_esborrar_etiquetes(const Comanda &c);
		
		//Consultores
		//Pre: 
		//Post:
		Instant consultar_rellotge();
		
		//Lectura
		
		//Escriptura
		
		//Pre: cert
		//Post: s'ha escrit el rellotge al canal de sortida
		void escriure_rellotge();
		
		//Pre: cert
		//Post: s'han escrit les tasques especificades al canal de sortida
		void escriure_tasques_futures(const Comanda &c);
		
		//Pre: cert
		//Post: s'han escrit totes les tasques passades al canal de sortida
		void escriure_tasques_passades();
    
};

#endif