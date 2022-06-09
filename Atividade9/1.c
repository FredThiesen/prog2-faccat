#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[50];
    int matricula;
    float notaFinal;
};

typedef struct aluno Aluno;

int imprimirArquivo();
int cadastraAluno(Aluno *aluno);
int buscarNoArquivo(int numeroRegistro);
// int imprimirAluno(Aluno *aluno);

// limpa o console, funciona para windows e linux
void limpaBuffer() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void limpaConsole() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

int main(void) {
    Aluno aluno;

    Aluno *alunoPtr = &aluno;

    char operacao = 0;

    while (operacao != 5) {
        limpaConsole();
        printf("Digite a opcao desejada:\n");
        printf("1 - Apresentar todo conteudo do arquivo\n");
        printf("2 - Apresentar conteudo de um registro\n");
        printf("3 - Cadastrar um registro\n");
        printf("4 - Estatísticas\n");
        printf("5 - Fechar o programa\n");
        scanf("%d", &operacao);
        fflush(stdin);

        switch (operacao) {
            case 1:
                imprimirArquivo();
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            case 2:
                printf("Digite o numero do registro que deseja buscar: ");
                scanf("%d", &operacao);
                fflush(stdin);
                buscarNoArquivo(operacao);
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            case 3:
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]", aluno.nome);
                limpaBuffer();
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                limpaBuffer();
                printf("Digite a nota final: ");
                scanf("%f", &aluno.notaFinal);
                limpaBuffer();
                cadastraAluno(alunoPtr);
                break;
            case 4:
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
        }
    }

    return 0;
}

int cadastraAluno(Aluno *aluno) {
    FILE *arquivo;

    arquivo = fopen("arquivo.dat", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 0;
    }

    fwrite(&aluno, sizeof(Aluno), 1, arquivo);

    fclose(arquivo);
    return 1;
}

// int imprimirAluno(Aluno *aluno) {
//     FILE *arquivo;

//     arquivo = fopen("arquivo.dat", "rb");

//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo!");
//         return 0;
//     }

//     while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
//         printf("Nome: %s\n", aluno.nome);
//         printf("Matricula: %d\n", aluno.matricula);
//         printf("Nota final: %f\n", aluno.notaFinal);
//     }

//     fclose(arquivo);
//     return 1;
// }

int imprimirArquivo() {
    FILE *arquivo;
    Aluno aluno;
    Aluno *alunoPtr = &aluno;
    char nome[50];
    int idade;

    arquivo = fopen("arquivo.dat", "ab+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 0;
    }

    // assing to aluno,
    // call imprimirAluno for each entry
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        printf("Nome: %s\n", aluno.nome);
        printf("Matricula: %d\n", aluno.matricula);
        printf("Nota final: %f\n\n\n", aluno.notaFinal);
    }

    fclose(arquivo);
}

int buscarNoArquivo(int numeroMatricula) {
    FILE *arquivo;
    Aluno aluno;
    char nome[50];
    int matricula;
    float notaFinal;

    arquivo = fopen("arquivo.dat", "ab+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 0;
    }

    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (aluno.matricula == numeroMatricula) {
            printf("Nome: %s\n", aluno.nome);
            printf("Matricula: %d\n", aluno.matricula);
            printf("Nota final: %f\n", aluno.notaFinal);
        }
    }

    fclose(arquivo);
}