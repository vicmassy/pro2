#ifndef __INSTANT__
#define __INSTANT__

#ifndef __DIAGRAMA__
#include <string>
#include <iostream>
#endif

using namespace std;

/** @class Instant
    @brief Representa una moment en el temps.
*/

class Instant {

    private:
	/** @brief Funcio de conversio d'un caracter numeric a un enter.
        \pre El parametre c es un caracter numeric.
        \post Converteix el caracter c en un enter.
        */
        int num(char c) const;
	
	/** @brief Funcio d'escriptura d'enters en format data o hora.
        \pre El parametre n es un enter.
        \post Escriu pel canal estandard de sortida l'enter n, i si es un enter mes petit
        que 10, es a dir de dos digits, afegeig un 0 davant.
        */
        void escriurenum(int n) const;
	
        int hh, min, dd, mm, yy;
    
    public: 
    
        //Constructores
        
        /** @brief
        \pre Cert.
        \post Es crea un instant buit.
        */
        Instant ();

        /** @brief
        \pre d i h tenen format de data i hora.
        \post Es crea la data amb els valors dels parametres.
        */
        Instant (const string &d, const string &h);
        
        //Consultores
        
        /** @brief Compara si un element es estrictament mes petit que un altre.
        \pre Cert.
        \post Retorna true si el parametre implicit es estrictament mes petit que i. Si no retorna false.
        **/
        bool operator<(const Instant &i) const; 
        
        /** @brief Consulta l'hora del rellotge.
        \pre Cert.
        \post Retorna l'hora del parametre implicit.
        */
        void modificar_hora();
        
        //Modificadors
        
        /** @brief Modifica l'hora del rellotge.
        \pre h te format d'hora.
        \post La nova hora del parametre implicit es h.
        */
        void modificar_hora(const string &h);
        
        /** @brief Modifica la data del rellotge.
        \pre d te format de data.
        \post La nova data del parametre implicit es d.
        */
        void modificar_data(const string &d);
        
        //Escriptura
        
        /** @brief Escriu la data i l'hora del p.i.
        \pre Cert.
        \post Ha escrit la data i hora al canal de sortida.
        */
        void escriure() const;
    
};

#endif