#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "unistd.h"
#include "ctype.h"
#define max 10
char SISTEMA;
char apresenta(){
	/*
	.::::.  ::      .::::.  ||
	::  ::  ::      ::  ::  ||
	::  ::  ::      ::::::  ||
	*::::*  ::::::  ::  ::  ::
    */
	printf("\t.::::.  ::      .::::.  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::  ::  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::::::  ||\n");
	usleep(200000);
	printf("\t*::::*  ::::::  ::  ::  ::\n\n");
	printf("\tPOR GENTILEZA, INFORME QUAL SISTEMA OPERACIONAL VC UTILIZA:\nD=DOS\nU=UNIX\n\n");
	printf("\tDUVIDAS? DIGITE (i) PARA MAIS INFORMAÇÕES\n");
	pergunta:
	fflush(stdin);
	scanf("%c",&SISTEMA);
	SISTEMA=toupper(SISTEMA);
	switch(SISTEMA){
		case 'D':
		system("cls");
		fflush(stdin);
		break;
		case 'U':
		system("clear");
		fflush(stdin);
		break;
		case 'I':
		printf("\nDOS = Window\nUNIX = Mac e Linux(há exeções)");
		getchar();
		goto pergunta;
		break;
		default:
		printf("\nENTRADA INVALIDA, FAVOR DIGITAR SOMENTE AS LETRAS INDICADAS\n");
		goto pergunta;
	}
	return SISTEMA;
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL,"portuguese");
	int totpessoas, contatot=0, resposta;
	apresenta();
	pergunta:
	printf("quantas pessoas sairam juntas?\n");
	scanf("%d",&totpessoas);
	if (totpessoas>max)
	{
		printf("por definição o valor máximo é 10\n");
		sleep(3);
		getchar();
		if (SISTEMA=='U')
			system("clear");
		else
			system("cls");
		goto pergunta;
	}
	int *v = (int*) malloc( totpessoas * sizeof(int));
	for (int i = 0; i <totpessoas;i++){
		printf("valor da %dª conta: ",i+1);
		scanf("%d",&v[i]);
	}
	for (int i = 0; i < totpessoas; i++)
		contatot+=v[i];
	printf("qual a soma das contas?\n");
	scanf("%d",&resposta);
	if (resposta==contatot)
		printf("acertô mizeravi!\n");
	else
		printf("pooxa, não foi dessa vez q vc conseguiu :/\n");
	return 0;
}
