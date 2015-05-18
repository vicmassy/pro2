#include "Agenda.hh"

void Agenda::escriure_tasca(Tasques::const_iterator it) const {
    (*it).second.escriure_nom();
    cout << ' ';
    (*it).first.escriure();
    (*it).second.escriure_etiquetes();
}

void Agenda::agenda_afegir_etiqueta(Tasques::iterator it, const string &tag) {
    (*it).second.afegir_etiqueta(tag);
    Etiquetes::iterator et_it = etiquetes.lower_bound(tag);
    if (et_it != etiquetes.end() and (*et_it).first == tag)
        (*et_it).second.insert(pair<Instant,Tasques::iterator> ((*it).first, it));
    else {
        Tasques_ref m;
        m.insert(pair<Instant,Tasques::iterator> ((*it).first, it));
        etiquetes.insert(et_it, pair<string,Tasques_ref> (tag, m));
    }
}

void Agenda::esborrar_totes_etiquetes_agenda(Tasques::iterator it) {
    set<string>::iterator etiq_it;
    while((*it).second.primera_etiqueta(etiq_it)){
        Etiquetes::iterator map_it = etiquetes.find(*etiq_it);
        (*map_it).second.erase((*it).first);
        if ((*map_it).second.empty())
            etiquetes.erase(map_it);
        (*it).second.esborrar_etiqueta(etiq_it);
    }
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
    set<string>::iterator tag_it;
    while((*it_original).second.primera_etiqueta(tag_it)) {
        Etiquetes::iterator map_it = etiquetes.find(*tag_it);
        (*map_it).second.erase((*it_original).first);
        (*map_it).second.insert(pair<Instant,Tasques::iterator> (i, it));
        (*it_original).second.esborrar_etiqueta(tag_it);
    }
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

void Agenda::escriure_tasques_etiquetes(Comanda &c, Tasques::iterator &begin, Tasques::iterator &end){
    int num_menu = 1;
    while(begin != end){
        if((*begin).second.te_etiqueta(c.etiqueta(1))){
            cout << num_menu << ' ';
            escriure_tasca(begin);
            cout << endl;
            menu.push_back(begin);
            num_menu++;
        }
        begin++;
    }
}

void Agenda::escriure_tasques_expressio(Comanda &c, Tasques::iterator &begin, Tasques::iterator &end){
    int num_menu = 1;
    while(begin!=end){
        if((*begin).second.compleix_expressio(c.expressio())){
            cout << num_menu << ' ';
            escriure_tasca(begin);
            cout << endl;
            menu.push_back(begin);
            num_menu++;
        }
        begin++;
    }
}

/* FUNCIONS DE LA PART DE CERCA PER ETIQUETES (EN PROGRES!)

void convertir_expressio(const string &s, vector<expressio_processada> &v) {
    int i = 0;
    while(i < s.size()) {
        int n;
        Etiquetes::const_iterator tag_it;
        Tasques_ref::const_iterator it;
        if (s[i] == '#') {
            int j = i;
            while (s[i] != '.' and s[i] != ',' and s[i] != ')') ++i;
            v.push_back({etiquetes.find(s.substr(j, i-j))));
        }
        else {
            if (s[i] == '(') n = 1;
            else if (s[i] == ')') n = 2;
            else if (s[i] == '.') n = 3;
            else n = 4;
            ++i;
        }
    }
}

Tasques::iterator seguent_element (const vector<pair<char, Tasques::iterator> > &v, int &i, int &j) {
    if (v[i].first == '#') {
        return v[i].second;
    }
    ++i; --j;
    int k = i;
    int p = 0;
    while (p != 0 or (v[k].first != '.' and v[k].first != ',')) {
        if (v[k].first == '(') ++p;
        else if (v[k].first == ')') --p;
        ++k;
    }
    
} */ 
        
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
        agenda_afegir_etiqueta(it, c.etiqueta(i));
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
        agenda_afegir_etiqueta(menu[k], c.etiqueta(j));
    return true;
}

bool Agenda::esborrar_tasca(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    esborrar_totes_etiquetes_agenda(menu[i]);
    tasques.erase(menu[i]);
    menu[i] = tasques.end();
    return true;
}

bool Agenda::esborrar_etiqueta(Comanda &c) {
    int i = c.tasca() - 1;
    if (comprovar_modificable(i) and (*menu[i]).second.esborrar_etiqueta(c.etiqueta(1))){
        etiquetes[c.etiqueta(1)].erase((*menu[i]).first);
        return true;
    }
    return false;
}

bool Agenda::esborrar_etiquetes(Comanda &c) {
    int i = c.tasca() - 1;
    if (not comprovar_modificable(i))
        return false;
    esborrar_totes_etiquetes_agenda(menu[i]);
    return true;
}

Instant Agenda::consultar_rellotge() const {
    return r;
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
    if(c.te_expressio())
        escriure_tasques_expressio(c,begin,end);
    else if(c.nombre_etiquetes() == 1)
        escriure_tasques_etiquetes(c,begin,end);
    else
        escriure_tasques_interval(begin,end);
}

void Agenda::escriure_tasques_passades() const {
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