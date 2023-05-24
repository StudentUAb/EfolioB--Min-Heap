/*
** file: minh.h
**
** min Heap por comandos
** (binary tree on array)
** UC: 21046 - EDAF @ UAb
** e-fólio B 2022-23
**
** Aluno: 2100927 - Ivo Baptista
*/

// Defina:
// em minh.h as classes da estrutura de dados
// em minh.cpp a implementação dos métodos das classes da estrutura de dados

// minh.h
#ifndef _MINH_H
#define _MINH_H

//Bibliotecas
#include <iostream>

//Classe MINH
class MINH {
    //Membros privados
private:
    int* v;
    int n;
    int nv;
    //Funções privadas
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void swap(int& a, int& b);
    void heapifyDown(int i);
    //Membros públicos
public:
    //Construtor
    MINH(int nmax = 15);
    //Destrutor
    ~MINH();
    //Funções
    void insert(int item);
    int getMin();
    void print();
    int size();
    int capacity();
    void clear(bool printMessage = true);
    void deleteMin();
    void heapifyUp(int* items, int items_size);
    void resize(int newCapacity);
};

#endif

// EOF


