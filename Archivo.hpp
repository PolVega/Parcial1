#pragma once
#include <fstream>
using namespace std;
class Archivo {
	string nombre;
	string contenido;
	string comentario;
	ifstream entrada;
	ofstream salida;
public:
	Archivo(string nombre, string contenido = " ") :nombre(nombre), contenido(contenido) {
		salida.open(nombre);
		salida << nombre;
		comentario = "-";
	}
	void set(string contenido) {
		this->contenido = contenido;
	}
	string getcontenido() {
		return contenido;
	}
	string getnombre() {
		return nombre;
	}
	string getcomentario() {
		return comentario;
	}
	void setcomentario(string comentario) {
		this->comentario = comentario;
	}
	void setcontenido(string contenido) {
		this->contenido = contenido;
	}
};