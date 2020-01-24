/*faça uma função recursiva que permita inverter um número inteiro N. EX.: 123 = 321*/

#include <stdio.h>

int invert(int n, int k)
{
		if(n == 0) return k;
			else return invert( (n/10) , ((10*k)+(n%10)) );
}

int main(){
	int n,k=0;
	scanf("%d",&n);
	printf("%d",invert(n,k));
	return 0;
}