#include "menus.h"

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

int menu_movment(int a, int *b, int primeiro, int ultimo){
    if( (a == 119 || a == 87) && *b != primeiro){
        *b-=1;
    }else if( (a == 115 || a == 83) && *b != ultimo){
        *b+=1;
    }else if( (a == 119 || a == 87) && *b == primeiro){
        *b = ultimo;
    }else if( (a == 115 || a == 83) && *b == ultimo){
        *b = primeiro;
    }else if(a == 10){
        return 1;
    }else{
        return 0;
    }
    return 0;
}

void menu_testes(int *var){
    char a = 0;
    int b = 0;
    while(a != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(b == 0){
            printf("\t\t\t\t\t\t\t\t|-> Testar voo %-39s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Testar cliente %-35s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar aeronave %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar todos %-37s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 18;
            }
        }else if(b == 1){
            printf("\t\t\t\t\t\t\t\t|-> Testar voo %-39s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar cliente %-35s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Testar aeronave %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar todos %-37s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 19;
            }
        }else if(b == 2){
            printf("\t\t\t\t\t\t\t\t|-> Testar voo %-39s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar cliente %-35s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar aeronave %-34s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Testar todos %-37s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 20;
            }
        }else if(b == 3){
            printf("\t\t\t\t\t\t\t\t|-> Testar voo %-39s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar cliente %-35s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar aeronave %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar todos %-37s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 21;
            }
        }else if(b == 4){
            printf("\t\t\t\t\t\t\t\t|-> Testar voo %-39s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar cliente %-35s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar aeronave %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Testar todos %-37s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 8;
            }
        }
    }   
}

void menu_cadastro(int *var, int IAR){ //IAR = inserir = 0, alterar = 1 ou remover = 2
    char a = 0;
    int b = 0;
    while(a != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(b == 0){
            printf("\t\t\t\t\t\t\t\t|-> Via arquivo %-38s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Via terminal %-37s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,2)){
                *var = 16;
            }
        }else if(b == 1){
            printf("\t\t\t\t\t\t\t\t|-> Via arquivo %-38s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Via terminal %-37s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,2)){
                *var = 17;
            }
        }else if(b == 2){
            printf("\t\t\t\t\t\t\t\t|-> Via arquivo %-38s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Via terminal %-37s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,2)){
                *var = 8;
            }
        }
    }
}

void menu_func_adm(int *var){
    char a = 0;
    int b = 0;
    while(a != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(b == 0){
            printf("\t\t\t\t\t\t\t\t|-> Inserir %-42s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Alterar %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Remover %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Realizar testes %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 12;
            }
        }else if(b == 1){
            printf("\t\t\t\t\t\t\t\t|-> Inserir %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Alterar %-42s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Remover %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Realizar testes %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 13;
            }
        }else if(b == 2){
            printf("\t\t\t\t\t\t\t\t|-> Inserir %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Alterar %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Remover %-42s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Realizar testes %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 14;
            }
        }else if(b == 3){
            printf("\t\t\t\t\t\t\t\t|-> Inserir %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Alterar %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Remover %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Realizar testes %-34s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 15;
            }
        }else if(b == 4){
            printf("\t\t\t\t\t\t\t\t|-> Inserir %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Alterar %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Remover %-42s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Realizar testes %-34s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,4)){
                *var = 2;
            }
        }
    }
}

void menu_usuario(int *var){
    char a = 0;
    int b = 0;
    while(a != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(b == 0){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados do seu voo %-25s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar seus dados %-31s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar o status do seu voo %-22s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,3)){
                *var = 9;
            }
        }else if(b == 1){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados do seu voo %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar seus dados %-31s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar o status do seu voo %-22s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,3)){
                *var = 10;
            }
        }else if(b == 2){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados do seu voo %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar seus dados %-31s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar o status do seu voo %-22s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,3)){
                *var = 11;
            }
        }else if(b == 3){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados do seu voo %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar seus dados %-31s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar o status do seu voo %-22s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-43s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,3)){
                *var = 1;
            }
        }
    }
}

