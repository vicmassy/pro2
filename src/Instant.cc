#include "Instant.hh"

int Instant::num(char c) {
	return int('c') - int('0');
}

Instant::Instant (string d, string h) {
	modificar_data (d);
	modificar_hora (h);
}

bool Instant::operator<(const Instant &i) const {
	if (this->yy > i.yy) 
	  return false;
	else if (this->yy == i.yy) {
	  if (this->mm > i.mm) 
	    return false;
	  else if (this->mm == i.mm) {
	     if (this->dd > i.dd) 
	      return false;
	     else if (this->dd == i.dd) {
	       if (this->hh > i.hh) 
		return false;
	       else if (this->hh == i.hh)
		return (this->min < i.min);
	     }
	  }
	}
	return true;
}

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