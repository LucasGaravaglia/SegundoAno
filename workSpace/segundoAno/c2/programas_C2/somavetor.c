#include <stdio.h>
#include <string.h>


int soma_vetor(int v[],int n){
	int s=0;
	for(;n>0;n--)
		s+=v[n-1];
	return s;
	
}