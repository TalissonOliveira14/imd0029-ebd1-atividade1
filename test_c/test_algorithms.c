#include <stdio.h>
#include <stdbool.h>
#include "busca_seq_ordenada.h"
#include "busca_binaria.h"
#include "recursao.h"

// Variável global para simular a API de versões defeituosas
int global_bad_version = 0;

bool isBadVersion(int version) {
    return version >= global_bad_version;
}

#define RUN_TEST(name, expr, expected)                               \
    do {                                                             \
        int result = (expr);                                         \
        printf("%-40s : %s\n", name,                                  \
               (result == (expected)) ? "OK" : "FAIL");              \
    } while(0)

int main() {
    printf("=== EXECUTANDO TESTES ===\n\n");
    
    // ========== TESTE 1: Busca Binária (Versões Defeituosas) ==========
    printf("1. BUSCA BINÁRIA (VERSÕES DEFEITUOSAS):\n");
    
    // Teste 1: Versão 4 é a primeira defeituosa
    global_bad_version = 4;
    RUN_TEST("Primeira versão defeituosa = 4", busca_binaria(5), 4);
    
    // Teste 2: Primeira versão já é defeituosa
    global_bad_version = 1;
    RUN_TEST("Primeira versão defeituosa = 1", busca_binaria(5), 1);
    
    // Teste 3: Última versão é defeituosa
    global_bad_version = 10;
    RUN_TEST("Última versão defeituosa = 10", busca_binaria(10), 10);
    
    printf("\n");
    
    // ========== TESTE 2: Especialidades Distintas ==========
    printf("2. ESPECIALIDADES DISTINTAS:\n");
    
    // Exemplo do enunciado: {4, 2, 1, 4, 2, 1} → 3 especialidades
    int arr1[] = {4, 2, 1, 4, 2, 1};
    RUN_TEST("Exemplo 1 - 6 elementos", conta_especialidades_distintas(arr1, 6), 3);
    
    // Vetor com todos iguais
    int arr2[] = {5, 5, 5, 5};
    RUN_TEST("Todos iguais", conta_especialidades_distintas(arr2, 4), 1);
    
    // Vetor com todos diferentes
    int arr3[] = {1, 2, 3, 4, 5};
    RUN_TEST("Todos diferentes", conta_especialidades_distintas(arr3, 5), 5);
    
    // Vetor vazio
    int arr4[] = {};
    RUN_TEST("Vetor vazio", conta_especialidades_distintas(arr4, 0), 0);
    
    printf("\n");
    
    // ========== TESTE 3: Recursão (Contagem de Caracteres) ==========
    printf("3. RECURSÃO (CONTAGEM DE CARACTERES):\n");
    
    // Exemplo do enunciado: "banana" com 'a' → 3
    RUN_TEST("banana com 'a'", recursao("banana", 'a'), 3);
    
    RUN_TEST("banana com 'n'", recursao("banana", 'n'), 2);
    RUN_TEST("banana com 'z'", recursao("banana", 'z'), 0);
    RUN_TEST("string vazia", recursao("", 'a'), 0);
    RUN_TEST("teste com 't'", recursao("teste", 't'), 2);
    
    printf("\n=== FIM DOS TESTES ===\n");
    
    return 0;
}
