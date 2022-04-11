//Header das funções relacionadas a cliente

// Evita problemas com inclusão duplicada na utilização de #include
#ifndef PROJETO_FTGAMING_STRUCT_H
#define PROJETO_FTGAMING_STRUCT_H

struct mercadoria {
    int codigo, quantidade;
    char descricao[100], nome[100];
};

struct cliente {
    int tel, cpf, codigoC;
    char nome[200];
};

struct vendas {
    int codVenda, codcliente, codproduto, formpagamento, quantvendida;
};

#endif //PROJETO_FTGAMING_CLIENTE_H
