#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
#include <stdexcept>


#include "hw2.h"

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {
  // COMPLETE HERE
}

template <typename T>
void Heap<T>::insert(T const& element) {
  data.push_back(element);
  // Balancear
  int it = data.size() - 1;
  
  bool cond;
  if (minHeap) {
    cond = data[it] < data[(it - 1) / 2];
  } else {
    cond = data[it] > data[(it - 1) / 2];
  }

  while (it > 0 && cond) {
    swap(data[it], data[(it - 1) / 2]);
    it = (it - 1) / 2; 
    if (minHeap) {
      cond = data[it] < data[(it - 1) / 2];
    } else {
      cond = data[it] > data[(it - 1) / 2];
    }
  }
}

template <typename T>
T Heap<T>::extractTop() {
  // COMPLETE HERE
  T val = data[0];
  data[0] = data[data.size()-1];
  data.pop_back();
  if(data.size() != 0){
    int size = data.size();
    int it = 0;
    while(true){
      int aux = it;
      bool cond1;
      if(minHeap){
        cond1 = data[2*it + 1] < data[it];
      }
      else{
        cond1 = data[2*it + 1] > data[it];
      }
      bool cond2;
      if(minHeap){
        cond2 = data[2*it + 2] < data[it];
      }
      else{
        cond2 = data[2*it + 2] > data[it];
      }
      if(data[2*it + 1] < data.size() && cond1){
        aux = data[2*it + 1];
      }
      if(data[2*it + 2] < data.size() && cond2){
        aux = data[2*it + 2];
      }
      if(it == aux){
        break;
      }
      swap(data[it],data[aux]);
      it = aux;
    }
  }
  return val;
}

template <typename T>
T Heap<T>::peek() const {

  if (data.empty()){
    throw out_of_range("No tiene elementos");
  }
    return data[0];
  
}

template <typename T>
size_t Heap<T>::size() const {
  return data.size();
}

template <typename T>
bool Heap<T>::isEmpty() const {
  return data.empty();
}


template <typename T>
void Heap<T>::clear() {
  data.clear();
}

#endif
