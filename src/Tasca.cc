#include "Tasca.hh"

bool Tasca::compleix_expressio_i(const string &s, int i, int j) const {
    if (s[i] == '#')
        return (etiquetes.count(s.substr(i, j-i+1)) == 1);
    ++i; --j;
    int k = i;
    int p = 0;
    while (p != 0 or (s[k] != '.' and s[k] != ',')) {
        if (s[k] == '(') ++p;
        else if (s[k] == ')') --p;
        ++k;
    }
    if (s[k] == '.') {
        return compleix_expressio_i(s, i, k-1) and
               compleix_expressio_i(s, k+1, j);
    }
    else {
        return compleix_expressio_i(s, i, k-1) or
               compleix_expressio_i(s, k+1, j);
    }
}

Tasca::Tasca(const string &n) {
    nom = n;
}

void Tasca::afegir_etiqueta(const string &tag) {
    etiquetes.insert(tag);
}

bool Tasca::esborrar_etiqueta(const string &tag) {
    return (etiquetes.erase(tag) == 1);
}

void Tasca::esborrar_etiqueta(set<string>::iterator it) {
    etiquetes.erase(it);
}

void Tasca::esborrar_totes_etiquetes() {
    etiquetes.clear();
}

void Tasca::modificar_titol(const string &s) {
    nom = s;
}

bool Tasca::primera_etiqueta(set<string>::iterator &it) const {
    it = etiquetes.begin();
    if(it == etiquetes.end())
        return false;
    return true;
}

bool Tasca::te_etiqueta(const string &tag) const {
    return (etiquetes.count(tag) == 1);
}

bool Tasca::compleix_expressio(const string &expressio) const {
    return compleix_expressio_i(expressio, 0, expressio.size()-1);
}        

void Tasca::escriure_nom() const {
    cout << nom;
}

void Tasca::escriure_etiquetes() const {
    set<string>::const_iterator it = etiquetes.begin();
    while (it != etiquetes.end()) {
        cout << ' ' << *it;
        ++it;
    }
}