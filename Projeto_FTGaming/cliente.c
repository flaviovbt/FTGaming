#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>



void gerenclientes(struct cliente *c, int *numcli, int *numclialoc){
	int op, k=0;

    while(k==0) {
        printf("\n1. Alterar cliente\n2. Cadastrar cliente\n3. Excluir cliente\n4. Consultar clientes\n5. Voltar\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1: alterar_cliente(c, *numcli);
                break;
            case 2: if(*numclialoc<*numcli+1)
    				{
				        *numclialoc+=10;
				        c = (struct cliente *) realloc(c, *numclialoc * sizeof(struct cliente)); //realoca mem?ria
				        if (!c) //Testa se a aloca??o foi bem sucedida
				            printf("Memória insuficiente\n");
				    }
					*numcli=adcionar_cliente(c, *numcli);
                break;
            case 3: *numcli=excluir_cliente(c, *numcli);
                break;
        	case 4: consultar_cliente(c, *numcli);
                break;
            case 5: k++;
                break;
            default: printf("Opção inválida");
                break;
    	}
    	//printf("\n\%d\n\n", *numcli);
    }
    printf("\n\n");
	
};


int alterar_cliente(struct cliente *c, int numcli){
	
  FILE *loja;        /* declaraï¿½ï¿½o do ponteiro para arquivo */ 
  int i, achou, n_clientes;
  char resp;

  loja = fopen("clientes_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* jï¿½ existe o arquivo */
    fread(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */ 
	fread(c, sizeof(struct cliente), n_clientes, loja);
    fclose(loja);
  } 
  else
  	n_clientes = 0;
	
	int cpf = 0;
	int cpf2 = 0;
    int telefone = 0;
    int op = 0;
    char nome2[200];

    printf("\nInforme o cpf do cliente: ");
    scanf("%d", &cpf);


    for(i=0;i<numcli;i++)  {

        if (c[i].cpf == cpf) {

            //printf("CLIENTE ENCONTRADO\n");

            printf("\nDigite:\n1. para editar o nome\n2. para telefone\n3. para cpf: ");
            scanf("%d", &op);

            if (op == 1) {
                printf("Digite o novo nome: ");

                setbuf(stdin,NULL);
                gets(nome2);
                strcpy(c[i].nome, nome2);
                printf("\nNome atualizado com sucesso.\n\n");
                
                     loja = fopen("clientes_data.dat", "wb");  /* cria o arquivo para escrita */
					  if (loja == NULL)
					   printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
					  else {
					  	fwrite(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
						fwrite(c, sizeof(struct cliente), n_clientes, loja);
						fclose(loja);
					  }

                return;
            }
            else if (op==2) {
                printf("Digite o novo telefone: ");
                scanf("%d", &telefone);

                c[i].tel = telefone;
                printf("\nTelefone atualizado com sucesso.\n\n");
                
                     loja = fopen("clientes_data.dat", "wb");  /* cria o arquivo para escrita */
					  if (loja == NULL)
					   printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
					  else {
					  	fwrite(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
						fwrite(c, sizeof(struct cliente), n_clientes, loja);
						fclose(loja);
					  }
                
                return;
            } else if (op==3) {
            	
            	printf("Digite o novo cpf: ");
                scanf("%d", &cpf2);

                c[i].cpf = cpf2;
                printf("\nCPF atualizado com sucesso.\n\n");
                
                     loja = fopen("clientes_data.dat", "wb");  /* cria o arquivo para escrita */
					  if (loja == NULL)
					   printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
					  else {
					  	fwrite(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
						fwrite(c, sizeof(struct cliente), n_clientes, loja);
						fclose(loja);
					  }
        
                fclose(loja);
                return;
            	
            	
			}
        }
    }
    close(loja);
    printf("CPF NÃO ENCONTRADO\n");
    
};

int verifica_se_cliente_existe (struct cliente *c, int numcli, int cpf) {
	
	
 FILE *loja;        /* declaraï¿½ï¿½o do ponteiro para arquivo */ 
  int i, achou, n_clientes;
  char resp;

  loja = fopen("clientes_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* jï¿½ existe o arquivo */
    fread(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */ 
	fread(c, sizeof(struct cliente), n_clientes, loja);
    fclose(loja);
  } 
  else
  	n_clientes = 0;
  	

    
		achou = 0;
		for (i = 0; i < n_clientes && !achou; i++) /* buscando o numero de um aluno */
			if (c[i].cpf == cpf) {
					return 1;
					achou = 1;
				}
				
		if (!achou) {
			printf("O CPF não foi encontrado! ");    /* inclui o aluno na ï¿½ltima posiï¿½ï¿½o livre do vetor */
			return 0;
		}
  	
  	
  	
}

int  adcionar_cliente(struct cliente *c, int numcli){

  FILE *loja;        /* declaraï¿½ï¿½o do ponteiro para arquivo */ 
  int i, achou, n_clientes;
  char resp;

  loja = fopen("clientes_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* jï¿½ existe o arquivo */
    fread(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */ 
	fread(c, sizeof(struct cliente), n_clientes, loja);
    fclose(loja);
  } 
  else
  	n_clientes = 0;
  	
	
	int cod, aux=0;
	
	char nome[200];
    int telefone;
    int cpf;
    int codigo;
    
  	printf("Insira o CPF: ");
    scanf("%d", &cpf);
    
		achou = 0;
		for (i = 0; i < n_clientes && !achou; i++) /* buscando o numero de um aluno */
			if (c[i].cpf == cpf) {
					printf("\nCpf do cliente ja cadastrado.");
					achou = 1;
				}
				
		if (!achou) {    /* inclui o aluno na ï¿½ltima posiï¿½ï¿½o livre do vetor */
			c[n_clientes].cpf = cpf;
		    printf("\nInsira o nome do cliente: ");
		    while (getchar() != '\n') /* void */;
		    gets(c[n_clientes].nome);
		    printf("Insira o nï¿½mero de telefone: ");
		    scanf("%d", &telefone);
		    c[n_clientes].tel = telefone;
		    c[n_clientes].codigoC=n_clientes;
          	
          	printf("\nCliente cadastrado com sucesso, seu código é %d!", n_clientes);
          	n_clientes++;
		}
		

    
        /* lista os alunos cadastrados */
		 // printf("\nClientes cadastrados:\n");
		 // for (i = 0; i < n_clientes; i++)
	     //   printf("\n%d		%s		%d", c[i].cpf, c[i].nome, c[i].tel);
        
          loja = fopen("clientes_data.dat", "wb");  /* cria o arquivo para escrita */
		  if (loja == NULL)
		   printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
		  else {
		  	fwrite(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
			fwrite(c, sizeof(struct cliente), n_clientes, loja);
			fclose(loja);
		  }
        

    return n_clientes;
    
    
};



int excluir_cliente(struct cliente *c, int numcli){
	
	
  FILE *loja;        /* declaraï¿½ï¿½o do ponteiro para arquivo */ 
  int i, achou, n_clientes;
  char resp;

  loja = fopen("clientes_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* jï¿½ existe o arquivo */
    fread(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */ 
	fread(c, sizeof(struct cliente), n_clientes, loja);
    fclose(loja);
  } 
  else
  	n_clientes = 0;
  	
	
	int cpf = 0;
    int quantidadeDesejada = 0;
    int op = 0;
    int j=0;
    i = 0;

    printf("\nInforme o cpf do cliente: ");
    scanf("%d", &cpf);

    for(i=0;i<n_clientes;i++)  {

        if (c[i].cpf == cpf) {

            //printf("MERCADORIA ENCONTRADA\n");

	
			
            for(j=i;j<n_clientes;j++)
            {
                c[j].codigoC=c[j+1].codigoC;
                c[j].cpf=c[j+1].cpf;
                c[j].tel=c[j+1].tel;
                strcpy(c[j].nome,c[j+1].nome);
            }
            

            
			printf("\nCliente excluído com sucesso\n\n");
            
			n_clientes--;
			
			
			
		  //printf("\nClientes cadastrados:\n");
		  //for (i = 0; i < n_clientes; i++)
	      //  printf("\n%d		%s		%d", c[i].cpf, c[i].nome, c[i].tel);
        
          loja = fopen("clientes_data.dat", "wb");  /* cria o arquivo para escrita */
		  if (loja == NULL)
		   printf("\nErro na criacao do arquivo. Nï¿½o foi possï¿½vel gravar os registros.");
		  else {
		  	fwrite(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */
			fwrite(c, sizeof(struct cliente), n_clientes, loja);
			fclose(loja);
		  }
			
			
			
            return n_clientes;
        }
    }
    printf("CLIENTE NÃO ENCONTRADO\n");
    return n_clientes;
};

int consultar_cliente(struct cliente *c, int numcli){
	
	
  FILE *loja;        /* declaraï¿½ï¿½o do ponteiro para arquivo */ 
  int achou, n_clientes;
  char resp;

  loja = fopen("clientes_data.dat", "rb");  /* abre o arquivo para leitura */
  if (loja != NULL) { /* jï¿½ existe o arquivo */
    fread(&n_clientes, sizeof(int), 1, loja); /* a primeira linha do arquivo contï¿½m o nï¿½mero de registros jï¿½ gravados */ 
	fread(c, sizeof(struct cliente), n_clientes, loja);
    fclose(loja);
  } 
  else
  	n_clientes = 0;
  	
	
	
	int cpf = 0;
    int telefone = 0;
    int codigo = 0;
    int op = 0;
    int i = 0;
    char nome[200];
    
    
     printf("\nDigite:\n1. para procurar por nome\n2. por cpf\n3. por telefone\n4. por codigo : ");
     scanf("%d", &op);
     
     if (op == 1) {
                printf("Digite o nome que seja buscar : ");
                setbuf(stdin,NULL);
                gets(nome);
                
                for(i=0;i<n_clientes;i++)  { 
                
	                if (strcmp(c[i].nome, nome) == 0) {
	                	
	                	printf("\nCpf: %d\n", c[i].cpf);
	                	printf("Nome: %s\n", c[i].nome);
	                	printf("Telefone: %d\n", c[i].tel);
	                	printf("Código: %d\n", c[i].codigoC);
	                	fclose(loja);
	                	return;
					}
								
				}
				printf("CLIENTE NÃO ENCONTRADO\n");
				fclose(loja);
                return n_clientes;
            }
            
            
     if (op == 2) {
                printf("Digite o cpf que seja buscar : ");
                setbuf(stdin,NULL);
                scanf("%d", &cpf);
                
                for(i=0;i<n_clientes;i++)  { 
                
	                if (c[i].cpf == cpf) {
	                	
	                	printf("\nCpf: %d\n", c[i].cpf);
	                	printf("Nome: %s\n", c[i].nome);
	                	printf("Telefone: %d\n", c[i].tel);
	                	printf("Código: %d\n", c[i].codigoC);
	                	fclose(loja);
	                	return;
					}
								
				}
				printf("CLIENTE NÃO ENCONTRADO\n");
				fclose(loja);
                return n_clientes;
            }
     if (op == 3) {
                printf("Digite o telefone que seja buscar : ");
                setbuf(stdin,NULL);
                scanf("%d", &telefone);
                
                for(i=0;i<n_clientes;i++)  { 
                
	                if (c[i].tel == telefone) {
	                	
	                	printf("\nCpf: %d\n", c[i].cpf);
	                	printf("Nome: %s\n", c[i].nome);
	                	printf("Telefone: %d\n", c[i].tel);
	                	printf("Código: %d\n", c[i].codigoC);
	                	fclose(loja);
	                	return;
					}
								
				}
				printf("CLIENTE NÃO ENCONTRADO\n");
				fclose(loja);
                return n_clientes;
            }
            
     if (op == 4) {
                printf("Digite o codigo que seja buscar : ");
                setbuf(stdin,NULL);
                scanf("%d", &codigo);
                
                for(i=0;i<n_clientes;i++)  { 
                
	                if (c[i].codigoC == codigo) {
	                	
	                	printf("\nCpf: %d\n", c[i].cpf);
	                	printf("Nome: %s\n", c[i].nome);
	                	printf("Telefone: %d\n", c[i].tel);
	                	printf("Código: %d\n", c[i].codigoC);
	                	fclose(loja);
	                	return;
					}
								
				}
				printf("CLIENTE NÃO ENCONTRADO\n");
				fclose(loja);
                return n_clientes;
            }
            
   if (op < 1 || op >3) {
				printf("\n Opção invalida, insira valores entre 1 e 4\n");
				fclose(loja);
                return;
            }

};




