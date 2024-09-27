#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memo�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//Fun��o responsavel pelo cadastro no sistema
{
	//Inicio cria��o de vari�veis/strings
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s = Strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / "w" = Write(escrever)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" serve pra atualizar o arquivo
	fprintf(file,","); // a , realmente � pra ,
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //%s � pra string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen (cpf,"r"); // "r" � de READ (ler)
	
	if(file== NULL)	
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	// \n � pra pular linha
	}
	
	system("pause");
	
}

int deletar ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Escolha o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// r de read(ler)
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()//int serve pra armazenar algo.
	{
	int opcao=0;//Definindo variaveis
	int test=1;
	
	for(test=1;test=1;)//serve pra fazer a "volta", voltar a tela inicial do programa
	{
	
		system("cls");//serve pra limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo Linguagem
	
		printf("## Cartorio EBAC ##\n\n");//as # s�o s� pra ter um espacinho
		printf("Escolha a op��o desejada do menu:\n\n");// o \n serve pra pular uma linha
		printf("\t1 - Registrar nomes\n");// o \t serve pra dar um espa�o antes da da frase.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:");//fim do menu

	
		scanf("%d",&opcao);//Armazenando a escolha do us�rio (%d � usado exclusivamente com n�meros decimais inteiros)
	
		system("cls");
	
		switch(opcao)//inicio da sele��o de menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta ();
			break;
			
			case 3:
			deletar ();
			break;
			
			case 4:
			printf("Obrigado porutilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel.\n");
			system("pause");
			break;	
		}	//fim da sele��o
	}
	}
