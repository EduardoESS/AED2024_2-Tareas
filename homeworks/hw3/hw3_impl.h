#ifndef HW3_IMPL_H
#define HW3_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw3.h"

template <typename T>
BST<T>::BST() : root(nullptr) {
  
}



template <typename T>
BST<T>::~BST() {
  clear();
}

template <typename T>
void BST<T>::insert(T const& value) {
  insert(root, value);
}

template <typename T>
bool BST<T>::search(T const& value) const {
  return search(root, value);
}

template <typename T>
void BST<T>::remove(T const& value) {
  remove(root, value);
}

template <typename T>
size_t BST<T>::size() const {
  return size(root);
  //return 0;
}

template <typename T>
T BST<T>::findMin() const {
  // COMPLETE HERE
  if (isEmpty()){
    throw std::runtime_error("BST está vacío");
  }
  return findMin(root)->value;
}

template <typename T>
T BST<T>::findMax() const {
  // COMPLETE HERE
  if (isEmpty()){
    throw std::runtime_error("BST está vacío");
  }
  return findMax(root)->value;
}

template <typename T>
bool BST<T>::isEmpty() const {
  return root == nullptr;
}

template <typename T>
void BST<T>::clear() {
  clear(root);
  root = nullptr; 
}

//############################ PRIVATE FUNCTIONS ###############################
template <typename T>
void BST<T>::insert(Node<T>*& node, T const& value) {
    if (!node) {
        node = new Node<T>(value); 
    } else if (value < node->value) {
        insert(node->left, value);  
    } else if (value > node->value) {
        insert(node->right, value);  
    }
}

template <typename T>
bool BST<T>::search(Node<T>* node, T const& value) const {
    if (!node) return false;  
    if (value == node->value) return true; 
    if (value < node->value) return search(node->left, value);  
    return search(node->right, value);  
}

template <typename T>
void BST<T>::remove(Node<T>*& node, T const& value) {
    if (!node) return;

    if (value < node->value) {
        remove(node->left, value);  
    } else if (value > node->value) {
        remove(node->right, value);  
    } else {
        // Nodo encontrado
        if (!node->left) {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
        } else if (!node->right) {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node<T>* minNode = findMin(node->right);
            node->value = minNode->value;
            remove(node->right, minNode->value);
        }
    }
}

template <typename T>
size_t BST<T>::size(Node<T>* node) const {
    if (!node) return 0;
    return 1 + size(node->left) + size(node->right);
}

template <typename T>
void BST<T>::clear(Node<T>*& node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
Node<T>* BST<T>::findMin(Node<T>* node) const {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}


template <typename T>
Node<T>* BST<T>::findMax(Node<T>* node) const {
    while (node && node->right) {
        node = node->right;

    }
    return node;
}
#endif
