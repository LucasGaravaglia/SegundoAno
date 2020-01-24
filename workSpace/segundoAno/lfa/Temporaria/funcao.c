#include "funcao.h"

void Carregar_Arquivo( char Arq[] ){
    char aux; //aux onde palavras que n�o usaremos para a cria��o da gramatica ser�o descartadas
    int tam_alfabeto = 0, num_estados = 0, i = 0;
    FILE *arq;
    num_estadosFinal = 0;

    arq = fopen("afd1.txt","r");

    if( arq == NULL ){
        printf("Erro ao abrir o arquivo");
    }
    else{

    //leitura do alfabeto
        do{//le tudo ate o { e armazena na variavel que nao ser� usada
            fscanf( arq, "%c", &aux );
        }while( aux != '{' );

        do{
            fscanf( arq, "%c", &alfabeto[tam_alfabeto] ); //alfabeto
            fscanf( arq, "%c", &aux );//virgula
            tam_alfabeto++;
        }while( aux != '}');

    //leitura dos estados
        do{//le tudo ate o { e armazena na variavel que nao ser� usada
            fscanf( arq, "%c", &aux );
        }while( aux != '{');

        do{
            fscanf( arq, "%c", &aux );//q
            fscanf( arq, "%d", &estados[num_estados] );//estado
            fscanf( arq, "%c", &aux );//virgula
            num_estados++;
        }while ( aux != '}');

    //leitura do estado inicial
        do{//le tudo ate o = e armazena na variavel que nao ser� usada
            fscanf( arq, "%c", &aux );//inicial
        }while( aux != '=');

        fscanf( arq, "%c", &aux );//q
        fscanf( arq, "%d", &EstadoInicial );//estado

        fscanf( arq, "\n" );

    //leitura dos estados finais
        do{//le tudo ate o { e armazena na variavel que nao ser� usada
            fscanf( arq, "%c", &aux );
        }while( aux != '{');

        do{
            fscanf( arq, "%c", &aux );//q
            fscanf( arq, "%d", &EstadosFinal[num_estadosFinal] );//estado
            fscanf( arq, "%c", &aux );//virgula
            num_estadosFinal++;
        }while ( aux != '}');

    //leitura das transi��es
        fscanf( arq, "%c", &aux);

        while(fgetc(arq) != EOF ){

            do{
                fscanf( arq, "%c", &aux );
            }while( aux != 'q');

            fscanf( arq, "%d", &transicao[num_transicoes].EstadoAtual);//primeiro estado
            fscanf( arq, "%c", &aux);//virgula
            fscanf( arq, "%c", &transicao[num_transicoes].CaracterLido);//letra do alfabeto

            do{//le tudo ate o q e armazena na variavel que nao ser� usada
                fscanf( arq, "%c", &aux );
            }while( aux != 'q');

        fscanf( arq, "%d", &transicao[num_transicoes].EstadoProx);//estado para onde a letra lida leva
        num_transicoes++;
        }

        printf("   ARQUIVO CARREGADO COM SUCESSO\n");
    }

}

void Carregar_ArquivoAFE( char *Arq ){
    char aux; //aux onde palavras que não usaremos para a criação da gramatica serão descartadas
    int tam_alfabetoAFE = 0, num_estadosFinalAFE = 0, i = 0,j = 0;
    FILE *arq;
    arq = fopen(arq,"r");

    if( arq == NULL ){
        printf("Erro ao abrir o arquivo");
    }
    else{

    //leitura do alfabeto
        do{//le tudo ate o { e armazena na variavel que nao será usada
            fscanf( arq, "%c", &aux );
        }while( aux != '{' );

        do{
            fscanf( arq, "%c", &alfabetoAFE[tam_alfabetoAFE] ); //alfabeto
            fscanf( arq, "%c", &aux );//virgula
            tam_alfabetoAFE++;
        }while( aux != '}');

    //leitura dos estados
        do{//le tudo ate o { e armazena na variavel que nao será usada
            fscanf( arq, "%c", &aux );
        }while( aux != '{');

        do{
            fscanf( arq, "%c", &aux );//letra que representa o estado
            fscanf( arq, "%d", &estadosAFE[num_estadosAFE] );//numero do estado
            fscanf( arq, "%c", &aux );//virgula
            num_estadosAFE++;
        }while ( aux != '}');

    //leitura do estado inicial
        do{//le tudo ate o = e armazena na variavel que nao será usada
            fscanf( arq, "%c", &aux );//inicial
        }while( aux != '=');

        fscanf( arq, "%c", &aux );//letra que representa o estado
        fscanf( arq, "%d", &EstadoInicialAFE );//numero do estado

        fscanf( arq, "\n" );

    //leitura dos estados finais
        do{//le tudo ate o { e armazena na variavel que nao será usada
            fscanf( arq, "%c", &aux );
        }while( aux != '{');

        do{
            fscanf( arq, "%c", &aux );//letra que representa o estado
            fscanf( arq, "%d", &EstadosFinalAFE[num_estadosFinalAFE] );//numero do estado
            fscanf( arq, "%c", &aux );//virgula
            num_estadosFinalAFE++;
        }while ( aux != '}');

    //leitura das transições
        fscanf( arq, "%c", &aux);

        while(fgetc(arq) != EOF ){

            do{
                fscanf( arq, "%c", &aux );
            }while( aux != 'q');

            fscanf( arq, "%d", &transicaoAFE[num_transicoesAFE].EstadoAtualAFE);//primeiro estado
            fscanf( arq, "%c", &aux);//virgula
            fscanf( arq, "%c", &transicaoAFE[num_transicoesAFE].CaracterLidoAFE);//letra do alfabeto

            for(;;){ 
                do{//le tudo ate o q e armazena na variavel que nao será usada
                fscanf( arq, "%c", &aux );
            }while( aux != 'q' || aux != '\n');
            if(aux == '\n') break;
                fscanf( arq, "%d", &transicaoAFE[num_transicoesAFE].EstadoProxAFE[j]);
                fscanf( arq, "%c", &aux );
                j++;
            }
            num_transicoesAFE++;
        }

        printf("   ARQUIVO AFE CARREGADO COM SUCESSO!!\n");
    }

}

int validar_palavra( char palavra[] ){
    int i = 0, j = 0;
    int aux;

    while(palavra[i]!=0){
        aux = 0;
        j = 0;
        while(alfabeto[j]!=0){
            if( palavra[i] == alfabeto[j] )aux++;
            j++;
        }
        if (aux == 0) return 1;
        i++;
    }

    return 0;
}

int processar_palavra(char palavra[], int estado){
    char simbolo = palavra[0];

    if(estado == -1) return 0;

    printf("[q%d]%s\n", estado, palavra);

    if(!simbolo && eh_final(estado)) return 1;

    return processar_palavra(palavra+1, prox_estado(estado, palavra[0]));
}

int eh_final(int estado) {
	int i;
	for(i = 0; i < num_estadosFinal; ++i) {
		if(estado == EstadosFinal[i]) {
			return 1;
		}
	}
	return 0;
}

int prox_estado(int estadoAtual, char simbolo) {
	int i;
	for(i = 0; i < num_transicoes; ++i) {
		if(transicao[i].EstadoAtual == estadoAtual && transicao[i].CaracterLido == simbolo) {
			return transicao[i].EstadoProx;
		}
	}

	return -1;
}