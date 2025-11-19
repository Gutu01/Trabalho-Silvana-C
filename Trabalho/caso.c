//  Essa é a biblioteca principal inclue diversas funções primordiais como o printf e o scanf.
#include <stdio.h>

//  Aqui eu faço duas constantes para determinar o número máximo de caracteres de um nome e o total de alunos que 
//vão ser cadastrados no sistema. Isso permite que o sistema inteiro aumente a quantidade de alunos sómente trocando
//esse valor.
#define MAX_LETRAS_NOME 100
#define TOTAL_ALUNOS 5

//  Aqui eu crio uma struct para agrupar e ficar mais organizado os dados dos alunos. Também fica mais fácil de dar
//manutenção com isso separado.
typedef struct{
    char nome[MAX_LETRAS_NOME];
    int matricula;
    float notas[3];
    float media;
       
}Aluno;

//  Aqui eu já declado todas minhas funções logo no começo para que a função main possa usar. Porém, podesse perceber
//que não há nenhuma caraceristica em nenhuma delas, isso se deve porque eu deixei só a criação delas no começo e 
//posterguei a estrutura dela depois do main para deixar o código mais limpo e organizado.
//  Dessa forma, ao entrar no código, não demora muito tempo para chegar na função main. Novamente repito, isso melhora
//na hora de fazer a manuteção.
void cadastrarAluno(Aluno *alunos, int *quantidade);
void calcularMedias(Aluno *alunos, int quantidade);
float calcularMediaTurma(Aluno *alunos, int quantidade,float *media_geral); 
void exibirRelatorio(Aluno *alunos, int quantidade); 

//  Aqui é a função principal onde vamos chamar todas nossas funções e seus respictivos valores.
int main(){

//  Aquie eu chamo a estruct (que é a que guarda a imformação dos estudantes) e já coloco o total dela. Também chama
//minhas variáveis (zeradas para começar do zero) para fazer calculos que foram pedidos no exercício.
    Aluno alunos[TOTAL_ALUNOS];
    int quantidade = 0;
    float media_geral = 0;

//  Aqui eu chamo todas as funções solicitadas no exercío. Nota-se o uso do & para modificar valores e mandar para 
//nossa queridíssima função main e ser armazenadonas variáveis respectivas. Agora o que não tem o & ele serve como
//parametro para usar dentro da função. Todas ou retornam valores ou exibem mensagens. Um exemplo é o cadastrarAluno
//que mostra texto e lê informações dos alunos e já joga pra sruct, outro exemplo é o calcularMediaTurma que retorna
//o valor media_geral e posteriormente é exibido no printf na função principal.
    cadastrarAluno(alunos, &quantidade);
    calcularMedias(alunos, quantidade);
    calcularMediaTurma(alunos, quantidade, &media_geral);
    printf("\nA média geral da turma é de: %.2f", media_geral);
    exibirRelatorio(alunos, quantidade);

//  Aqui é para finalizar o programa com mensagem de sucesso.
    return 0;
}

//  Aqui que o bicho pega, essa função trás a struct aponta para a categoria alunos lá denro do main com o * e ainda 
//aponta para a variável quantidade, isso serve para manipular valores detro da função void. De resto é só um algoritmo
//que lê a entrada do usuário e vai guardando na struct Aluno alunos.
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

//  Aqui faz a mesma coisa que o anterior na questão de estrutura do void, porém ele não possue o * pois não precisamos
//alterar nada em quantidade uma vez que já definimos a quantidade de alunos. Sei que a contagem de quantidade de alunos
//é inútil por conta da constante lá em cima, mas resolvi preserva-la por recomendação do exercício, mas ela poderia ser
//feita muitas outas maneiras. Aliás, esse código inteiro pode ser feito de muitas outras maneiras e ainda mais caprichado.
//Mas nesse caso esse exercício tem apenas o objetivo de atender o que foi requerido no trabalho.
//  Nessa função é feita a média de cada aluno e é exibido logo de cara.
void calcularMedias(Aluno *alunos, int quantidade){
    for (int i=0; i < quantidade; i++){
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3;
        printf("\nA média de %s é de: %.2f", alunos[i].nome, alunos[i].media);
    }
}

//  Essa função tem um diferencial que é o *media_geral. Como já falado anteriormente, esse * é para manipular valores
//dentro da função principal, então, nesse caso ele joga a conta da média geral da turma lá para a variável que fica
//na main.
float calcularMediaTurma(Aluno *alunos, int quantidade,float *media_geral){
    float total=0;
    for (int i=0; i < quantidade; i++){
        total += alunos[i].media; 
    }
    *media_geral = total/quantidade;
    return *media_geral;
}

//  Por fim, mas não menos importante temos a função relatório que na altura do campeonato não tem nenhuma novidade.
//  Ela apensa começa guardando a maior nota e menor como a primeira nota digitada e depois entra num loop ficar 
//verificando o tempo todo se o número do indice da repetição é maior ou menor e assim vai indo o baile.
//  Nesse mesmo caminho fiz uma variável interna no void só para contar os aprovados e depois exibir. Se eles forem
//maior ou igual a 7 conta mais um a cada loop.
//  No final tudo é exibido com grácias.
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

//  Espero de coração que tenha gostado professora. Sei que não detalhei tudo porque há coisas que são muito básicas 
//para ficar detalhando e sei que no código real esses comentário são mais para situar para que serve cada coisa, não
//como funciona tudo.
//  Esse trabalho me proporcionou um conhecimento henriquecedor, muito obrigado, professora.