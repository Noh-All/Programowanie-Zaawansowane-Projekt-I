#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class DoublyLinkedList;

/**
 * @brief Implementuje wzorzec Iterator dla listy dwukierunkowej.
 * Umo�liwia przechodzenie w prz�d i w ty�.
 * @tparam T Typ danych listy.
 */
template <typename T>
class Iterator {
private:
    Node<T>* current;

public:
    /**
     * @brief Konstruktor Iteratora.
     * @param node Wska�nik na w�ze�, od kt�rego rozpoczyna si� iterator.
     */
    Iterator(Node<T>* node) : current(node) {}

    /**
     * @brief Operator dereferencji. Zwraca referencj� do danych w bie��cym w�le.
     * @return Referencja do danych.
     */
    T& operator*() {
        return current->data;
    }

    /**
     * @brief Operator inkrementacji pre-fix. Przesuwa na nast�pny element.
     * @return Referencja do bie��cego iteratora.
     */
    Iterator<T>& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    /**
     * @brief Operator dekrementacji pre-fix. Przesuwa na poprzedni element.
     * @return Referencja do bie��cego iteratora.
     */
    Iterator<T>& operator--() {
        if (current) {
            current = current->prev;
        }
        return *this;
    }

    /**
     * @brief Operator por�wnania (==).
     */
    bool operator==(const Iterator<T>& other) const {
        return current == other.current;
    }

    /**
     * @brief Operator por�wnania (!=).
     */
    bool operator!=(const Iterator<T>& other) const {
        return current != other.current;
    }

    /**
     * @brief Wy�wietla nast�pny element w stosunku do bie��cego.
     */
    void DisplayNext();

    /**
     * @brief Wy�wietla poprzedni element w stosunku do bie��cego.
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
        std::cout << "Brak nast�pnego elementu." << std::endl;
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