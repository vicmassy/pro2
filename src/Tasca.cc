#include "Tasca.hh"

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

bool Tasca::compleix_expressio(const string &expressio, int &i){
    char base = expressio[i];
    if(base == '#'){
        int pos_inicial = i;
        while(expressio[i] != ')' or expressio[i] != ',' or expressio[i] != '.')
            i++;
        string etiqueta = expressio.substr(pos_inicial,i-pos_inicial);
        return te_etiqueta(etiqueta);
    } else {
        i++;
        bool e1 = compleix_expressio(expressio,i);
        char op = expressio[i];
        i++;
        bool e2 = compleix_expressio(expressio,i);
        i++;
        if(op == '.')
            return (e1 and e2);
        else 
            return (e1 or e2);
    }
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