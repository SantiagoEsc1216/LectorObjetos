#include "Lector.h"


Lector::Lector() {
	contadorId = 1;
}

Modelo Lector::leerArchivo(string archivo) {
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
	return modelo;
}

void Lector::imprimirObjeto() {
	cout << "o: " << modelo.getModelo() << endl;


	for(Vertice v : modelo.vertices)
	{
		cout <<fixed <<"v: " << v.getX() <<" " << v.getY() << " " << v.getZ() << endl;
	}
	
	for (Cara c : modelo.caras) {
		cout << "f: ";
		for (int v : c.getVertices()) {
			cout << v << " ";
		}
		cout << endl;
	}
}

void Lector::guardarModelo(string linea) {

	linea.erase(0, 2);
	modelo.setModelo(linea);

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
	modelo.vertices.push_back(v);

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
	modelo.caras.push_back(c);
}