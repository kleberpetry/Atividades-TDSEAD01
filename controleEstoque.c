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
int sequencia=0,cont,nvendas=0;
double vendas[50];

cadastro(){
	system("cls");
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	printf("\nDigite o valor do produto: ");
	scanf("%lf",&produtos[sequencia].valor);
	printf("\nDigite o estoque do produto: ");
	scanf("%d",&produtos[sequencia].estoque);
	produtos[sequencia].codigo=sequencia+1;
	sequencia++;
}
entrada(){
	system("cls");
	int codigo,achou;
	printf("\nDigite o código do produto: ");
	scanf("%d",&codigo);
	for(cont=0;cont<sequencia;cont++){
		if(produtos[cont].codigo==codigo){
			printf("\nEstoque atual: %d",produtos[cont].estoque);
			printf("\nDigite o valor de entrada: ");
			int entrada;
			scanf("%d",&entrada);
			produtos[cont].estoque+=entrada;
			printf("\nEstoque atualizado, novo estoque: %d\n",produtos[cont].estoque);
			achou=1;
			break;
		}else{
			achou=0;
		}
	}
	if(achou==0){
		printf("\nProduto não encontrado!\n");
	}
	system("pause");
}
ajuste(){
	system("cls");
	int codigo, achou;
	printf("\nDigite o código do produto: ");
	scanf("%d",&codigo);
	for(cont=0;cont<sequencia;cont++){
		if(produtos[cont].codigo==codigo){
			printf("\nCódigo: %d",produtos[cont].codigo);
			printf("\nNome: %s",produtos[cont].nome);
			printf("\nValor: %0.2lf",produtos[cont].valor);
			printf("\nDigite o novo nome do produto: ");
			fflush(stdin);
			gets(produtos[cont].nome);
			printf("\nDigite o novo valor do produto: ");
			scanf("%lf",&produtos[cont].valor);
			printf("\nCadastro atualizado com sucesso!\n");
			achou=1;
			break;
		}else{
			achou=0;
		}
	}
	if(achou==0){
		printf("\nProduto não encontrado!\n");
	}
	system("pause");
}
listagem(){
	system("cls");
	if(produtos[0].codigo!=NULL){
		for(cont=0;cont<sequencia;cont++){
			printf("\n-----------------------------");
			printf("\nCódigo: %d",produtos[cont].codigo);
			printf("\nNome: %s",produtos[cont].nome);
			printf("\nValor: %0.2lf",produtos[cont].valor);
			printf("\nEstoque: %d\n",produtos[cont].estoque);
		}
	}else{
		printf("\nSem produtos cadastrados!\n");
	}
	
	system("pause");
}
venda(){
	system("cls");
	int codigo,qtde,continuar,ok;
	double subtotal, total;
	do{
		system("cls");
		printf("\nDigite o código do produto: ");
		scanf("%d",&codigo);
		for(cont=0;cont<sequencia;cont++){
			if(produtos[cont].codigo==codigo){
				printf("\nNome do produto: %s",produtos[cont].nome);
				printf("\nInsira a quantidade do produto: ");
				scanf("%d",&qtde);
				if(produtos[cont].estoque>0 && produtos[cont].estoque>=qtde){
					subtotal=produtos[cont].valor*qtde;
					total+=subtotal;
					printf("\nSubtotal da venda: %0.2lf\n",subtotal);
					ok=1;
					break;
				}else{
					printf("\nEstoque insuficiente!\n");
					ok=0;
					system("pause");
					break;
				}
			}
		}
		if(ok==1){
			printf("\nDeseja incluir mais algum produto: ");
			printf("\n1 para sim - 2 para não");
			printf("\nOpção: ");
			scanf("%d",&continuar);
		}else{
			printf("\nProduto sem estoque ou não cadastrado\n");
			printf("\nDeseja continuar? 1 sim 2 não");
			scanf("%d",&continuar);
		}
	}while(continuar!=2);
	printf("\nTotal da venda é: %0.2lf\n",total);
	vendas[nvendas]=total;
	nvendas++;
	system("pause");
}
relatorio(){
	system("cls");
	if(vendas[0]>0){
		for(cont=0;cont<nvendas;cont++){
			printf("\n--------------------------\n");
			printf("\n venda n%d: %0.2lf\n",cont+1,vendas[cont]);
		}
	}else{
		printf("\nNão existe vendas lançadas!\n");
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
		printf("\nDigite 5 para venda");
		printf("\nDigite 6 para relatório de vendas");
		printf("\nDigite a opção desejada:");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				cadastro();
			break;
			case 2:
				entrada();
			break;
			case 3:
				ajuste();
			break;
			case 4:
				listagem();
			break;
			case 5:
				venda();
			break;
			case 6:
				relatorio();
			break;
			default:
				printf("\nOpção inválida!");
		}
	}while(opcao!=0);
		
	return 0;
}
