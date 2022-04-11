//[SI200] - Algoritmos de  Programa√ß√£o de Computadores II
//Programa em C para uso em uma loja de perif√©ricos - FT Gaming

//Desenvolvedores:
//Alexandre de Oliveira Stephano 265642
//Fl√°vio Vin√≠cius Barroso Teixeira 173903
//Matheus de Araujo Marques 241689

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "cliente.h"
#include "produto.h"
#include "venda.h"
#include "struct.h"
#include <locale.h>


int main(){
	
	int numcli=0, numclialoc=0, quantaloc=0, quantmer=0, vendasaloc=0, vendas=0;
	
	int quantidadeVenda = 0;
	
	int codigoMerc = 0;
	
	int cpf = 0;
	
	int op, k=1, op2, k2=1;
    
    struct mercadoria *M;
	M = (struct mercadoria *) malloc(10 * sizeof(struct mercadoria)); /*Aloca mem√≥riaa*/
    if (!M) /* Testa se a aloca??o foi bem sucedida */
        printf("Mem?ria insuficiente\n");
    else {
        quantaloc+=10;
    }
    
    struct cliente *C;
	C = (struct cliente *) malloc(10 * sizeof(struct cliente)); /*Aloca mem?ria*/
    if (!C) /*Testa se a aloca??o foi bem sucedida*/
        printf("Memoria insuficiente\n");
    else {
        numclialoc+=10;
    }
    
    struct vendas *V;
    V = (struct vendas *) malloc(10 * sizeof(struct vendas)); /*Aloca mem?ria*/
    if (!V) /*Testa se a aloca??o foi bem sucedida*/
        printf("Memoria insuficiente\n");
    else {
        vendasaloc+=10;
    }
    
    //C[0].numero= 100; 
    //printarcli(C);
    
    setlocale(LC_ALL,"portuguese");
    
    while(k) {
        printf("1. Gerenciamento de estoque\n2. Gerenciamento de clientes\n3. Gerenciamento de vendas\n4. sair\n");
        scanf("%d", &op);
        printf("\n");

        switch (op) {
            case 1:
                gerenestoque(M, &quantmer, &quantaloc);
                break;
            case 2:
                gerenclientes(C, &numcli, &numclialoc);
                break;
            case 3:
            	k2=1;
            	while(k2){
	            	printf("1. Realizar venda\n2. Listar vendas\n3. Sair\n");
	            	scanf("%d", &op2);
	            	switch(op2)
	            	{
	            		case 1:
	            			

	            			
	            			printf("Digite a quantidade que deseja vender: ");
	            			scanf("%d", &quantidadeVenda);
	            			
	            			printf("Digite o codigo do produto: ");
	            			scanf("%d", &codigoMerc);
	            			
	            			printf("Digite o cpf do cliente que deseja vender: ");
	            			scanf("%d", &cpf);
	            			
	            			if (alterar_estoque_venda(M, quantmer, quantidadeVenda, codigoMerc) == 0 && verifica_se_cliente_existe(C, numcli, cpf) == 1) {
						
	            			
			            	if(vendasaloc<vendas+1)
		    				{
						        vendasaloc+=10;
						        V = (struct vendas *) realloc(V, vendasaloc * sizeof(struct vendas)); //realoca mem?ria
						        if (!V) //Testa se a aloca??o foi bem sucedida
						            printf("Mem?ria insuficiente\n");
						    }
						   
							vendas=realizarvenda(V, vendas, quantidadeVenda, codigoMerc, cpf);
							
							};
							
	            			/*
	            			realizarvenda(V, &vendas, quantidadeVenda);
	            			
	            			
	            						            	if(numclialoc<numcli+1)
		    				{
						        numclialoc+=10;
						        C = (struct cliente *) realloc(C, numclialoc * sizeof(struct cliente)); //realoca mem?ria
						        if (!C) //Testa se a aloca??o foi bem sucedida
						            printf("Mem?ria insuficiente\n");
						    }
							numcli=adcionar_cliente(C, numcli);
	            			
	            			realizarvenda(V, &vendas, quantidadeVenda);*/
	            			//alterar_estoque();
	            			break;
	            		case 2:
	            			listarvendas(V, vendas);
	            			break;
	            		case 3:
	            			k2=0;
	            			break;
	            		default:
	            			printf("OpÁ„o Inv·lida!\n\n");
	                		break;
					}
					printf("\n");
				}
                break;
            case 4:
            	k=0;
            	break;
            default:
                printf("OpÁ„o Inv·lida!\n\n");
                break;
        }
    }
    free(C);
    free(V);
    free(M);
    
    
    return 0;
}

