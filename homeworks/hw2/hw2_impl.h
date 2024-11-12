#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;


#include "hw2.h"

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {
  // COMPLETE HERE
}

template <typename T>
void Heap<T>::insert(T const& element) {
  // COMPLETE HERE
  
  //Eduardo
data.push_back(element);
size_t i=data.size() - 1;

while(i>0){
size_t parent = (i-1)/2;
if((minHeap && data[i]<data[present]) || (!minHeap && data[i]> data[parent])){
swap(data[i], data[parent]);
i = parent;
} else{
break;
}
}
}


template <typename T>
T Heap<T>::extractTop() {
  // COMPLETE HERE
  
  //Eduardo
  //return T{};
  if (data.empty()) {
        cerr << "Error: Heap vacio!!!" << endl;
        return T();  
    }
  T topElement = data[0];
  data[0] = data.back();
  data.pop_back();

  size_t i = 0;
  while(i<data.size()){
    size_t left = 2*i + 1;
    size_t right = 2*i + 2;
    size_t swapIndex= i;

    if(left < data.size() && ((minHeap && data[left] < data[swapIndex]) || (!minHeap && data[left] > data[swapIndex]))){
            swapIndex = left;
        }
        if(right < data.size() && ((minHeap && data[right] < data[swapIndex]) || (!minHeap && data[right] > data[swapIndex]))){
            swapIndex = right;
        }

        if(swapIndex==i){
            break;
        }

        swap(data[i],data[swapIndex]);
        i = swapIndex;
  }
  return topElement;
}

template <typename T>
T Heap<T>::peek() const {
  // COMPLETE HERE
  
  //Eduardo
  //return T{};
if (data.empty()){
throw out_of_range("Heap is empty");
}
return data[0];
  
}

template <typename T>
size_t Heap<T>::size() const {
  // COMPLETE HERE
  
  //Eduardo
  //return 0;
  return data.size();
  
}

template <typename T>
bool Heap<T>::isEmpty() const {
  // COMPLETE HERE
  
  //Eduardo
  //return true;
  return data.empty();
  
}


template <typename T>
void Heap<T>::clear() {
  // COMPLETE HERE
  
//Eduardo
data.clear();

}

#endif
