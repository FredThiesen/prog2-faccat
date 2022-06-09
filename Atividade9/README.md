Utilizando structs, desenvolva um programa em C que armazena registros de alunos de uma turma em arquivo (utilizar modo binário) com os seguintes campos (atributos):

Matrícula
Nome
Nota final

Toda vez que o programa ser executado, ele deverá apresentar o seguinte texto (menu de opções) e perguntar:

Digite a opção desejada:
1 - Apresentar todo conteúdo do arquivo
2 - Apresentar conteúdo de um registro (struct)
3 - Cadastrar um registro
4 - Estatísticas
5 - Fechar o programa

Caso a opção 1 seja escolhida, o programa deverá imprimir em tela todo conteúdo do arquivo, mas de maneira formatada como no seguinte exemplo:

Matrícula: 123456
Nome: Enzo da Silva
Nota final: 8

Matrícula: 123457
Nome: Juliette dos Santos
Nota final: 9

Caso a opção 2 seja escolhida, o usuário irá informar um código de matrícula e o programa deverá imprimir em tela os dados deste registro no seguinte formato de saída:

Matrícula: 123456
Nome: Enzo da Silva
Nota final: 8

Caso não exista registro com o código de matrícula informado pelo usuário, o programa deverá exibir uma mensagem sobre isso e apresentar o menu de opções novamente.

Caso a terceira opção seja escolhida, o usuário deverá cadastrar um novo registro. Se a opção 4 for escolhida, o programa deverá apresentar as seguintes estatísticas da turma:

Quantidade de alunos existentes no arquivo
Média da turma
Nome do aluno com a menor nota
Nome do aluno com a maior nota

Na opção 5 o programa deve ser encerrado. O modo de escrita escolhido deve preservar o conteúdo do arquivo para leituras e escritas futuras.

Para entregar essa atividade submeta os arquivos de código individualmente. Não utilize diretórios compactados (rar, zip, tar.gz, tar.bz2, etc..).
