#include "Lector.h"


Lector::Lector() {
	vector<Vertice> vertices;
}

void Lector::leerArchivo(string archivo) {

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
				lineas[i].erase(0, 1);
				//obj.objeto = lineas[i][2];
				cout<< "o:" + lineas[i]<<endl;
				break;
			case 'v':
				lineas[i].erase(0, 1);
				/*stringstream ss(lineas[i]);
				while()
				Vertice v = { str[], 0.1, 0.1};
				vertices.push_back(v);*/
				cout << "v:" + lineas[i]<<endl;
				break;
			case 'f':
				lineas[i].erase(0, 1);
				cout << "f:" + lineas[i]<<endl;
				break;
			}
		}
	}
}

void Lector::imprimirObjeto() {

}