//main chula para testar 
#include "veiculo.h"
#include <stdio.h>
int main(){
    Lista *veiculos= criarLista();
    Veiculo *v1 = criarVeiculo("Toyota Corolla","2022","RXZ-3A45");
    Veiculo *v2 = criarVeiculo("Tesla Model 3","2024","EVE-0101");
    inserirVeiculo(veiculos, v1, 0);
    inserirVeiculo(veiculos, v2, 1);  
    mostrarVeiculos(veiculos);
    removerVeiculo(veiculos,0);
    mostrarVeiculos(veiculos);
    removerPlaca(veiculos, "EVE-0101");
    mostrarVeiculos(veiculos);




}