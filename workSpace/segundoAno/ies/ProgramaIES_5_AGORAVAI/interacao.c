#include "interacao.h"
#include "testevoo.h"
#include "lista_cliente.h"
#include "relatoriotesteaeronave.h"
#include "relatoriotesteclietes.h"
#include "relatoriotestes.h"
#include "relatoriotestevoo.h"

#define NUM_MESTRE 1000

Lista_Voo * insere_terminal_voo(Lista_Voo *v){
        Flight voo;
        int temp;
        voo.nomeD = malloc(50*sizeof(char));
        voo.nomeO = malloc(50*sizeof(char));
        voo.prefixo = malloc(50*sizeof(char));
        voo.tipo = malloc(50*sizeof(char));
        printf("Prefixo do voo:\n");
        scanf("%s",voo.prefixo);
        printf("Tipo da aeronave:\n");
        scanf("%s%*c",voo.tipo);
        printf("Cidade de origem:\n");
        scanf("%[^\n]",voo.nomeO);
        printf("Sigla de origem:\n");
        scanf("%s",voo.siglaO);
        printf("Horario de Saida:\n");
        scanf("%s%*c",voo.horaP);
        printf("Cidade de destino:\n");
        scanf("%[^\n]",voo.nomeD);
        printf("Sigla de Destino:\n");
        scanf("%s%*c",voo.siglaD);
        printf("Horario de chegada:\n");
        scanf("%s%*c",voo.horaC);
        printf("Duracao:\n");
        scanf("%s%*c",voo.duracao);
        temp = countListFlight(v);
        v = insertListFlight(v,voo);
        if(temp == countListFlight(v))
            printf("Erro ao inserir voo.\n");
        else
            printf("Voo inserido com sucesso.\n");
        printf("\nSelecione qualquer tecla para voltar ao menu\n");
        getch();
        return v;
}

Lista_Cliente * insere_terminal_cliente(Lista_Cliente *c){
        Client client;
        int temp;
        client.nome = malloc(50*sizeof(char));
        client.programa = malloc(50*sizeof(char));
        client.categoria = malloc(50*sizeof(char));
        printf("Cpf do cliente:\n");
        scanf("%s%*c",client.cpf);
        printf("Nome do cliente:\n");
        scanf("%[^\n]%*c",client.nome);
        printf("Nome do programa:\n");
        scanf("%[^\n]%*c",client.programa);
        printf("Categoria:\n");
        scanf("%[^\n]%*c",client.categoria);
        printf("Saldo de milhas:\n");
        scanf("%d",&client.saldo);
        temp = countListClient(c);
        c = insertListClient(c,client);
        system("clear");
        if(temp == countListClient(c))
            printf("Erro ao inserir Client.\n");
        else
            printf("Client inserido com sucesso.\n");
        printf("\nSelecione qualquer tecla para voltar ao menu\n");
        getch();
        return c;
}

Lista_Plane * insere_terminal_aeronave(Lista_Plane *p){
        Plane aeronave;
        int temp;
        aeronave.modelo = malloc(50*sizeof(char));
        printf("Digite o modelo da aeronave:\n");
        scanf("%s",aeronave.modelo);
        printf("Alcance da aeronave:\n");
        scanf("%d",&aeronave.alcance);
        printf("Altura da aeronave:\n");
        scanf("%d",&aeronave.altura);
        printf("Quantidade de banheiros da aeronave:\n");
        scanf("%d",&aeronave.banheiros);
        printf("Qantidade de cadeiras na aeronave:\n");
        scanf("%d",&aeronave.cadeiras);
        printf("Comprimento da aeronave:\n");
        scanf("%d",&aeronave.comprimento);
        printf("Envergadura da aeronave:\n");
        scanf("%d",&aeronave.envergadura);
        printf("Velocidade de Cruzeiro da aeronave:\n");
        scanf("%d",&aeronave.velocidadeC);
        imprime_plane(aeronave);
        temp = countListPlane(p);
        p = insertListPlane(p,aeronave);
        if(temp == countListPlane(p))
            printf("Erro ao inserir Aeronave.\n");
        else
            printf("Aeronave inserida com sucesso.\n");
            
        printf("\nSelecione qualquer tecla para voltar ao menu\n");
        getch();
        free(aeronave.modelo);
        return p;
}

