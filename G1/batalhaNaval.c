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
// se ao final do loop houver algum navio, o jogador 1 venceu (funcao checa se ha navios na matriz)
// se nao houver navios, o jogador 2 venceu

// loop para pedir opcao de jogar novamente ou sair
// se jogar novamente, reinicia o programa

#define NAVIO_TAMANHO 5
#define NAVIO_QTD 3
#define TAMANHO_TABULEIRO 10
#define LINHAS "ABCDEFGHIJ"
const int COLUNAS[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


// funcao para checar se ha navios na matriz
// retorna 1 se houver navios na matriz
// retorna 0 se nao houver navios na matriz
int checaNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    int i, j;
    for(i = 0; i < TAMANHO_TABULEIRO; i++){
        for(j = 0; j < TAMANHO_TABULEIRO; j++){
            if(tabuleiro[i][j] == 1){
                return 1;
            }
        }
    }
    return 0;
}

// funcao para inicializar a matriz de tabuleiro
void inicializaTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    int i, j;
    for(i = 0; i < TAMANHO_TABULEIRO; i++){
        for(j = 0; j < TAMANHO_TABULEIRO; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void imprimeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicionando, int atacando, char *jogador){
    char linhas[] = LINHAS;
    int i, j;
    printf(" ----------------- TABULEIRO -----------------\n\n");
    printf(" Turno do jogador: %s\n\n", jogador);
    if(posicionando){
        printf(" ------------ Posicionando navios ------------\n");
    }else if(atacando){
        printf(" ------------ Atacando navios ------------\n");
    }
    }
    printf("   ");
    for(i = 0; i< TAMANHO_TABULEIRO; i++){
        printf(" %d  ", i + 1);
    }
    printf("\n");
    for(i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%c | ", linhas[i]);
        for(j = 0; j < TAMANHO_TABULEIRO; j++){
            int valor = tabuleiro[i][j];
            char navio = 'n';
            char vazio = '-';
            
            if(valor == 1){
                printf("%c | ", navio);
            }else{
                printf("%c | ", vazio);
            }
        }
        printf("\n");
    }
}

// retorna um array de coordenada, onde o primeiro elemento é
// linha, e o segundo é coluna
int * interpretaPosicao(char *posicao){
    //precisa ser static porque o ponteiro sera usado fora da funcao
    static int posicaoInt[3];

    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        if(toupper(posicao[0]) == LINHAS[i]){
            posicaoInt[0] = i;
        }
    } 
    // isdigit retorna 1 se for número
    if(!isdigit(posicao[2])){
        posicaoInt[1] = COLUNAS[posicao[1] - '0' - 1];
    }
    else{
        posicaoInt[1] = COLUNAS[posicao[2] - '0' - 1] + TAMANHO_TABULEIRO;
    }
    
    return posicaoInt;
}

//checa se uma string de posicao (exemplo: "A1") é valida
int checaStringPosicaoValida(char *posicao){

    printf("checando a string %s\n", posicao);

    if(strlen(posicao) != 2 && strlen(posicao) != 3){
        printf("string invalida por tamanho\n");
        return 0;
    }

// checa se posicao[0] esta entre A e J
    if(!(toupper(posicao[0]) >= 'A' && toupper(posicao[0]) <= 'J')){
        printf("string invalida por letra\n");
        return 0;
    }
// isdigit retorna 1 se for número
    if(!isdigit(posicao[1])){
        printf("string invalida por número\n");
        return 0;
    }

    return 1;
}

