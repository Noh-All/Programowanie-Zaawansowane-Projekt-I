#include "DoublyLinkedList.h"
#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Clear();
}

// ------------------------------------------------------------------
// METODY FUNKCJONALNE - DODANO PUSTE CIA£A {}
// ------------------------------------------------------------------

template <typename T>
void DoublyLinkedList<T>::AddFront(T data) {
    // LOGIKA
}

template <typename T>
void DoublyLinkedList<T>::AddBack(T data) {
    // LOGIKA
}

template <typename T>
void DoublyLinkedList<T>::AddAtIndex(T data, int index) {
    // LOGIKA
}

template <typename T>
void DoublyLinkedList<T>::RemoveFront() {
    // LOGIKA
}

template <typename T>
void DoublyLinkedList<T>::RemoveBack() {
    // LOGIKA
}

template <typename T>
void DoublyLinkedList<T>::RemoveAtIndex(int index) {
    // LOGIKA
}

template <typename T>
void DoublyLinkedList<T>::Display() {
    // LOGIKA (Tymczasowa informacja, ¿eby by³o widaæ, ¿e dzia³a)
    std::cout << "Lista (implementacja Display wymagana)." << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::DisplayReverse() {
    // LOGIKA (Tymczasowa informacja)
    std::cout << "Lista w odwrotnej kolejnosci (implementacja DisplayReverse wymagana)." << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::Clear() {
    // LOGIKA (Tymczasowa informacja)
    std::cout << "Czyszczenie listy (implementacja Clear wymagana)." << std::endl;
}

// ------------------------------------------------------------------
// METODY ITERATORA - DODANO RETURN
// ------------------------------------------------------------------

template <typename T>
Iterator<T> DoublyLinkedList<T>::begin() {
    return Iterator<T>(head); // Musi zwracaæ wartoœæ
}

template <typename T>
Iterator<T> DoublyLinkedList<T>::end() {
    return Iterator<T>(nullptr); // Musi zwracaæ wartoœæ
}

// ------------------------------------------------------------------
// JAWNE INSTANCJACJE
// ------------------------------------------------------------------

// JAWNA INSTANCJACJA dla typu int (wymagane, poniewa¿ definicje s¹ w .cpp)
template class DoublyLinkedList<int>;