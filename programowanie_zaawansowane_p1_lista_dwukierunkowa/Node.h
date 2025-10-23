#pragma once

/**
 * @brief Reprezentuje pojedynczy w�ze� w li�cie dwukierunkowej.
 * @tparam T Typ danych przechowywanych w w�le.
 */
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    /**
     * @brief Konstruktor w�z�a.
     * @param value Dane, kt�re maj� by� przechowywane w w�le.
     */
    Node(T value);

    /**
     * @brief Destruktor w�z�a.
     */
    ~Node();
};

template <typename T>
Node<T>::Node(T value) : data(value), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::~Node() {}