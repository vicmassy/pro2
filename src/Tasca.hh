#ifndef __TASCA__
#define __TASCA__

#ifndef __DIAGRAMA__
#include <iostream>
#include <map>
#endif

using namespace std;


class Tasca {
  
  	private:

		string nom;
		map<string,bool> etiquetes;


  	public:

		//Constructors

  		/** @brief
		\pre cert
		\post es crea una tasca amb titol n
		*/
		Tasca(string n);
		
		//Modificadores
		
		/** @brief Afegeix una etiqueta a la tasca
		\pre cert
		\post s'afegeix l'etiqueta al p.i.
		*/
		void afegir_etiqueta(string tag);
		
		/** @brief Esborra una etiqueta de la tasca
		\pre cert
		\post si tag pertany a la tasca, es esborrada
		*/
		void esborrar_etiqueta(string tag);
		
		/** @brief Esborra totes les etiquetes de la tasca
		\pre cert
		\post s'han esborrat totes les etiquetes
		*/
		void esborrar_totes_etiquetes();

		//Consultores
		
		/** @brief Retorna si la etiqueta pertany a la tasca
		\pre cert
		\post retorna true si tag es al pi
		*/
		bool te_etiqueta(string tag);
		
		//IO
	
		/** @brief
		\pre El p.i. no es buit
		\post Escriu la tasca pel canal de sortida
		*/
		void escriure_tasca();

};

#endif