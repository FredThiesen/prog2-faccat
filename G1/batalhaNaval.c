#include <stdio.h>
#include <stdlib.h>
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
// se jogar novamente, reinicia o programa e troca os jogadores

#define NAVIO_TAMANHO 5
#define NAVIO_QTD 3
#define TENTATIVAS_QTD 30
#define TAMANHO_TABULEIRO 20

// se você alterar o tamanho do tabuleiro, altere as linhas e colunas abaixo.
#define LINHAS "ABCDEFGHIJKLMNOPQRST"
const int COLUNAS[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};


// funcao para checar se ha navios na matriz
// retorna 1 se houver navios não destruídos na matriz
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

// limpa o console, funciona para windows e linux
void limpaConsole(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
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

void imprimeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int posicionando, char *jogador){
    char linhas[] = LINHAS;
    int i, j;
    char navio, navioAtingido, tiroErrado, vazio;
    limpaConsole();
    printf(" ----------------- TABULEIRO -----------------\n\n");
    printf(" Turno do jogador: %s\n\n", jogador);
    if(posicionando){
        navio = 'N';
        vazio = '-';
        printf(" ------------ Posicionando navios ------------\n");
    }else{
        navioAtingido = 'X';
        tiroErrado = '?';
        vazio = '-';
        printf(" ------------ Atacando navios ------------\n");
    }
    printf("   ");
    for(i = 0; i< TAMANHO_TABULEIRO; i++){
        if(i < 9){
            printf(" %d  ", i+1);
        }else{
            printf(" %d ", i+1);
        }
    }
    printf("\n");
    for(i = 0; i < TAMANHO_TABULEIRO; i++){
        printf("%c |", linhas[i]);
        for(j = 0; j < TAMANHO_TABULEIRO; j++){
            int valor = tabuleiro[i][j];
            
            switch(valor){
                case 0:
                    printf(" %c ", vazio);
                    break;
                case 1:
                    if(posicionando){
                        printf(" %c ", navio);
                    }else{
                        printf(" %c ", vazio);
                    }
                    break;
                case 2:
                    printf(" %c ", navioAtingido);
                    break;
                case 3:
                    printf(" %c ", tiroErrado);
                    break;
                default:
                    break;
            }

            printf("|");
        }
        printf("\n");
    }
}

int concatenaDoisInteiros(int a, int b){
    char str[10];
    sprintf(str, "%d%d", a, b);
    return atoi(str);
}
// retorna um array de coordenada, onde o primeiro elemento é
// linha, e o segundo é coluna
int * interpretaPosicao(char *posicao){
    //precisa ser static porque o ponteiro sera usado fora da funcao
    static int posicaoInt[2];

    for(int i = 0; i < TAMANHO_TABULEIRO; i++){
        if(toupper(posicao[0]) == LINHAS[i]){
            posicaoInt[0] = i;
        }
    } 
    // isdigit retorna 1 se for número
    if(!isdigit(posicao[2])){
        posicaoInt[1] = COLUNAS[posicao[1] - '0' - 1];
    }else{
        int c = concatenaDoisInteiros(posicao[1] - '0', posicao[2] - '0');
        posicaoInt[1] = c - 1;
    }
    
    return posicaoInt;
}

//checa se uma string de posicao (exemplo: "A1") é valida
int checaStringPosicaoValida(char *posicao){

    char primeiraLinha = LINHAS[0];
    char ultimaLinha = LINHAS[TAMANHO_TABULEIRO - 1];

    if(strlen(posicao) != 2 && strlen(posicao) != 3){
        //posicao invalida por tamanho
        return 0;
    }

    // checa se posicao[0] esta entre a primeira e a ultima letra de LINHAS
    if(!(toupper(posicao[0]) >= primeiraLinha && toupper(posicao[0]) <= ultimaLinha)){
        //posicao invalida por letra\n
        return 0;
    }

    // isdigit retorna 1 se for número
    if(!isdigit(posicao[1])){
        //posicao invalida por número
        return 0;
    }

    if(strlen(posicao) == 3 && !isdigit(posicao[2])){
        return 0;
    }
    if(isdigit(posicao[2])){
        int c = concatenaDoisInteiros(posicao[1] - '0', posicao[2] - '0');
        if(c > TAMANHO_TABULEIRO){
            return 0;
        }
    }
            

    return 1;
}

