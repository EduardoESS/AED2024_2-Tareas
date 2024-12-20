#ifndef HW3_H
#define HW3_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros. El archivo de tests se incluye solo a modo
de referencia, pero no es una version completa de los tests que serán
utilizados.

Todas las funciones listadas en este archivo serán testeadas por el corrector
automático, con el mismo prototipo mostrado en este archivo.

*******************************************************************************/
template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;

    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
struct BST {

Node<T>* root;

    BST();

    ~BST();

    void insert(T const& value);

    bool search(T const& value) const;

    void remove(T const& value);

    size_t size() const;

    T findMin() const;

    T findMax() const;

    bool isEmpty() const;

    void clear();

private:
    void insert(Node<T>*& node, T const& value);
    bool search(Node<T>* node, T const& value) const;
    void remove(Node<T>*& node, T const& value);
    size_t size(Node<T>* node) const;
    void clear(Node<T>*& node);
    Node<T>* findMin(Node<T>* node) const;
    Node<T>* findMax(Node<T>* node) const;
};

#include "hw3_impl.h"

#endif
