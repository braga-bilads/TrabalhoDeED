#ifndef SW_H
#define SW_H

//  Tipo que define streamWriter (tipo opaco)
typedef struct streamWriter* StreamWriter;

/* 
 * Aloca memoria para o streamWriter e o inicializa
 * inputs: caminho do diretorio a ser aberto para escrita
 * output: streamWriter criado
 * pre-condicao: o caminho do diretorio existe e nao necessita
 *               ter sido alocado dinamicamente
 * pos-condicao: streamWriter alocado e inicializado
 */
StreamWriter CriarStreamWriter(char *path);

/* 
 * Libera memoria alocada para o streamWriter
 * inputs: streamWriter
 * output: nenhum
 * pre-condicao: streamWriter existe
 * pos-condicao: toda a memoria alocada para streamWriter foi liberada
 */
void DeletarStreamWriter(StreamWriter sw);

/* 
 * Escreve uma linha no arquivo referente ao streamWriter
 * inputs: streamWriter e string a ser escrita
 * output: nenhum
 * pre-condicao: streamWriter e string existem
 * pos-condicao: a string foi escrita no arquivo referente ao streamWriter
 */
void WriteLine(StreamWriter sw, char *string);

#endif