#include<stdio.h>
#include<string.h>
int suma(int *a,int *b){
    return *a+*b;
}
int resta(int *a,int *b){
    return *a-*b;
}
int multiplicacion(int *a,int *b){
    int r=0;
    for(int i=1;i<=*b;i++)
        r=suma(a,&r);
    return r;
}
float division(int *a, int *b) {
    float c = 0.0;
    int r = *a;
    while (r >= *b) {
        r = resta(&r,a);
        c++;
    }
    c+=(float)r/ *b;
    return c;
}
int main(){
    int a,b;
    printf("ingresa el primer numero \n");
    scanf(" %d",&a);
    printf("ingresa el segundo numero \n");
    scanf(" %d",&b);
    printf("La suma es %i \n",suma(&a,&b));
    printf("La resta es %i \n",resta(&a,&b));
    printf("La multiplicacion es %i \n",multiplicacion(&a,&b));
    if(b>0)
        printf("La division es %.2f \n",division(&a,&b));
    else
        printf("No se puede dividir entre cero o un numero Negativo");
    return 0;
}

