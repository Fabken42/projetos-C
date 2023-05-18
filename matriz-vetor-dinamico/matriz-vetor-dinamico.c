#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraMatriz(int **mat, int linhas, int colunas);
void imprimeMatriz(int **mat, int linhas, int colunas);
void geraVetor(int *vet, int qtdVet);
void imprimeVetor(int *vet, int qtdVet);

	void geraMatriz(int **mat, int linhas, int colunas){
		int i,j;
		for(i=0;i<linhas;i++){
			for(j=0;j<colunas;j++){
				*(*(mat+i)+j)=rand()%100;
			}
		}
		return imprimeMatriz(mat,linhas,colunas);
	}

	void imprimeMatriz(int **mat, int linhas, int colunas){
		int i,j;
		printf("\n----------------------------------------------\n");
		for(i=0;i<linhas;i++){
			for(j=0;j<colunas;j++){
				printf("%5d",*(*(mat+i)+j));
			}
			printf("\n");
		}
		printf("\n----------------------------------------------\n");
		return;
	}
	
	void geraVetor(int *vet, int qtdVet){
		int i;
		for(i=0;i<qtdVet;i++)
			*(vet+i) = rand()%100;
		return imprimeVetor(vet,qtdVet);
	}

	void imprimeVetor(int *vet, int qtdVet){
		int i;
		printf("\n----------------------------------------------\n");
		for(i=0;i<qtdVet;i++)
			printf("%5d",*(vet+i));
		printf("\n----------------------------------------------\n");
		return;
	}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int i, j, opt, continuar, linMat, colMat, qtdVet, *vet, **mat;
	do{
		printf("\nEscolha uma opcao:\n1- Gerar matriz aleatoria\n2- Gerar vetor aleatorio\n3- Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nDigite o numero de linhas: ");
				scanf("%d",&linMat);
				printf("\nDigite o numero de colunas: ");
				scanf("%d",&colMat);
				
				//ALOCAÇÃO DINÂMICA DE MATRIZ
				mat = malloc(linMat * sizeof(int*));
				for(i=0;i<linMat;i++){
					mat[i] = malloc(colMat * sizeof(int));
				}
				//-----------------------------//
				geraMatriz(mat,linMat,colMat);
				break;
			case 2:
				printf("\nDigite o numero de termos: ");
				scanf("%d",&qtdVet);
				
				//ALOCAÇÃO DINÂMICA DE VETOR
				vet = malloc(qtdVet * sizeof(int));
				//----------------------------//
				geraVetor(vet,qtdVet);
				break;
			case 3:
				printf("\nAte logo!");
				break;
			default:
				printf("\nOpcao invalida!\n");
				continue;
		}
	} while(opt!=3);
	return 0;
}
