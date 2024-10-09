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


template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
  
    AVLNode<T>* x=  y->left;
    AVLNode<T>* x_ = x-> right;

    x->rigth= y;
    y ->left = x_;

     x->height = max(height(x->left), height(x->right)) + 1;
     y->height = max(height(y->left), height(y->right)) + 1;

    return x;

}

// Rotación izquierda
template <typename T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x) {
 
    AVLNode<T>* y = x->right;
    AVLNode<T>*  y_ = y->left;

    y->left = x;
    x->right = y_;

    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
  // COMPLETE HERE
  AVLNode<T>* current = node;
  while (current->left != nullptr)
    current = current->left;
  return current;
}


// Inserción
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
  if (!node){ 
      return new AVLNode<T>(key);
      }

  if (key < node->data){
    node->left = insert(node->left, key);
}
  else if (key > node->data){
    node->right = insert(node->right, key);
 } else{
    return node; // no repetidos
      }
  int bal = getBalance(node);
  node->height = max(height(node->left),height(node->right));

  if(key < node->left->data && bal > 1){
    return leftRotate(node);
  }
  if(key > node->right->data && bal < -1){
    return rightRotate(node);
  }
  if(key < node->right->data && bal < -1){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  if(key > node->left->data && bal > 1){
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  return node;
}

// Eliminar un nodo
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* root, T key) {
  if (root == nullptr){
      return root;
  }
    if (key<root->data){
        root->left= remove(root->left, key);
    }
else if (key>root->data){
        root->right= remove(root->right, key);
    }else{
    if(root->left==nullptr || root->right == nullptr ){
      AVLNode<T>* nodo_;
      if(root->left == nullptr){
         nodo_ = root->right;
      }
      else{
         nodo_ = root->left;
      }
        if(nodo_==nullptr){
            nodo_=root;
            root=nullptr;
        }else{
            *root=*nodo_;
        }
        delete nodo_;
    }else{
        AVLNode<T>* nodo_ = minValueNode(root->right);
        root->data=nodo_->data;
        root->right=remove(root->right, nodo_->data);
    }
    }

    if(root==nullptr){
        return root;
    }

    int bal = getBalance(root);
    root->height = max(height(root->left),height(root->right));

    if(key < root->left->data && bal > 1){
      return leftRotate(root);
    }
    if(key > root->right->data && bal < -1){
      return rightRotate(root);
    }
    if(key < root->right->data && bal < -1){
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
    if(key > root->left->data && bal > 1){
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
    return root;
}

// Búsqueda
template <typename T>
bool AVLTree<T>::search(AVLNode<T>* node, T key) {
  if (node == nullptr){
        return false;
}
    if (node->data == key){
        return true;
}
     if (key < node->data){
        return search(node->left, key);
}else{
    return search(node->right, key);
         }
    
}

// Recorrido preorder
template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
  if(root!=nullptr)
  {
    ret.push_back(root->key);
    preorder(root->left,ret);
    preorder(root->right,ret);
  }
}

// Recorrido inorder
template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
  if(root!=nullptr)
  {
    inorder(root->left);
    ret.push_back(root->key);
    inorder(root->right,ret);
  }
}

// Recorrido postorder
template <typename T>
void AVLTree<T>::postorder(AVLNode<T>* root, std::vector<T>& ret) {
  // COMPLETE HERE
  if (root != nullptr)
  {
    postorder(root->left,ret);
    postorder(root->right,ret);
    ret.push_back(root->key);
  }
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
  vector<T> output;
  preorder(this->root,output);
  return output;
}

template <typename T>
std::vector<T> AVLTree<T>::inorderTraversal() {
  // COMPLETE HERE
  vector<T> output;
  inorder(this->root,output);
  return output;
}

template <typename T>
std::vector<T> AVLTree<T>::postorderTraversal() {
  // COMPLETE HERE
  vector<T> output;
  postorder(this->root,output);
  return output;
}

template <typename T>
int AVLTree<T>::height() {
  return height(this->root);
}

template <typename T>
bool AVLTree<T>::isBalanced() {
  // COMPLETE HERE
  return abs(getBalance(this->root))<=1;
}

#endif
