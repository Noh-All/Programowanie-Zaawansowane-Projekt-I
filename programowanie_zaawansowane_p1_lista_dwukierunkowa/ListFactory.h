#pragma once

// Do��cz plik nag��wkowy listy, poniewa� Fabryka musi wiedzie�,
// jaki typ obiektu ma tworzy�.
#include "DoublyLinkedList.h" 

/**
 * @brief Wzorzec projektowy Fabryki do tworzenia instancji listy.
 * @tparam T Typ danych przechowywanych w li�cie.
 */
template<typename T>
class ListFactory {
public:
    /**
     * @brief Statyczna metoda tworz�ca now� list� dwukierunkow� na stercie.
     * @return Wska�nik (DoublyLinkedList<T>*) do nowo utworzonego obiektu.
     */
    static DoublyLinkedList<T>* CreateNewList() {
        // U�ywa 'new' do alokacji pami�ci i zwraca wska�nik
        return new DoublyLinkedList<T>();
    }
};