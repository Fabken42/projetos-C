#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTD_NOTAS 3

	typedef struct aluno{
		char nome[15];
		float notas[QTD_NOTAS];
		float media;
		char situacao[15];
		struct aluno *prox;
	}Aluno;

	void push(Aluno **al){
		int i;
		float soma,media;
		Aluno *aux = (Aluno*)(malloc(sizeof(Aluno)));
		printf("\nDigite o nome: ");
		scanf("%s",&aux->nome);
		for(i=0;i<QTD_NOTAS;i++){
			printf("\nDigite a nota %d: ",i+1);
			scanf("%f",&aux->notas[i]);
			soma+=aux->notas[i];
		}
		media = soma/QTD_NOTAS;
		aux->media = media;
		
		if(media<4)
			strcat(aux->situacao,"Reprovado");
		else if(media<7)
			strcat(aux->situacao,"Recuperacao");
		else
			strcat(aux->situacao,"Aprovado");
			
		aux->prox = *al;
		*al = aux;
		return;
	}
	
	void pop(Aluno **al){
		Aluno *aux;
		
		if(*al){
			printf("\nRemovendo aluno: %s\n",(*al)->nome);
			aux = *al;
			*al=(*al)->prox;
			free(aux);
			return;
		}
		printf("\nPilha esta vazia!\n");
		return;
	}
	
	void imprime(Aluno *al){
		Aluno *aux;
		
		for(aux = al; aux!=NULL; aux = aux->prox)
			printf("%s - %s\n",aux->nome,aux->situacao);
		return;
	}
	
	void busca_aluno(Aluno *al,char aluno_buscado[]){
		Aluno *aux = al;
		while(aux){
			if(strcmp(aluno_buscado,aux->nome)==0){
				printf("\nAluno: %s\n\nNota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\nMedia: %.2f\nSituacao: %s\n",aux->nome,aux->notas[0],aux->notas[1],aux->notas[2],aux->media,aux->situacao);
				return;
			}
			else aux = aux->prox;
		}
		printf("\nAluno nao foi encontrado!\n");
	}

// pilha que recebe nome do aluno, 3 notas. E calcula media aritmetica (switch-case imprimir,adicionar aluno,remover do topo)
int main(int argc, char *argv[]) {
	int opt;
	char aluno_buscado[15];
	Aluno *al = NULL;
	printf("\n----Cadastro de alunos e notas----\n");
	do{
		printf("\n----------------------------------------\n");
		printf("\nEscolha uma opcao:\n\n1- Adicionar aluno\n2- Remover do topo\n3- Imprimir situacao\n4- Buscar aluno\n5- Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				push(&al);
				break;
			case 2:
				pop(&al);
				break;
			case 3:
				imprime(al);
				break;
			case 4:
				printf("Digite o nome do aluno: ");
				getchar();
				gets(aluno_buscado);
				busca_aluno(al,aluno_buscado);
				break;
			case 5:
				printf("\nAte logo!\n");
				break;
			default:
				printf("\nOpcao invalida!\n");
		}
	}while(opt!=5);
	return 0;
}
