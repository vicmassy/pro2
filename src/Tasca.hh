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
		\pre cert
		\post es crea una tasca amb titol n
		*/
		Tasca(string n);
		
		/** @brief
		\pre cert
		\post es crea una tasca amb titol n i e etiquetes
		*/
		Tasca(string n, map<string,bool> &e);


		//Modificadores


		//Consultores
	
		/** @brief
		\pre El p.i. no es buit
		\post Escriu la tasca pel canal de sortida
		*/
		void escriure_tasca();

};

#endif