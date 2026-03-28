#include <stdio.h>
#include "polinomio.h"

int main() {
    Lista *p = criarLista();
    
    // 3x^5 + 6x^2 + 1
    adicionarTermo(p, 3.0, 5);
    adicionarTermo(p, 6.0, 2);
    adicionarTermo(p, 1.0, 0);

    printf("Resultado para x=2: %.2f\n", avaliarPolinomio(p, 2.0));

    liberarLista(p);
    return 0;
}