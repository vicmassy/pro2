#include "Instant.hh"

int Instant::num(char c) const {
    return int(c) - int('0');
}

void Instant::escriurenum(int n) const {
    if (n < 10)
        cout << '0';
    cout << n;
}

/** @brief
\pre Cert.
\post Es crea un instant buit.
*/
Instant::Instant () {}

/** @brief
\pre d i h tenen format de data i hora.
\post Es crea la data amb els valors dels parametres.
*/
Instant::Instant (const string &d, const string &h) {
    modificar_data(d);
    modificar_hora(h);
}

/** @brief Compara si un element es estrictament mes petit que un altre.
\pre Cert.
\post Retorna true si el parametre implicit es estrictament mes petit que i. Si no retorna false.
**/
bool Instant::operator<(const Instant &i) const {
    if (this->yy < i.yy)
        return true;
    if (this->yy == i.yy) {
        if (this->mm < i.mm)
            return true;
        if (this->mm == i.mm) {
            if (this->dd < i.dd)
                return true;
            if (this->dd == i.dd) {
                if (this->hh < i.hh)
                    return true;
                if (this->hh == i.hh)
                    return (this->min < i.min);
            }
        }
    }
    return false;     
}

/** @brief Modifica l'hora del rellotge.
\pre h te format d'hora.
\post La nova hora del parametre implicit es h.
*/
void Instant::modificar_hora(const string &h) {
    min = num(h[3])*10 + num(h[4]);
    hh = num(h[0])*10 + num(h[1]);
}

/** @brief Modifica la data del rellotge.
\pre d te format de data.
\post La nova data del parametre implicit es d.
*/
void Instant::modificar_data(const string &d) {
    dd = num(d[6])*10 + num(d[7]);
    mm = num(d[3])*10 + num(d[4]);
    yy = num(d[0])*10 + num(d[1]);
}

/** @brief Escriu la data i l'hora del p.i.
\pre Cert.
\post Ha escrit la data i hora al canal de sortida.
*/
void Instant::escriure() const {
    escriurenum(dd);
    cout << '.';
    escriurenum(mm);
    cout << '.';
    escriurenum(yy);
    cout << ' ';
    escriurenum(hh);
    cout << ':';
    escriurenum(min);
}