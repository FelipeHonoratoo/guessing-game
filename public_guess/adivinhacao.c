//Incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definindo as constantes
#define NUMERO_DE_TENTATIVAS 3

int main()
{
	//Imprime cabeçalho Bonito do jogo
	printf("\n\n");
	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|_|_/_\\                            \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinha%c%co! \n", 135, 132);
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|__/                              \n");
	printf("\n\n");

	// declarando variaveis que serao usadas mais a frente 
 	int chute;	
	int acertou;
	int nivel;
	int numerodetentativas;

	//Definindo a quantidade inicial de pontos
	double pontos = 1000;

	//Gerando um número secreto aleatório
	srand(time(0));
	int numerosecreto = rand() % 100;


	//Escolhendo o nível de dificuldade
	printf("Qual o n%cvel de Dificuldade?\n",140);
	printf("(1) F%ccil (2) M%cdio (3) Dif%ccil\n\n", 160, 130, 161);
	printf("Escolha: ");

	scanf("%d", &nivel);

	switch(nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 13;
			break;
		default:
			numerodetentativas = 6;
			break;
	}

	//Loop principal do jogo
	for (int i = 1; i <= numerodetentativas; i++)
	{
		printf("\n");
		printf("Tentativa %d de %d\n", i, numerodetentativas);
		printf("Qual e o seu chute? ");

		scanf("%d", &chute);

		//tratamento de chute negativo
		if(chute < 0) {
			printf("\nNegativo n%co pode seu Burro!\n", 132);
			i--;
			continue;
		}

		//Verifica se acertou, foi maior ou menor
		acertou = (chute == numerosecreto);

		if(acertou) {
				break;
		} else if(chute > numerosecreto) {
				printf("\nSeu chute foi Maior que o N%cmero Secreto!\n\n", 163);
		} else {
				printf("\nSeu chute foi Menor que o N%cmero Secreto!\n\n", 163);	
		}

		//Calcula a quantidade de pontos
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}

	//Imprimindo mensagem de Vitória ou Derrota
	printf("\n");
	if (acertou){
		printf("\n");
		printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
		printf("\nParab%cns! Voc%c Ganhou!!\n", 130, 136);;
		printf("Total de Pontos: %.2f\n", pontos);
		system ("pause");
	} else {
		printf("\n");
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");
		printf("\nVoc%c perdeu!! Tente de novo!\n", 136);
		system ("pause");
	}
	return 0;
}