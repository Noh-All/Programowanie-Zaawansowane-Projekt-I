#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class DoublyLinkedList;

/**
 * @brief Implementuje wzorzec Iterator dla listy dwukierunkowej.
 * Umo¿liwia przechodzenie w przód i w ty³.
 * @tparam T Typ danych listy.
 */
template <typename T>
class Iterator {
private:
    Node<T>* current;

public:
    /**
     * @brief Konstruktor Iteratora.
     * @param node WskaŸnik na wêze³, od którego rozpoczyna siê iterator.
     */
    Iterator(Node<T>* node) : current(node) {}

    /**
     * @brief Operator dereferencji. Zwraca referencjê do danych w bie¿¹cym wêŸle.
     * @return Referencja do danych.
     */
    T& operator*() {
        return current->data;
    }

    /**
     * @brief Operator inkrementacji pre-fix. Przesuwa na nastêpny element.
     * @return Referencja do bie¿¹cego iteratora.
     */
    Iterator<T>& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    /**
     * @brief Operator dekrementacji pre-fix. Przesuwa na poprzedni element.
     * @return Referencja do bie¿¹cego iteratora.
     */
    Iterator<T>& operator--() {
        if (current) {
            current = current->prev;
        }
        return *this;
    }

    /**
     * @brief Operator porównania (==).
     */
    bool operator==(const Iterator<T>& other) const {
        return current == other.current;
    }

    /**
     * @brief Operator porównania (!=).
     */
    bool operator!=(const Iterator<T>& other) const {
        return current != other.current;
    }

    /**
     * @brief Wyœwietla nastêpny element w stosunku do bie¿¹cego.
     */
    void DisplayNext();

    /**
     * @brief Wyœwietla poprzedni element w stosunku do bie¿¹cego.
     */
    void DisplayPrevious();
};

// Implementacje metod iteratora
template <typename T>
void Iterator<T>::DisplayNext() {
    if (current && current->next) {
        std::cout << current->next->data << std::endl;
    }
    else {
        std::cout << "Brak nastêpnego elementu." << std::endl;
    }
}

template <typename T>
void Iterator<T>::DisplayPrevious() {
    if (current && current->prev) {
        std::cout << current->prev->data << std::endl;
    }
    else {
        std::cout << "Brak poprzedniego elementu." << std::endl;
    }
}