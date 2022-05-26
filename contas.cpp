/*
programa para movimentar contas bancarias
*/

#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

//VARIAVEIS GLOBAIS EXISTEM E TODO CÓDIGO
char numeroAgencia1[10];/*sequencia 10 de caracteres para o numero da agencia da primeira conta*/
char numeroConta1[20];/*sequencia 20 de caracteres para o numero da conta da primeira conta*/
float saldo1;/*saldo da primeira conta*/

char numeroAgencia2[10];/*sequencia 10 de caracteres para o numero da agencia da segunda conta conta*/
char numeroConta2[20];/*sequencia 20 de caracteres para o numero da conta da segunda conta*/
float saldo2;/*saldo da segunda conta*/
/*
dividir em problemas menores,
-melhora a manutenção
-leitura,
-reutlização do código
-agilidade de resolução de problemas
*/

int verificar_qual_e_a_conta(char agencia[10], char conta[20]){
	if(strcmp( agencia, numeroAgencia1)==0 ){
		if(strcmp(conta,numeroConta1)==0){
			
			return 1;
			
		}else{
			printf("numero da conta errado");
		}
	}else if(strcmp(agencia, numeroAgencia2)==0){
		if(strcmp(conta, numeroConta2)==0){
			return 2;
		}
		else{
			printf("numero da conta errado");
		}
	}else{
		printf("numero da agencia errada");
	}
}


/*função void(não retorna valor) deposito perguntará para o usuario o numero da conta*/
void deposito(){
	/*variaveis locais ssó extem nessa função*/
	char numeroAgDeposito[10];
	char numeroContaDeposito[20];
	float valorDeposito;
	int conta;

	printf("********operação*depósito*******\n");

	printf("Informe o numero da agencia:");
	scanf("%s",numeroAgDeposito);
	/*
		nao usa & para receber porque em c o tipo string é um ponteiro
	*/
	printf("Informe o numero da conta:");
	scanf("%s",numeroContaDeposito);
	
	printf("Informe o valor R$:");
	scanf("%f",&valorDeposito);
	
	/*Procurar qual a conta existente que vai receber o depósito*/
	
	//verificar se a conta 1 que vai receber o depósito
	/*no C as strings são listas então nao pode usar o == para comparar por essa razão usa a biblioteca de string*/
	/*
	strcmp(): fala quantos caracteres se diferem,
	então se for zero o numero de caracteres a s strings são identicas
	
	*/
	
	conta = verificar_qual_e_a_conta(numeroAgDeposito, numeroContaDeposito);
	
	if(conta==1){
		saldo1+=valorDeposito;
	}
	if(conta==2){
		saldo2+=valorDeposito;
	}
	
	
}




void transferencia(){
	//variaveis de entrada
	char numeroAg1Tranferencia[10];
	char numeroConta1Tranferencia[20];
	char numeroAg2Tranferencia[10];
	char numeroConta2Tranferencia[20];
	
	int qual_conta_tirar;
	int qual_conta_receber;
	
	float quanto_transferir;
	
	float saldo_tirar;
	float saldo_receber;
	
	printf("\n********operação*transferencia*******\n");
	//saber de qual conta transferir
	printf("Digite o numero da sua Agencia: ");
	scanf("%s", numeroAg1Tranferencia);
	
	printf("Digite o numero da sua conta: ");
	scanf("%s", numeroConta1Tranferencia);
	
	qual_conta_tirar=verificar_qual_e_a_conta(numeroAg1Tranferencia, numeroConta1Tranferencia);
	
	if(qual_conta_tirar==1){
		saldo_tirar=saldo1;
	}
	if(qual_conta_tirar==2){
		saldo_tirar=saldo2;
	}
	
	//perguntar qual é a conta que vai transferir
	printf("Digite o numero da Agencia que vai o dinheiro: ");
	scanf("%s", numeroAg2Tranferencia);
	
	printf("Digite o numero da conta: ");
	scanf("%s", numeroConta2Tranferencia);
	
	qual_conta_receber=verificar_qual_e_a_conta(numeroAg2Tranferencia, numeroConta2Tranferencia);

	if(qual_conta_receber==1){
		saldo_receber=saldo1;
	}
	if(qual_conta_receber==2){
		saldo_receber=saldo2;
	}

	printf("quanto transferir?: ");
	scanf("%f", &quanto_transferir);
	
	saldo_tirar= saldo_tirar-quanto_transferir;
	saldo_receber+=quanto_transferir;
	
	if(qual_conta_tirar==1){
		saldo1=saldo_tirar;
	}
	if(qual_conta_tirar==2){
		saldo2=saldo_tirar;
	}
	
	if(qual_conta_receber==1){
		saldo1=saldo_receber;
	}
	if(qual_conta_receber==2){
		saldo2=saldo_receber;
	}
	
	
}



