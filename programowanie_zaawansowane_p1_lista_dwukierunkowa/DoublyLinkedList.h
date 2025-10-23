#pragma once

#include "Node.h"
#include "Iterator.h"
#include <iostream>      // Potrzebne dla metod Display...
#include <stdexcept>     // Opcjonalnie, do obs³ugi b³êdów

/**
 * @brief Klasa implementuj¹ca listê dwukierunkow¹.
 * @tparam T Typ danych przechowywanych w liœcie.
 */
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // --- Konstruktor i Destruktor ---
    DoublyLinkedList();
    ~DoublyLinkedList();

    // --- Metody Funkcjonalne ---
    void AddFront(T data);
    void AddBack(T data);
    void AddAtIndex(T data, int index);
    void RemoveFront();
    void RemoveBack();
    void RemoveAtIndex(int index);
    void Display();
    void DisplayReverse();
    void Clear();

    // --- Metody do Obs³ugi Iteratora ---
    Iterator<T> begin();
    Iterator<T> end();
};

// ===================================================================
// == IMPLEMENTACJA METOD (TO JEST "LOGIKA", KTÓREJ CI BRAKUJE)
// ===================================================================

// --- Konstruktor i Destruktor ---

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Clear();
}

// --- Metody Dodaj¹ce ---

template <typename T>
void DoublyLinkedList<T>::AddFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (size == 0) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::AddBack(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (size == 0) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::AddAtIndex(T data, int index) {
    if (index < 0 || index > size) {
        std::cerr << "Blad: Nieprawidlowy indeks do wstawienia." << std::endl;
        return;
    }
    if (index == 0) {
        AddFront(data);
        return;
    }
    if (index == size) {
        AddBack(data);
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    size++;
}

// --- Metody Usuwaj¹ce ---

template <typename T>
void DoublyLinkedList<T>::RemoveFront() {
    if (size == 0) return;

    Node<T>* temp = head;
    if (size == 1) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::RemoveBack() {
    if (size == 0) return;

    Node<T>* temp = tail;
    if (size == 1) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::RemoveAtIndex(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Blad: Nieprawidlowy indeks do usuniecia." << std::endl;
        return;
    }
    if (index == 0) {
        RemoveFront();
        return;
    }
    if (index == size - 1) {
        RemoveBack();
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    size--;
}

// --- Metody Wyœwietlaj¹ce i Clear ---

template <typename T>
void DoublyLinkedList<T>::Display() {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::DisplayReverse() {
    Node<T>* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::Clear() {
    while (size > 0) {
        RemoveFront();
    }
}

// --- Metody Iteratora ---

template <typename T>
Iterator<T> DoublyLinkedList<T>::begin() {
    return Iterator<T>(head);
}

template <typename T>
Iterator<T> DoublyLinkedList<T>::end() {
    return Iterator<T>(nullptr);
}