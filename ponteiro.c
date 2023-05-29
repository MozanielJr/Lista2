#include <stdio.h>

int main(){
    printf("Teste");


    int n1;
    int *n2;

    n1 = 1;
    n2 = &n1;



    printf("Valor de n1: %d \n", n1);
    printf("Endereco de n1: %d \n", &n1);
    printf("Endereco de n2(d): %d \n", n2);
    printf("Endereco de n2(p): %p \n", n2);
    printf("Endereco de n1(p): %p \n", n1);
    printf("Valor apontado por n2: %d \n", *n2);

    
}