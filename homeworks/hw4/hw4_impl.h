#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>

#include "hw4.h"
using namespace std;
//########################## Funciones de Ayuda #############################

vector<int> computePrefix(string const & pattern){

  size_t pathLength = pattern.size();
  vector<int> prefix(pathLength, 0);
  int pathIdx = 0;

  for(size_t i=1;i<pathLength;i++){
    while( pathIdx > 0 && pattern[pathIdx] != pattern[i]){
      pathIdx = prefix[pathIdx - 1];
    }
    if (pattern[pathIdx] == pattern[i]) {
      pathIdx++;
    }
    prefix[i] = pathIdx;
  }

  return prefix;
}






//########################### Algoritmos HW4 ############################

vector<int> stringMatch_naive(string const& text,
                                   string const& pattern)
{
  // Implemente aqui el método mas ingenuo para resolver el problema de string
  // matching.

  vector<int> ret;
  size_t textSize = text.size();
    size_t patternSize = pattern.size();


    for (size_t i = 0; i <= textSize - patternSize; ++i) {
        bool match = true;

      
        for (size_t j = 0; j < patternSize; ++j) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            ret.push_back(i);
        }
    }

    return ret;
}

vector<int> stringMatch_RabinKarp(string const& text,
                                       string const& pattern)
{
  // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
  // de string matching.


  
  vector<int> ret;
  size_t textSize = text.size();
    size_t patternSize = pattern.size();
    if (patternSize > textSize) {
      return ret;
    }

    const int prime = 101; 
    int base = 256;        
    int patternHash = 0, textHash = 0, h = 1;

  
    for (size_t i = 0; i < patternSize - 1; ++i) {
        h = (h * base) % prime;
    }


    for (size_t i = 0; i < patternSize; ++i) {
        patternHash = (base * patternHash + pattern[i]) % prime;
        textHash = (base * textHash + text[i]) % prime;
    }

    
    for (size_t i = 0; i <= textSize - patternSize; ++i) {
        if (patternHash == textHash) {
            bool match = true;

          
            for (size_t j = 0; j < patternSize; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                ret.push_back(i);
            }
        }

    
        if (i < textSize - patternSize) {
            textHash = (base * (textHash - text[i] * h) + text[i + patternSize]) % prime;
            if (textHash < 0) textHash += prime;  
        }
    }

    return ret;
}

vector<int> stringMatch_KnuthMorrisPratt(string const& text,
                                             string const& pattern)
{
  // Implemente aqui el algoritmo de Knuth-Morris-Pratt para resolver el
  // problema de string matching.


  vector<int> ret;
  size_t textSize = text.size();
    size_t patternSize = pattern.size();

     if (patternSize == 0 || textSize < patternSize) return ret;


    vector<int> prefix = computePrefix(pattern);
    size_t q = 0; 

  
    for (size_t i = 0; i < textSize; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1]; 
        }
        if (pattern[q] == text[i]) {
            q++;  
        }
        if (q == patternSize) {
            ret.push_back(i - patternSize + 1);  
            q = prefix[q - 1];
        }
    }

    return ret;
}

#endif
