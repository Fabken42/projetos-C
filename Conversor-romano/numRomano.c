#include <stdio.h>
#include <stdlib.h>

int imprimeMenu();
void converteDecimal(int n);
void converteRomano(char romano[]);


	int imprimeMenu(){
		int opt=0,n,i=0;
		char romano[25]={};
			printf(" 1- Converter algarismo romano para decimal\n 2- Converter algarismo decimal para romano\n 3- sair\n\n Opcao: ");
			scanf("%d",&opt);
			printf("--------------------------------------------------\n");
			
			switch(opt){
				case 1:
					printf(" Digite um valor em romano [ex.: XVII]: ");
					scanf("%s",romano);
					//transforma letras em maiúsculas
					while(romano[i]){
						romano[i] = toupper(romano[i]);
						i++;
					}
					converteRomano(romano);
					break;
					
				case 2:
					printf(" Digite um valor em decimal [1 - 3999]: ");
					scanf("%d",&n);
					if(n<1 || n>3999){
						printf("\n Valor digitado nao pertence ao intervalo!\n\n");
						opt=0;
					}
					else{
						printf("\n\t%d = ",n);
						converteDecimal(n);
					}
					break;
					
				case 3:
					printf("\n Ate logo!\n");
					break;
					
				default:
					printf("\n Opcao invalida!\n");
			}
		printf("\n--------------------------------------------------\n");
		return opt;
	}
	
	//converte decimal em romano
	void converteDecimal(int n){
		do{ //'continue' onde repeticao é possível (M,C,X) | 'break' em 9 e 4, pois sabe-se que resto = 0 | valor 1 tem loop próprio
			if(n>=1000){
				printf("M"); n-=1000;
				continue;
			}
			if(n>=900){
				printf("CM"); n-=900;
			}
			if(n>=500){
				printf("D"); n-=500;
			}
			if(n>=400){
				printf("CD"); n-=400;
			}
			if(n>=100){
				printf("C"); n-=100;
				continue;
			}
			if(n>=90){
				printf("XC"); n-=90;
			}
			if(n>=50){
				printf("L"); n-=50;
			}
			if(n>=40){
				printf("XL"); n-=40;
			}
			if(n>=10){
				printf("X"); n-=10;
				continue;
			}
			if(n==9){
				printf("IX");
				break;
			}
			if(n>=5){
				printf("V"); n-=5;
			}
			if(n==4){
				printf("IV");
				break;
			}
			if(n>=1){
				while(n>=1){
				printf("I");
				n--;
				}
			}
		} while(n>0);
		return;
	}
	
	// Converte romano em decimal
	void converteRomano(char romano[]){
		int i=0, s=0, valido, atual=0, corrige=0, qtd[12]={}; //qtd[] conta quantas vezes que cada valor aparece (ex.: MMM => qtd[0]=3)
		
		do{
			valido = 0; // se ao final do loop valido = 0, entao letra é inválida (ex.: 'A') 
			
			if(romano[i]=='M'){
				if(atual>1) // se atual maior que 1 (num mágico), valor deve ser corrigido (ex.: XM => MX)
					corrige = 1;
				atual=1; qtd[atual-1]++; valido = 1;
				s+=1000;
			}
			if(romano[i]=='C' && romano[i+1]=='M'){
				if(atual>2 || romano[i+2]=='D') //CMD precisa ser corrigido, pois correto seria MCD
					corrige = 1;
				atual=2; qtd[atual-1]++; valido = 1;
				s+=900;
				i++;
			}
			if(romano[i]=='D'){
				if(atual>3)
					corrige = 1;
				atual=3; qtd[atual-1]++; valido = 1;
				s+=500;
			}
			if(romano[i]=='C' && romano[i+1]=='D'){
				if(atual>4)
					corrige = 1;
				atual=4; qtd[atual-1]++; valido = 1;
				s+=400;
				i++;
			}
			if(romano[i]=='C'){
				if(atual>5)
					corrige = 1;
				atual=5; qtd[atual-1]++; valido = 1;
				s+=100;
			}
			if(romano[i]=='X' && romano[i+1]=='C'){
				if(atual>6 || romano[i+2]=='L') //XCL precisa ser corrigido, pois correto seria CXL
					corrige = 1;
				atual=6; qtd[atual-1]++; valido = 1;
				s+=90;
				i++;
			}
			if(romano[i]=='L'){
				if(atual>7)
					corrige = 1;
				atual=7; qtd[atual-1]++; valido = 1;
				s+=50;
			}
			if(romano[i]=='X' && romano[i+1]=='L'){
				if(atual>8)
					corrige = 1;
				atual=8; qtd[atual-1]++; valido = 1;
				s+=40;
				i++;
			}
			if(romano[i]=='X'){
				if(atual>9)
					corrige = 1;
				atual=9; qtd[atual-1]++; valido = 1;
				s+=10;
			}
			if(romano[i]=='I' && romano[i+1]=='X'){
				if(atual>10 || romano[i+2]=='V') //IXV precisa ser corrigido, pois correto seria XIV
					corrige = 1;
				atual=10; qtd[atual-1]++; valido = 1;
				s+=9;
				i++;
			}
			if(romano[i]=='V'){
				if(atual>11)
					corrige = 1;
				atual=11; qtd[atual-1]++; valido = 1;
				s+=5;
			}
			if(romano[i]=='I' && romano[i+1]=='V'){
				if(atual>12)
					corrige = 1;
				atual=12; qtd[atual-1]++; valido = 1;
				s+=4;
				i++;
			}
			if(romano[i]=='I'){
				if(atual>13)
					corrige = 1;
				atual=13; qtd[atual-1]++; valido = 1;
				s+=1;
			}
			i++;
		} while(romano[i] && valido);
		
		for(i=0;i<13;i++){
			if(i%4 && qtd[i]>1) //CM D CD XC L XL IX V IV podem aparecer no máx uma vez no valor digitado pelo usuário
				corrige = 1;
			else if(qtd[i]>3) //M C X I podem aparecer no máx 3 vezes
				corrige = 1;
		}
		if(s>3999) // valor não pode ser representado, pois excede 
			printf("\n Valor excede limite de '3999'!\n");
		else if(!(valido)) 
			printf("\n    Valor digitado eh invalido!\n [contem caracteres diferentes de MDCLXVI]\n");
		else{
			if(!(corrige)) //valor que não precisou ser corrigido
				printf("%s = %d",romano,s);
			else{
				printf("\n   %c Valor corrigido %c \n\n\t",25,25);
				converteDecimal(s);
				printf(" = %d",s);
			}
		}
		return;
	}


int main(int argc, char *argv[]) {
	int opt=0;
	
	do{
		printf("\n\t  ---CONVERSOR ROMANO---\n\n");
		opt = imprimeMenu();
	} while(opt!=3); //opt '3' para sair
	
	return 0;
}
