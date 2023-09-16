#include "Lector.h"


Lector::Lector() {
	contadorId = 1;
	indexModelo = -1;
}

vector<Modelo> Lector::leerArchivo(string archivo) {
	vector <string> lineas;
	ifstream file(archivo);
	if (!file.is_open()) {
		cout << "Error al abrir archivo";
	}
	else {
		while (getline(file, linea)) {
			lineas.push_back(linea);
		}
		file.close();
		for (int i = 0; i < lineas.size(); i++) {
			switch (lineas[i].front()) {
			case 'o':
				guardarModelo(lineas[i]);
				break;
			case 'v':
				guardarVertice(lineas[i]);
				break;
			case 'f':
				guardarCara(lineas[i]);
				break;
			}
		}
	}
	return modelos;
}

void Lector::guardarModelo(string linea) {

	linea.erase(0, 2);
	Modelo m(linea);
	modelos.push_back(m);
	indexModelo++;
}

void Lector::guardarVertice(string linea) {

	vector<float> p;
	linea.erase(0, 2);
	stringstream ss(linea);
	string token;
;
	while (getline(ss, token, ' ')) {
		p.push_back(stof(token));
	}
	Vertice v;
	v.serPuntos(p);
	v.setId(contadorId);
	contadorId++;
	modelos[indexModelo].vertices.push_back(v);

}

void Lector::guardarCara(string linea) {
	vector<int> v;
	linea.erase(0, 2);
	stringstream ss(linea);
	string token;

	while (getline(ss, token, ' ')) {
		v.push_back(stoi(token));
	}
	Cara c;
	c.setVertices(v);
	modelos[indexModelo].caras.push_back(c);
}