/** @file Instant.hh
    @brief Classe Instant
 */

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
/*  Invariants:
        - L'instant representat esta entre l'any 2000 i l'any 2099.
*/

class Instant {

    private:
	/** @brief Converteix un numero codificar en ASCII a un enter.
        \pre El parametre c es un caracter entre '0' i '9'.
        \post Retorna l'enter representat per c.
        */
        int num(char c) const;
	
	/** @brief Escriu un enter amb dues xifres.
        \pre El parametre n esta entre 0 i 99.
        \post S'ha escrit pel canal estandard de sortida l'enter n amb dues xifres.
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