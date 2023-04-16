//Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.
#include <stdio.h>

struct numeros{
    int a,b,c,d;
};

int main(){
    struct numeros ler4Numeros();
    struct numeros n = ler4Numeros();
    printf("Os numeros sao: %d %d %d %d",n.a,n.b,n.c,n.d);
    return 0;
}

struct numeros ler4Numeros(){
    struct numeros n;
    printf("Digite 4 numeros: ");
    scanf("%d %d %d %d",&n.a,&n.b,&n.c,&n.d);
    return n;
}