int checaPosicaoValida(int direcao, int posicao[2], int tamanhoNavio, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    int linha = posicao[0], coluna = posicao[1];

    if(linha < 0 || linha > 9 || (linha + tamanhoNavio) > 9){
        return 0;
    }
    
    if(coluna < 0 || coluna > 9 || (coluna + tamanhoNavio) > 9){
        return 0;
    }

    if(direcao == 1){
        //horizontal
        // checa se o navio pode ser posicionado a partir dessa posicao  
        for(int i = linha; i <= linha + tamanhoNavio; i++){
            if(tabuleiro[i][coluna] == 1){
                return 0;
            }
        }
    }
    else if(direcao == 2){
        //vertical
        for(int j = linha; j <= coluna + tamanhoNavio; j++){
            if(tabuleiro[linha][j] == 1){
                return 0;
            }
        }
    }
}

// funcao para posicionar um navio na matriz
// tamanho 5
void posicionaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    int linha, coluna;
    char posicao[3];
    int direcao;
    int tamanhoNavio = 5;
    int *posicaoInt;
    int turnoJogador = 1;

    int step = 1;
    //step 1: pedir a posicao e checar se é valida (existe no tabuleiro e esta livre);
    //step 2: pedir a orientacao e checar se é valida (1 ou 2) e se o comprimento (5) é valido;
    
    while(step == 1 || step == 2){
        while(step == 1){
            printf("Digite a posicao do navio (ex: A1): ");
            scanf("%s", posicao);

            if(checaStringPosicaoValida(posicao) == 0){
                printf("Posicao invalida!\n");
                //continue "reinicia" o laço de repeticao
                break;
            } else{
                posicaoInt = interpretaPosicao(posicao);
                linha = posicaoInt[0];
                coluna = posicaoInt[1];
                if(tabuleiro[linha][coluna] != 1){
                    step = 2;
                }
                else{
                    printf("Posicao invalida!\n");
                }
                printf("posicao recebida: %d %d\n", linha, coluna);
            }
            
        };
    
        while(step== 2){
            printf("Digite a direcao do navio (1 para horizontal e 2 para vertical): ");
            scanf("%d", &direcao);

            if(direcao != 1 && direcao != 2){
                printf("Direcao invalida!\n");
            }
            else{
                if(checaPosicaoValida(direcao, posicaoInt, tamanhoNavio, tabuleiro)){
                    step = 3;
                }
            }
                
            if(direcao == 1){
                // horizontal
                if(linha + tamanhoNavio > TAMANHO_TABULEIRO){
                    printf("O navio nao cabe nessa posicao!\n");
                    printf("Por favor, digite outra posicao!\n");
                    step=1;
                    continue;
                }
                for(int j = coluna; j < coluna + tamanhoNavio; j++){
                    tabuleiro[linha][j] = 1;
                }
                step=3;
            }
            else if(direcao == 2){
                //vertical
                if(coluna + tamanhoNavio > TAMANHO_TABULEIRO){
                    printf("O navio nao cabe nessa posicao!\n");
                    printf("Por favor, digite outra posicao!\n");
                    step=1;
                    continue;
                }
                for(int i = linha; i < linha + tamanhoNavio; i++){
                    tabuleiro[i][coluna] = 1;
                }
                step=3;
            } else{
                printf("Direcao invalida!\n");
            }
        };
    }
    

    

    printf("\n");

    imprimeTabuleiro(tabuleiro, turnoJogador);

    printf("\n");
}

int main(void){
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char jogador1[100];
    char jogador2[100];
    char *jogadorAtual;
    int turnoJogador = 1;
    int naviosPosicionados;

    // pede o nome dos jogadores 1x
    printf("Insira o nome do jogador 1: ");
    scanf("%[^\n]s", nomeJogador1);
    fflush(stdin);
    printf("Insira o nome do jogador 2: ");
    scanf("%[^\n]s", nomeJogador2);
    fflush(stdin);

    inicializaTabuleiro(tabuleiro);
    imprimeTabuleiro(tabuleiro, turnoJogador, );

    while(1){
        naviosPosicionados = 0;
        while(naviosPosicionados < NAVIO_QTD){
            posicionaNavio(tabuleiro);
            naviosPosicionados++;
        }
        break;
    }
    printf("navios posicionados");
    turnoJogador = 2;
}