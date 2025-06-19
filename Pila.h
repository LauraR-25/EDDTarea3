#ifndef PILA_H
#define PILA_H

struct Nodo{
    int dato;
    Nodo* siguiente;
};

class Pila{
    private:
        Nodo* cima;

    public:
        Pila();
        ~Pila();
        void push(int valor);
        int pop();
        bool estaVacia() const;
        int cimaValor() const;
        void mostrar() const;
    };

#endif