#pragma once
#include "Carpeta.hpp"
using namespace std;
class User {
public:
	string user;
	string contrase�a;
	string ubicacion;
	Carpeta* Mydir;
public:
	User() {
	}
	User(string user, string contrase�a, string ubicacion) :user(user), contrase�a(contrase�a), ubicacion(ubicacion) {
		Mydir = new Carpeta(user, ubicacion);
		this->ubicacion = ubicacion+"\\"+user;
	}
	void setuser(string user) {
		this->user = user;
	}
	void insertar() {
		chdir(ubicacion.c_str());
		string r;
		cout << "Ingrese el nombre del directorio\n";
		cin >> r;
		Mydir->insertar(r);
	}
	void setpass(string contrase�a) {
		this->contrase�a = contrase�a;
	}
	string getpass() {
		return contrase�a;
	}
	void setubicacion(string ubicacion) {
		this->ubicacion = ubicacion;
		Mydir = new Carpeta(user, ubicacion);
		this->ubicacion = ubicacion + "\\" + user;
	}

	string getNombre() {
		return user;
	}


};