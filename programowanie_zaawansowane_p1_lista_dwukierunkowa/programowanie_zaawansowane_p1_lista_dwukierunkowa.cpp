#include <iostream>
#include "ListFactory.h"         // Do tworzenia listy
#include "DoublyLinkedList.h"    // Do definicji listy
#include "Iterator.h"            // Do testów iteratora

int main() {
    std::cout << "--- Testy Listy Dwukierunkowej (typ int) ---" << std::endl;

    // Tworzenie Listy na stercie przy użyciu Fabryki
    DoublyLinkedList<int>* myList = ListFactory<int>::CreateNewList();

    // 1. Testowanie dodawania (AddFront, AddBack, AddAtIndex)
    std::cout << "\n[1. DODAWANIE]" << std::endl;

    myList->AddBack(5);                   // Lista: [5]
    myList->AddFront(1);                  // Lista: [1, 5]
    myList->AddAtIndex(3, 1);             // Lista: [1, 3, 5]
    myList->AddBack(7);                   // Lista: [1, 3, 5, 7]

    std::cout << "Lista po operacjach Add (oczekiwane: 1 3 5 7): ";
    myList->Display(); // <-- FAKTYCZNE WYWOŁANIE

    // 2. Testowanie wyświetlania w odwrotnej kolejności
    std::cout << "\n[2. WYŚWIETLANIE ODWROTNE]" << std::endl;
    std::cout << "Lista w odwrotnej kolejności (oczekiwane: 7 5 3 1): ";
    myList->DisplayReverse(); // <-- FAKTYCZNE WYWOŁANIE

    // 3. Testowanie Iteratora
    std::cout << "\n[3. TEST ITERATORA]" << std::endl;

    Iterator<int> it = myList->begin(); // Pobieramy iterator na początek (na '1')

    std::cout << "Iterator wskazuje na (oczekiwane: 1): " << *it << std::endl;

    std::cout << "Test DisplayNext (oczekiwane: 3): ";
    it.DisplayNext(); // <-- FAKTYCZNE WYWOŁANIE

    ++it; // Przesuwamy iterator na element '3'
    std::cout << "Iterator przesuniety na (oczekiwane: 3): " << *it << std::endl;

    std::cout << "Test DisplayPrevious (oczekiwane: 1): ";
    it.DisplayPrevious(); // <-- FAKTYCZNE WYWOŁANIE

    // 4. Testowanie usuwania (RemoveFront, RemoveBack, RemoveAtIndex)
    std::cout << "\n[4. USUWANIE]" << std::endl;
    // Lista to [1, 3, 5, 7]
    myList->RemoveFront();      // Usuwa '1'. Lista: [3, 5, 7]
    myList->RemoveBack();       // Usuwa '7'. Lista: [3, 5]
    myList->RemoveAtIndex(1); // Usuwa '5'. Lista: [3]

    std::cout << "Lista po usunieciu (oczekiwane: 3): ";
    myList->Display();

    myList->RemoveFront(); // Usuwa '3'. Lista: [] (pusta)
    std::cout << "Lista po usunieciu wszystkich (powinna byc pusta): ";
    myList->Display();

    // 5. Testowanie Clear()
    std::cout << "\n[5. CZYSZCZENIE]" << std::endl;
    // Dodajmy coś, żeby było co czyścić
    myList->AddBack(200);
    myList->AddBack(100);
    std::cout << "Lista przed Clear (oczekiwane: 200 100): ";
    myList->Display();

    myList->Clear(); // <-- FAKTYCZNE WYWOŁANIE

    std::cout << "Lista po Clear (powinna byc pusta): ";
    myList->Display();

    // Zwalnianie pamięci listy (ponieważ została utworzona na stercie przez Factory)
    delete myList;

    std::cout << "\n--- Testy zakonczone pomyslnie ---" << std::endl;

    return 0;
}