#include "produto.h"

#include <stdio.h>

#include <stdlib.h>

#include "struct.h"

#include <string.h>

void gerenestoque(struct mercadoria * m, int * quantmer, int * quantaloc) {
  int op, k = 0;

  while (k == 0) {
    printf("\n1. Alterar estoque\n2. Cadastrar produto\n3. Excluir produto\n4. Consultar produtos\n5. Voltar\n");
    scanf("%d", & op);

    switch (op) {
    case 1:
      alterar_estoque(m, * quantmer);
      break;
    case 2:
      if ( * quantaloc < * quantmer + 1) {
        * quantaloc += 10;
        m = (struct mercadoria * ) realloc(m, * quantaloc * sizeof(struct mercadoria)); //realoca mem?ria
        if (!m) //Testa se a aloca??o foi bem sucedida
          printf("Memória insuficiente\n");
      }
      * quantmer = adcionar_produto(m, * quantmer);
      break;
    case 3:
      * quantmer = remover_produto(m, * quantmer);
      break;
    case 4:
      consultar_produtos(m, * quantmer);
      break;
    case 5:
      k++;
      break;
    default:
      printf("Opção inválida");
      break;
    }
    //printf("\n\%d\n\n", *quantmer);
  }
  printf("\n\n");

};

void alterar_estoque(struct mercadoria * m, int quantmer) {

  FILE * loja_produto; /* declaraï¿½ï¿½o do ponteiro para arquivo */
  int i, achou, n_produtos;
  char resp;

  loja_produto = fopen("produtos_data.dat", "rb"); /* abre o arquivo para leitura */
  if (loja_produto != NULL) {
    /* jï¿½ existe o arquivo */
    fread( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fread(m, sizeof(struct mercadoria), n_produtos, loja_produto);

    fclose(loja_produto);
  } else
    n_produtos = 0;

  int codigoDaMercadoria = 0;
  int quantidadeDesejada = 0;
  int op = 0;
  char descricao2[100];

  printf("\nInforme o código da mercadoria: ");
  scanf("%d", & codigoDaMercadoria);

  i = 0;
  for (i = 0; i < n_produtos; i++) {

    if (m[i].codigo == codigoDaMercadoria) {

      //printf("MERCADORIA ENCONTRADA\n");

      printf("\nDigite:\n1. para editar a descricao\n2. para quantidade: ");
      scanf("%d", & op);

      if (op == 1) {
        printf("Digite a nova descrição: ");

        setbuf(stdin, NULL);
        gets(descricao2);
        strcpy(m[i].descricao, descricao2);
        printf("\nDescrição atualizada com sucesso.\n\n");

        loja_produto = fopen("produtos_data.dat", "wb"); /* cria o arquivo para escrita */
        if (loja_produto == NULL)
          printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
        else {
          fwrite( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
          fwrite(m, sizeof(struct mercadoria), n_produtos, loja_produto);
          fclose(loja_produto);
        }

        fclose(loja_produto);

        return;
      } else {
        printf("Digite a nova quantidade: ");
        scanf("%d", & quantidadeDesejada);

        m[i].quantidade = quantidadeDesejada;
        printf("\nQuantidade atualizada com sucesso.\n\n");

        loja_produto = fopen("produtos_data.dat", "wb"); /* cria o arquivo para escrita */
        if (loja_produto == NULL)
          printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
        else {
          fwrite( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
          fwrite(m, sizeof(struct mercadoria), n_produtos, loja_produto);
          fclose(loja_produto);
        }

        fclose(loja_produto);

        return;
      }
    }
  }
  printf("MERCADORIA NÃO ENCONTRADA\n");
  fclose(loja_produto);

};

int alterar_estoque_venda(struct mercadoria * m, int quantmer, int quantidadeVenda, int codigoMerc) {

  FILE * loja_produto; /* declaraï¿½ï¿½o do ponteiro para arquivo */
  int i, achou, n_produtos;
  char resp;

  loja_produto = fopen("produtos_data.dat", "rb"); /* abre o arquivo para leitura */
  if (loja_produto != NULL) {
    /* jï¿½ existe o arquivo */
    fread( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fread(m, sizeof(struct mercadoria), n_produtos, loja_produto);

    fclose(loja_produto);
  } else
    n_produtos = 0;

  int codigoDaMercadoria = codigoMerc;
  int quantidadeDesejada = 0;
  int op = 0;
  char descricao2[100];
  int quantidadeNova = 0;

  i = 0;
  for (i = 0; i < n_produtos; i++) {

    if (m[i].codigo == codigoDaMercadoria) {

      //printf("MERCADORIA ENCONTRADA\n");
      quantidadeNova = m[i].quantidade - quantidadeVenda;

      loja_produto = fopen("produtos_data.dat", "wb"); /* cria o arquivo para escrita */
      if (loja_produto == NULL)
        printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
      else {
        fwrite( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
        fwrite(m, sizeof(struct mercadoria), n_produtos, loja_produto);
        fclose(loja_produto);
      }

      fclose(loja_produto);

      if (quantidadeNova < 0) {
        printf("\nQuantidade insuficiente em estoque para realizar venda\n");
        fclose(loja_produto);
        return 1;
      }

      m[i].quantidade = m[i].quantidade - quantidadeVenda;
      //printf("\nQuantidade atualizada com sucesso.\n\n");
      return 0;

    }
  }

  printf("MERCADORIA NÃO ENCONTRADA\n");
  return 1;
};

int adcionar_produto(struct mercadoria * m, int quantmer) {

  FILE * loja_produto; /* declaraï¿½ï¿½o do ponteiro para arquivo */
  int i, achou, n_produtos;
  char resp;

  loja_produto = fopen("produtos_data.dat", "rb"); /* abre o arquivo para leitura */
  if (loja_produto != NULL) {
    /* jï¿½ existe o arquivo */
    fread( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fread(m, sizeof(struct mercadoria), n_produtos, loja_produto);

    fclose(loja_produto);
  } else
    n_produtos = 0;

  int cod = 0, aux = 0;
  i = 0;
  printf("\nInsira o código do produto: ");
  scanf("%d", & cod);

  achou = 0;
  for (i = 0; i < n_produtos && !achou; i++) /* buscando o numero de um aluno */
    if (m[i].codigo == cod) {
      printf("\nO produto ja está cadastrado.");
      achou = 1;
    }

  if (!achou) {
    /* inclui o aluno na ï¿½ltima posiï¿½ï¿½o livre do vetor */
    m[n_produtos].codigo = cod;
    printf("Insira a quantidade em estoque: ");
    scanf("%d", & m[n_produtos].quantidade);
    printf("Insira o nome: ");
    setbuf(stdin, NULL);
    gets(m[n_produtos].nome);
    printf("Insira uma descrição: ");
    setbuf(stdin, NULL);
    gets(m[n_produtos].descricao);
    printf("\nMercadoria cadastrada com sucesso!\n\n");
    n_produtos++;
  }

  loja_produto = fopen("produtos_data.dat", "wb"); /* cria o arquivo para escrita */
  if (loja_produto == NULL)
    printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
  else {
    fwrite( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fwrite(m, sizeof(struct mercadoria), n_produtos, loja_produto);
    fclose(loja_produto);
  }

  fclose(loja_produto);

  //printf("%d\n %d\n %s\n %s\n\n", m[0].codigo, m[0].quantidade, m[0].nome, m[0].descricao); //Teste da aloca??o
  return n_produtos;
};

int remover_produto(struct mercadoria * m, int quantmer) {

  FILE * loja_produto; /* declaraï¿½ï¿½o do ponteiro para arquivo */
  int i, achou, n_produtos;
  char resp;

  loja_produto = fopen("produtos_data.dat", "rb"); /* abre o arquivo para leitura */
  if (loja_produto != NULL) {
    /* jï¿½ existe o arquivo */
    fread( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fread(m, sizeof(struct mercadoria), n_produtos, loja_produto);

    fclose(loja_produto);
  } else
    n_produtos = 0;

  int codigoDaMercadoria = 0;
  int quantidadeDesejada = 0;
  int op = 0;
  int j = 0;
  i = 0;

  printf("\nInforme o codigo da mercadoria: ");
  scanf("%d", & codigoDaMercadoria);

  for (i = 0; i < n_produtos; i++) {

    if (m[i].codigo == codigoDaMercadoria) {

      //printf("MERCADORIA ENCONTRADA\n");

      for (j = i; j < n_produtos; j++) {
        m[j].codigo = m[j + 1].codigo;
        m[j].quantidade = m[j + 1].quantidade;
        strcpy(m[j].nome, m[j + 1].nome);
        strcpy(m[j].descricao, m[j + 1].descricao);
      }

      printf("\nMercadoria excluída\n\n");

      loja_produto = fopen("produtos_data.dat", "wb"); /* cria o arquivo para escrita */
      if (loja_produto == NULL)
        printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
      else {
        fwrite( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
        fwrite(m, sizeof(struct mercadoria), n_produtos, loja_produto);
        fclose(loja_produto);
      }

      fclose(loja_produto);

      n_produtos--;
      return n_produtos;
    }
  }

  loja_produto = fopen("produtos_data.dat", "wb"); /* cria o arquivo para escrita */
  if (loja_produto == NULL)
    printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
  else {
    fwrite( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fwrite(m, sizeof(struct mercadoria), n_produtos, loja_produto);
    fclose(loja_produto);
  }

  fclose(loja_produto);

  printf("MERCADORIA NÃO ENCONTRADA\n");
  return n_produtos;
};

int consultar_produtos(struct mercadoria * m, int quantmer) {

  FILE * loja_produto; /* declaraï¿½ï¿½o do ponteiro para arquivo */
  int i, achou, n_produtos;
  char resp;

  loja_produto = fopen("produtos_data.dat", "rb"); /* abre o arquivo para leitura */
  if (loja_produto != NULL) {
    /* jï¿½ existe o arquivo */
    fread( & n_produtos, sizeof(int), 1, loja_produto); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
    fread(m, sizeof(struct mercadoria), n_produtos, loja_produto);

    fclose(loja_produto);
  } else
    n_produtos = 0;

  int codigo = 0;
  int op = 0;
  i = 0;
  char nome[200];

  printf("\nDigite:\n1. para procurar por nome\n2. por codigo: ");
  scanf("%d", & op);

  if (op == 1) {
    printf("Digite o nome que seja buscar : ");
    setbuf(stdin, NULL);
    gets(nome);

    for (i = 0; i < n_produtos; i++) {

      if (strcmp(m[i].nome, nome) == 0) {

        printf("\nNome: %s\n", m[i].nome);
        printf("Quantidade: %d\n", m[i].quantidade);
        printf("Código: %d\n", m[i].codigo);
        printf("Descrição: %s\n", m[i].descricao);

        fclose(loja_produto);

        return;
      }

    }
    printf("PRODUTO NÃO ENCONTRADO\n");
    fclose(loja_produto);
    return n_produtos;
  }

  if (op == 2) {
    printf("Digite o codigo que seja buscar : ");
    setbuf(stdin, NULL);
    scanf("%d", & codigo);

    for (i = 0; i < n_produtos; i++) {

      if (m[i].codigo == codigo) {

        printf("\nNome: %s\n", m[i].nome);
        printf("Quantidade: %d\n", m[i].quantidade);
        printf("Código: %d\n", m[i].codigo);
        printf("Descrição: %s\n", m[i].descricao);

        fclose(loja_produto);

        return;
      }

    }
    printf("PRODUTO NÃO ENCONTRADO\n");
    fclose(loja_produto);
    return n_produtos;
  }

  if (op < 1 || op > 2) {
    printf("\n Opção invalida!\n");
    fclose(loja_produto);
    return;
  }

};
