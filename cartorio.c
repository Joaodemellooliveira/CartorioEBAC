#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o para registro de nomes
{
	setlocale(LC_ALL,"portuguese"); //determinando idioma
	
	char arquivo[40]; // Inicio defini��o de vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // fim defini��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); // solicitando input do usu�rio
	scanf("%s",cpf); // guardando input
	
	strcpy(arquivo,cpf); // Copiando valores de vari�ves, de cpf para arquivo
	
	FILE *file; // solicita fun��o para lidar com arquivo
	file = fopen(arquivo,"w"); // definine atributos do arquivo que ser� criado
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo para edi��o
	fprintf(file,","); // escreve a virgula ap�s dados j� presentes no arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); // solicitando input do usu�rio
	scanf("%s",nome); // guardando input
	
	file = fopen(arquivo,"a"); //abre arquivo para edi��o
	fprintf(file,nome); // escreve valor da vari�vel para o arquivo
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo para edi��o
	fprintf(file,","); // escreve a virgula ap�s dados j� presentes no arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // solicitando input do usu�rio
	scanf("%s",sobrenome); // guardando input
	
	file = fopen(arquivo,"a"); //abre arquivo para edi��o
	fprintf(file,sobrenome); // escreve valor da vari�vel para o arquivo
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo para edi��o
	fprintf(file,","); // escreve a virgula ap�s dados j� presentes no arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // solicitando input do usu�rio
	scanf("%s",cargo); // guardando input
	
	file = fopen(arquivo,"a"); //abre arquivo para edi��o
	fprintf(file,cargo); // escreve valor da vari�vel para o arquivo
	fclose(file); // fecha arquivo
	
	system("pause");
}

int consulta() // fun��o para cosulta de nomes
{
	setlocale(LC_ALL,"portuguese"); //determinando idioma
	
	char cpf[40]; // Inicio defini��o de vari�veis
	char conteudo[200]; // fim defini��o de vari�veis
	
	printf("Digite o CPF a ser consultado: "); // solicitando input do usu�rio
	scanf("%s",cpf); // guardando input
	
	FILE *file; // solicita fun��o para lidar com arquivo
	file = fopen(cpf,"r"); // definine atributos ao lidar com o arquivo
	
	
	if(file == NULL) // definindo resposta para o caso de arquivo inexistente
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Loop para passsar valor do arquivo para vari�vel
	{
		printf("\nEstas s�o as informa�oes do usu�rio: "); // exibindo informa��o ao usu�rio
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file); //Fechando arquivo ao fim da consulta
	}
	
	system("pause");
	
}

int deletar() // fun��o para deletar nomes
{
	setlocale(LC_ALL, "portuguese"); //determinando idioma
	
	char cpf[40]; //definindo vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Pedindo Input ao usu�rio
	scanf("%s",cpf); //captando input
	
	
	FILE*file; // consultando existencia do CPF a ser deletado
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso usu�rio inexistente
	{
		printf("\nO usu�rio n�o se encontra no sistema\n\n");
		system("pause");
	}
	
	else //caso usu�rio existente
	{
		fclose(file);
		remove(cpf);
		printf("\nO usu�rio foi deletado com sucesso\n\n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0; // definindo vari�vel de op��o do menu
	int laco=1; // definindo vari�vel do la�o do menu
	char senhadigitada[10]="a"; // Definindo vari�vel para captar senha do usus�rio, com valor padr�o "a"
	int comparacao; // definindo vari�vel para execu��o da condicional if
	
	printf("\t### Cart�rio da EBAC ###\n\n"); // Inicio login do administrador
	printf("Login de administrador!\n\nDigite a sua senha: "); // solicitando input do usu�rio
	scanf("%s",senhadigitada); // Guardando Input recebido
	
	comparacao = strcmp(senhadigitada, "admin"); //comparando string recebido contra o pr� determinado e salvando integer como valor da vari�vel
	
	if(comparacao == 0) // Inicio condicional para acesso do admin
	{
		system("cls"); //Limpeza de tela para menu
		
		for(laco=1;laco=1;) // Inicio la�o para retorno ao menu
		{
			system("cls"); //limpeza de tela para la�o
		
			setlocale(LC_ALL, "portuguese"); //determinando idioma
	
			printf("\t### Cart�rio da EBAC ###\n\n"); // Inicio tela menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
		
			printf("Desenvolvido por Jo�o de Mello \n sob a supervis�o da EBAC\n\n"); 
			printf("Op��o: "); // fim tela menu
	
			scanf("%d",&opcao); //armazenando input do usu�rio
		
			system("cls");
		
			switch (opcao) // inicio da sele��o
			{
				case 1:
					registro();
				break;
				
				case 2:
					consulta();
				break;
				
				case 3:
					deletar();
				break;
				
				case 4: // Op��o sair do sistema
					printf("Obrigado por utilizar o sistema\n");
					return 0; // encerra o sistema
				break;
		
				default: // op��o padr�o
					printf("Esta op��o n�o est� disponivel\n");
					system("pause");
				break;
				
			} // fim da sele��o
		} // Fim la�o de retorno ao menu
	} // fim para acesso do admin
	else // retorno padr�o para senha incorreta
	{
		system("cls"); //Limpeza de tela para senha incorreta
		printf("\nSenha incorreta\n");
	}
}
