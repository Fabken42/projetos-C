#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *esquerda, *direita;	
}No;


void imprimeArvore2d(No *raiz, int tabulacoes){ //inicialmente tab = 0
	int i;
	if(raiz){
		imprimeArvore2d(raiz->direita, tabulacoes+1);
		
		for(i=0;i<tabulacoes;i++){
			printf("\t");
		}
		printf("%d\n",raiz->valor);
		
		imprimeArvore2d(raiz->esquerda, tabulacoes+1);
	}
}

void imprimeArvoreCrescente(No *raiz){
	if(raiz){
	imprimeArvoreCrescente(raiz->esquerda);
	printf("%d ",raiz->valor);
	imprimeArvoreCrescente(raiz->direita);
	}
}

void insereNo(No **raiz, int num){
	
	No *aux = *raiz;
	No *novo = malloc(sizeof(No)); //criando nó (folha) a ser inserido
	novo->esquerda = NULL;
	novo->direita = NULL;
	novo->valor = num;
	
	if(!aux){ //não há nada inserido na árvore
		*raiz = novo;
		return;
	}
	
	while(aux->esquerda || aux->direita){
		if(aux->esquerda && num < aux->valor){
			aux = aux->esquerda;
		}else if(aux->direita && num> aux->valor){
			aux = aux->direita;
		}else break;
	}
	
	if(num < aux->valor)
		aux->esquerda = novo;
	else
		aux->direita = novo;
}

No *buscaValor(No *raiz, int valor){
	while(raiz){
		if(raiz->valor == valor)
			return raiz;
		else if(raiz->valor > valor)
			raiz = raiz->esquerda;
		else raiz = raiz->direita;
	}
	return NULL;
}

int calculaAltura(No *raiz){
	if(!raiz)
		return -1;
	
	int esq = calculaAltura(raiz->esquerda);
	int dir = calculaAltura(raiz->direita);

	if(esq>dir)
		return esq+1;
	return dir+1;
}

int contaNos(No *raiz){
	if(!raiz) return 0; //caso-base
	
	int soma = contaNos(raiz->esquerda) + contaNos(raiz->direita);
	return soma+1;
}

int contaFolhas(No *raiz){
	if(!raiz)
		return 0;
	if(!raiz->esquerda && !raiz->direita)
		return 1;
		
	return contaFolhas(raiz->esquerda) + contaFolhas(raiz->direita);
}

No *removeNo(No *raiz, int valor){
	if(!raiz){
		printf("\nO valor %d nao foi encontrado!\n",valor);
		return NULL;
	}
	
	if(raiz->valor == valor){
		if(raiz->esquerda && raiz->direita){ //nó com dois filhos
			No *aux = raiz->esquerda;
			while(aux->direita) //raiz troca de lugar com nó mais a direita do filho da esquerda (que é necessariamente nó com um filho ou folha)
				aux = aux->direita;
			
			raiz->valor = aux->valor;
			aux->valor = valor;
			raiz->esquerda = removeNo(raiz->esquerda, valor);
			return raiz;
			
		} else if(raiz->esquerda || raiz->direita){ //nó com 1 filho
			No *aux;
			printf("\nRemovendo no: %d\n",valor);
			
			if(raiz->esquerda){
				aux = raiz->esquerda;
				free(raiz);
				return aux;
			}
			aux = raiz->direita;
			free(raiz);
			return aux;
			
		} else{ //nó folha
			printf("\nRemovendo no: %d\n",valor);
			free(raiz);
			return NULL;
		}
	}
	
	if(valor < raiz->valor)
		raiz->esquerda = removeNo(raiz->esquerda, valor);
	else raiz->direita = removeNo(raiz->direita, valor);
	return raiz;
}

void esvaziaArvore(No **raiz){
	if(!(*raiz))
		return;
	
	esvaziaArvore(&(*raiz)->esquerda);
	esvaziaArvore(&(*raiz)->direita);
	printf("\nRemovendo valor: %d\n",(*raiz)->valor);
	free(*raiz);
}


int main(int argc, char *argv[]) {
	int valor_de_busca, valor_a_remover, opt, altura, qtd_nos, qtd_folhas, imprime_opt, num, tabulacoes=0;
	No *raiz=NULL, *aux;
	
	do{
		printf("\n------------------------------------------");
		printf("\nEscolha uma opcao:\n1-Imprimir arvore\n2-Inserir no\n3-Buscar valor\n4-Calcular altura\n5-Contar nos\n6-Contar folhas\n7-Remover no\n8-Esvaziar arvore\n9-Sair\n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1:
				if(!raiz){
					printf("\nArvore vazia!\n");
					break;	
				}
				
				printf("\n1-Imprimir em 2D\n2-Imprimir em ordem crescente\n");
				scanf("%d",&imprime_opt);
				
				imprime_opt==1 ? imprimeArvore2d(raiz, tabulacoes) : imprimeArvoreCrescente(raiz);
				break;
			case 2:
				printf("\nValor a ser inserido: \n");
				scanf("%d",&num);
				insereNo(&raiz, num);
				break;
			case 3:
				printf("\nDigite o valor a ser encontrado: \n");
				scanf("%d",&valor_de_busca);
				aux = buscaValor(raiz, valor_de_busca);
				if(!aux){
					printf("\nValor %d nao foi encontrado!\n");
				} else{
					printf("\nO valor foi encontrado e ");
					if(aux->esquerda && aux->direita)
						printf("tem 2 filhos\n");
					else if(aux->esquerda || aux->direita)
						printf("tem 1 filho\n");
					else printf("eh uma folha");
				}
				break;
			case 4:
				altura = calculaAltura(raiz);
				printf("\nAltura da Arvore: %d\n", altura);
				break;
			case 5:
				qtd_nos = contaNos(raiz);
				printf("\nQuantidade de Nos: %d\n", qtd_nos);
				break;
			case 6:
				qtd_folhas = contaFolhas(raiz);
				printf("\nQuantidade de Folhas: %d\n",qtd_folhas);
				break;
			case 7:
				if(!raiz){
					printf("\nArvore vazia!\n");
					break;	
				}
				
				printf("\nDigite o valor a ser removido: \n");
				scanf("%d",&valor_a_remover);
				raiz = removeNo(raiz, valor_a_remover);
				break;
			case 8:
				esvaziaArvore(&raiz);
				raiz = NULL;
				break;
			case 9:
				printf("\nAte logo!\n");
				break;
			default:
				printf("\nOpcao invalida!\n");
		}
	}while(opt!=9);
	return 0;
}
