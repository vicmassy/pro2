#include "Instant.hh"

int Instant::num(char c) {
  return int('c') - int('0');
}

Instant::Instant (string d, string h) {
  modificar_data (d);
  modificar_hora (h);
}

Instant::Instant (Instant i) {
  
}

static bool Instant::compge(const Instant &a, const Instant &b) {
  if (a.yy > b.yy)
    return true;
  if (a.yy == b.yy) {
    if (a.mm > b.mm)
      return true;
    if (a.mm == b.mm) {
      if (a.dd > b.dd) 
	return true;
      if (a.dd == b.dd) {
	if (a.hh > b.hh)
	  return true;
	if (a.hh == b.hh)
	  return (a.min > b.min);
      }
    }
  }
  return false;
}

/*
static bool Instant::operator<(const Instant &i) const {
  if (apellido1 != n.apellido1) return apellido1 < n.apellido1;
  else if (apellido2 != n.apellido2) return apellido2 < n.apellido2;
  else return nombre < n.nombre;
}
*/

void Instant::modificar_hora(string h) {
  hh = num(h[0])*10 + num(h[1]);
  min = num(h[3])*10 + num(h[4]);
}

void Instant::modificar_data(string d) {
  dd = num(d[0])*10 + num(d[1]);
  mm = num(d[3])*10 + num(d[4]);
  yy = num(d[6])*10 + num(d[7]);
}

void Instant::escriure_data() {
  cout << dd << '.' << mm << '.' << yy << ' ' << hh << ':' << min;
}