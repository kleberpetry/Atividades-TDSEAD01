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
	system("cls");
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	printf("\nDigite o valor do produto: ");
	scanf("%lf",&produtos[sequencia].valor);
	printf("\nDigite o estoque do produto: ");
	printf("%d",&produtos[sequencia].estoque);
	produtos[sequencia].codigo=sequencia+1;
	sequencia++;
}
entrada(){
	
}
ajuste(){
	
}
listagem(){
	system("cls");
	for(cont=0;cont<sequencia;cont++){
		printf("\n-----------------------------");
		printf("\nCódigo: %d",produtos[cont].codigo);
		printf("\nNome: %s",produtos[cont].nome);
		printf("\nValor: %0.2lf",produtos[cont].valor);
		printf("\nEstoque: %d",produtos[cont].estoque);
	}
	system("pause");
}
main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	do{
		system("cls");
		printf("\nDigite 1 para cadastro de produto");
		printf("\nDigite 2 para entrada de estoque");
		printf("\nDigite 3 para alterar o cadastro");
		printf("\nDigite 4 para listagem de produtos");
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
			case 4:
				//listagem dos produtos
			break;
			default:
				printf("\nOpção inválida!");
		}
	}while(opcao!=0);
		
	return 0;
}
