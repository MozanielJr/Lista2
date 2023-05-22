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
#include <stdlib.h>
#include<locale.h>


struct Professor {
    char nome[50];
    int funcional;
    char titulacao[20];
};

struct Disciplina {
    char nome[50];
    int codigo;
    int carga_horaria;
    struct Professor professor_responsavel;
    int estudantes[10]; // Adicionando campo para armazenar os índices dos estudantes
    int num_estudantes; // Adicionando campo para contar o número de estudantes
};

struct Estudante {
    char nome[50];
    char matricula[10];
    int idade;
};

void le_valida_idade(int* idade) {
    do {
        printf("Digite a idade do aluno entre 16 a 26 anos: ");
        scanf("%d", idade);
        if (idade < 16 && idade > 26){
            printf("Idade inválida!\n");      
        }
    } while (*idade < 16 || *idade > 26);
}

void bubble_sort(struct Estudante* estudantes, int num_estudantes) {
    int i, j;
    struct Estudante temp;
    for (i = 0; i < num_estudantes - 1; i++) {
        for (j = 0; j < num_estudantes - i - 1; j++) {
            if (estudantes[j].idade > estudantes[j + 1].idade) {
                temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int i;
    int num_estudantes = 0;

    struct Professor professores[3] = {
        {"Professor1", 1, "Especialista"},
        {"Professor2", 2, "Mestre"},
        {"Professor3", 3, "Doutor"}
    };

    struct Disciplina disciplinas[2] = {
        {"Disciplina - 1", 1, 60, professores[0], {0}, 0}, // Inicializando o campo de estudantes e num_estudantes
        {"Disciplina - 2", 2, 80, professores[1], {0}, 0} // Inicializando o campo de estudantes e num_estudantes
    };

    struct Estudante estudantes[15];

    // Cadastro de estudantes
    for (i = 0; i < 15; i++) {
        printf("Digite o nome do aluno %d: ", i+1);
        scanf(" %[^\n]s", estudantes[i].nome);

        printf("Digite a matricula do aluno %d: ", i+1);
        scanf(" %[^\n]s", estudantes[i].matricula);

        le_valida_idade(&estudantes[i].idade);

        int disciplina_escolhida;
        printf("Escolha a disciplina (1 - Disciplina1, 2 - Disciplina2): ");
        scanf("%d", &disciplina_escolhida);

        if (disciplina_escolhida == 1 && disciplinas[0].num_estudantes < 10) {
            disciplinas[0].estudantes[disciplinas[0].num_estudantes] = i;
            disciplinas[0].num_estudantes++;
        } else if (disciplina_escolhida == 2 && disciplinas[1].num_estudantes < 10) {
            disciplinas[1].estudantes[disciplinas[1].num_estudantes] = i;
            disciplinas[1].num_estudantes++;
        } else {
            printf("\nDisciplina cheia ou inválida! O aluno não foi matriculado.\n");
            getchar();
            continue;
        }

        num_estudantes++;
        
        system("cls");
    }

    // Relatório dos alunos matriculados na primeira disciplina ordenados por idade
    printf("Relatório dos alunos matriculados na primeira disciplina ordenados por idade:\n\n");
    printf("codigo_disciplina\tnome_professor\tnome_estudante\tidade_estudante\n");

    bubble_sort(estudantes, disciplinas[0].num_estudantes);

    for (i = 0; i < disciplinas[0].num_estudantes; i++) {
        printf("%-17d\t%-15s\t%-15s\t%d\n", disciplinas[0].codigo,
               disciplinas[0].professor_responsavel.nome,
               estudantes[disciplinas[0].estudantes[i]].nome,
               estudantes[disciplinas[0].estudantes[i]].idade);
    }

    // Relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente
    printf("\nRelatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n\n");
    printf("codigo_disciplina\tnome_professor\tnome_estudante\tidade_estudante\n");

    bubble_sort(estudantes, disciplinas[1].num_estudantes);
    for (i = disciplinas[1].num_estudantes - 1; i >= 0; i--) {
        printf("%-17d\t%-15s\t%-15s\t%d\n", disciplinas[1].codigo,
               disciplinas[1].professor_responsavel.nome,
               estudantes[disciplinas[1].estudantes[i]].nome,
               estudantes[disciplinas[1].estudantes[i]].idade);
    }

    return 0;
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