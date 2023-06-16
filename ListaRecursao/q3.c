/*3. Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inverte(int n);

int main(){

    inverte(456);
    printf("%d", inverte(456));
}

int inverte(int n){
    if(n < 10){
        return n;
    }else{
        int ultimoDigito = n % 10; //pega o ultimo digito
        int resto = n / 10; //pega o resto
        int qtdDigitos = log10(resto) + 1; //pega a quantidade de digitos do resto
        return ultimoDigito * pow(10, qtdDigitos) + inverte(resto); //retorna o último digito concatenado com o resto invertido
    }
}