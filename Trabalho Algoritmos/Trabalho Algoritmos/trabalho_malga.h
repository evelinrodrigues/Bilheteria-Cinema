#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include "colors.h"


struct Sessao{
	int assento[8][8], hora, minuto, sala;
	
};
struct Filme{
	Sessao s [10];
	int quant_sessao;
	char nome[80], diretor[80], genero[40];
	int duracao, class_ind;
};

struct Ingresso{
	char assento_char, tipoing;
	int assento_int;
	float preco;
};
	
using namespace std;
int menuPrincipal()
{
	int op;
	system("cls");
 				
system("cls");
FORENORMAL_COLOR;

printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n");       
	printf("\t********************************************************************************************\n");
	printf("\t*                                     MENU PRINCIPAL                                       *\n");
	printf("\t********************************************************************************************\n\n");
	printf("\t********************************************************************************************\n");
	printf("\t*       1- CADASTRAR NOVO FILME                                                            *\n");
	printf("\t*       2- VENDA                                                                           *\n");
	printf("\t*       3- EXCLUIR FILME                                                                   *\n");
	printf("\t*       4- SAIR                                                                            *\n");
	printf("\t*                                                                                          *\n");
	printf("\t********************************************************************************************\n");
				printf(" 	    			              @-_________________-@				    \n");
          		printf("				        @-_____|   CINEMIGOS    |_____-@				\n");
    			printf("	  			 ________|_____________________________|________		\n");
 	  			printf("	 			|______________________________________________|		\n");
   				printf("	 			|        ____    ______________-   ____        |		\n");
   				printf("	 			| -  -  |    |   |  TICKETS   |   |    | -     |		\n");
  				printf("	 			|  --   |____| - |_o___oo___o_| - |____|   -   |		\n");
  				printf("	 			|    -  |    |- | -      -     |  |    |--     |		\n");
  				printf("	 			|_______|====|__|______________|__|====________|		\n");
 				printf("    		 	       /_________________________________________________\\	\n");
 	printf("\t********************************************************************************************\n");
 	printf("\t*Informe a opção desejada:                                                                 *\n");
 	printf("\t********************************************************************************************\n");
 	printf("\t");
	scanf("%i",&op);
	
	return op;
}
//recebe infos de filme
Filme telaCadastro()
{
	int i,j,k;
	char resp='s';
	Filme f;
	system("cls");
	//recebe as informaçoes do filme a ser cadastrado
	printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
	 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
	 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
	 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
	 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
	 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n\n");
       
	printf("\t********************************************************************************************\n");
	printf("\t*                                     CADASTRO                                             *\n");
	printf("\t********************************************************************************************\n");
	printf("\tNome do filme: ");
	fflush(stdin);
	gets(f.nome);
	printf("\n\tClassificação indicativa: ");
	scanf("%i",&f.class_ind);
	printf("\n\tDuração em minutos: ");
	scanf("%i",&f.duracao);
	printf("\n\tDiretor: ");
	fflush(stdin);
	gets(f.diretor);
	printf("\n\tGênero do filme: ");
	fflush(stdin);
	gets(f.genero);
	//zera a variavel
	f.quant_sessao = 0;
	
		printf("\n\tInforme a quantidade de sessões que esse filme terá diariamente: ");
		scanf("%i",&f.quant_sessao);
		for(i=0;i<f.quant_sessao;i++)
		{
			printf("\n\tInforme o horario da %i sessão. No formato (HH:MM): ",i+1);
			scanf("%i:%i", &f.s[i].hora, &f.s[i].minuto);
			printf("\n\tInforme a sala da %i sessão: ",i+1);
			scanf("%i",&f.s[i].sala);
		}
	
	//for para percorrer todas as sessoes
	for(k=0;k<f.quant_sessao;k++)
	{
	//um for para zerar/inicializar as variaveis
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				f.s[k].assento[i][j] = 0;
			}
		}
	}
	return f;
	
}
//tela de exclusao de filme cadastrado
int telaExcluir(Filme f [], int tam)
{
	system("cls");
	int i, cod, aux;
	char resp;
	//verifica se há algum filme cadastrado
	if(tam==0)
	{
		printf("\t_--------------------------\n");
		printf("\t| Nenhum filme cadastrado! |\n");
		printf("\t----------------------------\n");
		getch();
		return -1;
	}
	//lista filmes cadastrados
	printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
	 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
	 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
	 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
	 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
	 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n\n");
	printf("\t********************************************************************************************\n");
	printf("\t*                               FILMES CADASTROS                                           *\n");
	printf("\t********************************************************************************************\n\n");
	for(i=0;i<tam;i++)
	{
		printf("\t--------------------------------------------------------------------------------------------\n");
		printf("\tCódigo: %i\n \tNome: %s\n \tClassificação indicativa: %i\n \tDuração: %i\n \tDiretor: %s\n \tGênero: %s\n\n", i+1, f[i].nome, f[i].class_ind, f[i].duracao, f[i].diretor, f[i].genero);
		printf("\t--------------------------------------------------------------------------------------------\n\n");
	}

	printf("\tInforme o código do filme que deseja excluir ou 0 para voltar: ");
	scanf("%i",&aux);
	if (aux == 0)
	{
		return -1;
	}
	cod = aux - 1;
	printf("\n\tVocê tem certeza que deseja excluir esse filme? Digite s para sim e qualquer outra tecla para não: ");
	scanf("%s",&resp);
	
	if(resp == 's' || resp == 'S')
	{
		return cod;	
	}
	else
	{
		return -1;
	}
}
//fecha o programa
int telaSair()
{
	system("cls");
	char resp;
	printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
	 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
	 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
	 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
	 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
	 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n\n");
	printf("\t********************************************************************************************\n");
	printf("\t*                                       LOG OFF                                            *\n");
	printf("\t********************************************************************************************\n\n");
	printf("\tVocê tem certeza que deseja sair? Digite s para sim e qualquer outra tecla para não: ");
	fflush(stdin);
	scanf("%s",&resp);
	system("cls");
	if(resp == 's' || resp == 'S')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//desenha mapa de assentos
void telaAssento(Filme f[], int cod_filme, int cod_sessao)
{
	int i, j;
	system("cls");
	printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
	 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
	 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
	 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
	 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
	 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n\n");
	printf("\t********************************************************************************************\n");
	printf("\t*                                    MAPA DE ASSENTOS                                      *\n");
	printf("\t********************************************************************************************\n\n");
	
	printf("\t  1 2 3 4 5 6 7 8\n");
	for(i=0;i<8;i++)
	{
		//nomeia as colunas
		switch(i)
		{
			case 0: 
				printf("\tA");
				break;
			case 1:
				printf("\tB");
				break;
			case 2:
				printf("\tC");
				break;
			case 3:
				printf("\tD");
				break;
			case 4:
				printf("\tE");
				break;
			case 5:
				printf("\tF");
				break;
			case 6:
				printf("\tG");
				break;
			case 7:
				printf("\tH");
				break;
		}
		//imprime vazio e ocupado
		for(j=0;j<8;j++)
		{
			if(f[cod_filme].s[cod_sessao].assento[i][j]==0)
			{
				printf("| ");
			}
			else
			{
				printf("|x");
			}
		}
		printf("|\n");
	}
	printf("\t _________________\n");
	printf("\t        TELA        \n");
}
	
//efetiva a compra
int precoIngresso()
{
	system("cls");
	int dia;
	float preco;
	printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n");       
	printf("\t********************************************************************************************\n");
	printf("\t*                                   INFORMAÇÕES NECESSÁRIAS                                *\n");
	printf("\t********************************************************************************************\n\n");
	printf("\tInforme o dia da semana:\n\t 1- para segunda-feira\n\t 2- para terça, quarta e quinta\n\t 3- para sexta, sábado e domingo\n");
	printf("\t");
	scanf("%i", &dia);
	//recebe preco a ser pago conforme o dia da semana
	switch(dia)
	{
		case 1: 
			preco = 9;
			break;
		case 2: 
			preco = 15;
			break;
		case 3:
			preco = 21;
			break;
	}
	return preco;
}
//imprime ingresso
void telaTicket(Filme f [], Ingresso ing[], int quant_ingresso, int cod_filme, int cod_sessao)
{
	system("cls");
	int i;
	printf( "\t\t  ______  __ .__   __. _______ .___  ___. __   _______   ______       _______.\n"
 "\t\t /      ||  ||  \\ |  ||   ____||   \\/   ||  | /  _____| /  __  \\     /       |\n"
 "\t\t|  ,----'|  ||   \\|  ||  |__   |  \\  /  ||  ||  |  __  |  |  |  |   |   (----`\n"
 "\t\t|  |     |  ||  . `  ||   __|  |  |\\/|  ||  ||  | |_ | |  |  |  |    \\   \\    \n"
 "\t\t|  `----.|  ||  |\\   ||  |____ |  |  |  ||  ||  |__| | |  `--'  |.----)   |   \n"
 "\t\t \\______||__||__| \\__||_______||__|  |__||__| \\______|  \\______/ |_______/    \n");       
	for(i=0;i<quant_ingresso;i++)
	{
			printf("\t********************************************************************************************\n");
			printf("\t* %s             \n",f[cod_filme].nome);
		if(ing[i].tipoing == 'm' || ing[i].tipoing == 'M')
		{
			printf("\t* Meia-entrada   \n");
		}
		else
		{
			printf("\t* Inteira        \n");
		}
			printf("\t* Sala: %i       \n",f[cod_filme].s[cod_sessao].sala);
			printf("\t* Horário: %i:%i \n",f[cod_filme].s[cod_sessao].hora,f[cod_filme].s[cod_sessao].minuto);
			printf("\t* Assento: %c/%i \n",ing[i].assento_char, ing[i].assento_int);
			printf("\t* Preço: %.2f    \n",ing[i].preco);
			printf("\t********************************************************************************************\n\n");
			
}
	printf("\t********************************************************************************************\n");
	printf("\t*                                  OBRIGADO!                                               *\n");
	printf("\t********************************************************************************************\n\n");
	getch();
}
