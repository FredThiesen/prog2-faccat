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
int cadastrarAluno(Aluno *aluno);
int buscarNoArquivo(int numeroRegistro);
void imprimirAluno(Aluno aluno);
int imprimirEstatisticas();

// limpa o console, funciona para windows e linux
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
                printf("Digite o numero da matricula do aluno que deseja buscar: ");
                scanf("%d", &aluno.matricula);
                fflush(stdin);
                buscarNoArquivo(aluno.matricula);
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            case 3:
                printf("Digite o nome do aluno: ");
                scanf("%[^\n]", aluno.nome);
                fflush(stdin);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                fflush(stdin);
                printf("Digite a nota final: ");
                scanf("%f", &aluno.notaFinal);
                fflush(stdin);
                cadastrarAluno(alunoPtr);
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            case 4:
                imprimirEstatisticas();
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            case 5:
                printf("\nFechando o programa...\n");
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
        }
    }

    return 0;
}

int cadastrarAluno(Aluno *aluno) {
    FILE *arquivo;
    arquivo = fopen("arquivo.dat", "ab+");

    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.");
        fclose(arquivo);
        return 0;
    } else {
        fwrite(aluno, sizeof(Aluno), 1, arquivo);
        fclose(arquivo);
        printf("\nAluno cadastrado com sucesso!\n");
        return 1;
    }
}

void imprimirAluno(Aluno aluno) {
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nota final: %.2f\n\n", aluno.notaFinal);
}

int imprimirArquivo() {
    FILE *arquivo;
    Aluno aluno;

    arquivo = fopen("arquivo.dat", "ab+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        fclose(arquivo);
        return 0;
    }

    // assing to aluno,
    // call imprimirAluno for each entry
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        imprimirAluno(aluno);
    }

    fclose(arquivo);
}

int buscarNoArquivo(int numeroMatricula) {
    FILE *arquivo;
    Aluno aluno;
    int alunoEncontrado = 0;

    arquivo = fopen("arquivo.dat", "ab+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        fclose(arquivo);
        return 0;
    }

    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        if (aluno.matricula == numeroMatricula) {
            imprimirAluno(aluno);
            fclose(arquivo);
            return 1;
        }
    }

    if (!alunoEncontrado) {
        printf("Aluno nao encontrado!");
    }

    fclose(arquivo);
}

int imprimirEstatisticas() {
    FILE *arquivo;
    Aluno aluno;

    arquivo = fopen("arquivo.dat", "ab+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        fclose(arquivo);
        return 0;
    }
    // Quantidade de alunos existentes no arquivo
    // Média da turma
    // Nome do aluno com a menor nota
    // Nome do aluno com a maior nota

    int quantidadeAlunos = 0;
    float somaNotas = 0;
    float media = 0;
    float notaMenor = 100.1;
    float notaMaior = -0.1;
    char nomeMenor[50];
    char nomeMaior[50];

    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        quantidadeAlunos++;
        somaNotas += aluno.notaFinal;
        if (aluno.notaFinal < notaMenor) {
            notaMenor = aluno.notaFinal;
            strcpy(nomeMenor, aluno.nome);
        }
        if (aluno.notaFinal > notaMaior) {
            notaMaior = aluno.notaFinal;
            strcpy(nomeMaior, aluno.nome);
        }
    }

    if (quantidadeAlunos == 0) {
        printf("Nao ha alunos cadastrados no arquivo!");
    } else if (quantidadeAlunos == 1) {
        printf("media da turma: %.2f\n", somaNotas);
        printf("aluno com a menor nota: %s\n", nomeMaior);
        printf("aluno com a maior nota: %s\n", nomeMaior);
    } else {
        media = somaNotas / quantidadeAlunos;
        printf("Quantidade de alunos: %d\n", quantidadeAlunos);
        printf("Media da turma: %.2f\n", media);
        printf("Aluno com a menor nota: %s\n", nomeMenor);
        printf("Aluno com a maior nota: %s\n", nomeMaior);
    }

    fclose(arquivo);
    return 1;
}