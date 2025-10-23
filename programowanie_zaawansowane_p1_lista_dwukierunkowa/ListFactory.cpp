#pragma once
#include "DoublyLinkedList.h"

/**
 * @brief Implementuje wzorzec Factory. Odpowiada za tworzenie instancji listy.
 * @tparam T Typ danych listy.
 */
template <typename T>
class ListFactory {
public:
    /**
     * @brief Tworzy nowy obiekt DoublyLinkedList na stercie (heap).
     * @return WskaŸnik na now¹ instancjê DoublyLinkedList.
     */
    static DoublyLinkedList<T>* CreateNewList();
};

template <typename T>
DoublyLinkedList<T>* ListFactory<T>::CreateNewList() {
    return new DoublyLinkedList<T>();
}