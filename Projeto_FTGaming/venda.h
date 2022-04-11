//Header das funções relacionadas a venda

// Evita problemas com inclusão duplicada na utilização de #include
#ifndef PROJETO_FTGAMING_VENDA_H
#define PROJETO_FTGAMING_VENDA_H
#include "struct.h"
int realizarvenda(struct vendas *v, int vendas, int quantidadeVenda , int codigoMerc, int cpf);


void listarvendas(struct vendas *v, int vendas);

#endif //PROJETO_FTGAMING_VENDA_H
