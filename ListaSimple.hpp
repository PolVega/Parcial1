#pragma once
#include "ListaDoble.hpp"
using namespace std;
template <typename T>
class ListaSimple {
    Nodo<T>* inicio;
    Nodo<T>* fin;
    int elements;
public:
    ListaSimple() {
        fin = inicio = nullptr;
        elements = 0;
        ifstream entrada("size.txt");
        entrada >> elements;
        entrada.close();
    }

    void insertar(T e) {    //O(1)   
        Nodo<T>* n = new Nodo<T>(e);
        if (inicio == nullptr)
            inicio = fin = n;
        else {
            fin->siguiente = n;
            fin = n;
        }
        elements++;
    }
    T At(int pos) {
        if (pos >= 0 && pos < elements) {
            Nodo<T>* aux = inicio;
            for (int i = 0; i < pos; i++)
                aux = aux->siguiente;
            if (aux != nullptr)return aux->elemento;//HERE
        }
        else
            return nullptr;
    }
 
    void eliminarPosicion(int pos) {
        if (pos > elements)
            return;

        if (pos == 0)
            eliminarInicio();
        else {
            Nodo<T>* aux = inicio;
            for (int i = 0; i < pos; i++)
                aux = aux->siguiente;
            aux->siguiente->siguiente->anterior = aux;
            aux->siguiente = aux->siguiente->siguiente;
            delete aux;
            elements--;


        }
    }
 
    int pos(string r,function<bool(T,string x)>com) {
        int p=0, pos=0;
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            p++;
            aux = aux->siguiente;
        }
        aux = inicio;
        cout << "ELEMENTOS " << p<<endl;
        for (int i= 0; i < p; i++) {
            if (com(aux->elemento, r))  cout << "retorno " << i << endl; return pos ;
            aux = aux->siguiente;
        }
        return -1;
    }

    int cantidad() {
        short c = 0;
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            c++;
            aux = aux->siguiente;
        }
        return c;
    }
};