void altera_terminal_voo(Lista_Voo *v){
    char temp [50];
    Flight voo, desejado;
    printFlightList(v);
    printf("Insira o prefixo do voo que voce deseja alterar:\n");
    scanf("%s", temp);
    system("clear");
    desejado.prefixo = malloc(50*sizeof(char));
    strcpy(desejado.prefixo, temp);
    if(viewFlightList(v,desejado)){
        printf("\n\n");
        voo.prefixo = malloc(20*sizeof(char));
        voo.nomeD = malloc(50*sizeof(char));
        voo.nomeO = malloc(50*sizeof(char));
        voo.tipo = malloc(20*sizeof(char));
        printf("Prefixo do voo:\n");
        scanf("%s",voo.prefixo);
        printf("Tipo da aeronave:\n");
        scanf("%s%*c",voo.tipo);
        printf("Cidade de origem:\n");
        scanf("%[^\n]",voo.nomeO);
        printf("Sigla de origem:\n");
        scanf("%s",voo.siglaO);
        printf("Horario de Saida:\n");
        scanf("%s%*c",voo.horaP);
        printf("Cidade de destino:\n");
        scanf("%[^\n]",voo.nomeD);
        printf("Sigla de Destino:\n");
        scanf("%s%*c",voo.siglaD);
        printf("Horario de chegada:\n");
        scanf("%s%*c",voo.horaC);
        printf("Duracao:\n");
        scanf("%s%*c",voo.duracao);
        if(changeListaFlight(v,voo, desejado))
            printf("Voo inserido com sucesso.\n");
        else
            printf("Nao foi possivel alterar\n");
        
        free(voo.prefixo);
        free(voo.nomeD);
        free(voo.nomeO);
        free(voo.tipo);
        
    }else
        printf("Voo nao encontrado");
    printf("\nSelecione qualquer tecla para voltar ao menu\n");
    
    
    getch();
    free(desejado.prefixo);
    
}

void altera_terminal_cliente(Lista_Cliente *v){
    char temp[20];
    Client desejado, client;
    printClientList(v);
    printf("Insira o cpf do cliente que vc deseja alterar:\n");
    scanf("%s", temp);
    system("clear");
    strcpy(desejado.cpf,temp);
    if(printListClient(v,desejado)){
        client.nome = malloc(20*sizeof(char));
        client.programa = malloc(20*sizeof(char));
        client.categoria = malloc(20*sizeof(char));
        printf("Seu cpf:\n");
        scanf("%s%*c",client.cpf);
        printf("Nome do cliente:\n");
        scanf("%[^\n]%*c",client.nome);
        printf("Nome do programa:\n");
        scanf("%[^\n]%*c",client.programa);
        printf("Categoria:\n");
        scanf("%[^\n]%*c",client.categoria);
        printf("Saldo de milhas:\n");
        scanf("%d",&client.saldo);
        if(changeListClient(v,client,desejado))
            printf("Cliente alterado com sucesso!!\n");
        else
            printf("Nao foi alterar\n");
        free(client.nome);
        free(client.programa);
        free(client.categoria);
    }else
        printf("Voo nao encontrado\n");
        
    printf("\nSelecione qualquer tecla para voltar ao menu\n");
    
    getch();
    
}

void altera_terminal_aeronave(Lista_Plane *v){
    char temp[20];
    Plane desejado,aeronave;
    printPlaneList(v);
    printf("Insira modelo da aeronave que voce deseja alterar:\n");
    scanf("%s", temp);
    system("clear");
    desejado.modelo = malloc(20*sizeof(char));
    strcpy(desejado.modelo,temp);
    if(printListPlane(v,desejado)){
        aeronave.modelo = malloc(20*sizeof(char));
        printf("Digite o modelo da aeronave:\n");
        scanf("%s",aeronave.modelo);
        printf("Alcance da aeronave:\n");
        scanf("%d",&aeronave.alcance);
        printf("Altura da aeronave:\n");
        scanf("%d",&aeronave.altura);
        printf("Quantidade de banheiros da aeronave:\n");
        scanf("%d",&aeronave.banheiros);
        printf("Qantidade de cadeiras na aeronave:\n");
        scanf("%d",&aeronave.cadeiras);
        printf("Comprimento da aeronave:\n");
        scanf("%d",&aeronave.comprimento);
        printf("Envergadura da aeronave:\n");
        scanf("%d",&aeronave.envergadura);
        printf("Velocidade de Cruzeiro da aeronave:\n");
        scanf("%d",&aeronave.velocidadeC);
        if(changeListPlane(v,aeronave,desejado))
            printf("Aeronave alterada com sucesso!\n");
        else
            printf("Nao foi alterar\n");
    }else
        printf("Aeronave nao encontrada\n");
    printf("\nSelecione qualquer tecla para voltar ao menu\n");
    free(desejado.modelo);
    getch();






}

