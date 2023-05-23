#include <stdio.h>

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
        printf("Digite a idade do aluno: ");
        scanf("%d", idade);
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
    int i;
    int num_estudantes = 0;

    struct Professor professores[3] = {
        {"Professor1", 1, "Especialista"},
        {"Professor2", 2, "Mestre"},
        {"Professor3", 3, "Doutor"}
    };

    struct Disciplina disciplinas[2] = {
        {"Disciplina1", 1, 60, professores[0], {0}, 0}, // Inicializando o campo de estudantes e num_estudantes
        {"Disciplina2", 2, 80, professores[1], {0}, 0} // Inicializando o campo de estudantes e num_estudantes
    };

    struct Estudante estudantes[15];

    // Cadastro de estudantes
    for (i = 0; i < 5; i++) {
        printf("Digite o nome do aluno: ");
        scanf("%s", estudantes[i].nome);

        printf("\nDigite a matricula do aluno: ");
        scanf("%s", estudantes[i].matricula);

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
            printf("Disciplina cheia ou inválida! O aluno não foi matriculado.\n");
            continue;
        }

        num_estudantes++;
    }

    // Relatório dos alunos matriculados na primeira disciplina ordenados por idade
    printf("Relatório dos alunos matriculados na primeira disciplina ordenados por idade:\n");
    printf("codigo_disciplina  nome_professor nome_estudante idade_estudante\n");

    bubble_sort(estudantes, disciplinas[0].num_estudantes);

    for (i = 0; i < disciplinas[0].num_estudantes; i++) {
        printf("%-17d%-15s%-15s%d\n", disciplinas[0].codigo,
               disciplinas[0].professor_responsavel.nome,
               estudantes[disciplinas[0].estudantes[i]].nome,
               estudantes[disciplinas[0].estudantes[i]].idade);
    }

    // Relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente
    printf("\nRelatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n");
    printf("codigo_disciplina  nome_professor nome_estudante idade_estudante\n");

    bubble_sort(estudantes, disciplinas[1].num_estudantes);
    for (i = disciplinas[1].num_estudantes - 1; i >= 0; i--) {
        printf("%-17d%-15s%-15s%d\n", disciplinas[1].codigo,
               disciplinas[1].professor_responsavel.nome,
               estudantes[disciplinas[1].estudantes[i]].nome,
               estudantes[disciplinas[1].estudantes[i]].idade);
    }

    return 0;
}
