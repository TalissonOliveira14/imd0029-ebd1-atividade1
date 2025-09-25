#include "busca_binaria.h"
#include <stdbool.h>

int global_bad_version = 0;

bool isBadVersion(int version) {
    return version >= global_bad_version;
}

int busca_binaria(int n) {
    int esquerda = 1;
    int direita = n;
    
    while (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        if (isBadVersion(meio)) {
            direita = meio;
        } else {
            esquerda = meio + 1;
        }
    }
    
    return esquerda;
}