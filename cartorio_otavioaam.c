#include <stdio.h>	//biblioteca de comunicacao com o usuario
#include <stdlib.h>	//biblioteca de alocacao de espaco em memoria
#include <locale.h>	//biblioteca de alocacoes de texto por regiao
#include <string.h> //Biblioteca responsavel por cuidar das strings

int registro() //Função responsável por cadastrar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem	
	
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s se refere a salvar uma string

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //Salva o valor do CPF
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e seleciona a opcao incluir (a)
	fprintf(file, ","); // coloca uma virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome); // armazena na string
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //salva o valor do nome
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); //Coloca a virgula entre as palavras
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir e LER (r) o arquivo da variavel cpf
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");	
}

int deletar()
{
	char cpf[40];
	
	printf("Selecione o CPF do usuário que deve ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	
	//para caso não exista o usuário, o sistema vai dar uma mensagem
	FILE *file; //acessa a biblioteca e procura o arquivo
	file = fopen(cpf,"r"); // acha o arquivo e lê (r)
	
	if(file == NULL) //caso não exista o arquivo (file == NULL) ele manda a mensagem de que não existe
	{
		printf("Esse usuario não existe no sistema. \n");
		system("pause");
	}
	
		
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ## \n\n");
	printf("Login de ADM! \n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
	
			system("cls"); //responsavel por limpar a tela
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("\n\n\t ### Cartorio da EBAC ###\n\n"); //Início do MENU
			printf("\t Escolha a opção desejada do menu:\n\n");
			printf("\t 1- Registrar nomes\n");
			printf("\t 2- Consultar Nomes\n");
			printf("\t 3- Deletar Nomes\n\n"); 
			printf("\t 4- Sair do sistema \n\n");
			printf("Opção: ");//Final do MENU
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls");
		
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro();	//chamada de funções (registro)
				break;
				
				case 2:
				consulta(); //chamada de funções (consulta)
				break;
				
				case 3:
				deletar(); //chamada de funções (deletar)
				break;	
				
				case 4:
				printf("Obrigado por utilizar o sistema :)\n");
				return 0;
				break;
				
				default: //caso o usuario escreva outra opção além de 1 - 3, o sistema da essa mensagem abaixo
				printf("\n\n Não existe essa opção, por favor volte ao menu!\n");
				system("pause");
				break;
			} //Fim da selecao
			
		}
	}
	
	else
		printf("Senha incorreta");
	
}


