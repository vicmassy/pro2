#include "Instant.hh"

int Instant::num(char c) const {
    return int(c) - int('0');
}

void Instant::escriurenum(int n) const {
    if (n < 10)
        cout << '0';
    cout << n;
}

Instant::Instant () {}

Instant::Instant (const string &d, const string &h) {
    modificar_data(d);
    modificar_hora(h);
}

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

void Instant::modificar_hora(const string &h) {
    min = num(h[3])*10 + num(h[4]);
    hh = num(h[0])*10 + num(h[1]);
}

void Instant::modificar_data(const string &d) {
    dd = num(d[0])*10 + num(d[1]);
    mm = num(d[3])*10 + num(d[4]);
    yy = num(d[6])*10 + num(d[7]);
}

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