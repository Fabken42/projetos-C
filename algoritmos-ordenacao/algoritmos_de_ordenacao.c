#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void imprimeVet(int nums[],int ini, int fim){
	int i=ini;
	printf("\n[");
	for(;i<fim-1;i++){
		printf("%d, ",nums[i]);
	}
	printf("%d]",nums[i]);
}

void bubbleSort(int nums[]){
	imprimeVet(nums,0,TAM);

	int i, j, aux;
	for(i=0;i<TAM-1;i++){ 
		for(j=0;j<(TAM-1)-i;j++){
			if(nums[j]>nums[j+1]){
				aux = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = aux;
			}
		}
		imprimeVet(nums,0,TAM);
	}
}

void selectionSort(int nums[]){ 
	imprimeVet(nums,0,TAM);

	int i, j, indice_menor, aux;
	
	for(i=0; i<TAM-1; i++){
		indice_menor = i;
		for(j=i+1; j<TAM; j++){
			if(nums[j]<nums[indice_menor])
				indice_menor = j;
		}
		aux = nums[indice_menor];
		nums[indice_menor] = nums[i];
		nums[i] = aux;
		
		imprimeVet(nums,0,TAM);
	}
}

void insertionSort(int nums[]){ 
	imprimeVet(nums,0,TAM);
	
	int i, j, aux;
	for(i=1; i<TAM; i++){
		j=i;
		while(j>0 && nums[j]<nums[j-1]){
			aux = nums[j];
			nums[j] = nums[j-1];
			nums[j-1] = aux;
			j--;
		}
		imprimeVet(nums,0,TAM);
	}
}

void merge(int nums_esq[], int nums_dir[], int nums[], int tam_esq, int tam_dir){
	int esq=0, dir=0, i=0;
	
	while(esq < tam_esq && dir < tam_dir){
		if(nums_esq[esq] < nums_dir[dir])
			nums[i++] = nums_esq[esq++];
		else
			nums[i++] = nums_dir[dir++];
	}
	
	while(esq < tam_esq)
		nums[i++] = nums_esq[esq++];
	while(dir < tam_dir)
		nums[i++] = nums_dir[dir++];
	
	imprimeVet(nums,0,i);
	printf("\n");
	
}

void mergeSort(int nums[], int tamanho){
	
	if(tamanho<=1){ //caso base
		if(tamanho==1) printf("\n[%d]",nums[0]);
		return;
	}
		
	int i=0,j=0;
	int *nums_esq = (int*) malloc(sizeof(int) * (tamanho/2));
	int *nums_dir = (int*) malloc(sizeof(int) * (tamanho-(tamanho/2)));

	for(;i<tamanho;i++){
		if(i<tamanho/2)
			nums_esq[i] = nums[i];
		else
			nums_dir[j++] = nums[i];
	}
	
	mergeSort(nums_esq,tamanho/2);
	mergeSort(nums_dir,tamanho-(tamanho/2));
	merge(nums_esq, nums_dir, nums, i-j, j);
}

void quickSort(int nums[], int ini, int fim){
	
	imprimeVet(nums, ini, fim+1);

	if(ini>=fim){ //caso base
		printf("\n");
		return;
	}
		
	int pivo = fim, i = ini-1, j = ini, aux;
	
	while(j<fim){
		if(nums[j] < nums[pivo]){
			aux = nums[++i];
			nums[i] = nums[j];
			nums[j] = aux;
		}
		j++;
	}
	aux = nums[++i];
	nums[i] = nums[pivo];
	nums[pivo] = aux;
	
	pivo = i;
	
	imprimeVet(nums, ini,fim+1);
	printf("\n");
	quickSort(nums, ini, pivo-1); //esquerda
	quickSort(nums, pivo+1, fim); //direita

	return;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int nums[TAM] = {}, opt, i, num;
	
	do{
		printf("\n------------------------------------------\n");
		printf("Escolha uma opcao:\n\n1-Gerar vetor aleatorio\n2-Bubble Sort\n3-Selection Sort\n4-Insertion Sort\n5-Merge Sort\n6-Quick Sort\n7-Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1: //vetor aleatório
				for(i=0;i<TAM;i++){
					num = rand()%100;
					nums[i] = num;
				}
				printf("\nVetor gerado:\n");
				imprimeVet(nums,0,TAM);
				break;
			case 2:
				bubbleSort(nums);
				break;
			case 3:
				selectionSort(nums);
				break;
			case 4:
				insertionSort(nums);
				break;
			case 5:
				mergeSort(nums,TAM);
				break;
			case 6:
				quickSort(nums,0,TAM-1);
				imprimeVet(nums, 0, TAM);
				break;
			case 7:
				printf("\nAte logo!\n");
				break;
			default:
				printf("\nOpcao invalida!\n");
		}
	} while(opt != 7);
	return 0;
}