void menu_adm(int *var){
    char a = 0;
    int b = 0;
    while(a != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(b == 0){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um voo %-25s[%c] |\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um usuário %-21s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar status de um voo %-24s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de uma aeronave %-19s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Menu de funções de administrador %-16s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-42s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,5)){
                *var = 4;
            }
        }else if(b == 1){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um voo %-25s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um usuário %-21s[%c] |\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar status de um voo %-24s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de uma aeronave %-19s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Menu de funções de administrador %-16s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-42s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,5)){
                *var = 5;
            }
        }else if(b == 2){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um voo %-25s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um usuário %-21s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar status de um voo %-24s[%c] |\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de uma aeronave %-19s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Menu de funções de administrador %-16s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-42s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,5)){
                *var = 6;
            }
        }else if(b == 3){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um voo %-25s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um usuário %-21s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar status de um voo %-24s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de uma aeronave %-19s[%c] |\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Menu de funções de administrador %-16s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-42s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,5)){
                *var = 7;
            }
        }else if(b == 4){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um voo %-25s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um usuário %-21s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar status de um voo %-24s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de uma aeronave %-19s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Menu de funções de administrador %-16s[%c] |\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-42s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,5)){
                *var = 8;
            }
        }else if(b == 5){
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um voo %-25s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de um usuário %-21s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar status de um voo %-24s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Mostrar dados de uma aeronave %-19s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Menu de funções de administrador %-16s[%c] |\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Voltar %-42s[%c] |\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,5)){
                *var = 1;
            }
        }
    }
}

void menu_base(int *var){
    char a = 0;
    int b = 0;
    while(a != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(b == 0){
            printf("\t\t\t\t\t\t\t\t|-> Logar como administrador %-25s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Logar como usuário %-31s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Sair %-45s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,2)){
                *var = 2;
            }
        }else if(b == 1){
            printf("\t\t\t\t\t\t\t\t|-> Logar como administrador %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Logar como usuário %-31s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Sair %-45s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,2)){
                *var = 3;
            }
        }else if(b == 2){
            printf("\t\t\t\t\t\t\t\t|-> Logar como administrador %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Logar como usuário %-31s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Sair %-45s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");
            printf("\t\t\t\t\t\t\t\t                               \\ \n");
            printf("\t\t\t\t\t\t\t\t	       - \\- -           \\ \n");
            printf("\t\t\t\t\t\t\t\t	     - -  \\- ____________\\__________ \n");
            printf("\t\t\t\t\t\t\t\t	   - - - - \\___{}_O_O_O_O_/O_O_O__*_/>\n");
            printf("\t\t\t\t\t\t\t\t	 - - - - - - - - - - -  /\n");
            printf("\t\t\t\t\t\t\t\t                               /\n");
            printf("\t\t\t\t\t\t\t\t                              /	\n");
            a = getchChar();
            if(menu_movment(a,&b,0,2)){
                *var = 0;
            }
        }
    }
}
 
void menu_decider(){
    int var = 1; //Variável de decisão do menu
    int IAR; //Variável de decisão de cadastro(Inserir = 0, alterar = 1, remover = 2)
    while(var){ //Enquanto var for diferente de 0
        if(var == 1){ //Entra no menu base
            menu_base(&var);
        }else if(var == 2){ //Entra no menu de adm
            menu_adm(&var);
        }else if(var == 3){ //Entra no menu de usuário
            menu_usuario(&var);
        }else if(var == 4){ //Mostra os dados de um voo (versão administrador)
            var = 1;
        }else if(var == 5){ //Mostra os dados de um usuário (versão administrador)
            var = 1;
        }else if(var == 6){ //Mostra o status de um voo (versão administrador)
            var = 1;
        }else if(var == 7){ //Mostra os dados de uma aeronave
            var = 1;
        }else if(var == 8){ //Entra no menu funções de adm
            menu_func_adm(&var);
        }else if(var == 9){ //Mostra os dados de um voo (versão cliente)
            var = 1;
        }else if(var == 10){ //Mostra os dados de um usuário (versão cliente)
            var = 1;
        }else if(var == 11){ //Mostra o status de um voo (versão cliente)
            var = 1;
        }else if(var == 12){ //Entra no menu de cadastros
            menu_cadastro(&var,0);
        }else if(var == 13){ //Entra no menu de cadastros
            menu_cadastro(&var,1);
        }else if(var == 14){ //Entra no menu de cadastros
            menu_cadastro(&var,2);
        }else if(var == 15){ //Entra no menu de testes
            menu_testes(&var);
        }else if(var == 18){ //Realizar teste de voo
            var = 1;
        }else if(var == 19){ //Realizar teste de cliente
            var = 1;
        }else if(var == 20){ //Realizar teste de aeronave
            var = 1;
        }else if(var == 21){ //Realizar todos os testes
            var = 1;
        }else{
            var = 1;
        }
    }
}
