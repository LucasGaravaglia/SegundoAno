#include <stdio.h>



int main(){
	int i,soma=0,temp=0,verif1,verif2;
	unsigned long long int cpf,cpf2;
		scanf("%lld",&cpf);
		cpf2=cpf;
		verif2=cpf2%10;cpf2/=10;
		verif1=cpf2%10;cpf2/=10;

		for(i=2,soma=0;i<11;i++,temp=0){
			temp=cpf2%10;cpf2/=10;
			soma+=(temp*i);
	}
	soma=(soma*10)%11;
	if(soma != verif1) printf("CPF Invalido\n");
	
	cpf/=10;
	for(i=2,soma=0;i<12;i++,temp=0){
		temp=cpf%10;cpf/=10;
		soma+=(temp*i);	
		}
	soma=(soma*10)%11;
	if(soma != verif2) printf("CPF Invalido\n");
		printf("CPF Valido\n");

		

	return 0;
}