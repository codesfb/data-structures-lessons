#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[20];
    float preco;
} Produto;

int main() {
    FILE *arq;
    Produto p;
    
    // 1. Criando dados de teste
    Produto lista[3] = {
        {1, "Teclado", 150.0},
        {2, "Mouse", 80.0},
        {3, "Monitor", 1200.0}
    };

    // Abre para escrita binária (wb)
    arq = fopen("produtos.bin", "wb");
    if (arq == NULL) return 1;

    // Grava os 3 produtos de uma vez
    fwrite(lista, sizeof(Produto), 3, arq);
    fclose(arq);

    // ---------------------------------------------------------
    // 2. Testando o fseek e ftell
    // ---------------------------------------------------------
    arq = fopen("produtos.bin", "rb");
    if (arq == NULL) return 1;

    // A. Descobrir o tamanho total do arquivo
    fseek(arq, 0, SEEK_END);
    long tamanhoTotal = ftell(arq);
    printf("Tamanho total do arquivo: %ld bytes\n", tamanhoTotal);

    // B. Ir direto para o SEGUNDO produto (índice 1)
    // Pulamos o tamanho de 1 struct Produto para cair no início da segunda
    fseek(arq, 1 * sizeof(Produto), SEEK_SET);
    
    // Lendo o produto onde o cursor parou
    fread(&p, sizeof(Produto), 1, arq);
    
    printf("\n--- Produto Recuperado via fseek ---\n");
    printf("ID: %d | Nome: %s | Preco: R$ %.2f\n", p.id, p.nome, p.preco);

    // C. Onde estamos agora?
    printf("\nPosicao atual do cursor: %ld bytes\n", ftell(arq));

    fclose(arq);
    return 0;
}