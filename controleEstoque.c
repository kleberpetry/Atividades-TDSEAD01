#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct produto{
	int codigo;
	char nome[100];
	double valor;
	int estoque;
};
struct produto produtos[50];
int sequencia=0,cont;

cadastro(){
	
}
entrada(){
	
}
ajuste(){
	
}
main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	printf("\nDigite 1 para cadastro de produto");
	printf("\nDigite 2 para entrada de estoque");
	printf("\nDigite 3 para alterar o cadastro");
	printf("\nDigite a opção desejada:");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			//cadastro
		break;
		case 2:
			//entrada estoque
		break;
		case 3:
			//alterar estoque
		break;
		default:
			printf("\nOpção inválida!");
	}
		
	return 0;
}
