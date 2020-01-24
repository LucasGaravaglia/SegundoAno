/*
faça uma função recursiva que calcule e retorne
o N-ésimo termo da sequencia Fibonacci. Alguns números desta sequencia são: 1,1,2,3,5,8,13,21,34,55,89
*/

#include <stdio.h>

int fib(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	else return (fib(n-1)+fib(n-2));
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
	return 0;
}