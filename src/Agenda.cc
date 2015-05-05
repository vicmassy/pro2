#include "Agenda.hh"

Agenda::Agenda(string d, string h) {
	// TODO: Hem de convertir els strings en un objecte instant i guardar-lo a r
	r.modificar_data(d);
	r.modificar_hora(h);
}

void Agenda::modificar_rellotge(const Comanda &c) {
	/*
	Instant nou(consultar_rellotge());
	if (c.nombre_dates() == 1)
		nou.modificar_data(c.data(1));
	if (c.te_hora())
		nou.modificar_hora(c.hora());
	if (not(nou < consultar_rellotge()))
	  	// TODO: Gestionar quan és igual, que no canviï
		modificar_rellotge(nou);
	else
		cout << ERROR << endl;
	*/
	/*
  	if (c.nombre_dates() == 1)
		r.modificar_data(c.data(1));
  	if (c.te_hora())
		r.modificar_hora(c.hora);
	*/
}

void Agenda::inserir_tasca(const Comanda &c) {
	/*
	vector<string> etiquetes(c.nombre_etiquetes());
	for (int i = 1; i <= c.nombre_etiquetes(); ++i)
		etiquetes[i-1] = c.etiqueta(i);
	if(c.nombre_dates() == 0){
	  	// TODO: Posar data actual
	}
	inserir_tasca(c.titol(), Instant(c.data(1), c.hora), etiquetes);
	*/
}

void Agenda::modificar_tasca(const Comanda &c){

}

void Agenda::esborrar_tasca(const Comanda &c){

}

void Agenda::esborrar_etiqueta(const Comanda &c){

}

void Agenda::esborrar_etiquetes(const Comanda &c){

}

Instant Agenda::consultar_rellotge(){
	return r;
}

void Agenda::escriure_rellotge(){

}

void Agenda::escriure_tasques_futures(const Comanda &c){
	/*
	string etiquetes;
	if (c.nombre_etiquetes() == 1)
		etiquetes = c.etiqueta(1);
	else if (c.te_expressio())
		etiquetes = c.expressio();
	else
		etiquetes = "";
	*/
}

void Agenda::escriure_tasques_passades(){

}