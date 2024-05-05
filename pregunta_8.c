#include <stdio.h>
#include <omp.h>

int main() {
    int N,M;
    printf("Ingresar el numero de terminos de la serie \n");
    scanf("%d",&N);
    printf("Ingresa el numero a procesadores a usar \n");
    scanf("%d",&M);  
    int terminos[N]; 

    #pragma omp parallel num_threads(M)
    {
        // Sección para calcular la serie
        #pragma omp for
        for (int i = 0; i < N; i++) {
            terminos[i] = 2 * (i + 1); // Calcular el término i de la serie
        }

        // Sección para mostrar la serie
        #pragma omp single
        {
            printf("Serie generada: ");
            for (int i = 0; i < N; i++) {
                printf("%d ", terminos[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
