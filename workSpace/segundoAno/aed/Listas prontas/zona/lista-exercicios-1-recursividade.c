#include <stdio.h>
#include <math.h>
#include <string.h>

//1Função que printa de 0 a n numeros
int printn(int n,int z){
	if(n >= z){ 
		printf("%d ",z);
	return (printn(n,z+1));
		}
		else{
			return 0;
		}
}
//2Função que printa de 0 a n numeros
int printn2(int n){
	if(n >= 0){ 
		printf("%d ",n);
	return (printn2(n));
		}
		else{
			return 0;
		}
}
//3Função que soma todos os valores entre 0 e n
int soman(int n,int z){
	if(n >= 0){
		z = z+n;
		return (soman(n-1,z));
	}else return z;
}
//Função fatorial recursivo
int fat(int n){
	if(n == 0) return 1;
	else return n*fat(n-1);
}
//4Função superfatorial recursivo
int sfat(int n){
	if(n == 0) return 1;
		else return (sfat(n-1)*fat(n));		
}
//5Função que calcula o fatorial exponencial de um numero n
int fatexp(int n,float y){
	if(n == 0){
		return 0;
	}else return (fatexp(y-1,pow(n-1,n-2)));
}
//6Função para calcular o catalao
int catalao(int n,int y){
	if(n != 0){
		return catalao(n-1,y*((2.0*(2*n-1))/(n+1))); 
		}else{
			return y;	
		}

}
//11Função que soma os digitos de um numero
int somadigi(int n,int x){
	if(n == 0){
		return x;
	}else{
		x = x + (n%10);
		return somadigi(n/10,x);
	}
}
int StringPalin(char s[] ,int n){
	int x = strlen(s) ;
	if(x-n < n) return 1;
	if(s[n] != s[n-x]) return 0;
	else StringPalin(s,n+1);

}

int main(){
	int n=0,x=0,temp;
	char s[50] ;
	scanf("%[^\n]",&s);
	if(StringPalin(s,n)) printf("Palindrome");
		else printf("nao palindrome");

	return 0;
}