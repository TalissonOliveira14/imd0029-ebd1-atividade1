#include <stdio.h>
#include <stdbool.h>
#include "busca_seq_ordenada.h"
#include "busca_binaria.h"
#include "recursao.h"

extern int global_bad_version;
extern bool isBadVersion(int version);

#define RUN_TEST(name, expr, expected) \
    do { \
        int result = (expr); \
        printf("%-40s : %s\n", name, (result == (expected)) ? "OK" : "FAIL"); \
    } while(0)

int main() {
    printf("=== EXECUTANDO TESTES ===\n\n");
    
    printf("1. BUSCA BINARIA (VERSOES DEFEITUOSAS):\n");
    
    global_bad_version = 4;
    RUN_TEST("Primeira versao defeituosa = 4", busca_binaria(5), 4);
    
    global_bad_version = 1;
    RUN_TEST("Primeira versao defeituosa = 1", busca_binaria(5), 1);
    
    global_bad_version = 10;
    RUN_TEST("Ultima versao defeituosa = 10", busca_binaria(10), 10);
    
    printf("\n");
    
    printf("2. ESPECIALIDADES DISTINTAS:\n");
    
    int arr1[] = {4, 2, 1, 4, 2, 1};
    RUN_TEST("Exemplo 1 - 6 elementos", conta_especialidades_distintas(arr1, 6), 3);
    
    int arr2[] = {5, 5, 5, 5};
    RUN_TEST("Todos iguais", conta_especialidades_distintas(arr2, 4), 1);
    
    int arr3[] = {1, 2, 3, 4, 5};
    RUN_TEST("Todos diferentes", conta_especialidades_distintas(arr3, 5), 5);
    
    printf("\n");
    
    printf("3. RECURSAO (CONTAGEM DE CARACTERES):\n");
    
    RUN_TEST("banana com 'a'", recursao("banana", 'a'), 3);
    RUN_TEST("banana com 'n'", recursao("banana", 'n'), 2);
    RUN_TEST("banana com 'z'", recursao("banana", 'z'), 0);
    RUN_TEST("string vazia", recursao("", 'a'), 0);
    RUN_TEST("teste com 't'", recursao("teste", 't'), 2);
    
    printf("\n=== FIM DOS TESTES ===\n");
    
    return 0;
}
