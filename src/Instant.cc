#include "Instant.hh"

int Instant::num(char c) {
	return int('c') - int('0');
}

Instant::Instant(){
	
}

Instant::Instant (string d, string h) {
	modificar_data (d);
	modificar_hora (h);
}

Instant::Instant (const Instant &i) {
  
}

bool Instant::operator<(const Instant &i) const {
	//TODO: S'ha d'implementar la funcio. Retorno true nomes perque compili
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