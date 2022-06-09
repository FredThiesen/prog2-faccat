#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
        int id;
		char nome[50];
		int matricula;
		float notaFinal;
	}Aluno ;

void limpaBuffer();
void imprimeArquivo(FILE* arquivo);
void imprimeRegistro(FILE* arquivo);
void adicionaRegistro(FILE* arquivo, Aluno aluno);
void imprimeAlunoFormatado(Aluno aluno);
void calculaEstatisticas(FILE* arquivo);
int main()
{
    Aluno aluno1;

    int opcao;
    printf("1-Apresentar todo conteúdo do arquivo\n2-Apresentar conteúdo de um registro\n3-Cadastrar um registro\n4-Estatisticas\n5-Fechar o programa\n");
    scanf("%d", &opcao);
    limpaBuffer();

    FILE *arquivo ;

    while(opcao!=5){

        switch(opcao){
            case 1: imprimeArquivo(arquivo);
            break;
            case 2: imprimeRegistro(arquivo);
            break;
            case 3: adicionaRegistro(arquivo, aluno1);
            break;
            case 4: calculaEstatisticas(arquivo);
            break;
        }
        printf("\n...Digite algo para continuar");
        getchar();
        limpaBuffer();
        printf("\n\n1-Apresentar todo conteúdo do arquivo\n2-Apresentar conteúdo de um arquivo\n3-Cadastrar um registro\n4-Fechar o programa\n");
        scanf("%d", &opcao);
        limpaBuffer();

    }


    return 0;
}
void imprimeArquivo(FILE* arquivo){
    system("clear||cls");
    arquivo = fopen("arquivo.dat", "ab+") ;

    Aluno aluno;

	if ( arquivo == NULL ) {
		printf( "Nao foi possivel abrir arquivo." ) ;
	} else {
		while(fread(&aluno, sizeof(Aluno), 1, arquivo)) {
		imprimeAlunoFormatado(aluno);
	}
    }
    fclose(arquivo);
}

void imprimeRegistro(FILE* arquivo){
    system("clear||cls");
     arquivo = fopen("arquivo.dat", "ab+") ;

      Aluno aluno;

     printf("Digite o numero da matrícula que quer procurar: ");
     int registro;
     scanf("%d",&registro);
     limpaBuffer();
     int flag=0;
        if ( arquivo == NULL ) {
            printf( "Nao foi possivel abrir arquivo." ) ;
        } else {
            while(fread(&aluno, sizeof(Aluno), 1, arquivo)) {
            if(aluno.matricula==registro){
                imprimeAlunoFormatado(aluno);
                flag=1;
            }

        }
        }
        if(!flag){
            printf("Numero de matricula nao encontrado!\n");
        }
    fclose(arquivo);
}
void adicionaRegistro(FILE* arquivo, Aluno aluno){
    arquivo = fopen("arquivo.dat", "ab") ;

    printf("Digite o nome do aluno: ");
    scanf("%[^\n]",aluno.nome);
    limpaBuffer();
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno.matricula);
    limpaBuffer();
    printf("Digite a nota final: ");
    scanf("%f",&aluno.notaFinal);
     limpaBuffer();

    if ( arquivo == NULL ) {
		printf( "Nao foi possivel abrir arquivo." ) ;
	} else {
	  fwrite (&aluno, sizeof(Aluno), 1, arquivo);
    }
    system("clear||cls");
    printf("Registro adicionado!!\n");
    fclose(arquivo);
}
void limpaBuffer(){
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
void imprimeAlunoFormatado(Aluno aluno){
    printf("Matricula: %d\nNome: %s\nNota final: %.2f\n\n",aluno.matricula, aluno.nome, aluno.notaFinal);
}
void calculaEstatisticas(FILE* arquivo){
    system("clear||cls");
    arquivo = fopen("arquivo.dat", "ab+") ;

    Aluno aluno;
    int quantidadeAlunos=0;
    float media=0.0;
    Aluno piorAluno, melhorAluno;
    piorAluno.notaFinal=10.1;
    melhorAluno.notaFinal=0;


	if ( arquivo == NULL ) {
		printf( "Nao foi possivel abrir arquivo." ) ;
	} else {
		while(fread(&aluno, sizeof(Aluno), 1, arquivo)) {
		quantidadeAlunos++;
		media+=aluno.notaFinal;
        if(aluno.notaFinal>melhorAluno.notaFinal){
            melhorAluno=aluno;
        }
        if(aluno.notaFinal<piorAluno.notaFinal){
            piorAluno=aluno;
        }

	}
    }

    printf("Quandidade de alunos no arquivo: %d\n",quantidadeAlunos);
    printf("Media da turma: %.2f\n",media/quantidadeAlunos);
    printf("Nome do pior aluno: %s\n",piorAluno.nome);
    printf("Nome do melhor aluno: %s\n",melhorAluno.nome);
    fclose(arquivo);

}
