#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>

#include "hw4.h"

//########################## Funciones de Ayuda #############################

std::vector<int> computePrefix(std::string const& pattern) {
    size_t m = pattern.size();
    std::vector<int> prefix(m, 0);
    int k = 0;

    for (size_t q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }

    return prefix;
}



//########################### Algoritmos HW4 ############################

std::vector<int> stringMatch_naive(std::string const& text,
                                   std::string const& pattern)
{
  // Implemente aqui el método mas ingenuo para resolver el problema de string
  // matching.

  std::vector<int> ret;
  size_t textSize = text.size();
    size_t patternSize = pattern.size();

    for (size_t i = 0; i <= textSize - patternSize; ++i) {
        if (text.substr(i, patternSize) == pattern) {
            ret.push_back(i);
        }
    }
  return ret;
}

std::vector<int> stringMatch_RabinKarp(std::string const& text,
                                       std::string const& pattern)
{
  // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
  // de string matching.

  std::vector<int> ret;
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

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                              std::string const& pattern)
{
  // Implemente aqui el algoritmo de Knuth-Morris-Pratt para resolver el
  // problema de string matching.

  std::vector<int> ret;
  size_t textSize = text.size();
    size_t patternSize = pattern.size();

    if (patternSize == 0 || textSize < patternSize) return ret;

    std::vector<int> prefix = computePrefix(pattern);
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
