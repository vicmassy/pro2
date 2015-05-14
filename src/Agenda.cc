#include "Agenda.hh"

void Agenda::escriure_tasca(tasques_it_c it) const {
    (*it).second.escriure_nom();
    cout << ' ';
    (*it).first.escriure();
    cout << ' ';
    (*it).second.escriure_etiquetes();
}

void Agenda::agenda_afegir_etiqueta(tasques_it it, const string &tag) {
    (*it).second.afegir_etiqueta(tag);
    map<string,map<Instant,tasques_it> >::iterator it2 = etiquetes.find(tag);
    if (it2 != etiquetes.end())
        (*it2).second.insert(pair<Instant,tasques_it> ((*it).first, it));
    else {
        map<Instant,tasques_it> m;
        m.insert(pair<Instant,tasques_it> ((*it).first, it));
        etiquetes.insert(pair< string,map<Instant,tasques_it> > (tag, m));
    }
}

bool Agenda::comprovar_modificable(int i) {
    if (i < 0 or i >= menu.size())
        return false;
    if (menu[i] == tasques.end())
        return false;
    if ((*menu[i]).first < r)
        return false;
    return true;
}    
        
/** @brief
\pre Cert.
\post Es crea una agenda buida amb data d i hora h.
*/
Agenda::Agenda(const string &d, const string &h) {
    r.modificar_data(d);
    r.modificar_hora(h);
}

/** @brief Canvia el valor del rellotge intern.
\pre c es una comanda de modificar rellotge.
\post S'actualitza el valor del rellotge amb les dades de la comanda si son valides (si en falten 
s'utilitzen les actuals) i retorna true. Si no son valides no fa res i retorna false.
*/
bool Agenda::modificar_rellotge(Comanda &c) {
    Instant t = r;
    if (c.nombre_dates() == 1)
        t.modificar_data(c.data(1));
    if (c.te_hora())
        t.modificar_data(c.hora());
    if (t < r)
        return false;
    r = t;
    return true;
}


/** @brief Insereix una nova tasca a l'agenda.
\pre c es una comanda d'inserir tasca.
\post Si la data i hora son al futur i no coincideixen amb una altra tasca, retorna true i s'insereix la tasca.
Si no, retorna false i no es fa res. Si falten hora i/o data s'utilitzen les actuals.
*/
bool Agenda::inserir_tasca(Comanda &c) {
    Instant t = r;
    r.modificar_hora(c.hora());
    if (c.nombre_dates() == 1)
        r.modificar_data(c.data(1));
    if (t < r)
        return false;
    if (tasques.count(t) == 1)
        return false;
    Tasca q(c.titol());
    tasques_it it = tasques.insert(pair<Instant,Tasca> (t,q)).first;
    for (int i = 1; i <= c.nombre_etiquetes(); ++i)
        agenda_afegir_etiqueta(it, c.etiqueta(i));
    return true;
}


/** @brief Modifica una tasca existent de la agenda que es trobi al menu.
\pre c es una comanda de modificar tasca i existeix un menu (s'ha realitzat una escriptura de tasques previament).
\post Si les noves data i hora son al passat o coincideixen amb una altra tasca, si el numero  de tasca no es al menu,
si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res. En cas contrari modifica la tasca i retorna true.
*/
bool Agenda::modificar_tasca(Comanda &c) {
    return true;   
}


/** @brief Esborra una tasca de l'agenda.
\pre c es una comanda d'esborrar tasca i existeix un menu (s'ha realitzat una escriptura de tasques previament).
\post Si el numero  de tasca no es al menu, si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res.
En cas contrari retorna true i esborra la tasca.
*/
bool Agenda::esborrar_tasca(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    tasques.erase(menu[i]);
    menu[i] = tasques.end();
    return true;
}


/** @brief Esborra una etiqueta d'una tasca.
\pre c es una comanda d'esborrar etiqueta i existeix un menu (s'ha realitzat una escriptura de tasques previament).
\post Si la etiqueta no pertany a la tasca, el numero de tasca no es al menu, s'ha esborrat la tasca oja es al passat; 
retorna fals i no fa res. En cas contrari retorna true i esborra l'etiqueta de la tasca.
*/
bool Agenda::esborrar_etiqueta(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    return (*menu[i]).second.esborrar_etiqueta(c.etiqueta(1));
}


/** @brief Esborra totes les etqieutes d'una tasca.
\pre c es una comanda d'esborrar totes les etiquetes i existeix un menu (s'ha realitzat una escriptura de tasques previament).
\post Si el numero  de tasca no es al menu, si s'ha esborrat la tasca o si ja es al passat; retorna fals i no fa res.
En cas contrari retorna true i esborra totes les etiquetes de la tasca.
*/
bool Agenda::esborrar_etiquetes(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    (*menu[i]).second.esborrar_totes_etiquetes();
    return true;
}
        

/** @brief Retorna el rellotge intern.
\pre Cert.
\post Retorna la data i l'hora actuals de l'agenda.
*/
Instant Agenda::consultar_rellotge() const {
    return r;
}


/** @brief Escriu el rellotge intern.
\pre Cert.
\post S'ha escrit el rellotge (data i hora) al canal de sortida.
*/
void Agenda::escriure_rellotge() const {
    r.escriure();
    cout << endl;
}


/** @brief Escriu les tasques especificades a la comanda i genera el menu pertinent
\pre c conte una comnanda de consulta de tasques.
\post Escriu les tasques futures a l'interval proporcionat (si no hi ha, al rellotge intern); o les que compleixin
una expressio amb etiquetes; o ambdues. Esborra el menu anterior i en crea un de nou amb aquestes tasques.
*/
void Agenda::escriure_tasques_futures(Comanda &c) {

}


/** @brief Escriu les tasques passades.
\pre Cert.
\post Escriu totes les tasques passades.
*/
void Agenda::escriure_tasques_passades() const {
    tasques_it_c it = tasques.begin();
    int i = 1;
    while ((*it).first < r and it != tasques.end()) {
        cout << i << ' ';
        escriure_tasca(it);
        cout << endl;
        ++i;
        ++it;
    }
}