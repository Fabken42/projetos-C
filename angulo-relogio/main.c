#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	float calculaAngulo(int hora, int minuto);
	int transformaMinutos(float angulo);
	void imprimeRelogio(int hora, int min, int graus, int minutos);
	
	/* (ponteiro menor) 1 hora - 30° (60 minutos - 30° | 1 minuto - 0.5°)
	(ponteiro maior) 1 minuto - 6°
	6/0.5 = 12. Logo ponteiro maior se move 12x mais rápido que o menor */
	
	float calculaAngulo(int hora, int minuto){
		if(hora>=12)
			hora-=12;
		float grauMinuto = minuto*6;
		float grauHora = hora*30 + (grauMinuto/12);
		float result = (grauMinuto - grauHora);
		if(result<0)
			result*=-1;
		if(result>180)
			result-=180;
		return result; 
	}
	
	int transformaMinutos(float angulo){
		int res = (angulo - floor(angulo))*60;
		return res;	
	}
	
	void imprimeRelogio(int hora, int min, int graus, int minutos){
		printf("        _\n");
		printf("      ,/_\\,\n");
		printf("    ,/_/ \\_\\,\t         O horario ");
		hora>10 ? printf(" %d:",hora) : printf(" 0%d:",hora);
		min>10 ? printf("%d",min) : printf("0%d",min);
		printf("\n   /_/ ___ \\_\\\n");
		printf("  /_/ |(V)| \\_\\");
		printf("\t        forma um angulo de\n");
		printf("    |  .-.  |");
		printf("\t\t     %d%c %d'\n",graus,248,minutos);
		printf("    | / / \\ |\n");
		printf("    | \\ \\ / |\n");
		printf("    |  '-'  |\n");
		printf("    '--,-,--'\n");
		printf("       | |\n");
		printf("       | |\n");
		printf("       | |\n");
		printf("       /\\|\n");
		printf("       \\/|\n");
		printf("        /\\\n");
		printf("        \\/\n");
	};
	
int main(int argc, char *argv[]) {
	int hora=0, min=0, graus, minutos,opt=1;
	float angulo=0;
	do{
		printf("\n ---ANGULO FORMADO ENTRE PONTEIROS---\n\n");
		printf(" Digite o horario no formato HH:MM (ex.: 11:35)\n ");
		scanf("%d : %d",&hora,&min);
		printf("\n-------------------------------------------------\n");
		if((hora<0 || hora>23) || (min<0 || min>59))
			printf("\n Horario digitado invalido!\n");
		else{
			angulo = calculaAngulo(hora, min);
			graus = angulo; //graus (int) ficará só com parte inteira do ângulo
			minutos = transformaMinutos(angulo);
			imprimeRelogio(hora,min,graus,minutos);
			
			printf("\n-------------------------------------------------\n");
		}
		printf("\n Deseja continuar? [1-SIM | 2-NAO]: ");
		scanf("%d",&opt);
	} while(opt!=2);
	return 0;
}
