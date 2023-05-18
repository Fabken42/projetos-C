#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 17
	
	int funcao_espalhamento(int num){
		return num % TAM;
	}
	
	void insere(int num, int nums[]){
		int chave = funcao_espalhamento(num);
		
		while(nums[chave]){ //se já houver elemento na mesma chave -> verificar próxima posição
			chave = funcao_espalhamento(++chave);
		}
		
		nums[chave] = num;
	}
	
	void imprime_tabela(int nums[]){
		int i;
		for(i=0;i<TAM;i++){
			printf("%d\n",nums[i]);
		}
	}
	
	void busca_valor(int valor_buscado, int nums[]){
		int chave = funcao_espalhamento(valor_buscado);
		
		while(nums[chave]!=valor_buscado && nums[chave]!=0){
			chave = funcao_espalhamento(++chave);
		}
		if(nums[chave] == valor_buscado){
			printf("\nEncontrei o valor %d na tabela!\n",valor_buscado);
		} else {
			printf("\nNao encontrei o valor %d na tabela!\n",valor_buscado);
		}
	}
	
	
int main(int argc, char *argv[]) {
	srand(time(NULL));
	int nums[TAM]={};
	int num, i, valor_buscado, qtd_termos = TAM/2;
	
	for(i=0;i<qtd_termos;i++){
		num = rand()%100;
		insere(num,nums);	
	}
	
	printf("\nTABELA HASH:\n");
	imprime_tabela(nums);
	
	printf("\nDigite o valor que deseja buscar: \n");
	scanf("%d",&valor_buscado);
	busca_valor(valor_buscado, nums);
	
	return 0;
}
