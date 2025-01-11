#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
#include "utils.h"

class Stack {
    private:
        /// @brief Ponteiro para o array que armazena os elementos da pilha
        Position* elements;

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
        void push(const Position& element);

        /// @brief Pegar o elemento do topo da pilha
        /// @return Elemento do topo da pilha
        Position pop();

        /// @brief Pegar o elemento do topo da pilha sem removê-lo
        /// @return Elemento do topo da pilha
        Position peek();

        /// @brief Verificar se a pilha está vazia
        /// @return true se a pilha estiver vazia, false caso contrário
        bool isEmpty();

        /// @brief Verificar se a pilha está cheia
        /// @return true se a pilha estiver cheia, false caso contrário
        bool isFull();

        /// @brief Verificar se a pilha contém um elemento
        /// @param element Elemento a ser verificado
        /// @return true se a pilha contém o elemento, false caso contrário
        bool contains(const Position& element);

        /// @brief Sobrecarga do operador de inserção para imprimir a pilha
        /// @param os Stream de saída
        /// @param stack Pilha a ser impressa
        /// @return Stream de saída
        friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
};

#endif