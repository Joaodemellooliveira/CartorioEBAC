#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função para registro de nomes
{
	setlocale(LC_ALL,"portuguese"); //determinando idioma
	
	char arquivo[40]; // Inicio definição de variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // fim definição de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); // solicitando input do usuário
	scanf("%s",cpf); // guardando input
	
	strcpy(arquivo,cpf); // Copiando valores de variáves, de cpf para arquivo
	
	FILE *file; // solicita função para lidar com arquivo
	file = fopen(arquivo,"w"); // definine atributos do arquivo que será criado
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo para edição
	fprintf(file,","); // escreve a virgula após dados já presentes no arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); // solicitando input do usuário
	scanf("%s",nome); // guardando input
	
	file = fopen(arquivo,"a"); //abre arquivo para edição
	fprintf(file,nome); // escreve valor da variável para o arquivo
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo para edição
	fprintf(file,","); // escreve a virgula após dados já presentes no arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // solicitando input do usuário
	scanf("%s",sobrenome); // guardando input
	
	file = fopen(arquivo,"a"); //abre arquivo para edição
	fprintf(file,sobrenome); // escreve valor da variável para o arquivo
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo,"a"); //abre arquivo para edição
	fprintf(file,","); // escreve a virgula após dados já presentes no arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // solicitando input do usuário
	scanf("%s",cargo); // guardando input
	
	file = fopen(arquivo,"a"); //abre arquivo para edição
	fprintf(file,cargo); // escreve valor da variável para o arquivo
	fclose(file); // fecha arquivo
	
	system("pause");
}

int consulta() // função para cosulta de nomes
{
	setlocale(LC_ALL,"portuguese"); //determinando idioma
	
	char cpf[40]; // Inicio definição de variáveis
	char conteudo[200]; // fim definição de variáveis
	
	printf("Digite o CPF a ser consultado: "); // solicitando input do usuário
	scanf("%s",cpf); // guardando input
	
	FILE *file; // solicita função para lidar com arquivo
	file = fopen(cpf,"r"); // definine atributos ao lidar com o arquivo
	
	
	if(file == NULL) // definindo resposta para o caso de arquivo inexistente
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Loop para passsar valor do arquivo para variável
	{
		printf("\nEstas são as informaçoes do usuário: "); // exibindo informação ao usuário
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file); //Fechando arquivo ao fim da consulta
	}
	
	system("pause");
	
}

int deletar() // função para deletar nomes
{
	setlocale(LC_ALL, "portuguese"); //determinando idioma
	
	char cpf[40]; //definindo variáveis
	
	printf("Digite o CPF do usuário a ser deletado: "); // Pedindo Input ao usuário
	scanf("%s",cpf); //captando input
	
	
	FILE*file; // consultando existencia do CPF a ser deletado
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso usuário inexistente
	{
		printf("\nO usuário não se encontra no sistema\n\n");
		system("pause");
	}
	
	else //caso usuário existente
	{
		fclose(file);
		remove(cpf);
		printf("\nO usuário foi deletado com sucesso\n\n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0; // definindo variável de opção do menu
	int laco=1; // definindo variável do laço do menu
	char senhadigitada[10]="a"; // Definindo variável para captar senha do ususário, com valor padrão "a"
	int comparacao; // definindo variável para execução da condicional if
	
	printf("\t### Cartório da EBAC ###\n\n"); // Inicio login do administrador
	printf("Login de administrador!\n\nDigite a sua senha: "); // solicitando input do usuário
	scanf("%s",senhadigitada); // Guardando Input recebido
	
	comparacao = strcmp(senhadigitada, "admin"); //comparando string recebido contra o pré determinado e salvando integer como valor da variável
	
	if(comparacao == 0) // Inicio condicional para acesso do admin
	{
		system("cls"); //Limpeza de tela para menu
		
		for(laco=1;laco=1;) // Inicio laço para retorno ao menu
		{
			system("cls"); //limpeza de tela para laço
		
			setlocale(LC_ALL, "portuguese"); //determinando idioma
	
			printf("\t### Cartório da EBAC ###\n\n"); // Inicio tela menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
		
			printf("Desenvolvido por João de Mello \n sob a supervisão da EBAC\n\n"); 
			printf("Opção: "); // fim tela menu
	
			scanf("%d",&opcao); //armazenando input do usuário
		
			system("cls");
		
			switch (opcao) // inicio da seleção
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
				
				case 4: // Opção sair do sistema
					printf("Obrigado por utilizar o sistema\n");
					return 0; // encerra o sistema
				break;
		
				default: // opção padrão
					printf("Esta opção não está disponivel\n");
					system("pause");
				break;
				
			} // fim da seleção
		} // Fim laço de retorno ao menu
	} // fim para acesso do admin
	else // retorno padrão para senha incorreta
	{
		system("cls"); //Limpeza de tela para senha incorreta
		printf("\nSenha incorreta\n");
	}
}
