#ifndef __INSTANT__
#define __INSTANT__

#include <string>
#include <iostream>

using namespace std;

class Instant {

private:
  
    int num(char c);
    int hh, min, dd, mm, yy;
    
public: 
    
    //Creadora
  
    //Pre: d i h tenen format de data i hora respectivament
    //Post: es crea la data amb els valors dels parametres
    Instant (string d, string h);

    Instant (const Instant &i);
    
    //Consultora
    
    //Pre: cert
    //Post: retorna true si a > b, sino false
    static bool compge(const Instant &a, const Instant &b);
    
    //Comparadors
    
    bool operator<(const Instant &i) const; 
    
    //Modificadors
    
    //Pre: h te format d'hora
    //Post: la nova hora del parametre implicit es la d'h
    void modificar_hora(string h);
    
    //Pre: d te format de data
    //Post: la nova data del parametre implicit es la de d
    void modificar_data(string d);
    
    //Escriptura
    
    //Pre: cert
    //Post: escriu la data i hora al canal de sortida
    void escriure_data();
    
};

#endif