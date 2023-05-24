/*
** file: minh.cpp
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

// minh.cpp
#include "minh.h"

// Métodos privados

//Construtor
MINH::MINH(int nmax) {
   v = new int[nmax];
   nv = nmax;
   n = 0;
}

//Destrutor
MINH::~MINH() {
   delete[] v;
}

//Comando insert
void MINH::insert(int item) {
   // Verifica se o heap está cheio
   static bool heapCheioMessagePrinted = false;  // adiciona a variável booleana 
    // static para que a mensagem de heap cheio seja impressa apenas uma vez
   if (n >= nv) {
       if (!heapCheioMessagePrinted) {  // verifica se a mensagem já foi impressa
           std::cout << "Comando insert: Heap cheio!\n";
           heapCheioMessagePrinted = true;  // marca que a mensagem já foi impressa
       }
       return; // não insere o item
   }
   // Se o heap não estiver cheio, redefine a variável para false
   heapCheioMessagePrinted = false;  
   // para que a mensagem seja impressa novamente se o heap estiver cheio novamente
   v[n] = item;
    // Encontre a posição correta para o novo item
   int i = n;
   // Enquanto o item for menor que o pai, troque-o com o pai
   while (i != 0 && v[i] < v[parent(i)]) {
       swap(v[i], v[parent(i)]);
       i = parent(i);
   }
    // Incrementa o tamanho do heap
   n++;
}

//Comando getMin
int MINH::getMin() {
    // Verifica se o heap está vazio
   if (n == 0) {
    // Imprime uma mensagem de erro e retorna um valor inválido para indicar erro
       std::cerr << "Comando getMin: Heap vazio!\n";
       return -1; // Valor inválido para indicar erro
   }
    // Retorna o primeiro elemento do heap
   return v[0];
}

//Comando print
void MINH::print() {
    // Verifica se o heap está vazio
    if (n == 0) {
        // Imprime uma mensagem de erro e retorna
        std::cerr << "Comando print: Heap vazio!\n";
        return;
    }
    // Imprime o heap
    std::cout << "Heap=\n";
    int levelSize = 1;
    int levelCount = 0;
    // Imprime cada elemento do heap
    for (int i = 0; i < n; i++) {
        // Verifique se não é o primeiro elemento do nível antes de adicionar o espaço
        if (levelCount != 0) {
            std::cout << " ";
        }
        // Imprime o elemento
        std::cout << v[i];
        // Incrementa o contador de elementos do nível
        levelCount++;
        // Verifica se é o último elemento do nível
        if (levelCount == levelSize) {
            std::cout << std::endl;
            levelSize *= 2;
            levelCount = 0;
        }
    }
    // se não imprimiu uma nova linha no final da última linha, imprima agora
    if (levelCount != 0) {
        std::cout << std::endl;
    }
}

//Comando size
int MINH::size() {
   // Retorna o tamanho do heap
   return n;
}

//Comando capacity
int MINH::capacity() {
    // Retorna a capacidade do heap
   return nv;
}

//Comando clear
void MINH::clear(bool printMessage) {
    // Verifica se o heap está vazio
    if (printMessage && n == 0) {
        // Imprime uma mensagem de erro e retorna
        std::cout << "Comando clear: Heap vazio!\n";
    }
    // Redefine o tamanho do heap para zero
    n = 0;
}

//Comando deleteMin
void MINH::deleteMin() {
    // Verifica se o heap está vazio
   if (n == 0) {
        //Imprime uma mensagem de erro e retorna
       std::cerr << "Comando delete: Heap vazio!\n";
       return;
   }
    // Substitua o primeiro elemento pelo último
   v[0] = v[n - 1];
   // Decrementa o tamanho do heap
   n--;
    // Reordene o heap
   heapifyDown(0);
}

// Função auxiliar para reordenar o heap para cima  
void MINH::heapifyUp(const std::vector<int>& items) {
    // Envia false para não imprimir uma mensagem de erro se o heap estiver cheio
   clear(false); 
   // Verifique se o heap está cheio
   if (items.size() > nv) {
        // Imprime uma mensagem de erro e retorna
       std::cerr << "Comando heapify_up: Heap excede capacidade máxima!\n";
       return;
   }
   // Copia diretamente os itens para o heap
   for (int i = 0; i < items.size(); i++) {
        // Verifica se o heap está cheio
       v[i] = items[i];
   }
   // Atualize o tamanho do heap
   n = items.size();
   // Reordenar o heap
   for (int i = n / 2 - 1; i >= 0; i--) {
        // Reordene o heap para baixo
       heapifyDown(i);
   }
}

// Função auxiliar para verificar a capacidade do heap e redimensioná-lo se necessário
void MINH::resize(int newCapacity) {
    // Verifica se a nova capacidade é menor que o número de itens atual
   if (newCapacity < n) {
       std::cerr << "Comando redim_max: Nova capacidade menor que o número de itens atual!\n";
       return;// Não redimensiona o heap    
   }
    // Aloca um novo vetor com a nova capacidade
   int* newV = new int[newCapacity];
    // Copia os itens do heap para o novo vetor
   for (int i = 0; i < n; i++) {
        // Copia o item
       newV[i] = v[i];
   }
    // Libera a memória do vetor antigo
   delete[] v;
   // Atualiza o vetor e a capacidade
   v = newV;
   // Atualiza a capacidade
   nv = newCapacity;
}

//Função parent 
int MINH::parent(int i) {
    // Retorna o índice do pai
   return (i - 1) / 2;
}
 //Função leftChild
int MINH::leftChild(int i) {
    // Retorna o índice do filho esquerdo
   return 2 * i + 1;
}

//Função rightChild
int MINH::rightChild(int i) {
    // Retorna o índice do filho direito
   return 2 * i + 2;
}

//Função swap
void MINH::swap(int& a, int& b) {
    // Troca os valores de a e b
   int temp = a;
   a = b;
   b = temp;
}

//Função auxiliar para reordenar o heap para baixo
void MINH::heapifyDown(int i) {
    // Encontra o menor elemento entre o pai e os filhos
   int smallest = i;
   int left = leftChild(i);
   int right = rightChild(i);
    // Verifica se o filho esquerdo é menor que o pai
   if (left < n && v[left] < v[smallest]) {
       smallest = left;
   }
    // Verifica se o filho direito é menor que o pai
   if (right < n && v[right] < v[smallest]) {
       smallest = right;
   }
    // Verifica se o pai não é o menor elemento
   if (smallest != i) {
       swap(v[i], v[smallest]);
       heapifyDown(smallest);
   }
}

// EOF
