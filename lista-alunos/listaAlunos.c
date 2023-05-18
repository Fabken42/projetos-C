#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTD_NOTAS 3


	typedef struct no{
		char nome[15];
		float notas[QTD_NOTAS];
		float media;
		struct no *prox;
	}No;
	
	typedef struct aluno{
		No *ini;
		int tam;
	}Aluno;
	
	
	void iniciaLista(Aluno *al){
		al->tam = 0;
		al->ini = NULL;
	}

	void adicionaAl(Aluno *al, char nome[], float notas[]){ //insere em ordem alfabética
		int i;
		float soma=0;
		No *aux = al->ini;
		No *novo = (No *) malloc(sizeof(No));
		
		strcpy(novo->nome, nome);
		for(i=0;i<QTD_NOTAS;i++){
			novo->notas[i] = notas[i];
			soma+=notas[i];
		}
		novo->media = soma/QTD_NOTAS;
		novo->prox = NULL;
		al->tam++;
		//------------------------------------------------------//
		if(!aux){ //se não houver elementos na lista
			al->ini = novo;
			return;
		}
		
		while(aux->prox && strcmp(aux->prox->nome, nome)<0)
			aux = aux->prox;
		
		if(al->ini->nome == aux->nome && strcmp(aux->nome, nome)>0){ //insere no início
			novo->prox = aux;
			al->ini = novo;
		}
		else{ //insere no meio ou fim
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
	
	void removeAl(Aluno *al, char nome[]){
		No *aux = al->ini;
		if(!aux){
			printf("\nLista esta vazia!\n");
			return;
		}
		else if(strcmp(aux->nome, nome) ==0){ //remove do início
			al->ini = al->ini->prox;
			free(aux);
			al->tam--;
		}
		else{ //remove do meio ou fim
			while(aux->prox && strcmp(aux->prox->nome,nome)<0){
				aux = aux->prox;
			}
			if(aux->prox && strcmp(aux->prox->nome, nome) ==0){ //nome encontrado na lista
				No *removido = aux->prox;
				aux->prox = aux->prox->prox;
				free(removido);
				al->tam--;
			}
			else { //nome não encontrado na lista
				printf("\nAluno %s nao encontrado!\n",nome);
				return;
			}
		}
		printf("\nAluno %s removido com sucesso!\n",nome);
	}
	
	void imprimeAl(Aluno al){
		No *aux = al.ini;
		printf("\n TOTAL DE ALUNOS: %d\n",al.tam);
		printf("\n%15s | MEDIA\n","ALUNO");
		printf("      *********************\n");
		for(; aux; aux = aux->prox)
			printf("%15s | %.2f\n",aux->nome,aux->media);
	}
	
	void consultaDetalhesAl(Aluno al,char nome[]){
		No *aux = al.ini;
		if(!aux)
			printf("\nLista esta vazia!\n");
		else{
			for(;aux;aux = aux->prox){
				if(strcmp(nome,aux->nome)==0){
					printf("\nALUNO: %s\nNOTA 1: %.2f\nNOTA 2: %.2f\nNOTA 3: %.2f\nMEDIA: %.2f\nSITUACAO: ",aux->nome,aux->notas[0],aux->notas[1],aux->notas[2],aux->media);
					if(aux->media<4)
						printf("REPROVADO\n");
					else if(aux->media<6)
						printf("RECUPERACAO\n");
					else printf("APROVADO\n");
					return;
				}
			}
			printf("\nAluno nao encontrado!\n");
		}
	}
	
	void liberaLista(Aluno *al){
		No *aux = al->ini;
		while(aux){
			No *removido = aux;
			aux = aux->prox;
			free(removido);
		}
	}

int main(int argc, char *argv[]) { 
	Aluno al;
	iniciaLista(&al);
	
	int opt, i;
	float notas[QTD_NOTAS];
	char nome[15];
	do{
		printf("\n-----------------------------------------------\n");
		printf("\nEscolha uma opcao:\n1-Adicionar aluno\n2-Remover aluno\n3-Imprimir lista\n4-Consultar detalhes\n5-Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				getchar();
				printf("\nDigite o nome: ");
				gets(nome);
				for(i=0;i<QTD_NOTAS;i++){
					printf("\nDigite a nota %d: ",i+1);
					scanf("%f",&notas[i]);
				}
				adicionaAl(&al,nome,notas);
				break;
			case 2:
				getchar();
				printf("\nDigite o nome: ");
				gets(nome);
				removeAl(&al, nome);
				break;
			case 3:
				imprimeAl(al);
				break;
			case 4:
				getchar();
				printf("\nDigite o nome: ");
				gets(nome);
				consultaDetalhesAl(al,nome);
				break;
			case 5:
				liberaLista(&al);
				printf("\nAte logo!\n");
				break;
			default:
				printf("\nOpcao invalida!\n");
		}
	}while(opt!=5);
	return 0;
}
