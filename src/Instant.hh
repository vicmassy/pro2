#ifndef __INSTANT__
#define __INSTANT__

#include <string>
#include <iostream>

using namespace std;

/** @class Instant
	@brief Representa una classe Instant.
*/

class Instant {

	private:
  
		int num(char c);
		int hh, min, dd, mm, yy;
	
	public: 
	
		//Creadores
	  
	  	/** @brief
		\pre Cert.
	   	\post Es crea un instant sense valors.
	   	*/
	   	Instant ();

	   	/** @brief
		\pre d i h tenen format de data i hora respectivament.
		\post Es crea la data amb els valors dels parametres.
		*/
		Instant (string d, string h);
	
		/** @brief
	   	\pre Instant i no esta buit
	   	\post es crea una copia de l'instant i
	   	*/
		Instant (const Instant &i);
		
		//Comparadors
		
		/** @brief
		\pre LOLXD
		\post LOLA
		**/
		bool operator<(const Instant &i) const; 
		
		//Modificadors
		
		/** @brief
		\pre h te format d'hora
		\post la nova hora del parametre implicit es la d'h
		*/
		void modificar_hora(string h);
		
		/** @brief
		\pre d te format de data
		\post la nova data del parametre implicit es la de d
		*/
		void modificar_data(string d);
		
		//Escriptura
		
		/** @brief
		\pre cert
		\post escriu la data i hora al canal de sortida
		*/
		void escriure_data();
	
};

#endif