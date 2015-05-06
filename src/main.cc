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
                else {
                    if(not a.modificar_rellotge(c))
                        cout << ERROR << endl;
                }
            }
            else if(c.es_insercio()) {
                if(not a.inserir_tasca(c))
                    cout << ERROR << endl;
            }
            else if(c.es_consulta()){
                if(c.es_passat())
                    a.escriure_tasques_passades();
                else {
                    if (not a.escriure_tasques_futures(c))
                        cout << ERROR << endl;
                }
            }
            else if(c.es_modificacio()) {
                if (not a.modificar_tasca(c))
                    cout << ERROR << endl;
            }
            else if(c.es_esborrat()){
                if(c.tipus_esborrat() == "tasca") {
                    if (not a.esborrar_tasca(c))
                        cout << ERROR << endl;
                }
                else if(c.tipus_esborrat() == "etiqueta") {
                    if (not a.esborrar_etiqueta(c))
                        cout << ERROR << endl;
                }
                else if(c.tipus_esborrat() == "etiquetes") {
                    if (not a.esborrar_etiquetes(c))
                        cout << ERROR << endl;
                }
            }   
        }
    }
    return 0;
}