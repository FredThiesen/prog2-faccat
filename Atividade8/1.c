#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerArquivo(char *nomeArquivo);
void cadastraPessoa(char nome[], int idade);
void buscarNoArquivo(int numeroRegistro);

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
    struct ficha_funcionario {
        char nome[50];
        int idade;
    };

    struct ficha_funcionario funcionario[100];

    char operacao = 0;

    while (operacao != 4) {
        limpaConsole();
        printf("Digite a opcao desejada:\n");
        printf("1 - Apresentar todo conteudo do arquivo\n");
        printf("2 - Apresentar conteudo de um registro\n");
        printf("3 - Cadastrar um registro\n");
        printf("4 - Fechar o programa\n");
        scanf("%d", &operacao);
        fflush(stdin);

        switch (operacao) {
            case 1:
                lerArquivo("arquivo.txt");
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
                printf("Digite o nome do funcionario: ");
                scanf("%s", funcionario[operacao].nome);
                fflush(stdin);
                printf("Digite a idade do funcionario: ");
                scanf("%d", &funcionario[operacao].idade);
                fflush(stdin);
                cadastraPessoa(funcionario[operacao].nome, funcionario[operacao].idade);
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            case 4:
                printf("Fechando o programa...");
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
            default:
                printf("Opcao invalida!");
                printf("\nPressione qualquer tecla para continuar\n");
                getchar();
                break;
        }
    }

    return (0);
}

void cadastraPessoa(char nome[], int idade) {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "a");
    fprintf(arquivo, "%s, %d\n", nome, idade);
    fclose(arquivo);
}

void lerArquivo(char *nomeArquivo) {
    FILE *arquivo;
    int impressos = 0;
    arquivo = fopen(nomeArquivo, "r");
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL) {
        printf("%s", linha);
        impressos++;
    }
    if (feof(arquivo)) {
        printf("O arquivo esta vazio.");
    }
    fclose(arquivo);
}

void buscarNoArquivo(int numeroRegistro) {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");
    char linha[100];
    int contador = 0;
    while (fgets(linha, 100, arquivo) != NULL) {
        contador++;
        if (contador == numeroRegistro) {
            printf("Nome: ");
            for (int i = 0; i < strlen(linha); i++) {
                if (linha[i] == ',') {
                    printf("\n");
                    printf("Idade: ");
                } else {
                    printf("%c", linha[i]);
                }
            }
            break;
        }
    }
    fclose(arquivo);
}