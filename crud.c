#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    int idade;
    char curso[50];
} Aluno;

#define MAX_ALUNOS 100

Aluno lista_alunos[MAX_ALUNOS];
int num_alunos = 0;

void criar_aluno() {
    Aluno novo_aluno;
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &novo_aluno.matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", novo_aluno.nome);
    printf("Digite a idade do aluno: ");
    scanf("%d", &novo_aluno.idade);
    printf("Digite o curso do aluno: ");
    scanf("%s", novo_aluno.curso);

    lista_alunos[num_alunos++] = novo_aluno;
}

void mostrar_lista_alunos() {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("Matrícula: %d, Nome: %s, Idade: %d, Curso: %s\n",
               lista_alunos[i].matricula, lista_alunos[i].nome,
               lista_alunos[i].idade, lista_alunos[i].curso);
    }
}

void atualizar_aluno() {
    int matricula;
    printf("Digite a matrícula do aluno a ser atualizado: ");
    scanf("%d", &matricula);

    for (int i = 0; i < num_alunos; i++) {
        if (lista_alunos[i].matricula == matricula) {
            printf("Digite o novo nome do aluno: ");
            scanf("%s", lista_alunos[i].nome);
            printf("Digite a nova idade do aluno: ");
            scanf("%d", &lista_alunos[i].idade);
            printf("Digite o novo curso do aluno: ");
            scanf("%s", lista_alunos[i].curso);
            break;
        }
    }
}

void deletar_aluno() {
    int matricula;
    printf("Digite a matrícula do aluno a ser deletado: ");
    scanf("%d", &matricula);

    for (int i = 0; i < num_alunos; i++) {
        if (lista_alunos[i].matricula == matricula) {
            for (int j = i; j < num_alunos - 1; j++) {
                lista_alunos[j] = lista_alunos[j + 1];
            }
            num_alunos--;
            break;
        }
    }
}

void menu_principal() {
    int opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("1. Criar Aluno\n");
        printf("2. Mostrar Lista de Alunos\n");
        printf("3. Atualizar Aluno\n");
        printf("4. Deletar Aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_aluno();
                break;
            case 2:
                mostrar_lista_alunos();
                break;
            case 3:
                atualizar_aluno();
                break;
            case 4:
                deletar_aluno();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
}

int main() {
    menu_principal();
    return 0;
}

