#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


	int sorteiaNum();
	int escolheNivel();
	int joga(int *numTentativas, int chances);
	int analisaVal(int sorteado,int chute, int numTentativas, int chances, int *vitoriasSeg);
	void chegouPerto(int sorteado, int chute);
	void imprimeTrofeu();
	void imprimeRobo();

	int sorteiaNum(){
		int n;
		n = rand()%100+1;
		return n;
	}

	int escolheNivel(){
		int c=0,opt;
		do{
			printf("Selecione a dificuldade:\n1- Facil   (8 tentativas)\n2- Medio   (6  tentativas)\n3- Dificil (4  tentativas)\n");
			printf("\nOpcao: ");
			scanf("%d",&opt);
			// c = numero de chances a depender de dificuldade
			switch(opt){
				case 1:
					c=8;
					break;
				case 2:
					c=6;
					break;
				case 3:
					c=4;
					break;
				default:
					printf("\nPor favor selecione uma opcao valida!\n\n");
			}
		} while(c==0);
		return c;
	}
	
	int joga(int *numTentativas, int chances){
		int chute;
		while(1){
		printf("\nSeu palpite [%d/%d]: ",*numTentativas+1,chances);
		scanf("%d",&chute);
		*numTentativas+=1;
			//Verifica se valor é inválido
			if(chute<1 || chute>100){
				printf("\nPor favor digite um valor valido! [1-100]\n");
				printf("------------------------------------------");
				*numTentativas-=1;
				continue;
			}
			else return chute;
		}
	}
	
	int analisaVal(int sorteado,int chute, int numTentativas, int chances,int *vitoriasSeg){
		//JOGADOR VENCE
		if(chute==sorteado){
			*vitoriasSeg+=1;
			printf("\nUau! Voce acertou em %d tentativas!\n",numTentativas);
			printf("Vitorias consecutivas: %d\n",*vitoriasSeg);
			imprimeTrofeu();
			return 1;
		} //JOGADOR PERDE
		if(numTentativas==chances){
			*vitoriasSeg=0;
			chegouPerto(sorteado, chute);
			return 1;
		}
		//DAR DICA PARA JOGADOR
		printf("\n---------------------------------\n");
		(sorteado>chute) ? printf("\nMais alto...\n") : printf("\nMais baixo...\n");
		return 0;
	}
	
	void chegouPerto(int sorteado, int chute){
		//Compara ultimo chute do jogador com valor sorteado
		if(abs(sorteado-chute)<5)
			printf("\nUff! Voce chegou muito perto!\n");
		else if(abs(sorteado-chute)<10)
			printf("\nEh... Ate que voce chegou perto!\n");
		else
			printf("\nEssa passou meio longe. Tente na proxima!\n");
			
		imprimeRobo();
		printf("\nEstava pensando no numero %d.\n",sorteado);
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
		
	void imprimeRobo(){ //imprime se jogador perde
		printf("           __\n");
		printf("   _(\\    |@@|\n");
		printf("  (__/\\__ \\--/ __\n");
		printf("     \\___|----|  |   __\n");
		printf("         \\ }{ /\\ )_ / _\\\n");
		printf("         /\\__/\\ \\__O (__\n");
		printf("        (--/\\--)    \\__/\n");
		printf("        _)(  )(_\n");
		printf("       `---''---`\n");
	}

int main(int argc, char *argv[]) {
	int sorteado, chute, chances, fim=0, numTentativas=0, opt,vitoriasSeg=0;
	srand(time(NULL));
	do{
		printf("\n  	  ----JOGO DA ADIVINHACAO----\n\n");
		printf(" Tente descobrir em que numero [1-100] estou pensando...\n");
		printf("---------------------------------------------------------\n");
		
		sorteado = sorteiaNum();
		chances = escolheNivel();
		//O bloco de repetição abaixo representa uma partida
		do{	
			chute = joga(&numTentativas, chances);
			fim = analisaVal(sorteado, chute, numTentativas, chances, &vitoriasSeg);
		} while(!fim);
		
		printf("\nDeseja jogar novamente? [1-SIM | 2-NAO]: ");
		scanf("%d",&opt);
		fim=0; numTentativas=0;
		
	} while(opt!=2);
	printf("\nAte logo!");
	return 0;
}
