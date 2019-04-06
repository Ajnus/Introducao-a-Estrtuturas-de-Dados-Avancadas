#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


float** cria (int n)
{
	int i;
	float** mat = (float**)malloc(n * sizeof(float*));
	if (mat == NULL)
	{
		printf("Mem%cria insuficiente!", 162);
		exit(1);
	}

	for (i = 0; i < n; i++)
	{
		mat[i] = (float*) malloc((i + 1) * sizeof(float));
		if (mat[i] == NULL)
		{
			printf("Mem%cria insuficiente!", 162);
			exit(1);
		}
	}
	return mat;
}
float acessa(int n, float** mat, int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
	{
		printf("Acesso inv%clido!\n", 160);
		exit(1);
	}

	if (i > j)
		return mat[i][j];							/* retorna o elemento representado */
	else
		return mat[j][i];							/*       retorna o simétrico       */
}
void preenche_matriz_triangular(int n, float** mat)
{
	float valor;

	scanf("%f", &valor);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
		{
			if (i == j)
				mat[i][j] = valor;
			else
				mat[i][j] = 0;
		}
			
}
void imprime_matriz_simetrica(int n, float** mat)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i >= j)
				printf("|%.0f", mat[i][j]);
			else
				printf("|%.0f", mat[j][i]);
			if (j == (n - 1))
				printf("|\n");
		}
}

int main(void)
{
	int n;
	float** matriz;

	printf("Digite o n%cmero de linhas e colunas da matriz triangular:\n", 163);
	scanf("%d", &n);
	matriz = cria(n);

	printf("Digite o valor dos elementos da diagonal da matriz:\n");
	preenche_matriz_triangular(n, matriz);

	printf("\nA matriz triangular %c:\n", 130);
	imprime_matriz_simetrica(n, matriz);

	printf("\n");

	/* libera memória */
	for (int i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);

	return 0;
}