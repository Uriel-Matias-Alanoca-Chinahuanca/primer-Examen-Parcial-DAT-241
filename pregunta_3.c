#include <stdio.h>
#include <omp.h>
void multiplicacion(int x, int y) {
    int result = 0;
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < y; i++) {
        int xp = x;
        result += xp;
    }
    printf("%d * %d = %d\n", x, y, result);
}

void division(int x, int y) {   
    float r = 0;
    #pragma omp parallel for reduction(+:r)
    for (int i = x; i >= y; i -= y) 
        r++;
    r += (float)(x % y) / y;
    printf("%d / %d = %.2f\n", x, y, r);
}
int main(){
    int a,b;
    printf("Ingresa el primer numero ");
    scanf("%d",&a);
    printf("Ingresa el segundo numero ");
    scanf("%d",&b);
    printf("Multiplicacion\n");
    multiplicacion(a,b);
    printf("Division\n");
    division(a,b);
    return 0;
}