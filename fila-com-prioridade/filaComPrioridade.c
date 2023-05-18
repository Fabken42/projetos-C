#include <stdio.h>
#include <stdlib.h>
#define IDADE_PRIORITARIA 65

	typedef struct no{
		char nome[15];
		int idade;
		struct no *prox;	
	}No;
	
	typedef struct pessoa{
		No *ini;
		No *fim;
	}Pessoa;


	void adicionaPessoa(Pessoa *p){
		No *aux = p->ini;
		No *novo = (No *) malloc(sizeof(No));
		getchar();
		
		printf("\nDigite o nome: ");
		gets(novo->nome);
		printf("\nDigite a idade: ");
		scanf("%d",&novo->idade);
		novo->prox = NULL;
		
		if(p->ini == NULL){ //adiciona no início, pois não há nada inserido
			p->ini = novo;
			p->fim = novo;
		}
		else if(novo->idade>=IDADE_PRIORITARIA){ //insere com prioridade (se idade >= 65)
			if(p->ini->idade<IDADE_PRIORITARIA){ //prioridade inserido no início da fila
				novo->prox = p->ini;
				p->ini = novo;
			}
			else{ //prioridade vai para o fim das prioridades
				while(aux->prox && aux->prox->idade>=IDADE_PRIORITARIA)
					aux = aux->prox;	
				novo->prox = aux->prox;
				aux->prox = novo;
				
				if(novo->prox == NULL)
					p->fim = novo;
			}
		}
		else { //insere sem prioridade
			p->fim->prox = novo;
			p->fim = novo;
		}
	}
	
	No* removePessoa(Pessoa *p){
		No *removido;
		Pessoa *aux;
		
		if(p->ini){
			removido = p->ini;
			p->ini = p->ini->prox;
			removido->prox = NULL;
			printf("\nRemocao bem sucedida\n");
		} else
			printf("\nPilha esta vazia!\n");
		
		return removido;
	}
	
	void imprimeFila(Pessoa *p){
		No *aux;
		printf("\nAguardando na fila:\n");
		for(aux = p->ini;aux!=NULL;aux = aux->prox)
			printf("\n%s (%d anos)",aux->nome,aux->idade);
	}
	
int main(int argc, char *argv[]) { //Se pessoa tiver idade >=65 anos, será adicionada ao início da fila | Se já houver idosos na fila, último cadastro vai para fim das prioridades
	int opt=0;
	Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
	p->ini = NULL;
	p->fim = NULL;
	No* removido = NULL;
	
	while(opt!=5){
		printf("\n------------------------------------------------\n");
		printf("Escolha a opcao: \n1- Adicionar pessoa\n2- Remover pessoa\n3- Imprimir fila\n4- Consultar ultimo removido\n5- Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				adicionaPessoa(p);
				break;
			case 2:
				removido = removePessoa(p);
				break;
			case 3:
				imprimeFila(p);
				break;
			case 4:
				if(removido)
					printf("\nO ultimo removido foi %s de %d anos\n",removido->nome,removido->idade);
				else printf("\nNinguem foi removido!\n");
				break;
			case 5:
				printf("\nAte logo!\n");
				break;
			default:
				printf("\nOpcao invalida!\n");
		}
	}
	return 0;
}
