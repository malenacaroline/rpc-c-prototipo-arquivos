/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOME 100
#define _GNU_SOURCE


int *
criar_arquivo_100_svc(arquivo *argp, struct svc_req *rqstp)
{
	static int  result;
	FILE *pont_arq;

	printf("O cliente requisitou o procedimento remoto CRIAR ARQUIVO.\n");

	pont_arq = fopen(argp->nome,"a");
	fclose(pont_arq);

	printf("O arquivo %s foi criado com sucesso.\n",argp->nome);

	if (pont_arq == NULL) {
		result = 0;
	}else{
		result = 1;
	} 
	

	return &result;
}

int *
deletar_arquivo_100_svc(arquivo *argp, struct svc_req *rqstp)
{
	static int  result;
	int arq;

	printf("O cliente requisitou o procedimento remoto DELETAR ARQUIVO.\n");
	
	result = remove(argp->nome);//funcao remove retorna 0 se deu certo
	
	printf("O arquivo %s foi deletado com sucesso.\n",argp->nome);

	
	return &result;
}

int *
copiar_arquivo_100_svc(arquivo *argp, struct svc_req *rqstp)
{
	static int  result;
	FILE *arq_copiar;
	FILE *arq_copiado;
	int x,y;
	char conteudo[1000];
	char nome_enviado[100];
	char nome_arqs[2][MAX_NOME];
	char nome_arq1[100];
	char nome_arq2[100];
	int ch;
	

	strcpy(nome_enviado,argp->nome);
	printf("nome = %s\n",nome_enviado);
	sscanf(nome_enviado, "%s %s", nome_arqs[0], nome_arqs[1]);
	
	
	printf("O cliente requisitou o procedimento remoto COPIAR ARQUIVO.\n");
	

	arq_copiar = fopen(nome_arqs[0],"r");//arquivo para copiar o conteudo
	arq_copiado = fopen(nome_arqs[1],"w");//arquivo que vai receber o conteudo copiado

	if(arq_copiar == NULL){
		printf("Erro na abertura do arquivo\n");
		result = 0;
		
	}else{
		copiarArquivo(arq_copiar,arq_copiado);
		fclose(arq_copiar);
		fclose(arq_copiado);
		printf("O arquivo foi copiado com sucesso.\n");
		result = 1;
	}
	
	

	return &result;
}
void copiarArquivo(FILE *arq1, FILE *arq2){
	char conteudo[1000];
	
	while (fgets(conteudo,1000,arq1) != NULL)
	fputs(conteudo,arq2);
}
int *
escrever_arquivo_100_svc(arquivo *argp, struct svc_req *rqstp)
{
	static int  result;
	FILE *arq;
	char ext[5]= ".txt";
	
	strcat(argp->nome, ext);
	arq = fopen(argp->nome,"w");

	if(arq ==NULL){
		printf("Erro na abertura do arquivo\n");
		result = 0;
	}else{
		fprintf(arq,"%s",argp->conteudo);
		printf("O cliente requisitou o procedimento remoto ESCREVER ARQUIVO.\n");
		printf("CONTEÚDO PARA SER INSERIDO NO ARQUIVO: %s\n",argp->conteudo);
		printf("O arquivo %s foi alterado com sucesso.\n",argp->nome);
		result = 1;
	}
	fclose(arq);
	


	

	return &result;
}

int *
ler_arquivo_100_svc(arquivo *argp, struct svc_req *rqstp)
{
	static int  result;
	FILE *arq;
	size_t len=1000;
	char *linha = malloc(len);
	char conteudo[100];

	printf("O cliente requisitou o procedimento remoto LER ARQUIVO.\n");
	arq = fopen(argp->nome,"r");
	
	if(arq == NULL){
		printf("Erro na abertura do arquivo.\n");
		result = 0;	
	}else{
		printf("\n-------------------- CONTEUDO DO ARQUIVO --------------------\n\n");
		while(getline(&linha,&len,arq) > 0){
			printf("%s\n", linha);
		}
		if(linha){
			free(linha);
		}
		fclose(arq);
		printf("\nO arquivo %s foi lido com sucesso.\n",argp->nome);
		result = 1;
	}

	return &result;
}
