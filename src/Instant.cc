#include "Instant.hh"

/** @brief
\pre Cert.
\post Es crea un instant buit.
*/
Instant::Instant () {

}

/** @brief
\pre d i h tenen format de data i hora.
\post Es crea la data amb els valors dels parametres.
*/
Instant::Instant (const string &d, const string &h) {

}

/** @brief Compara si un element es estrictament mes petit que un altre.
\pre Cert.
\post Retorna true si el parametre implicit es estrictament mes petit que i. Si no retorna false.
**/
bool Instant::operator<(const Instant &i) const {

}

/** @brief Modifica l'hora del rellotge.
\pre h te format d'hora.
\post La nova hora del parametre implicit es h.
*/
void Instant::modificar_hora(const string &h) {

}

/** @brief Modifica la data del rellotge.
\pre d te format de data.
\post La nova data del parametre implicit es d.
*/
void Instant::modificar_data(const string &d) {

}

/** @brief Escriu la data i l'hora del p.i.
\pre Cert.
\post Ha escrit la data i hora al canal de sortida.
*/
void Instant::escriure() const {

}