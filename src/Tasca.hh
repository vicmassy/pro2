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

		Tasca(string n);

		Tasca(string n, map<string, bool> &e);


		//Consultores
	
		//Pre: El p.i. no es buit
		//Post: Escriu la tasca pel canal de sortida
		void escriure_tasca();

};

#endif