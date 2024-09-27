#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()//Função responsavel pelo cadastro no sistema
{
	//Inicio criação de variáveis/strings
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s = Strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo / "w" = Write(escrever)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" serve pra atualizar o arquivo
	fprintf(file,","); // a , realmente é pra ,
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //%s é pra string
	
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
	file = fopen (cpf,"r"); // "r" é de READ (ler)
	
	if(file== NULL)	
	{
		printf ("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	// \n é pra pular linha
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
		printf("O usuário não se encontra no sistema!.\n");
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
	
		printf("## Cartorio EBAC ##\n\n");//as # são só pra ter um espacinho
		printf("Escolha a opção desejada do menu:\n\n");// o \n serve pra pular uma linha
		printf("\t1 - Registrar nomes\n");// o \t serve pra dar um espaço antes da da frase.
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:");//fim do menu

	
		scanf("%d",&opcao);//Armazenando a escolha do usário (%d é usado exclusivamente com números decimais inteiros)
	
		system("cls");
	
		switch(opcao)//inicio da seleção de menu
		{
			case 1:
			registro();//chamada de funções
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
			printf("Essa opção não esta disponivel.\n");
			system("pause");
			break;	
		}	//fim da seleção
	}
	}
