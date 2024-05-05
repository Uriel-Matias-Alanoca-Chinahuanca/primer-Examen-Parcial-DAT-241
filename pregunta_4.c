#include <stdio.h>
#include <omp.h>
int N;
void matriz_por_vector(int m[][N], int v[N], int r[N], int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        r[i] = 0;
        for (int j = 0; j < N; j++)
            r[i] += m[i][j] * v[j];
    }
}
int main() {
    printf("Ingresar N: ");
    scanf("%d", &N);
    int matriz[N][N];
    int vector[N];
    int resultado[N];
    printf("Ingrese la matriz %dx%d\n", N, N);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            scanf("%d", &matriz[i][j]);
    
    printf("Ingrese el vector %dx1\n", N);
    for (int i = 0; i < N; i++) 
        scanf("%d", &vector[i]);

    matriz_por_vector(matriz, vector, resultado, N);
    printf("Resultado:\n");
    for (int i = 0; i < N; i++) 
        printf("%d ", resultado[i]);   
    return 0;
}
