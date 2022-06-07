#ifndef SW_H
#define SW_H

typedef struct streamWriter* StreamWriter;

/* 
 * Aloca memoria para o streamWriter e o inicializa
 * inputs: o caminho do diretorio a ser aberto para escrita
 * output: o streamWriter criado
 * pre-condicao: o caminho do diretorio ser valido
 */
StreamWriter CriarStreamWriter(char *path);

/* 
 * Libera memoria alocada para o streamWriter
 * inputs: o streamWriter
 * output: nenhum
 * pre-condicao: o streamWriter existe
 */
void DeletarStreamWriter(StreamWriter sw);

/* 
 * Escreve uma linha no arquivo referente ao streamWriter
 * inputs: o streamWriter e a string a ser escrita
 * output: nenhum
 * pre-condicao: o streamWriter existe
 */
void WriteLine(StreamWriter sw, char *string);

#endif