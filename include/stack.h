#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack {
    private:
        /// @brief Ponteiro para o array que armazena os elementos da pilha
        T* elements;

        /// @brief Tamanho máximo da pilha
        int maxSize;

        /// @brief Índice do topo da pilha
        int top;
    
    public:
        /// @brief Construtor da pilha
        /// @param size 
        Stack(int size);

        /// @brief Detrutor a pilha
        ~Stack();

        /// @brief Adiciona um elemento na pilha
        /// @param element Elemento a ser adicionado
        void push(const T& element);

        /// @brief Pegar o elemento do topo da pilha
        /// @return Elemento do topo da pilha
        T pop();

        /// @brief Pegar o elemento do topo da pilha sem removê-lo
        /// @return Elemento do topo da pilha
        T peek();

        /// @brief Verificar se a pilha está vazia
        /// @return true se a pilha estiver vazia, false caso contrário
        bool isEmpty();

        /// @brief Verificar se a pilha está cheia
        /// @return true se a pilha estiver cheia, false caso contrário
        bool isFull();
};

#endif