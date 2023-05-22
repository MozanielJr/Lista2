/*
Elabore um programa utilizando as estruturas Professor, Disciplina e Estudante.

Professor (nome, funcional, titulacao (especialista, mestre ou doutor)).
Disciplina (nome, codigo, carga_horaria, professor_responsavel (escolhidos dentre os professores cadastrados)).
Estudante (nome, matricula, idade).

Serão cadastrados 3 professores, 2 disciplinas e no máximo 15 estudantes distribuídos entre as duas disciplinas, uma disciplina não poderá ter mais que 10 estudantes matriculados.

Apresente um relatório dos alunos matriculados na primeira disciplina ordenados por idade.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Apresente um relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Utilize o bubble sort para ordenação utilizano um procedimento com passagem de parâmetros por referência.

Idade do estudante deverá estar validada entre 16 e 26 por meio de uma função le_valida_idade.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Professor {
    char nome[100];
    char matricula[10];
    int titulacao;
};

struct Disciplina {
    char nome[100];
    char matricula[10];
    int carga_horaria;
    int qtde_alunos;
    struct Professor professor[2];
};

struct Estudante {
    char nome[100];
    char matricula[10];
    int idade;
    struct Disciplina disciplina[1];
};

char saida();

int main() {

struct Estudante estudante[14];

// do{
// menu_inicial();
// continuar = saida()
// }while (continuar=='S'||continuar=='s');



    return 0;
}

char saida(){
        char continuar;
        printf("|      Deseja continuar? (S/N): ");
        scanf(" %c",&continuar);
        printf("+-----------------------------------+\n");
    return continuar;

}

// /*

// ------------------SISCAMAIS------------
// CADASTRAR PROFESSOR(1)
// CADASTRAR DISCIPLINA(2)
// CADASTRAR ALUNO(3)
// RELATORIOS (4)
// SAIR(0)
// ----------------------------------------



// ------------------SISCAMAIS------------
// CADASTRAR PROFESSOR

// NOME:
// MATRICULA:
// TITULAÇAO (1- ESPECIALSITA 2-MESTRE 3-DOUTOR):
// CONTINUAR (S-SIM N-NAO):
// ----------------------------------------

// ------------------SISCAMAIS------------
// CADASTRAR DISCIPLINA

// NOME:
// CODIGO:
// CARGA HORARIO: 
// ESCOLHA O PROFESSOR RESPONSAVEL ABAIXO:
// (1) XXXXXXXXX 
// (2) XXXXXXXXX
// (3) XXXXXXXXX
// CONTINUAR (S-SIM N-NAO):
// ----------------------------------------


// ------------------SISCAMAIS------------
// CADASTRAR ALUNO

// NOME:
// MATRICULA:
// IDADE:
// ESCOLHA A DISCIPLINA ABAIXO:
// (1) XXXXXXXXX 
// (2) XXXXXXXXX
// CONTINUAR (S-SIM N-NAO):
// ----------------------------------------

// ------------------SISCAMAIS------------
// CADASTRAR PROFESSOR(1)
// CADASTRAR DISCIPLINA(2)
// CADASTRAR ALUNO(3)
// RELATORIOS (4)
// SAIR(0)
// ----------------------------------------


/*


Apresente um relatório dos alunos matriculados na primeira disciplina ordenados por idade.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Apresente um relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

*/


//  * /