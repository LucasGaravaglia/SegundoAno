#include <stdio.h>
#include "asm_debug.h"

int setBit(int x, int t){
    int aux = 1;
    aux = aux << t;
    return x | aux;
}

int ClearBit(int x, int t){
    int aux = 1;
    aux = aux << t;
    aux = ~aux;
    return x & aux;
}

int modifyBit(int x, int t, int r){
    if(r) return setBit(x,t);
    else return ClearBit(x,t);
}

int flipBit(int x, int t){
    int aux = 1;
    aux = aux << t;
    return x^aux;
}

int x;

int main(){
    ASM_BEG

	INSPECT(" cmp x, eax ")
	INSPECT(" mov eax, 0xaabbccdd ")

	ASM_END
}