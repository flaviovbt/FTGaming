//Header das funções relacionadas a produto

// Evita problemas com inclusão duplicada na utilização de #include
#ifndef PROJETO_FTGAMING_PRODUTO_H
#define PROJETO_FTGAMING_PRODUTO_H
#include "struct.h"

void gerenestoque(struct mercadoria *m, int *quantmer, int *quantaloc);

void alterar_estoque(struct mercadoria *m, int quantmer);
int adcionar_produto(struct mercadoria *m, int quantmer);
int remover_produto(struct mercadoria *m, int quantmer);
int consultar_produtos(struct mercadoria *m, int quantmer);
int alterar_estoque_venda(struct mercadoria *m, int quantmer, int quantidadeVenda, int codigoMerc);


#endif //PROJETO_FTGAMING_PRODUTO_H
