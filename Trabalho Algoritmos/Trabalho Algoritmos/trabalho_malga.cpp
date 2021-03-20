#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "trabalho_malga.h"
#define N 100

/*
**********************************************
1924330 Flavia Tramontina
1922738 Evelin Rodrigues
1915563 Gabriela Holanda
1920267 Maria Helena Aquino
**********************************************
*/


int main()
{
	setlocale(LC_ALL, "Portuguese");
	SetConsoleOutputCP (28591);
	SetConsoleCP(28591);
	
	struct Filme f[N];
	struct Ingresso ing[64];
	UNDERLINE;
	FORENORMAL_COLOR;
	strcpy(f[0].nome, "Star Wars");
	strcpy(f[0].genero, "Ficção Científica");
	strcpy(f[0].diretor, "George Lucas");

	f[0].quant_sessao = 2;
	f[0].class_ind = 12;
	f[0].duracao = 120;
	f[0].s[0].hora = 18;
	f[0].s[0].minuto = 30;
	f[0].s[0].sala = 3;
	f[0].s[0].assento[3][3] = 1;
	f[0].s[0].assento[3][4] = 1;
	f[0].s[0].assento[3][5] = 1;
	f[0].s[0].assento[2][1] = 1;
	f[0].s[0].assento[2][2] = 1;
	f[0].s[1].hora = 21;
	f[0].s[1].minuto = 15;
	f[0].s[1].sala = 2;
	f[0].s[1].assento[2][5] = 1;
	f[0].s[1].assento[2][6] = 1;
	f[0].s[1].assento[2][7] = 1;
	f[0].s[1].assento[6][1] = 1;
	f[0].s[1].assento[6][2] = 1;
	

	strcpy(f[1].nome, "Esqueceram de mim");
	strcpy(f[1].genero, "Comedia");
	strcpy(f[1].diretor, "Chris Columbus");
	f[1].class_ind = 10;
	f[1].duracao = 135;
	f[1].quant_sessao = 3;
	f[1].s[0].hora = 15;
	f[1].s[0].minuto = 30;
	f[1].s[0].sala = 1;
	f[1].s[0].assento[4][3] = 1;
	f[1].s[0].assento[4][4] = 1;
	f[1].s[0].assento[4][5] = 1;
	f[1].s[0].assento[5][1] = 1;
	f[1].s[0].assento[5][2] = 1;
	f[1].s[1].hora = 18;
	f[1].s[1].minuto = 30;
	f[1].s[1].sala = 2;
	f[1].s[1].assento[2][3] = 1;
	f[1].s[1].assento[2][4] = 1;
	f[1].s[1].assento[2][5] = 1;
	f[1].s[1].assento[1][1] = 1;
	f[1].s[1].assento[1][2] = 1;
	f[1].s[2].hora = 22;
	f[1].s[2].minuto = 30;
	f[1].s[2].sala = 4;
	f[1].s[2].assento[1][3] = 1;
	f[1].s[2].assento[1][4] = 1;
	f[1].s[2].assento[1][5] = 1;
	f[1].s[2].assento[2][1] = 1;
	f[1].s[2].assento[2][2] = 1;
	f[1].s[2].assento[3][3] = 1;
	f[1].s[2].assento[3][4] = 1;
	f[1].s[2].assento[3][5] = 1;
	f[1].s[2].assento[3][1] = 1;
	f[1].s[2].assento[3][2] = 1;
	
	
	int i, j, op = 0, tam=2, aux;
	int resp_sair, resp_menu_principal = 0, cod_sessao, cod_filme, quant_ingresso = 0, n_assento, fileira_int;
	char resp='s', resp_assento ='s', fileira, resp_confirmar;
	float preco;
	
	//repete ate que o usuario escolha sair
	do 
	{
		resp_menu_principal = menuPrincipal();
		switch(resp_menu_principal)
		{
			case 1:
				resp = 's';
				while(resp == 's'|| resp =='S')
				{
					f[tam] = telaCadastro();
					printf("\n\t--------------------------------------------------------------------------------------------\n");
					printf("\tCódigo: %i\n \tNome: %s\n \tClassificação indicativa: %i\n \tDuração: %i\n \tDiretor: %s\n \tGênero: %s\n", tam, f[tam].nome, f[tam].class_ind, f[tam].duracao, f[tam].diretor, f[tam].genero);
					printf("\t--------------------------------------------------------------------------------------------\n\n");
					printf("\n\tDeseja confirmar o cadastro do filme? Digite 's' para sim e qualquer outra tecla para não: ");
					scanf("%s", &resp_confirmar);
					if (resp_confirmar == 's' || resp_confirmar == 'S')
					{
						printf("\n\tDeseja cadastrar um novo filme? Digite 's' para sim e qualquer outra tecla para não: ");
						scanf("%s",&resp);
						tam++;
					}	
					else {
						printf("\n\tDeseja voltar ao menu principal? Digite 's' para sim e qualquer outra tecla para não: ");
						scanf("%s", &resp_confirmar);
						if (resp_confirmar == 's' || resp_confirmar == 'S')
						{
							break;
						}
						else
						{
							resp = 's';
						}
					}
				}
			break;
			case 2:
				if(tam==0)
				{
					printf("\t------------------------\n");
					printf("\tNenhum filme cadastrado!\n");
					printf("\t------------------------\n");
					getch();
					break;
				}
				//lista os filmes
				for(i=0;i<tam;i++)
				{
					printf("\t--------------------------------------------------------------------------------------------\n");
					printf("\tCódigo: %i\n \tNome: %s\n \tClassificação indicativa: %i\n \tDuração: %i\n \tDiretor: %s\n \tGênero: %s\n\n", i+1, f[i].nome, f[i].class_ind, f[i].duracao, f[i].diretor, f[i].genero);
					printf("\t--------------------------------------------------------------------------------------------\n\n");
				}
				//recebe a posição do filme escolhido
				printf("\tDigite o código do filme escolhido ou 0 para voltar: ");
				scanf("%i",&aux);
				if (aux == 0)
				{
					break;
				}
				cod_filme = aux - 1;
				//volta para o menu caso codigo seja invalido
				if(cod_filme>tam)
				{
					printf("\t-------------------------\n");
					printf("\tCódigo de filme inválido!\n");
					printf("\t-------------------------\n");
					getch();
					break;
				}
				system("cls");
				//verifica se o filme possui sessoes cadastradas
				if (f[cod_filme].quant_sessao < 1)
				{
					printf("\tNenhuma sessão cadastrada para esse filme.");
					getch();
					break;
					
				}
				printf("\t********************************************************************************************\n");
				printf("\t*                                           SESSÕES                                        *\n");
				printf("\t********************************************************************************************\n\n");
				for(i=0;i<f[cod_filme].quant_sessao;i++)
				{
					printf("\t--------------------------------------------------------------------------------------------\n");
					printf("\tCódigo: %i\n\tHorário: %i:%i\n\tSala:%i\n\n",i+1,f[cod_filme].s[i].hora, f[cod_filme].s[i].minuto, f[cod_filme].s[i].sala);
					printf("\t--------------------------------------------------------------------------------------------\n\n");
				}
				printf("\tInforme o código da sessão escolhida ou 0 para voltar ao menu inicial: ");
				scanf("%i",&aux);
				if (aux == 0)
				{
					break;
				}
				cod_sessao = aux - 1;
				//verifica se o usuario digitou uma sessao valida
				if (cod_sessao >= f[cod_filme].quant_sessao)
				{
					printf("\t----------------------------\n");
					printf("\t\nCódigo de sessão inválido!\n");
					printf("\t----------------------------\n");
					getch();
					break;
				}
				telaAssento(f, cod_filme, cod_sessao);
				
				// registra o assento escolhido
				//repete enquanto o usuario escolhe novos assentos
				quant_ingresso  = 0;
				do 
				{
					printf("\n\tInforme o assento escolhido, sendo (fileira/assento)\n");
					printf("\t");
					
					fflush(stdin);
					scanf("%c/%i", &fileira,&n_assento);
					//armazena para imprimir no final
					ing[quant_ingresso].assento_int = n_assento;
					ing[quant_ingresso].assento_char = fileira;
					//transforma char em int
					switch(fileira)
					{
						case 'a':
							fileira_int = 0; 
							break;
						case 'A':
							fileira_int = 0; 
							break;
						case 'b':
							fileira_int = 1; 
							break;
						case 'B':
							fileira_int = 1; 
							break;
						case 'c':
							fileira_int = 2; 
							break;
						case 'C':
							fileira_int = 2; 
							break;
						case 'd':
							fileira_int = 3; 
							break;
						case 'D':
							fileira_int = 3; 
							break;
						case 'e':
							fileira_int = 4; 
							break;
						case 'E':
							fileira_int = 4; 
							break;
						case 'f':
							fileira_int = 5; 
							break;
						case 'F':
							fileira_int = 5; 
							break;
						case 'g':
							fileira_int = 6; 
							break;
						case 'G':
							fileira_int = 6; 
							break;
						case 'h':
							fileira_int = 7; 
							break;
						case 'H':
							fileira_int = 7; 
							break;
						defaut:
							fileira_int = 8;
							break;
					}
					//verifica se o assento é possivel
					if (fileira_int > 7 || n_assento > 8)
					{
						printf("\n\t-------------------------\n");
						printf("\tInsira um assento válido!\n");
						printf("\t-------------------------\n");
						getch();
					}
					//verifica se o assento esta livre
					else if(f[cod_filme].s[cod_sessao].assento[fileira_int][n_assento-1]!= 0)
					{
						printf("\t-------------------------\n");
						printf("\tAssento ocupado!\n");
						printf("\t-------------------------\n");
						getch();
					}
					else 
					{
						f[cod_filme].s[cod_sessao].assento[fileira_int][n_assento-1]= 1;
						fflush(stdin);
						printf("\n\tDeseja comprar mais um assento? Digite 's' para sim e qualquer outra tecla para não: ");
						scanf("%c",&resp_assento);
						quant_ingresso++;		
					}
				} while(resp_assento == 's'|| resp_assento == 'S');
				preco = precoIngresso();
				//pega as info para cada ingresso
				for(i=0;i<quant_ingresso;i++)
				{
					printf("\n\tInforme o tipo do %i ingresso, sendo 'm' para meia-entrada 'i' para inteiro: ", i+1);
					fflush(stdin);
					scanf("%c",&ing[i].tipoing);
					//define meia-entrada
					if(ing[i].tipoing == 'm' || ing[i].tipoing == 'M')
					{
						ing[i].preco = preco/2;
					}
					else
					{
						ing[i].preco = preco;
					}
				}
				
				telaTicket(f, ing, quant_ingresso, cod_filme, cod_sessao);
				
				
				break;
			case 3:
				cod_filme = telaExcluir(f, tam);
				if (cod_filme != -1)
				{
					//apaga filme e reordena o vetor
					for(i = cod_filme;i<tam;i++)
					{
						f[i]=f[i+1];	
					}
					tam--;
				}
				break;
			case 4: 
				resp_sair = telaSair();
				if (resp_sair == 1)
				{
					resp_menu_principal = 0;
					break;
				}
				break;
			default: 
				system("cls");
				printf("\t-----------------------------------------------------\n");
				printf("\n\tAperte qualquer tecla para voltar ao menu principal\n");
				printf("\t-----------------------------------------------------\n");
				getch();
				break;
		}
	}while (resp_menu_principal != 4);

	return 0;
}
