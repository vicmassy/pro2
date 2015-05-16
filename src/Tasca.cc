#include "Tasca.hh"

bool Tasca::compleix_expressio_i(const string &s, int &i, int &j) {
    if (s[i] == '#')
        return (etiquetes.count(s.substr(i, j-i+1)) == 1);
    ++i; --j;
    int k = i;
    int p = 0;
    while (p != 0 or (s[k] != '.' and s[k] != ',')) {
        if (s[i] == '(') ++p;
        else if (s[i] == ')') --p;
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

/** @brief
\pre Cert.
\post Crea una tasca amb titol n.
*/
Tasca::Tasca(const string &n) {
    nom = n;
}

/** @brief Afegeix una etiqueta a la tasca.
\pre Cert.
\post S'ha afegit l'etiqueta al p.i., si ja hi era no fa res.
*/
void Tasca::afegir_etiqueta(const string &tag){
    etiquetes.insert(tag);
}

/** @brief Esborra una etiqueta de la tasca.
\pre Cert.
\post Si tag pertany a la tasca, es esborrada i retorna true. Si no, no fa res i retorna false.
*/
bool Tasca::esborrar_etiqueta(const string &tag) {
    return (etiquetes.erase(tag) == 1);
}


void Tasca::esborrar_etiqueta(set<string>::iterator it){
    etiquetes.erase(it);
}

/** @brief Esborra totes les etiquetes de la tasca.
\pre Cert.
\post S'han esborrat totes les etiquetes del p.i.
*/
void Tasca::esborrar_totes_etiquetes() {
    etiquetes.clear();
}

void Tasca::modificar_titol(const string &s) {
    nom = s;
}

/** @brief 
\pre 
\post
*/
bool Tasca::primera_etiqueta(set<string>::iterator &it){
    it = etiquetes.begin();
    if(it == etiquetes.end())
        return false;
    return true;
}

/** @brief Retorna si la etiqueta pertany a la tasca.
\pre Cert.
\post Retorna true si tag pertany al p.i.
*/
bool Tasca::te_etiqueta(const string &tag) const {
    return (etiquetes.count(tag) == 1);
}

bool Tasca::compleix_expressio(const string &expressio){
    return compleix_expressio_i(expressio, 0, expressio.size()-1);
}        

/** @brief Escriu la tasca
\pre El p.i. no es buit.
\post S'ha escrit la tasca.
*/
void Tasca::escriure_nom() const {
    cout << nom;
}

/** @brief Escriu la tasca
\pre El p.i. no es buit.
\post S'han escrit les etiquetes en ordre lexicografic.
*/
void Tasca::escriure_etiquetes() const {
    set<string>::const_iterator it = etiquetes.begin();
    if (it != etiquetes.end()) {
        cout << *it;
        ++it;
    }
    while (it != etiquetes.end()) {
        cout << ' ' << *it;
        ++it;
    }
}