int imprimirAluno(Aluno *aluno) {
//     FILE *arquivo;

//     arquivo = fopen("arquivo.dat", "rb");

//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo!");
//         return 0;
//     }

//     while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
//         printf("Nome: %s\n", aluno.nome);
//         printf("Matricula: %ld\n", aluno.matricula);
//         printf("Nota final: %d\n", aluno.notaFinal);
//     }

//     fclose(arquivo);
//     return 1;
// }