#pragma once

/**
 * @brief Reprezentuje pojedynczy wêze³ w liœcie dwukierunkowej.
 * @tparam T Typ danych przechowywanych w wêŸle.
 */
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    /**
     * @brief Konstruktor wêz³a.
     * @param value Dane, które maj¹ byæ przechowywane w wêŸle.
     */
    Node(T value);

    /**
     * @brief Destruktor wêz³a.
     */
    ~Node();
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::~Node() {}