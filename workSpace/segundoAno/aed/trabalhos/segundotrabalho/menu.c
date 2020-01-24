#include "menu.h"
#include "arquivo.h"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "manterbiblioteca.h"


/* Captura um char do terminal
 * Pré-condição: nenhuma
 * Pós-condição: retorna o caracter 
*/
char getchChar(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}
/* Exibe o retorno ao menu
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void backmenu(){
    char key;
    printf("\nPrecione qualquer tecla para voltar ao menu.\n\n");
    key = getchChar();
}
/* Função auxiliar que ajuda a movimentação no menu
 * Pré-condição: Nenhuma
 * Pós-condição: A posição correta do menu é retornada
*/
int movmentMenu(int teclaPressionada, int *posicaoDoMenu, int primeiro, int ultimo){
    if( (teclaPressionada == TECLAPARACIMA1 || teclaPressionada == TECLAPARACIMA2) && *posicaoDoMenu != primeiro){
        *posicaoDoMenu-=1;
    }else if( (teclaPressionada == TECLAPARABAIXO1 || teclaPressionada == TECLAPARABAIXO2) && *posicaoDoMenu != ultimo){
        *posicaoDoMenu+=1;
    }else if( (teclaPressionada == TECLAPARACIMA1 || teclaPressionada == TECLAPARACIMA2) && *posicaoDoMenu == primeiro){
        *posicaoDoMenu = ultimo;
    }else if( (teclaPressionada == TECLAPARABAIXO1 || teclaPressionada == TECLAPARABAIXO2) && *posicaoDoMenu == ultimo){
        *posicaoDoMenu = primeiro;
    }else if(teclaPressionada == ENTER){
        return 1;
    }else{
        return 0;
    }
    return 0;
}
/* Função que mostra na tela o menu base
 * Pré-condição: Nenhuma
 * Pós-condição: O menu base é executado
*/
void mainMenu(int *var){
    char teclaPressionada = 0;
    int parteDoMenu = 0;
    int inicioMenu = 0; int fimMenu = 9;
    while(teclaPressionada != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        if(parteDoMenu == 0){
            printf("\t\t\t\t\t\t\t\t-> %-14s Carregar arquivos de inicialização.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = CARREGARARQUIVOINICIAL;
            }
        }else if(parteDoMenu == 1){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-35s Inserir livro.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = INSERIRLIVRO;
            }
        }else if(parteDoMenu == 2){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-18s Atualizar numero de exemplares.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = ATUALIZAREXEMPLARES;
            }
        }else if(parteDoMenu == 3){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-35s Remover livro.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = REMOVERLIVRO;
            }
        }else if(parteDoMenu == 4){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-27s Buscar dados do livro.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = BUSCARDADOSDOLIVRO;
            }
        }else if(parteDoMenu == 5){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-25s Imprimir árvore binária.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = IMPRIMIRARVOREBINARIA;
            }
        }else if(parteDoMenu == 6){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-15s Imprimir árvore binária por nível.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = IMPRIMIRARVORENIVEL;
            }
        }else if(parteDoMenu == 7){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-33s Imprimir acervo.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = IMPRIMIRACERVO;
            }
        }else if(parteDoMenu == 8){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-24s Gerar Listagem de livros.[%c]\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t-> Sair %-45s[%c]\n"," ",' ');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = LISTAGEMLIVROS;
            }
        }else if(parteDoMenu == 9){
            printf("\t\t\t\t\t\t\t\t-> Carregar arquivos de inicialização. %-14s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Inserir livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Atualizar numero de exemplares. %-18s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Remover livro. %-35s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Buscar dados do livro. %-27s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária. %-25s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir árvore binária por nível. %-15s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Imprimir acervo. %-33s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> Gerar Listagem de livros. %-24s[%c]\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t-> %-45s Sair[%c]\n"," ",'*');
            printf("\n\t\t\t\t\t\t\t\t ________________________________________________________\n\n");
            printf("\t\t\t\t\t\t\t\t\tUtilize w e s para se movimentar no menu         \n");
            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = SAIRDOPROGRAMA;
            }
        }

    }
    
}
/* Função que executa os menus
 * Pré-condição: Nenhuma
 * Pós-condição: O menu é executado
*/ 
void deciderMenu(){
    int MENU = 1; //Variável de decisão do menu
    while(MENU != SAIRDOPROGRAMA){ 
        if(MENU == MENUPRINCIPAL){
            system("clear");
            mainMenu(&MENU);
        }else if(MENU == INSERIRLIVRO){
            system("clear");
            InsereLivro();
            MENU = MENUPRINCIPAL;
        }else if(MENU == ATUALIZAREXEMPLARES){
            system("clear");
            atualizaexemplares(); 
            MENU = MENUPRINCIPAL;
        }else if(MENU == REMOVERLIVRO){
            system("clear");
            RemoveLivroCadastro();
            MENU = MENUPRINCIPAL;
        }else if(MENU == BUSCARDADOSDOLIVRO){
            system("clear");
            BuscaDadoLivro();            
            MENU = MENUPRINCIPAL;
        }else if(MENU == IMPRIMIRARVOREBINARIA){ 
            system("clear");
            ImprimiArvore();            
            MENU = MENUPRINCIPAL;
        }else if(MENU == IMPRIMIRARVORENIVEL){ 
            system("clear");
            ImprimiArvoreNivel();            
            MENU = MENUPRINCIPAL;
        }else if(MENU == IMPRIMIRACERVO){ 
            system("clear");
            ImprimeAcervo();
            MENU = MENUPRINCIPAL;
        }else if(MENU == LISTAGEMLIVROS){ 
            system("clear");
            ListaLivrosOrdenado();
            MENU = MENUPRINCIPAL;
        }else if(MENU == CARREGARARQUIVOINICIAL){  
            system("clear");                     
            LoadFile();
            MENU = MENUPRINCIPAL;
        }
            
    }
}
