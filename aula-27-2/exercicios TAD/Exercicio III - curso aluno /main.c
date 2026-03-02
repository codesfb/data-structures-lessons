#include "./curso/curso.h"
#include "./aluno/aluno.h"

#include <stdio.h>
#include <stdlib.h>


int main() {
    Curso* curso1 = criarCurso("ADS", "Análise e Desenvolvimento de Sistemas");
    Curso* curso2 = criarCurso("BES", "Bach. Engenharia de Software");

    Aluno* aluno1 = criarAluno(12345,"João", curso1); 
    Aluno* aluno2 = criarAluno( 67890, "Maria",curso2); 


    char nomeAluno[100];
    obterNomeAluno(aluno1,nomeAluno);

    Curso* cursoAluno = obterCurso(aluno1);
    char nomeCurso[100];
    obterNomeCurso(cursoAluno, nomeCurso);

    printf("Pront: %d, Nome: %s, Curso: %s \n",obterProntuario(aluno1), nomeAluno, nomeCurso);

    liberarCurso(curso1);
    liberarCurso(curso2);
    liberarAluno(aluno1);
    liberarAluno(aluno2);

    return 0;
}