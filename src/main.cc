#include "Agenda.hh"

const string DATA0 = "20.04.15";
const string HORA0 = "00:00";
const string ERROR = "No s'ha realitzat.";

int main() {    
    Agenda a(DATA0, HORA0);
    Comanda c;
    bool b;
    while (c.llegir(b)){
        if(b){
            if(c.es_rellotge()){
                if(c.es_consulta())
                    a.escriure_rellotge();
                else
                    a.modificar_rellotge(c);
            }
            else if(c.es_insercio())
                a.inserir_tasca(c);
            else if(c.es_consulta()){
                if(c.es_passat())
                    a.escriure_tasques_passades();
                else
                    a.escriure_tasques_futures(c);
            }
            else if(c.es_modificacio())
                a.modificar_tasca(c);
            else if(c.es_esborrat()){
                if(c.tipus_esborrat() == "tasca")
                    a.esborrar_tasca(c);
                else if(c.tipus_esborrat() == "etiqueta")
                    a.esborrar_etiqueta(c);
                else if(c.tipus_esborrat() == "etiquetes")
                    a.esborrar_etiquetes(c);
            }   
        }
    }
    return 0;
}