// checa se o navio cabe na posiço
int checaPosicaoValida(int direcao, int posicao[2], int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    int linha = posicao[0], coluna = posicao[1];

    if(linha < 0 || linha > TAMANHO_TABULEIRO - 1){
        return 0;
    }
    
    if(coluna < 0 || coluna > TAMANHO_TABULEIRO - 1){
        return 0;
    }

    if(direcao == 1){
        //horizontal
        if((coluna + NAVIO_TAMANHO) > TAMANHO_TABULEIRO){
            //navio no cabe no tabuleiro
            return 0;
        }
    }

    if(direcao == 2){
        //vertical
        if((linha + NAVIO_TAMANHO) > TAMANHO_TABULEIRO){
            //navio no cabe no tabuleiro
            return 0;
        }
    }

    if(direcao == 1){
        //horizontal
        // checa se o navio pode ser posicionado a partir dessa posicao  
        for(int j = coluna; j <= coluna + NAVIO_TAMANHO; j++){
            if(tabuleiro[linha][j] == 1){
                return 0;
            }
        }
    }
    else if(direcao == 2){
        //vertical
        for(int i = linha; i <= linha + NAVIO_TAMANHO; i++){
            if(tabuleiro[i][coluna] == 1){
                return 0;
            }
        }
    }

    return 1;
}

// funcao para posicionar um navio na matriz
// tamanho 5
void posicionaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], char *jogadorAtual){
    int linha, coluna;
    char posicao[3];
    int direcao;
    int *posicaoInt;
    int step = 1;
    //step 1: pedir a posicao e checar se é valida (existe no tabuleiro e esta livre);
    //step 2: pedir a orientacao e checar se é valida (1 ou 2) e se o comprimento (5) é valido;
    
    while(step == 1 || step == 2){
        while(step == 1){
            imprimeTabuleiro(tabuleiro, 1, jogadorAtual);
            printf("\nDigite a posicao do navio (ex: A1): \n");
            scanf("%s", posicao);
            fflush(stdin);

            if(!checaStringPosicaoValida(posicao)){
                printf("Posicao invalida! Pressione qualquer tecla para continuar: \n");
                getchar();
            } else{
                posicaoInt = interpretaPosicao(posicao);
                linha = posicaoInt[0];
                coluna = posicaoInt[1];
                if(tabuleiro[linha][coluna] != 1){
                    step = 2;
                }else{
                    printf("Posicao invalida! Pressione qualquer tecla para continuar: \n");
                    getchar();
                }     
            }
        };
    
        while(step== 2){
            imprimeTabuleiro(tabuleiro, 1, jogadorAtual);
            
            printf("\nDigite a direcao do navio: \n");
            printf("1 - HORIZONTAL\n");
            printf("2 - VERTICAL\n");
            scanf("%d", &direcao);
            fflush(stdin);

            if(direcao != 1 && direcao != 2){
                printf("Direcao invalida!\n");
                printf("\nPressione qualquer tecla para continuar: \n");
                getchar();
                continue;
            }else{
                if(!checaPosicaoValida(direcao, posicaoInt, tabuleiro)){
                    printf("O navio nao cabe nessa posicao!\n");
                    printf("Por favor, digite outra posicao!\n");
                    printf("\nPressione qualquer tecla para continuar: \n");
                    getchar();
                    step=1;
                    continue;
                }
            }
                
            if(direcao == 1){
                //horizontal
                for(int j = coluna; j < coluna + NAVIO_TAMANHO; j++){
                    tabuleiro[linha][j] = 1;
                }
                step=3;
            }else if(direcao == 2){
                //vertical
                for(int i = linha; i < linha + NAVIO_TAMANHO; i++){
                    tabuleiro[i][coluna] = 1;
                }
                step=3;
            }
        };
    }
}

void atacaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], char *jogadorAtual, int tentativa){
    int linha, coluna;
    char posicao[3];
    int *posicaoInt;
    int acertou = 0;
    int step = 1;

    while(step == 1){
        imprimeTabuleiro(tabuleiro, 0, jogadorAtual);
        printf("\n TENTATIVA %d\n", tentativa);
        printf("\nDigite a posicao do tiro (ex: A1): \n");
        scanf("%s", posicao);
        fflush(stdin);

        if(!checaStringPosicaoValida(posicao)){
            printf("\nPosicao invalida! Pressione qualquer tecla para continuar: \n");
            getchar();
        } else{
            posicaoInt = interpretaPosicao(posicao);
            linha = posicaoInt[0];
            coluna = posicaoInt[1];
            if(tabuleiro[linha][coluna] == 1){
                acertou = 1;
                step = 2;
            }else if(tabuleiro[linha][coluna] == 2 || tabuleiro[linha][coluna] == 3){
                printf("\nVoce ja atirou nessa posicao, tente novamente! \n");
                printf("\nPressione qualquer tecla para continuar: \n");
                getchar();
            }else if(tabuleiro[linha][coluna] == 0){
                acertou = 0;
                step = 2;
            }else{
                printf("Posicao invalida! Pressione qualquer tecla para continuar: \n");
                getchar();
            }   
        }
    };
            
    if(acertou){
        tabuleiro[linha][coluna] = 2;
        imprimeTabuleiro(tabuleiro, 0, jogadorAtual);
        printf("\nAcertou!\n");
        printf("\nPressione qualquer tecla para continuar: \n");
        getchar();
    }else{
        tabuleiro[linha][coluna] = 3;
        imprimeTabuleiro(tabuleiro, 0, jogadorAtual);
        printf("\nVoce errou!\n");
        printf("\nPressione qualquer tecla para continuar: \n");
        getchar();
    }
    step = 3;
}

char *trocaJogador (char *jogadorAtual, char jogador1[], char jogador2[]){
    if(strcmp(jogadorAtual, jogador1) == 0){
        return jogador2;
    }else{
        return jogador1;
    }
}

int main(void){
    // posição do tabuleiro pode ter 4 valores:
    // 0 - sem navio
    // 1 - com navio
    // 2 - navio atingido
    // 3 - tiro errado
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char nomeJogador1[100];
    char nomeJogador2[100];
    char *jogadorAtual;
    int opcao = 1; // 1 - jogar novamente, 2 - sair
    int vencedor = 0; // 1 - jogador 1 venceu, 2 - jogador 2 venceu

    // 1 enquanto jogador está posicionando navios, 0 enquanto está atacando
    int posicionando = 1;
    int naviosPosicionados;

    // pede o nome dos jogadores 1x
    printf("Insira o nome do jogador 1: ");
    scanf("%[^\n]s", nomeJogador1);
    fflush(stdin);
    printf("Insira o nome do jogador 2: ");
    scanf("%[^\n]s", nomeJogador2);
    fflush(stdin);

    jogadorAtual = nomeJogador1;

    while(opcao == 1){
        inicializaTabuleiro(tabuleiro);

        //
        // Seção de posicionar navios
        posicionando = 1;
        naviosPosicionados = 0;
        while(naviosPosicionados < NAVIO_QTD){
            posicionaNavio(tabuleiro, jogadorAtual);
            naviosPosicionados++;
        }
        imprimeTabuleiro(tabuleiro, 1, jogadorAtual);
        printf("\nNavios posicionados! Pressione qualquer tecla para continuar: \n");
        getchar();
        posicionando = 0;

        jogadorAtual = trocaJogador(jogadorAtual, nomeJogador1, nomeJogador2);

        //
        // Seção de atacar navios
        for(int tentativa = 1; tentativa <= TENTATIVAS_QTD; tentativa++){
            atacaNavio(tabuleiro, jogadorAtual, tentativa);
            //checa se tem navio ou se as tentativas acabaram
            if(!checaNavios(tabuleiro)){
                printf("\nParabens %s, voce venceu!\n", jogadorAtual);
                vencedor = 1;
                break;
            }
        }
        if(!vencedor){
            printf("\n%s, voce perdeu!\n", jogadorAtual);
        }
        do{
            printf("\nDeseja jogar novamente?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao);
            fflush(stdin);
            if(opcao != 1 && opcao != 2){
                printf("\nOpcao invalida!\n");
            }
        }while(opcao != 1 && opcao != 2);
        if(opcao == 2){
            break;
        }
    }
    printf("fim de jogo");
    printf("pressione qualquer tecla para continuar: ");
    getchar();
    return 0;
}