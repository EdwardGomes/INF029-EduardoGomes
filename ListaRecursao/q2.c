/*2) Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência 
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...*/

#include <stdio.h>
#include <stdio.h>

int fibonacci(int n);

int main(){

    fibonacci(10);
    printf("%d", fibonacci(10));
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}