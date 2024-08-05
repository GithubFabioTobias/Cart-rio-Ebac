#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings
	
int Registro() // fun��o respons�vel por cadastrar o usu�rio no sistema 
{
	// inicio da cria��o de vari�veis/string
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	// fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", CPF); // %s refere-se a string
	
	strcpy(arquivo, CPF); // respons�vel por copiar os valores das strings

	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,CPF); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", Nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, Sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", Cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, Cargo);
	fclose(file);
	
	system("pause");
	
}

int Consulta()
{	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char CPF[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", CPF);
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if(file == NULL)
	{
		printf(" N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
		system("pause");
	
	
}

int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O USU�RIO N�O SE ENCONTRA NO SISTEMA!. \n");
		system("pause");		
	}
	
}


int main ()
	{
	int opcao=0; // definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a Op��o Desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n"); 
		printf("\t2 - Consultar Nomes\n"); 
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: ");  // fim do menu
		
		scanf("%d", &opcao); // armazenando a esclha do usu�rio
		
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) // in�cio da sele��o do menu
		{
		
			case 1:
			Registro(); // chamada de fun��o
			break;
			
			case 2:
			Consulta();
			break;
			
			case 3:
			Deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o Sistema!\n");
			return 0;
			break;
		
			default:
			printf("Esta op��o n�o est� disponivel \n\n\n\n");
			system("pause");
			break;	
		} // fim da sele��o do menu
		
	}	
}
