//Header das funções relacionadas a cliente

// Evita problemas com inclusão duplicada na utilização de #include
#ifndef PROJETO_FTGAMING_CLIENTE_H
#define PROJETO_FTGAMING_CLIENTE_H
#include "struct.h"



void gerenclientes(struct cliente *c, int *numcli, int *numclialoc);

void alterar_cliente(struct cliente *c, int numcli);
int adcionar_cliente(struct cliente *c, int numcli);
int excluir_cliente(struct cliente *c, int numcli);
int verifica_se_cliente_existe (struct cliente *c, int numcli, int cpf);
void consultar_cliente(struct cliente *c, int numcli);


//void printarcli(struct cliente *c);

#endif //PROJETO_FTGAMING_CLIENTE_H
