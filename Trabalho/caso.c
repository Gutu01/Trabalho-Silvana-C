#include <stdio.h>

#define MAX_LETRAS_NOME 100
#define TOTAL_ALUNOS 5

typedef struct{
    char nome[MAX_LETRAS_NOME];
    int matricula;
    float notas[3];
    float media;
       
}Aluno;

void cadastrarAluno(Aluno *alunos, int *quantidade);
void calcularMedias(Aluno *alunos, int quantidade);
float calcularMediaTurma(Aluno *alunos, int quantidade,float *media_geral); 
void exibirRelatorio(Aluno *alunos, int quantidade); 


int main(){

    Aluno alunos[TOTAL_ALUNOS];
    int quantidade = 0;
    float media_geral = 0;

    cadastrarAluno(alunos, &quantidade);
    calcularMedias(alunos, quantidade);
    calcularMediaTurma(alunos, quantidade, &media_geral);
    printf("\nA média geral da turma é de: %.2f", media_geral);
    exibirRelatorio(alunos, quantidade);


    return 0;
}

void cadastrarAluno(Aluno *alunos, int *quantidade){
    for (int i = 0; i <TOTAL_ALUNOS; i++){
        printf("\nDigite o nome do %dº aluno: ", i + 1);
        scanf("%s", alunos[*quantidade].nome);

        printf("Digite a matrícula do %dº aluno: ", i + 1);
        scanf("%d", &alunos[*quantidade].matricula);

        for (int j = 0; j < 3; j++) {
            printf("Digite a %dº nota: ", j + 1);
            scanf("%f", &alunos[*quantidade].notas[j]);
        }

        (*quantidade)++;
    }
}



void calcularMedias(Aluno *alunos, int quantidade){
    for (int i=0; i < quantidade; i++){
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3;
        printf("\nA média de %s é de: %.2f", alunos[i].nome, alunos[i].media);
    }
}



float calcularMediaTurma(Aluno *alunos, int quantidade,float *media_geral){
    float total=0;
    for (int i=0; i < quantidade; i++){
        total += alunos[i].media; 
    }
    *media_geral = total/quantidade;
    return *media_geral;
}

void exibirRelatorio(Aluno *alunos, int quantidade){
    float maior_nota = alunos[0].media;
    float menor_nota = alunos[0].media;
    int aprovados = 0;

    for (int i=0; i<quantidade; i++){
        if (maior_nota < alunos[i].media){
            maior_nota = alunos[i].media;
        }else if(menor_nota > alunos[i].media){
            menor_nota = alunos[i].media;
        }
        if (alunos[i].media >= 7){
            aprovados ++;
        }
    }
    printf("\n\nRELATÓRIO:");
    printf("\nA maior média é: %.2f", maior_nota);
    printf("\nA menor média é: %.2f", menor_nota);
    printf("\n%d alunos foram aprovados.", aprovados);

}
