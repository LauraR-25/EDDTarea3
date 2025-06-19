#include <iostream>
#include "Pila.h"
using namespace std;

Pila::Pila(){
    cima = nullptr;
}

Pila::~Pila(){
    while (!estaVacia()){
        pop();
    }
}

void Pila::push(int valor){
    Nodo* nuevo= new Nodo{valor, cima};
    cima = nuevo;
}

int Pila::pop(){
    if (estaVacia()) {
        cerr<< "Error: pila vacía\n";
        return -1;
    }
    Nodo* temp= cima;
    int valor= temp->  dato;
    cima= cima->siguiente;
    delete temp;
    return valor;
}
bool Pila::estaVacia() const {
    return cima== nullptr;
}
int Pila::cimaValor() const{
    if(estaVacia()){
        cerr<< "Error: pila vacía\n";
        return -1;
    }
    return cima->dato;
}

void Pila::mostrar() const{
    Nodo* actual= cima;
    while (actual) {
        cout<< actual-> dato<< " ";
        actual= actual-> siguiente;
    }
    cout<< endl;
}

int main(){
    Pila original;
    Pila ordenada;
    Pila auxiliar;
    int n, valor;

    cout<< "Ingrese la cantidad de elementos de la pila: ";
    cin>> n;
    cout<< "Ingrese los valores de la pila:\n";
    int* temp = new int[n];
        for (int i=0; i < n; i++){
            cin >> temp[i];
        }
            for (int i=n - 1; i >= 0; i--){
            original.push(temp[i]);
        }
    delete[] temp;




    cout<< "Pila original: ";
    original.mostrar();

    while(!original.estaVacia()){
        int temp= original.pop();
        while (!ordenada.estaVacia() && ordenada.cimaValor()> temp){
            auxiliar.push(ordenada.pop());
        }
        ordenada.push(temp);

        while (!auxiliar.estaVacia()) {
            ordenada.push(auxiliar.pop());
        }
    }

    cout<< "Pila ordenada: ";
    ordenada.mostrar();

    return 0;
}
