#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings
	
int Registro() // função responsável por cadastrar o usuário no sistema 
{
	// inicio da criação de variáveis/string
	char arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	// fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", CPF); // %s refere-se a string
	
	strcpy(arquivo, CPF); // responsável por copiar os valores das strings

	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,CPF); // salva o valor da variável
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
		printf(" Não foi possível abrir o arquivo, não localizado!. \n");
	}
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
		system("pause");
	
	
}

int Deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O USUÁRIO NÃO SE ENCONTRA NO SISTEMA!. \n");
		system("pause");		
	}
	
}


int main ()
	{
	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a Opção Desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n"); 
		printf("\t2 - Consultar Nomes\n"); 
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");  // fim do menu
		
		scanf("%d", &opcao); // armazenando a esclha do usuário
		
		system("cls"); // responsável por limpar a tela
		
		switch(opcao) // início da seleção do menu
		{
		
			case 1:
			Registro(); // chamada de função
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
			printf("Esta opção não está disponivel \n\n\n\n");
			system("pause");
			break;	
		} // fim da seleção do menu
		
	}	
}
