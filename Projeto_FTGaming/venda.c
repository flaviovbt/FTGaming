#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

int realizarvenda(struct vendas *v, int vendas, int quantidadeVenda , int codigoMerc, int cpf) {
	
  FILE *loja;        /* declara��o do ponteiro para arquivo */ 
  int i, achou, n_vendas;
  char resp;

  loja = fopen("vendas_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* j� existe o arquivo */
    fread(&n_vendas, sizeof(int), 1, loja); /* a primeira linha do arquivo cont�m o n�mero de registros j� gravados */ 
	fread(v, sizeof(struct vendas), n_vendas, loja);
    fclose(loja);
  }
  else
  	n_vendas = 0;
	
	
	int codVenda,
	    codcliente,
	    codproduto,
	    formpagamento,
	    quantvendida;
	
	
	if (!cpf) {
    printf("\nInsira o codigo do cliente: ");
    scanf("%d", &codcliente);
	}
	codproduto = codigoMerc;

    printf("Insira a forma de pagamento: ");
    scanf("%d", &formpagamento);
	



        v[n_vendas].codcliente= codcliente;
        v[n_vendas].codproduto= codproduto;
        v[n_vendas].formpagamento= formpagamento;
        v[n_vendas].quantvendida= quantidadeVenda;
        v[n_vendas].codVenda=vendas;
        
        
        
        printf("\nVenda registrada com sucesso! , o c�digo da venda � : %d\n", n_vendas );
		n_vendas++;
		
                     loja = fopen("vendas_data.dat", "wb");  /* cria o arquivo para escrita */
					  if (loja == NULL)
					   printf("\nErro na criacao do arquivo. N�o foi poss�vel gravar os registros.");
					  else {
					  	fwrite(&n_vendas, sizeof(int), 1, loja); /* a primeira linha do arquivo cont�m o n�mero de registros j� gravados */
						fwrite(v, sizeof(struct vendas), n_vendas, loja);
						fclose(loja);
					  }
        
                fclose(loja);
	
    
    //printf("%d %d %s %d", c[0].codigoC, c[0].cpf, c[0].nome, c[0].tel); //Teste da aloca??o
    return n_vendas;
	
	
	
	
	
	
};

void listarvendas(struct vendas *v, int vendas) {
	
	
  FILE *loja;        /* declara��o do ponteiro para arquivo */ 
  int i, achou, n_vendas;
  char resp;

  loja = fopen("vendas_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* j� existe o arquivo */
    fread(&n_vendas, sizeof(int), 1, loja); /* a primeira linha do arquivo cont�m o n�mero de registros j� gravados */ 
	fread(v, sizeof(struct vendas), n_vendas, loja);
    fclose(loja);
  }
  else
  	n_vendas = 0;
	
		printf("\nTotal de vendas: %d\n", n_vendas);
		printf("---------------------------");
                for(i=0;i<n_vendas;i++)  { 
                
	                
	                	printf("\nC�digo do cliente: %d\n", v[i].codcliente);
	                	printf("C�digo do produto: %d\n", v[i].codproduto);
	                	printf("C�digo da venda: %d\n", v[i].codVenda);
	                	printf("Forma de pagamento: %d\n", v[i].formpagamento);
	                	printf("Quantidade vendida: %d\n", v[i].quantvendida);
	                	printf("---------------------------\n");
	                
					
								
				}
	fclose(loja);			
 	return;
	
	
};
