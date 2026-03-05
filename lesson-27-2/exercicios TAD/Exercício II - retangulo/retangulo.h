// Propriedades: altura, largura
// Operações: criarRetangulo, calcularArea, calcularPerimetro,
// liberarRetangulo
// Área do retângulo: altura*largura
// Perímetro do retângulo: 2 * (altura+largura)
#define ERROR 1
#define SUCCESS 0
typedef struct retangulo Retangulo;
Retangulo *CriarRetangulo(int a, int l);
int calcularArea(Retangulo *r);
int calcularPerimetro(Retangulo *r);
void liberarRetangulo(Retangulo *r);
