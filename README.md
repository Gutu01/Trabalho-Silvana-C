Trabalho de Estrutura de Dados – Projeto em Linguagem C
Curso: Análise e Desenvolvimento de Sistemas
Disciplina: Estrutura de Dados
Professor(a): SILVANA NASCIMENTO
Aluno(s): ________________________________
Data de Entrega: 17/11/2025
Objetivo
Aplicar os conhecimentos sobre ponteiros, vetores e modularização em linguagem C, por
meio da resolução de um problema prático com uso de técnicas adequadas de organização
do código, passagem de parâmetros por referência e gerenciamento de memória.
Estudo de Caso – Sistema de Cadastro e Análise de Notas de Alunos
A faculdade TechEdu está desenvolvendo um sistema para cadastrar alunos de uma
disciplina e calcular estatísticas relacionadas ao desempenho dos mesmos.
Cada aluno tem:
- Nome (string)
- Matrícula (int)
- Notas (3 notas: float)
O sistema precisa:
1. Cadastrar até 5 alunos
2. Calcular a média individual de cada aluno
3. Determinar e exibir:
 - A maior e a menor média
 - A média geral da turma
 - A quantidade de alunos aprovados (média >= 7.0)
Tarefas do Trabalho
1. Construção do Algoritmo
O código deve ser implementado em linguagem C, obedecendo às seguintes diretrizes:
- Utilizar ponteiros para manipular os vetores de notas
- Utilizar vetores para armazenar os dados dos alunos
- Modularizar o programa com, no mínimo, as seguintes funções:
void cadastrarAlunos(Aluno *alunos, int *quantidade);
void calcularMedias(Aluno *alunos, int quantidade);
float calcularMediaTurma(Aluno *alunos, int quantidade);
void exibirRelatorio(Aluno *alunos, int quantidade);
Estrutura sugerida:
typedef struct {
 char nome[50];
 int matricula;
 float notas[3];
 float media;
} Aluno;
Entregáveis
- Código-fonte (.c) com organização e comentários (PODE SER EM TXT)
- Documento PDF contendo:
 - Introdução ao problema
 - Trechos explicativos do código
 - Prints de execução
Critérios de Avaliação
Critério Pontuação
Correção do algoritmo, lógica e
comentários no código
1,0
Uso adequado de ponteiros/vetores 0,5
Modularização e funções 0,5
Total: 2,0 pts 
