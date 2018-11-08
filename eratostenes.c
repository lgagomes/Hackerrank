/*
Implementação do algoritmo do Crivo de Eratónestes
para encontrar números primos

https://pt.wikipedia.org/wiki/Crivo_de_Erat%C3%B3stenes
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i,j,N,raiz,counter=0;

    printf("Informe um numero:\n");
    scanf("%d",&N);

    int elementos[N+1];
    raiz = sqrt(N);

    for (i=0; i <=N+1; i++)
    {
        if(i == 0 || i == 1)
            elementos[i] = 0;
        else
            elementos[i] = 1;
    }

    for(j=2; j<=raiz; j++)
        for (i=0; i <=N+1; i++)
            if (i % j == 0 && i != j)
                elementos[i] = 0;

    printf("\nNumeros primos entre 0 e %d:\n", N);
    for (i=0; i <=N; i++)
        if (elementos[i] != 0)
		{
            printf("%d ", i);
			counter++;
		}
    printf("\nTotal: %d\n",counter);
    return 0;
}
