#pragma once
#include <iostream>
#include <string>
#include <functional>
using namespace System;
using namespace std;

template <typename T>
struct Nodo{
    T elemento;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
    Nodo(T e) { elemento = e; siguiente = anterior = nullptr; }

};
template <typename T>
class Lista {
    Nodo<T>* inicio;
    Nodo<T>* fin;
    long long elements;
public:
    Lista() { inicio = fin = nullptr; elements = 0; }

    void Insertar_Principio(T e) {
        Nodo<T>* aux = new Nodo<T>(e);
        if (inicio == nullptr)inicio = fin = aux;
        else {
            inicio->anterior = aux;
            aux->siguiente = inicio;
        }
        inicio = aux;
        inicio->anterior = nullptr;
        elements++;
    }
    void eliminarInicio() {
        if (elements > 0) {
            Nodo<T>* aux = inicio;
            inicio = inicio->siguiente;
            inicio->anterior = nullptr;

            delete aux;
            elements--;
        }
    }

    void eliminarPosicion(int pos) {
        if (pos > elements)
            return;

        if (pos == 0)
            eliminarInicio();
        else {
            Nodo<T>* aux = inicio;
            for (int i = 1; i < pos; i++)
                aux = aux->siguiente;
            aux->siguiente->siguiente->anterior = aux;
            aux->siguiente = aux->siguiente->siguiente;
            delete aux;
            elements--;


        }
    }




    T At() {
            Nodo<T>* aux = inicio;
            for (int i = 0; i < elements; i++)
                aux = aux->siguiente;
            if (aux != nullptr)return aux->elemento;//HERE

    }


    void insertarFinal(T e) {//O(1)
        Nodo<T>* nuevo = new Nodo<T>(e);
        if (inicio == nullptr) {
            insertarInicio(e);
        }
        else {
            fin->siguiente = nuevo;
            nuevo->anterior = fin;
            fin = nuevo;
        }
        ++elements;
    }




    void mostrar(function<void(T)>funMostrar) {
        Nodo<T>* aux = inicio;
        while (aux->siguiente != nullptr)
        {
            //cout<<aux->elemento<<" ";
            funMostrar(aux->elemento);
            aux = aux->siguiente;
        }
        funMostrar(aux->elemento);
    }

    int size() {
        short c = 0;
        Nodo<T>* aux = inicio;
        while (aux != nullptr) {
            c++;
            aux = aux->siguiente;
        }

        return c;
    }

};