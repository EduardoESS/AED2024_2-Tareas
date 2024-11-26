#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>

#include "hw4.h"
using namespace std;
//########################## Funciones de Ayuda #############################

vector<int> computePrefix(string const & pattern){

  size_t patLen = pattern.size();
  vector<int> prefix(patLen, 0);
  int patIdx = 0;

  for(size_t i=1;i<patLen;i++){
    while( patIdx > 0 && pattern[patIdx] != pattern[i]){
      patIdx = prefix[patIdx - 1];
    }
    if (pattern[patIdx] == pattern[i]) {
      patIdx++;
    }
    prefix[i] = patIdx;
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
        if (text.substr(i, patternSize) == pattern) {
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
    if (patternSize > textSize) return ret;

    const int prime = 101; // Número primo para el hash
    int textHash = 0, patternHash = 0, h = 1;

    // Calcular el valor de h = pow(d, m-1) % prime
    for (size_t i = 0; i < patternSize - 1; ++i)
        h = (h * 256) % prime;

    // Calcular los hashes iniciales para el patrón y la primera ventana del texto
    for (size_t i = 0; i < patternSize; ++i) {
        patternHash = (256 * patternHash + pattern[i]) % prime;
        textHash = (256 * textHash + text[i]) % prime;
    }

    // Deslizar el patrón sobre el texto
    for (size_t i = 0; i <= textSize - patternSize; ++i) {
        if (patternHash == textHash) {
            // Si los hashes coinciden, verificar carácter por carácter
            if (text.substr(i, patternSize) == pattern) {
                ret.push_back(i);
            }
        }

        // Calcular el hash de la siguiente ventana
        if (i < textSize - patternSize) {
            textHash = (256 * (textHash - text[i] * h) + text[i + patternSize]) % prime;
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
    int q = 0;  // Número de caracteres coincidentes

    for (size_t i = 0; i < textSize; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == static_cast<int>(patternSize)) {
            ret.push_back(i - patternSize + 1);
            q = prefix[q - 1];
        }
    }
  return ret;
}

#endif
