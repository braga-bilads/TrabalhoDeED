#ifndef SR_H
#define SR_H

//  Tipo que define streamReader (tipo opaco)
typedef struct streamReader* StreamReader;

/* 
 * Aloca memoria para o streamReader e o inicializa
 * inputs: caminho do diretorio a ser aberto para leitura
 * output: streamReader criado
 * pre-condicao: o caminho do diretorio existe e nao necessita
 *               ter sido alocado dinamicamente
 * pos-condicao: streamReader alocado e inicializado
 */
StreamReader CriarStreamReader(char *path);

/* 
 * Retorna o atributo endOfStream referente ao streamReader
 * inputs: streamReader
 * output: atributo endOfStream
 * pre-condicao: streamReader existe
 * pos-condicao: streamReader nao e modificado
 */
int RecuperaEndOfStream(StreamReader sr);

/* 
 * Libera memoria alocada para o streamReader
 * inputs: streamReader
 * output: nenhum
 * pre-condicao: streamReader existe
 * pos-condicao: toda a memoria alocada para streamReader foi liberada
 */
void DeletarStreamReader(StreamReader sr);

/* 
 * Le uma linha do arquivo referente ao streamReader
 * inputs: streamReader
 * output: string respectiva a linha lida
 * pre-condicao: streamReader existe
 * pos-condicao: a string retornada foi alocada dinamicamente
 */
char *ReadLine(StreamReader sr);

#endif