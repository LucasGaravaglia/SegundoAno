#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#define NUM_MESTRE 1000

/* ------------ ATENÇÃO ------------------------
 *
 *  MUDAR O DIRETORIO DESSES DEFINES, COLOCANDO
 *            O ENDEREÇO DO SEU PC
 *
 * ---------------------------------------------
*/

#define ArquivoMestre "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/RelatorioTestes.txt"
#define ArquivoVoo "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/RelatorioVoo.txt"
#define ArquivoClient "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/RelatorioClient.txt"
#define ArquivoAeronave "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/RelatorioAeronave.txt"
#define arqui_voo "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/voos.txt"
#define arqui_cliente "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/clientes.txt"
#define arqui_plane "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/planes.txt"
#define relat_dados_voos "/home/lucas/Área de Trabalho/AED-master/trabalhofinal/data_flights.txt"


/* Estruturas
 * Versão: 2.0
 * Ultima Modificação: 18/04/2019 - 23:00
 * Ultimo Editor: Levi
 */

//Struct que contem os dados de um voo.
typedef struct{
    char *prefixo,*nomeO,*nomeD,siglaO[4],siglaD[4],*tipo;
    char horaP[6],horaC[6],duracao[6];
}Flight;

//Struct que contem os dados de um cliente.
typedef struct {
    char *nome,*programa,*categoria, cpf[15];
    int saldo;
}Client;

//Struct que contem os dados da aeronave.
typedef struct{
    char *modelo;
    int comprimento,altura,envergadura,velocidadeC,alcance,cadeiras,banheiros;
}Plane;

//Struct para lista de voo
typedef struct no_voo{
    Flight voo;
    struct no_voo * prox;
    struct no_voo * ant;
}Lista_Voo;

//Struct para lista de clientes
typedef struct no_cliente{
    Client cliente;
    struct no_cliente * prox;
    struct no_cliente * ant;
}Lista_Cliente;

//Struct para lista de aeronaves
typedef struct no_plane{
    Plane aeronave;
    struct no_plane* prox;
    struct no_plane * ant;
}Lista_Plane;

#endif
