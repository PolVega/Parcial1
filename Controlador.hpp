#pragma once
#include "User.hpp"
#include "ListaSimple.hpp"
using namespace System;
using namespace std;

class Controlador {
private:

	ListaSimple<User*> usuarios;
	string ubicacionActual;
	string user, pass;
	int size;
public:
	Controlador() {

		ubicacionActual = _getcwd(0, NULL);
		chdir(ubicacionActual.c_str());
		ifstream entrada("size.txt");
		entrada >> size;
		entrada.close();
		for (int i = 0; i < size; i++) {
			usuarios.insertar(new User);
			ifstream salida("data.txt");
			salida >> user >> pass;
			salida.close();
			usuarios.At(i)->setpass(pass);
			usuarios.At(i)->setuser(user);

		}
		mkdir("Lista Usuarios");
		setlocale(LC_ALL, "spanish");
	};
	void exe() {
		int op;
		bool iti = true;
		cout << "\t\tLOGIN\t\t\n";
		cout << "\t\tREGISTER\t\t\n";
		cin >> op;
		switch (op) {
		case 1:
			system("cls");
			cout << "\tUSUARIO: ";
			cin >> user;
			cout << "\tCONTRASEÑA: ";
			cin >> pass;
			iti = login();
			if (iti == true) {
				menu();
			}
			else {
				if (iti == false) {
					registe();
					menu();
				}
			}
			break;
		case 2:
				cout << "Registre Usuario: ";
				cin >> user;
				cout << "Registre Contraseña: ";
				cin >> pass;
				registe();
			exe();
			break;
		}
	}
	bool login() {
		string r;
		string auxus, auxpass;
		int cont = 0;
		ifstream entrada("data.txt");
		if (entrada.fail()) {
			cout << "NO HAY USUARIOS REGISTRADOS, USTED ES EL PRIMERO\n";
			_sleep(1000);
			return false;
		}
		else {
			while (!entrada.eof()) {
				entrada >> auxus >> auxpass;

				if (user == auxus && pass == auxpass)cont++;
			}
			if (cont > 0) {
				cout << "USUARIO LOGUEADO CON EXITO" << endl;
				_sleep(1000);
				return true;
			}
			else {
				cout << "USUARIO REGISTRADO AUTOMATICAMENTE";
				_sleep(1000);
				return false;
			}
		}
		entrada.close();
	}
	bool registe() {
		size++;
		ofstream salida("data.txt", ios::app);
		salida << user << " " << pass << "\n";
		usuarios.insertar(new User(user,pass, ubicacionActual + "\\" + "Lista Usuarios"));
		salida.close();
		chdir(ubicacionActual.c_str());
		ofstream size("size.txt");
		size << usuarios.cantidad();
		salida.close();
		return false;
	}
	void save() {
		size = usuarios.cantidad();
		chdir(ubicacionActual.c_str());
		ofstream salida("size.txt");
		salida << usuarios.cantidad();
		salida.close();
		for (int i = 0; i < usuarios.cantidad(); i++) {
			ofstream salida("data.txt");
			salida << usuarios.At(i)->getNombre() << " " << usuarios.At(i)->getpass();
			salida.close();
		}
	}
	void menu() {
		int op;
		system("cls");
		cout << "\t\t\tBIENVENIDO " << user << "\t\t\n" << endl;
		cout << "\t\t\t1.CREAR REPOSITORIO" << endl;
		cout << "\t\t\t2.MOSTRAR REPOSITORIO" << endl;
		cout << "\t\t\t3.AÑADIR COMENTARIOS" << endl;
		cout << "\t\t\t4.BUSCAR REPOSITORIO" << endl;
		cout << "\t\t\t5.CERRAR SESIÓN" << endl;
		cin >> op;
		switch (op) {
		case 1:usuarios.At(usuarios.pos(user, [](User* t, string user) {return t->getNombre() == user; })-1)->insertar(); break;
		case 2:break;
		case 3:break;
		case 4:break;
		case 5:exe(); break;
		}


		save();
	};
	~Controlador() {};
};