void mostra_terminal_voo(Lista_Voo *lista){
    char LeituraPrefixo[20];
    Flight voo;
    voo.prefixo=malloc(sizeof(char)*20);
    printFlightList(lista);
    printf("\nDigite o Prefixo do voo que deseja consultar:\n");
    scanf("%s",LeituraPrefixo);
    strcpy(voo.prefixo,LeituraPrefixo);
    if(viewFlightList(lista, voo )){
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }else{
        printf("Voo nao encontrado\m");
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }
    free(voo.prefixo);
    getch();
}

void mostra_terminal_cliente(Lista_Cliente *lista){
    char cpf[20];
    Client cliente;
    printClientList(lista);
    printf("\nDigite o Cpf do cliente que voce deseja consultar:\n");
    scanf("%s",cpf);
    strcpy(cliente.cpf,cpf);
    if(printListClient(lista,  cliente)){
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }else{
        printf("Cliente nao encontrado\n");
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }
    getch();
}

void mostra_terminal_aeronave(Lista_Plane *lista){
    char modelo[50];
    Plane aviao;
    printPlaneList(lista);
    printf("\nDigite o modelo da aeronave que voce deseja consultar:\n");
    scanf("%s",modelo);
    aviao.modelo=malloc(sizeof(char)*50);
    strcpy(aviao.modelo,modelo);
    if(printListPlane(lista,  aviao)){
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }else{
        printf("Aeronave nao encontrada\n");
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }
    free(aviao.modelo);
    getch();
}

Lista_Voo * deleta_terminal_voo(Lista_Voo *v){
    int cont;
    char temp[20];
    Flight desejada;
    printFlightList(v);
    printf("Digite o voo que deseja deletar:\n");
    scanf("%s",temp);
    desejada.prefixo = malloc(50*sizeof(char));
    strcpy(desejada.prefixo,temp);
    cont = countListFlight(v);
    v = deleteListFlight(v,desejada);
    if(cont == countListFlight(v)){
        printf("Nao foi possivel deletar o voo.\n");
    }else
        printf("Voo deletado com sucesso!\n");
        
    printf("\n\nClique qualquer tecla para voltar ao menu.");
    free(desejada.prefixo);
    getch();
    return  v;
}

Lista_Cliente * deleta_terminal_cliente(Lista_Cliente *v){
    int cont;
    char temp[20];
    Client desejada;
    printClientList(v);
    printf("Digite o cpf do cliente a ser deletado:\n");
    scanf("%s",temp);
    strcpy(desejada.cpf,temp);
    cont = countListClient(v);
    v = deleteListClient(v,desejada);
    if(cont == countListClient(v)){
        printf("Nao foi possivel deletar o cliente.\n");

    }else
        printf("Cliente deletado com sucesso!\n");
    printf("\n\nClique qualquer tecla para voltar ao menu.");
    getch();
    return v;
}


Lista_Plane * deleta_terminal_aeronave(Lista_Plane *v){
    int cont;
    char temp[50];
    Plane desejada;
    printPlaneList(v);
    printf("Digite o modelo da aeronave a ser deletado:\n");
    scanf("%s", temp);
    desejada.modelo=malloc(sizeof(char)*50);
    strcpy(desejada.modelo ,temp);
    cont = countListPlane(v);
    v = deleteListPlane(v,desejada);
    if(cont == countListPlane(v)){
         printf("Nao foi possivel deletar a aeronave.\n");
    }else
        printf("Aeronave deletado com sucesso!\n");
       
    printf("\n\nClique qualquer tecla para voltar ao menu.");
    getch();
    free(desejada.modelo);
    return v;
}




void mostra_terminal_cliente_cliente(Lista_Cliente *lista){
    char cpf[20];
    Client cliente;
    
    printf("\nDigite o Seu Cpf:\n");
    scanf("%s",cpf);
    
    strcpy(cliente.cpf,cpf);
    
    if(printListClient(lista,  cliente)){
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }else{
        printf("Cadastro Nao encontrado\n");
        printf("\n\nClique qualquer tecla para voltar ao menu.");
    }
    getch();
    
}








