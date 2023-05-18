#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int imprimeMenu(FILE* fptr){
		int opt, cont=0;
		char texto[100];
		char c,aux;
		
		printf("\n\tEscolha uma opcao:\n\n1- Adicionar texto ao final\n2- Limpar arquivo\n3- Ler texto\n4- Consultar ocorrencias de caractere\n5- Sair\n");
		scanf("%d",&opt);
		printf("\n---------------------------------------------------\n");
		switch(opt){
			case 1: //adiciona texto ao final do arquivo
				getchar();
				printf("\nDigite uma frase: \n");
				gets(texto);
				
				fprintf(fptr,"%s\n",texto);
				printf("\n---------------------------------------------------\n");
				break;
				
			case 2: //limpa arquivo
				fclose(fptr); //fecha arquivo (antes aberto como 'a+')
				fptr = fopen("texto01.txt","w");
				
				if(fptr==NULL){
					printf("\nNao foi possivel abrir o arquivo!\n");
					exit(1);
				}
				fprintf(fptr,"");
				printf("\nArquivo foi limpo com sucesso!\n");
				
				printf("\n---------------------------------------------------\n");
				break;
				
			case 3: //lê texto (a cada loop var 'texto' armazena 100 caracteres do arquivo)
				while(fgets(texto, 100, fptr)!=NULL)
					printf("%s",texto);
				
				printf("\n---------------------------------------------------\n");
				break;
				
			case 4: //mostra ocorrências de um caractere
				getchar();
				
				printf("\nCaractere a ser consultado: ");
				scanf("%c",&c);
				printf("\n---------------------------------------------------\n");
				
				do{
					aux = fgetc(fptr);
					
					if(c==aux){
						putchar(toupper(aux));
						cont++;
					}
					else
						putchar(tolower(aux));	
				} while(aux!=EOF);
				printf("\nA frase tem %d caractere(s) '%c'\n",cont,c);
				
				printf("\n---------------------------------------------------\n");
				break;
				
			case 5:
				printf("\nAte logo!\n");
				break;
				
			default:
				printf("\nOpcao invalida!\n");
		}
		fclose(fptr);
		return opt;
	}

int main(int argc, char *argv[]) {
	int opt;
	FILE *fptr = fopen("texto01.txt","a+");
	
	if(fptr==NULL){ //se não conseguir criar arquivo txt
		printf("\nNao foi possivel abrir o arquivo!\n");
		exit(1);
	}
	else{
		
		do{
			printf("\n--- MANIPULACAO DE ARQUIVOS txt---\n");
			fptr = fopen("texto01.txt","a+");
			opt = imprimeMenu(fptr);		
		}while(opt!=5); //opt '5' - sair
	}
	return 0;
}
