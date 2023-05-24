/*
** file: main-minh.cpp
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
// em main-minh.cpp
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais

// Bibliotecas
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "minh.h"


int main() {
    // Criar um objeto MINH com capacidade máxima 15
    MINH heap(15);

   // Ler comandos do arquivo de entrada
    std::string line;
    // Ler linhas do arquivo de entrada
    while (std::getline(std::cin, line)) {
    // Ignorar linhas em branco e linhas de comentário
    if (line.empty() || line[0] == '#') {
        continue;
    }
        // Criar um fluxo de entrada para a linha
        std::istringstream iss(line);
        // Ler o comando
        std::string command;
        iss >> command;
        // Executar o comando INSERT
        if (command == "insert") {
            int value;
            while (iss >> value) {
                heap.insert(value);
            }
        }
        // Executar o comando PRINT_MIN
        else if (command == "print_min") {
            if (heap.size() == 0) {
                std::cout << "Comando print_min: Heap vazio!\n";
            } else {
                std::cout << "Min= " << heap.getMin() << "\n";
            }
        }
        // Executar o comando PRINT
        else if (command == "print") {
            heap.print();
        }
        // Executar o comando DIM
        else if (command == "dim") {
            std::cout << "Heap tem " << heap.size() << " itens\n";
        }
        // Executar o comando DIM_MAX
        else if (command == "dim_max") {
            std::cout << "Heap tem capacidade " << heap.capacity() << " itens\n";
        }
        // Executar o comando CLEAR
        else if (command == "clear") {
            heap.clear();
        }
        // Executar o comando DELETE
        else if (command == "delete") {
            heap.deleteMin();
        }
        // Executa HEAPYFY_DOWN
        else if (command == "heapify_up") {
            std::vector<int> items;
            int value;
            while (iss >> value) {
                items.push_back(value);
            }
            heap.heapifyUp(items);
        }
        // Executa Redimensionar
        else if (command == "redim_max") {
            int newCapacity;
            iss >> newCapacity;
            heap.resize(newCapacity);
        }
        else {
            std::cerr << "Comando desconhecido: " << command << "\n";
        }
    }

    return 0;// Termina normalmente
}

// EOF

