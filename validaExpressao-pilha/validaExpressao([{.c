#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	/*
		VERIFICAR SE '(', '[', '{', ')', ']', '}' SÃO VÁLIDOS EM EXPRESSÃO MATEMÁTICA (usar pilha)
		ex: (9+2)/{2*[5-(2+1)]-2} - Válido
			8+(3-2)]8+{{2/3} - Inválido
	*/
	
	typedef struct no{
		char simbolo;
		struct no *prox;
	}No;
	
	void push(No **topo,char simb){
		No *aux = (No*)(malloc(sizeof(No)));
		aux->simbolo = simb;
		aux->prox = *topo;
		*topo = aux;
		return;
	}
	
	void pop(No **topo,char simb){
		No *aux;
		if(*topo){
			char char_aux = (*topo)->simbolo;
			if(char_aux=='(' && simb==')' || char_aux=='[' && simb==']' || char_aux=='{' && simb=='}'){
				if(*topo){
					aux = *topo;
					*topo = (*topo)->prox;
					free(aux);
					return;
				}
			}
		}
		printf("\nExpressao invalida!\n");
		exit(1);
	}
	
int main(int argc, char *argv[]) { //concertar se usuario comecar digitando '), } ou ]'
	char expressao[30]={};
	int i;
	No *topo = NULL;
	printf("Digite a expressao matematica: ");
	gets(expressao);
	
	for(i=0;i<strlen(expressao);i++){
		if(expressao[i]=='(' || expressao[i]=='[' || expressao[i]=='{'){
			push(&topo,expressao[i]);
		}
		else if(expressao[i]==')' || expressao[i]==']' || expressao[i]=='}'){
			pop(&topo,expressao[i]);
		}
	}
	
	topo ? printf("\nExpressao invalida\n") : printf("\nExpressao valida!\n");
	return 0;
}
