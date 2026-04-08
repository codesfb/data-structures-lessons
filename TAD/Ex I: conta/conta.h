#define ERROR 0
#define SUCCESS 1


typedef struct conta Conta;

Conta *criaConta(int num, float saldo);
int depositar(Conta *conta, float valor);
int sacar(Conta *conta, float valor);
int transferir(Conta *conta, Conta *conta2,float valor);
int obterNum(Conta *conta);
float obterSaldo(Conta *conta);
void liberarConta(Conta *conta);

