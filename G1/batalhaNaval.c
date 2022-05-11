#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//main
// pede o nome dos jogadores 1x
// entra loop de jogada -> enquanto jogo estiver acontecendo
//     pede a jogada do jogador 1 -> coloca 3 navios (loop de navios) -> cada navio tem tamanho 5
// registra os navios na matriz de tabuleiro
// pede a jogada do jogador 2 (loop de jogadas) (30 tentativas) -> quebra o loop se todos os navios foram destruídos
// se ao final do loop houver algum navio, o jogador 1 venceu (função checa se há navios na matriz)
// se não houver navios, o jogador 2 venceu

// loop para pedir opção de jogar novamente ou sair
// se jogar novamente, reinicia o programa


// função para checar se há navios na matriz
// retorna 1 se houver navios na matriz
// retorna 0 se não houver navios na matriz
int checaNavios(int tabuleiro[10][10]){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(tabuleiro[i][j] == 1){
                return 1;
            }
        }
    }
    return 0;
}

// função para inicializar a matriz de tabuleiro
void inicializaTabuleiro(int tabuleiro[10][10]){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void imprimeTabuleiro(int tabuleiro[10][10]){
    int i, j;
    for(i = 0; i < 10; i++){
        printf(" | ");
        for(j = 0; j < 10; j++){
            printf("%d | ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// retorna um array de coordenada, onde o primeiro elemento é
// linha, e o segundo é coluna
int * interpretaPosicao(char *posicao){
    char linhas[10] = "ABCDEFGHIJ";
    int colunas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    static int posicaoInt[2];

    printf("%s\n", posicao);

    for(int i = 0; i < 10; i++){
        if(toupper(posicao[0]) == linhas[i]){
            posicaoInt[0] = i;
        }
    } 
    posicaoInt[1] = colunas[posicao[1] - '0' - 1];
    return posicaoInt;
}

int checaPosicaoValida(int direcao, int posicao[2], int tabuleiro[10][10]){
    int i, j;
    if(direcao == 1){
        //horizontal
        if(posicao[0] < 0 || posicao[0] > 9){
            return 0;
        }
        if(posicao[1] < 0 || posicao[1] > 9){
            return 0;
        }
        if(tabuleiro[posicao[0]][posicao[1]] == 1){
            return 0;
        }
        //testa se já existe um valor 1 na linha em até 5 casas
       
    }
    else if(direcao == 1){
        //vertical
        if(posicao[0] < 0 || posicao[0] > 9){
            return 0;
        }
        if(posicao[1] < 0 || posicao[1] > 9){
            return 0;
        }
        if(tabuleiro[posicao[0]][posicao[1]] == 1){
            return 0;
        }
    }
}

// função para posicionar um navio na matriz
// tamanho 5
void posicionaNavio(int tabuleiro[10][10]){
    int i, j;
    char posicao[3];
    int direcao;
    int tamanhoNavio = 5;

    printf("Digite a posição do navio (ex: A1): ");
    scanf("%s", posicao);

    int *posicaoInt = interpretaPosicao(posicao);

    printf("%s", posicaoInt[1]);

    printf("Digite a direção do navio (1 para horizontal e 2 para vertical): ");
    scanf("%d", &direcao);

    if(direcao == 1){
        // horizontal
        if(posicaoInt[0] + tamanhoNavio > 10){
            printf("O navio não cabe nessa posição!\n");
            return;
        }
        for(i = posicaoInt[0]; i < posicaoInt[0] + tamanhoNavio; i++){
            tabuleiro[posicaoInt[0]][i] = 1;
        }
    }
    else if(direcao == 2){
        //vertical
        for(j = posicaoInt[1]; j < posicaoInt[1] + tamanhoNavio; j++){
            tabuleiro[j][posicaoInt[1]] = 1;
        }
    } else{
        printf("Direção inválida!\n");
    }

    printf("\n");

    imprimeTabuleiro(tabuleiro);

    printf("\n");
}

int main(void){
    int tabuleiro[10][10];
    int i, j;
    char nomeJogador1[100];
    char nomeJogador2[100];
    int jogadorAtual;
    int jogada;
    int linha, coluna;
    int navio;
    int naviosDestruidos;
    int naviosRestantes;
    int naviosRestantesJogador1;

    // pede o nome dos jogadores 1x
    // printf("Insira o nome do jogador 1: ");
    // scanf("%[^\n]s", nomeJogador1);
    // printf("Insira o nome do jogador 2: ");
    // scanf("%[^\n]s", nomeJogador2);

    inicializaTabuleiro(tabuleiro);

    imprimeTabuleiro(tabuleiro);

    posicionaNavio(tabuleiro);


}