void extrato(){
	//entrada
	char numero_da_agencia[20];
	char numero_da_conta[10];
	int conta;
	
	printf("digite o numero da sua agencia: ");
	scanf("%s", numero_da_agencia);
	printf("digite o numero da sua conta: ");
	scanf("%s", numero_da_conta);
	
	conta=verificar_qual_e_a_conta(numero_da_agencia, numero_da_conta);
	if(conta==1){
		printf("\nO saldo é de R$ %f", saldo1);
	}
	if(conta==2){
		printf("\nO saldo é de R$ %f", saldo2);
	}
}

void saque(){
	//variaveis de entrada
	char numeroAgSaque[10];
	char numeroContaSaque[20];
	float quanto_sacar;
	printf("\n********operação*saque*******\n");
	//saber de qual conta sarca
	printf("Digite o numero da Agencia: ");
	scanf("%s", numeroAgSaque);
	
	printf("Digite o numero da conta: ");
	scanf("%s", numeroContaSaque);
	
	printf("quanto sacar?: ");
	scanf("%f", &quanto_sacar);
	
	if(strcmp(numeroAgSaque, numeroAgencia1)==0 ){
		if(strcmp(numeroContaSaque,numeroConta1)==0){
			
			//tirar do saldo quanto ira sacar
			saldo1=saldo1-quanto_sacar;
			//finalizar
			printf("saldo efetuado");
		}else{
			printf("numero da conta errado");
		}
	}else if(strcmp(numeroAgSaque, numeroAgencia2)==0){
		if(strcmp(numeroContaSaque, numeroConta2)==0){
			saldo2=saldo2-quanto_sacar;
			printf("saldo efetuado");
		}
		else{
			printf("numero da conta errado");
		}
	}else{
		printf("numero da agencia errada");
	}
	
	
}
/*função principal*/
int main(){
	bool continuar=true;
	setlocale(LC_ALL, "pt");
	//Abrir duas contas
	/*Cadastro conta 1*/
	printf("Informe o numero da agencia da conta 1: ");
	scanf("%s", numeroAgencia1);
	
	printf("Informe o numero da conta 1: ");
	scanf("%s", numeroConta1);
	
	printf("digite o saldo da conta1 em reais:");
	scanf("%f", &saldo1);
	/*Cadastro conta 2*/
	printf("Informe o numero da agencia da conta 2: ");
	scanf("%s", numeroAgencia2);
	
	printf("Informe o numero da conta 2: ");
	scanf("%s", numeroConta2);
	
	printf("digite o saldo da conta2 em reais:");
	scanf("%f", &saldo2);
	
	
	while(continuar){
		/*escolher função*/
		int fazer;
		printf("\n->O que fazer?<-\n1-deposito\n2-saque\n3-transferencia\n4-extrato\n5-Finalizar\n->");
		scanf("%d", &fazer);
		switch(fazer){
		case 1:
			deposito();
			break;
		case 2:
			saque();
			break;
		case 3:
			transferencia();
			break;
		case 4:
			extrato();
			break;
		case 5:
			continuar=false;
			break;
		default:
			break;
	}
	}
	

	return 0;
}
