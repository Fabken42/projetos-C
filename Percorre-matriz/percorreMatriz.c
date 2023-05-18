#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 7

	void geraMatriz(int mat[][TAM]){
		int i,j,aleat;
		for(i=0;i<TAM;i++){
			for(j=0;j<TAM;j++){
				aleat = rand()%2;
				mat[i][j] = aleat;
			}
		}
		return;
	}

	void imprimeMatriz(int mat[][TAM]){
		int i,j;
		printf("\n    0    1    2    3    4    5    6  |\n");
		printf("_____________________________________|____\n%38c\n",'|');
		for(i=0;i<TAM;i++){
			for(j=0;j<TAM;j++){
				printf("%5d",mat[i][j]);
			}
			printf("  |  %d\n",i);
		}
		return;
	}
	
	void pedePosicao(int *linha, int *coluna){
		do{
		printf("\nDigite a linha: ");
		scanf("%d",linha);
		printf("Digite a coluna: ");
		scanf("%d",coluna);
		
		if((*linha<0 || *linha>TAM-1) || (*coluna<0 || *coluna>TAM-1)){
			printf("\nPosicao invalida!\n-------------------------");
			continue;
			}
		break;
		} while(1);
		return;
	}
													//ini vale 0 ou 1
	void percorreMatriz(int mat[][TAM],int lin,int col,int ini){
		if(posicaoValida(lin,col)){
			if(posicaoValida(lin-1,col) && mat[lin-1][col]==ini){ //CIMA
				mat[lin-1][col] = 2;
				percorreMatriz(mat,lin-1,col,ini);
			}
			if(posicaoValida(lin+1,col) && mat[lin+1][col]==ini){ //BAIXO
				mat[lin+1][col] = 2;
				percorreMatriz(mat,lin+1,col,ini);
			}
			if(posicaoValida(lin,col-1) && mat[lin][col-1]==ini){ //ESQUERDA
				mat[lin][col-1] = 2;
				percorreMatriz(mat,lin,col-1,ini);
			}
			if(posicaoValida(lin,col+1) && mat[lin][col+1]==ini){ //DIREITA
				mat[lin][col+1] = 2;
				percorreMatriz(mat,lin,col+1,ini);
			}
			
		}
		else return;
	}
	
	int posicaoValida(int lin,int col){
		if((lin>=0 && lin<TAM) && (col>=0 && col<TAM))
			return 1;
		return 0;
	}


int main(int argc, char *argv[]) {
	srand(time(NULL));
	int mat[TAM][TAM]={},linha=0,coluna=0,inicio;
	geraMatriz(mat);
	imprimeMatriz(mat);
	printf("\n----------------------------------------------\n");
	pedePosicao(&linha,&coluna);
	inicio = mat[linha][coluna];
	percorreMatriz(mat,linha,coluna,inicio);
	mat[linha][coluna] = 2;
	imprimeMatriz(mat);
	
	return 0;
}
