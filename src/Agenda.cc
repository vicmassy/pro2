#include "Agenda.hh"

void Agenda::escriure_tasca(Tasques::const_iterator it) const {
    (*it).second.escriure_nom();
    cout << ' ';
    (*it).first.escriure();
    (*it).second.escriure_etiquetes();
}

bool Agenda::comprovar_modificable(int i) const {
    if (i < 0 or i >= menu.size())
        return false;
    if (menu[i] == tasques.end())
        return false;
    if ((*menu[i]).first < r)
        return false;
    return true;
}

void Agenda::modificar_temps(Tasques::iterator &it, const Instant &i) {
    Tasques::iterator it_original = it;
    it = (tasques.insert(pair<Instant,Tasca> (i, (*it).second))).first;
    tasques.erase(it_original);
}

void Agenda::obtenir_tasques_interval(Comanda &c, Tasques::iterator &begin, Tasques::iterator &end) {
    if (c.nombre_dates() == 0) {
       begin = tasques.lower_bound(r);
       end = tasques.end(); 
    } else if (c.nombre_dates() == 1) {
       Instant t1 (c.data(1), "00:00");
       Instant t2 (c.data(1), "23:59");
       begin = tasques.lower_bound(t1);
       end = tasques.upper_bound(t2);   
    } else {
       Instant t1 (c.data(1), "00:00");
       Instant t2 (c.data(2), "23:59");
       if (t2 < t1){
            begin = tasques.end();
            end = tasques.end();
        } else {
            begin = tasques.lower_bound(t1);
            end = tasques.upper_bound(t2);
        }
    }
}

void Agenda::escriure_tasques_interval(Tasques::iterator &begin, Tasques::iterator &end){
    int i = 1;
    while (begin != end) {
        cout << i << ' ';
        escriure_tasca(begin);
        cout << endl;
        menu.push_back(begin);
        ++begin;
        ++i;
    }
}

void Agenda::escriure_tasques_expressio(Comanda &c, Tasques::iterator &begin, Tasques::iterator &end){
    int num_menu = 1;
    while(begin!=end){
      bool b;
      if(c.te_expressio())
	b = (*begin).second.compleix_expressio(c.expressio());
      else
	b = (*begin).second.compleix_expressio(c.etiqueta(1));
      if(b){
	  cout << num_menu << ' ';
	  escriure_tasca(begin);
	  cout << endl;
	  menu.push_back(begin);
	  num_menu++;
      }	  
      begin++;
    }
}
        
Agenda::Agenda(const string &d, const string &h) {
    r.modificar_data(d);
    r.modificar_hora(h);
}

bool Agenda::modificar_rellotge(Comanda &c) {
    Instant t = r;
    if (c.nombre_dates() == 1)
        t.modificar_data(c.data(1));
    if (c.te_hora())
        t.modificar_hora(c.hora());
    if (t < r)
        return false;
    r = t;
    return true;
}

bool Agenda::inserir_tasca(Comanda &c) {
    Instant t = r;
    t.modificar_hora(c.hora());
    if (c.nombre_dates() == 1)
        t.modificar_data(c.data(1));
    if (t < r)
        return false;
    if (tasques.count(t) == 1)
        return false;
    Tasca q(c.titol());
    Tasques::iterator it = tasques.insert(pair<Instant,Tasca> (t,q)).first;
    for (int i = 1; i <= c.nombre_etiquetes(); ++i)
        (*it).second.afegir_etiqueta(c.etiqueta(i));
    return true;
}

bool Agenda::modificar_tasca(Comanda &c) {
    int k = c.tasca() - 1;
    if (not comprovar_modificable(k))
        return false;  
    bool canviar_temps = false;
    Instant i = (*menu[k]).first;
    if (c.nombre_dates() == 1) {
        i.modificar_data(c.data(1));
        canviar_temps = true;
    }
    if (c.te_hora()) {
        i.modificar_hora(c.hora());
        canviar_temps = true;
    }
    if (canviar_temps) {
        if (i < r)
            return false;
        if (tasques.count(i) == 1)
            return false;
        modificar_temps(menu[k], i);
    }
    if (c.te_titol())
        (*menu[k]).second.modificar_titol(c.titol());
    for (int j = 1; j <= c.nombre_etiquetes(); ++j)
        (*menu[k]).second.afegir_etiqueta(c.etiqueta(j));
    return true;
}

bool Agenda::esborrar_tasca(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    (*menu[i]).second.esborrar_totes_etiquetes();
    tasques.erase(menu[i]);
    menu[i] = tasques.end();
    return true;
}

bool Agenda::esborrar_etiqueta(Comanda &c) {
    int i = c.tasca() - 1;
    if (comprovar_modificable(i) and (*menu[i]).second.esborrar_etiqueta(c.etiqueta(1))){
        return true;
    }
    return false;
}

bool Agenda::esborrar_etiquetes(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    (*menu[i]).second.esborrar_totes_etiquetes();
    return true;
}

void Agenda::escriure_rellotge() const {
    r.escriure();
    cout << endl;
}

void Agenda::escriure_tasques_futures(Comanda &c) {
    menu.clear();
    Tasques::iterator begin;
    Tasques::iterator end;
    obtenir_tasques_interval(c,begin,end);
    if(c.te_expressio() or c.nombre_etiquetes() == 1)
        escriure_tasques_expressio(c,begin,end);
    else
        escriure_tasques_interval(begin,end);
}

void Agenda::escriure_tasques_passades() {
    menu.clear();
    Tasques::const_iterator it = tasques.begin();
    Tasques::const_iterator it_end = tasques.lower_bound(r);
    int i = 1;
    while (it != it_end) {
        cout << i << ' ';
        escriure_tasca(it);
        cout << endl;
        ++i;
        ++it;
    }
}