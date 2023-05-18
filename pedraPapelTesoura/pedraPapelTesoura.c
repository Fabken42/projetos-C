#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int i,sorteado, jogada,seqVitorias=0, continuar=2;
	char* jogadaPC[3]={"pedra","papel","tesoura"};
	do{
	sorteado = rand()%3+1;//1,2,3 para pedra,papel,tesoura
	printf("\n---Pedra Papel ou Tesoura---\n");
	printf("\n-------------------------------------\n");
	printf("\nSequencia de vitorias: %d\n",seqVitorias);
	
	do{
		printf("\n1- Pedra\n2- Papel\n3- Tesoura\n");
		scanf("%d",&jogada);
		if(jogada>=1 && jogada<=3)
			break;
		else printf("\nOpcao invalida!\n");
	} while(1);
	printf("\n-------------------------------------\n");
	
	if(sorteado == jogada) //empate
		printf("\nEmpate! Ambos escolheram %s\n",jogadaPC[sorteado-1]);
		
	else if((sorteado==1 && jogada==2)||(sorteado==2 && jogada==3)||(sorteado==3 && jogada==1)){ //jogador ganha
		printf("\nVoce venceu! O computador jogou %s\n",jogadaPC[sorteado-1]);
		seqVitorias++;
	}
	else{ //jogador perde
		printf("\nVoce perdeu! O computador jogou %s\n",jogadaPC[sorteado-1]);
		seqVitorias=0;
	}
	
	printf("\nJogar novamente? [1-Nao | 2-Sim]\n");
	scanf("%d",&continuar);
	} while(continuar-1);
	printf("\nAte logo!\n");
	return 0;
}
