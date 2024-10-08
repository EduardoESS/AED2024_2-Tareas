#ifndef AVL_IMPL_H
#define AVL_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "avl.h"
using namespace std;
// AVLNode

template <typename T>
AVLNode<T>::AVLNode(T value)
    : data(value), left(nullptr), right(nullptr), height(0) {}

// AVLTree

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
int AVLTree<T>::height(AVLNode<T>* node) {
  // COMPLETE HERE
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T>* node) {
  // COMPLETE HERE
}

template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
  // COMPLETE HERE
    AVLNode* x=  y->left;
    AVLNode* T2 = x-> right;
    // realiza la rotación

    x->rigth= y;
    y ->left = T2;
    //actualizar las alturas
     y->height = max(height(y->left), height(y->right)) + 1;
     x->height = max(height(x->left), height(x->right)) + 1;
// ahora retornamos la raíz
    return x;

}

// Rotación izquierda
template <typename T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x) {
  // COMPLETE HERE
}

template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
  // COMPLETE HERE
}

// Inserción
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
  if (!node) return new Node(value);

  if (value < node->value){
    node->left = insert(node->left, value);
}
  else if (value > node->value){
    node->right = insert(node->right, value);
 } else{
    return node; // Para evitar nodos repetidos
      }
}

// Eliminar un nodo
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* root, T key) {
  // COMPLETE HERE
}

// Búsqueda
template <typename T>
bool AVLTree<T>::search(AVLNode<T>* node, T key) {
  // COMPLETE HERE
}

// Recorrido preorder
template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
}

// Recorrido inorder
template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
}

// Recorrido postorder
template <typename T>
void AVLTree<T>::postorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
}

/// Public functions

template <typename T>
void AVLTree<T>::insert(T key) {
   root = insert(root, key);
}

template <typename T>
void AVLTree<T>::remove(T key) {
  // COMPLETE HERE
}

template <typename T>
bool AVLTree<T>::search(T key) {
  // COMPLETE HERE
}

template <typename T>
std::vector<T> AVLTree<T>::preorderTraversal() {
  // COMPLETE HERE
}

template <typename T>
std::vector<T> AVLTree<T>::inorderTraversal() {
  // COMPLETE HERE
}

template <typename T>
std::vector<T> AVLTree<T>::postorderTraversal() {
  // COMPLETE HERE
}

template <typename T>
int AVLTree<T>::height() {
  if (!root){
      return -1;
      }else{
      return (root->height);
      }

}

template <typename T>
bool AVLTree<T>::isBalanced() {
  // COMPLETE HERE
}

#endif
