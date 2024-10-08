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
  if (node == nullptr){
        return -1;
      }
    return (node->height);
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T>* node) {
  
    if (node == nullptr) {
    return 0;
  }
  return height(node->left) - height(node->right);
}
}

template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
  
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
 
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Realizar la rotación
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Retornar nueva raíz
    return y;
}

template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
  // COMPLETE HERE
}

// Inserción
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
  if (!node){ 
      return new Node(value);
      }

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
  if (root == nullptr){
      return root;
  }
    if (key<root->value){
        root->left= remove(root->left, key);
    }
else if (key>root->value){
        root->right= remove(root->right, key);
    }else{
    if(root->left==nullptr|| root->right == nullptr ){
        AVLNode<T>* temp= root->left=?root->left:root->right;
        if(temp==nullptr){
            temp=root;
            root=nullptr;
        }else{
            *root=*temp;
        }
        delete temp;
    }else{
        AVLNode<T>* temp = findMin(root->right);
        root->value=temp->value;
        root->right=remove(root->right, temp->value);
    }
    }
    if(root==nullptr){
        return root;
    }
    root->height=1+std::max(height(root->left), height(root->right));
    int balance=getBalance(root);
    if(Balance>1 && getBalance(root->left)>=0){
        return rotateRight(root);
    }
    if(balance>1&&getBalance(root->left)<0){
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance<-1&&getBalance(root->right)<=0){
        return rotateLeft(root);
    }
    if(balance<-1&&getBalance(root->right)>0){
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
    
}

// Búsqueda
template <typename T>
bool AVLTree<T>::search(AVLNode<T>* node, T key) {
  if (node == nullptr){
        return false;
}
    if (node->value == key){
        return true;
}
     if (key < node->value){
        return search(node->left, key);
}else{
    return search(node->right, key);
         }
    
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
  root = remove(root, key);
}

template <typename T>
bool AVLTree<T>::search(T key) {
  return search(root, key);
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
