#pragma once
#include "Carpeta.hpp"
using namespace std;
class User {
public:
	string user;
	string contraseņa;
	string ubicacion;
	Carpeta* Mydir;
public:
	User() {
	}
	User(string user, string contraseņa, string ubicacion) :user(user), contraseņa(contraseņa), ubicacion(ubicacion) {
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
	void setpass(string contraseņa) {
		this->contraseņa = contraseņa;
	}
	string getpass() {
		return contraseņa;
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