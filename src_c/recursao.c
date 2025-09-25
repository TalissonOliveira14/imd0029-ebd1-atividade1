#include "recursao.h"

int recursao(const char *str, char alvo) {
   
    if (*str == '\0') {
        return 0;
    }
    
    if (*str == alvo) {
        return 1 + recursao(str + 1, alvo);
    } else {
        return recursao(str + 1, alvo);
    }
}
