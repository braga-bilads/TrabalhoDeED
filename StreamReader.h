#ifndef SR_H
#define SR_H

typedef struct streamReader* StreamReader;

/* 
 * Aloca memoria para o streamReader e o inicializa
 * inputs: o caminho do diretorio a ser aberto para leitura
 * output: o streamReader criado
 * pre-condicao: o caminho do diretorio ser valido
 */
StreamReader CriarStreamReader(char *path);

/* 
 * Retorna o atributo endOfStream referente ao streamReader
 * inputs: o streamReader
 * output: o atributo endOfStream
 * pre-condicao: o streamReader existe
 */
int RecuperaEndOfStream(StreamReader sr);

/* 
 * Libera memoria alocada para o streamReader
 * inputs: o streamReader
 * output: nenhum
 * pre-condicao: o streamReader existe
 */
void DeletarStreamReader(StreamReader sr);

/* 
 * Le uma linha do arquivo referente ao streamReader
 * inputs: o streamReader
 * output: a string respectiva a linha lida
 * pre-condicao: o streamReader existe
 */
char *ReadLine(StreamReader sr);

#endif