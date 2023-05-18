#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoesForca.h"
#define TAM_LISTA_PALAVRAS 30
	
int main(int argc, char *argv[]) { //COLOCAR FUNCOES EM OUTRO ARQUIVO C
	srand(time(NULL));
	char *listaPalavras[TAM_LISTA_PALAVRAS] = {"BANANA","MORANGO","ABACATE","FUTEBOL","CORRIDA","MEDICINA","PARALELEPIPEDO","BATOM","GARRAFA","ROUPAS",
	"MORCEGO","LEBRE","FORMIGA","BOMBEIRO","POLICIAL","LIVRO","MOCHILA","CHINELO","DIAMANTE","GUITARRA","MENINA","ILHA","JANELA","DENTE","LAGARTIXA",
	"TRAVESSEIRO","APAGADOR","VIDEOGAME","BONDADE","ALPACA"};
	int auxChutes, auxLetrasErradas, i, posAleatoria, opt=1, compPalavra, erros, venceu, existeChute;
	char chute, palavraSorteada[15], espacos[15], letrasErradas[7], chutes[26];
	
	do{
		erros = 0; venceu = 0; auxLetrasErradas = 0; auxChutes=0;
		limpaVet(espacos,letrasErradas,chutes);
		
		posAleatoria = rand()%TAM_LISTA_PALAVRAS;
		strcpy(palavraSorteada, listaPalavras[posAleatoria]);
		compPalavra = strlen(palavraSorteada);
		preencheEspacos(compPalavra,espacos); //preenche com '_'
		
		do{
			chute = joga(chutes,auxChutes);
			auxChutes++;
			existeChute = analisaChute(compPalavra, chute, palavraSorteada, espacos, letrasErradas); //se analisaChute retorna 0, chute não ocorre em palavraSorteada
			if(!existeChute){
				erros++;
				letrasErradas[auxLetrasErradas++] = chute;
			}
				
			imprimeForca(erros);
			venceu = imprimeEspacos(espacos); //se não imprimir '_', logo palavra está completa
			imprimeErros(letrasErradas, auxLetrasErradas); //imprime letras ausentes na palavra sorteada
			printf("\n\n****************************************\n");
		} while(!venceu && erros<7);
		
		if(venceu){
			printf("\n   Parabens, voce venceu!\n");
			imprimeTrofeu();
		} else
			printf("\n   Voce perdeu! A palavra era %s!\n",palavraSorteada);
		
		printf("\nJogar novamente? [1-Sim | 2-Nao]\n");
		scanf("%d",&opt);
		
	} while(opt!=2);
	printf("\nAte logo!\n");
	return 0;
}
