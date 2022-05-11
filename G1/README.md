Atividade

Crie uma matriz de 20 linhas e 20 colunas. As linhas devem ser identificadas por letras e as colunas por números. Tal como mostra o exemplo abaixo:

```
   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | ... | 20 |
A  |   |   |   |   |   |   |   |     |    |
B  |   |   |   |   |   |   |   |     |    |
C  |   |   |   |   |   |   |   |     |    |
D  |   |   |   |   |   |   |   |     |    |
E  |   |   |   |   |   |   |   |     |    |
F  |   |   |   |   |   |   |   |     |    |
G  |   |   |   |   |   |   |   |     |    |
...|   |   |   |   |   |   |   |     |    |
T  |   |   |   |   |   |   |   |     |    |
```

Para esta matriz um jogador (jogador 1) deverá colocar 3 navios. Cada navio tem tamanho 5. Os navios podem ser dispostos na horizontal ou na vertical, a escolha é do jogador 1. A cada escolha do usuário, o programa mostra como está ficando o “mapa”, exibindo a matriz completa, mostrando a localização dos navios dispostos até o momento. Ao final, o programa espera que o jogador 1 pressione a tecla ‘v’ que limpará a tela.

Um segundo jogador (jogador 2), precisará destruir os navios do jogador 1. Para tanto, ele efetua disparos em uma posição da matriz (informando linha e coluna desejadas, e.g. B7). Caso no local informado esteja posicionado um navio, o programa anuncia “Acertou”! Caso não haja nada, o programa anuncia “Errou”! A cada tiro dado nesta segunda parte o programa deve imprimir a matriz completa, revelando as posições de acerto e erro já disparadas pelo jogador 2. Caso este segundo jogador não consiga, com os seus 30 tiros, acertar todas as posições dos 3 navios, o jogador 1 vence da rodada. Do contrário, o jogador 2 é o vencedor.

Ao final de cada rodada o jogo deverá perguntar “Jogar novamente”, ou “Sair”. Caso a primeira opção seja selecionada, o jogador 2 deverá montar o mapa, e o jogador 1 precisará acertar os navios.

O jogo deverá computar e apresentar:

Nome de cada jogador
Quantas rodadas cada jogador ganhou;
Quantos navios cada jogador destruiu (só pode contabilizar caso todas as posições dos navios sejam atingidas);
Quantas posições cada jogador acertou;
