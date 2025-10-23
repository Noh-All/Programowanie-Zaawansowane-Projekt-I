#pragma once

// Do³¹cz plik nag³ówkowy listy, poniewa¿ Fabryka musi wiedzieæ,
// jaki typ obiektu ma tworzyæ.
#include "DoublyLinkedList.h" 

/**
 * @brief Wzorzec projektowy Fabryki do tworzenia instancji listy.
 * @tparam T Typ danych przechowywanych w liœcie.
 */
template<typename T>
class ListFactory {
public:
    /**
     * @brief Statyczna metoda tworz¹ca now¹ listê dwukierunkow¹ na stercie.
     * @return WskaŸnik (DoublyLinkedList<T>*) do nowo utworzonego obiektu.
     */
    static DoublyLinkedList<T>* CreateNewList() {
        // U¿ywa 'new' do alokacji pamiêci i zwraca wskaŸnik
        return new DoublyLinkedList<T>();
    }
};