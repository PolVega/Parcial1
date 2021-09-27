#pragma once
#include "ListaDoble.hpp"
#include "Archivo.hpp"
#include <direct.h>
using namespace std;
class Carpeta {
	Lista<Archivo*> archivos;
	int sizeuser;
	string nombre;
	string ubicacion;
public:
	Carpeta(string nombre, string ubicacion) :nombre(nombre){
		chdir(ubicacion.c_str());
		mkdir(nombre.c_str());
		this->ubicacion = ubicacion + "\\" + nombre;
		chdir(this->ubicacion.c_str());
	}

	void insertar(string nom) {
		char c;
		chdir(this->ubicacion.c_str());
		archivos.Insertar_Principio(new Archivo(nom));
		cout << "Desea agregar contenido\n";
		cout << "SI(S), NO(N)\n";
		cin >> c;
		if (c == 'S') {
			string r;
			getline(cin, r);
			archivos.At()->setcontenido(r);
			cout << "Desea agregar comentario\n";
			cout << "Si(S),N0(N)\n";
			cin >> c;
			if (c == 'S') { getline(cin, r); archivos.At()->setcomentario(r); }
		}
		cout << "\nDocumento creado\n";
		_sleep(1000);
	}
};