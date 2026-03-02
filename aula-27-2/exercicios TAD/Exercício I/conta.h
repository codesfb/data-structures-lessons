#define ERROR 1
#define SUCCESS 0
typedef struct conta Conta;
Conta* criarConta(int numero, double saldo);
int depositar(Conta* conta, double valor);
int sacar(Conta* conta, double valor);          
void transferir(Conta* contaOrigem, Conta* contaDestino, double valor);
int obterNumero(Conta* conta);
double obterSaldo(Conta* conta);
void liberarConta(Conta* conta);