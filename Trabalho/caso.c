#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LETRAS_NOME 100

typedef struct{
    char nome[MAX_LETRAS_NOME];
    int matricula;
    float notas[3];
    float media;
       
}Aluno;

void cadastrarAluno(Aluno *alunos, int *quantidade);
void calcularMedias(Aluno *alunos, int quanlidade);
float calcularMediaTurma(Aluno *alunos, int quantidade);
void exibirRelatorio(Aluno *alunos, int quantidade);

int main(){

    Aluno alunos[5];
    int quantidade = 0;

    cadastrarAluno(alunos, &quantidade);



    return 0;
}

void cadastrarAluno(Aluno *alunos, int *quantidade){

    printf("Digite o nome do aluno: ");
    scanf("%s", alunos[*quantidade].nome);

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &alunos[*quantidade].matricula);

    for (int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &alunos[*quantidade].notas[i]);
    }

    (*quantidade)++;
}

void calcularMedias(Aluno *alunos, int quanlidade);
float calcularMediaTurma(Aluno *alunos, int quantidade);
void exibirRelatorio(Aluno *alunos, int quantidade);