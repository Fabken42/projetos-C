#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limpaVet();
void preencheEspacos(int compPalavra, char espacos[]);
void imprimeForca(int erros);
char joga(char chutes[],int auxChutes);
int analisaChute(int compPalavra, char chute, char palavraSorteada[], char espacos[], char letrasErradas[]);
int imprimeEspacos(char espacos[]);
void imprimeErros(char letrasErradas[], int aux);
void imprimeTrofeu();

	void limpaVet(char espacos[], char letrasErradas[], char chutes[]){
		memset(espacos,0,15);
		memset(letrasErradas,0,7);
		memset(chutes,0,26);
	}
	
	void preencheEspacos(int compPalavra,char espacos[]){
		int i;
		for(i=0;i<compPalavra;i++)
			espacos[i] = '_';
	}

	void imprimeForca(int erros){
		printf("\n");
				switch(erros){
			case 0:
				printf("    _______\n   |\t   |\n   |\t\n   |\t\n   |\t\n __|__\t\n");
				break;
			case 1:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t\n   |\t\n __|__\t\n");
				break;
			case 2:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t   |\n   |\t   |\n __|__\t  \n");
				break;
			case 3:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t  %c|\n   |\t   |\n __|__\t  \n",47);
				break;
			case 4:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t  %c|%c\n   |\t   |\n __|__\t  \n",47,92);
				break;
			case 5:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t  %c|%c\n   |\t   |\n __|__\t  %c \n",47,92,47);
				break;
			case 6:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t  %c|%c\n   |\t   |\n __|__\t  %c %c\n",47,92,47,92);
				break;
			case 7:
				printf("    _______\n   |\t   |\n   |\t   0\n   |\t-------\n   |\t  %c|%c\n __|__\t   |\n \t  %c %c",47,92,47,92);
		}
		printf("\n\t\t");
		return;
	}
	
	char joga(char chutes[], int auxChutes){
		char chute;
		int i,chuteEmChutes;
		do{
			chuteEmChutes=0;
			printf("\nSeu chute: ");
			scanf(" %c",&chute);
			
			if(!isalpha(chute)){ 
			 	printf("\nPor favor, digite uma letra!\n");
			 	continue;
			}
			
			chute = toupper(chute);
			 //verifica se é chute novo ou repetido
				for(i=0;i<auxChutes;i++){
					if(chute==chutes[i])
						chuteEmChutes=1;
				}
				
				if(chuteEmChutes){
					printf("\nVoce ja digitou essa letra!\n");
					continue;
				}
				else{
					chutes[i] = chute;
					break;
				}
		} while(1);
		
		return chute;
	}
	
	
int analisaChute(int compPalavra, char chute, char palavraSorteada[], char espacos[], char letrasErradas[]){
	int i, existeChute=0;
	for(i=0;i<compPalavra;i++){
		if(chute==palavraSorteada[i]){
			espacos[i] = chute;
			existeChute = 1;
		}
	}
	return existeChute;
}
	
	int imprimeEspacos(char espacos[]){
		int i=0,completou=1;
		while(espacos[i]!='\0'){
			printf("%c ",espacos[i++]);
			if(espacos[i]=='_')
				completou = 0;
		}
		return completou;
	}
	
	void imprimeErros(char letrasErradas[],int aux){
		int i;
		printf("\n\nChutes errados: ");
		for(i=0;i<aux;i++)
			printf("%c ",letrasErradas[i]);
	}

	void imprimeTrofeu(){
		printf("	   ___________\n");
	    printf("          '._==_==_=_.'\n");
	    printf("          .-\\:      /-.\n");
	    printf("         | (|:.     |) |\n");
	    printf("          '-|:.     |-'\n");
	    printf("            \\::.    /\n");
	    printf("             '::. .'\n");
	    printf("               ) (\n");
	    printf("             _.' '._\n");
	    printf("            `%c%c%c%c%c%c%c`\n\n",34,34,34,34,34,34,34);
		}
