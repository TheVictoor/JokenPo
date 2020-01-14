#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char menu;                 
char nome[40];
char lixo[10];

void comparar(int x , int y, int *user, int *pc){
  if (x == y) {
    printf("\tEMPATOU");
  } else if (x == 1) {
    if(y == 2 ) {
      printf("\tVOCE GANHOU");
      *user += 1;
    } else {
      printf("\tVOCE PERDEU");
      *pc += 1;
    }
  } else if (x == 2) {
    if (y == 1) {
      printf("\tVOCE PERDEU");
      *pc += 1;
    } else {
      printf("\tVOCE GANHOU");
      *user += 1;
    }
  } else if (x == 3) {
    if (y == 1) {
      printf("\tVOCE GANHOU");
      *user += 1;
    } else {
      printf("\tVOCE PERDEU");
      *pc += 1;
    }
  }
}

void linha(void){
  printf("\n\t------------------------------------------------------\n");
}

void linha1 (char x, char z) {
  int c;

  printf("\n\t");

  for(c = 0; c < 25; c++) {
    printf("%c%c",x,z);
  }

  printf("\n");
}

void game(void){
  int choice_pc;
  int choice_user=0;
  int try_again = 0;
  int user;
  int comp;
  comp=user=0;
  FILE *registro;      

  do {
    system("cls");

    srand (time(NULL));               
    choice_pc = rand() % 9;           
    if (choice_pc < 3)               
      choice_pc = 1;                 
    else if (choice_pc < 6)
     choice_pc = 2;                  
    else
      choice_pc = 3;                 

    printf("\t<><><><><><><><><><><> JOKEN PO <><><><><><><><><><><>\n");
    linha();

    printf("\t<><><><><><><><><>< FACA SUA ESCOLHA ><><><><><><><><>\n");
    printf("\t1 = PEDRA\n\t2 = PAPEL\n\t3 = TESOURA\n\t");
    scanf(" %d" , &choice_user);

    while (choice_user != 1 && choice_user != 2 && choice_user != 3) {
      printf("\n\tESCOLHA INVALIDA, TENTE NOVAMENTE\n");
      printf("\t<><><><><><><><><>< FACA SUA ESCOLHA ><><><><><><><><>\n");
      printf("\t1 = PEDRA\n\t2 = PAPEL\n\t3 = TESOURA\n\t");
    }

    switch (choice_user) {
      case 1:
        printf("\tVOCE ESCOLHEU PEDRA.");
        break;
      case 2:
        printf("\tVOCE ESCOLHEU PAPEL.");
        break;
      case 3:
        printf("\tVOCE ESCOLHEU TESOURA.");
        break;
    }

    linha();   

    if (choice_pc == 1)
      printf("\tO COMPUTADOR ESCOLHEU PEDRA");
    else if (choice_pc == 2)
      printf("\tO COMPUTADOR ESCOLHEU PAPEL");
    else
      printf("\tO COMPUTADOR ESCOLHEU TESOURA");

    linha();

    comparar(choice_pc, choice_user, &user, &comp );
    linha();

    printf("\t%s %d X %d PC",nome, user, comp );
    linha();

    printf("\t1 = JOGAR NOVAMENTE\n");
    printf("\t2 = SAIR\n\t");
    scanf(" %d" , &try_again);
    linha();

    while (try_again != 1 && try_again != 2) {
      printf("\tESCOLHA INVALIDA\n\tTENTE NOVAMENTE\n");
      printf("\t1 = JOGAR NOVAMENTE\n\t2 = MENU\n\t");
      scanf(" %d" , &try_again);
      linha();
    }

  } while (try_again == 1 ); 

  registro = fopen("HISTORICO.txt","a+");
  fprintf(registro,"\n%s\n%s" ,__DATE__,__TIME__);
  fprintf(registro,"\n%s %d\nCOMPUTADOR %d\n\n",nome,user,comp);
  fclose(registro);
} 

void menu_opcoes(){
  do{
    system("cls");
    printf("\n\t------------------------------------------------------\n");
    printf("\t------------------------ MENU ------------------------");
    linha();
    printf("\t- 1 = GAME                                           -\n");
    printf("\t- 2 = HISTORICO                                      -\n");
    printf("\t- 3 = CREDITOS                                       -\n");
    printf("\t- 4 = SAIR                                           -");
    linha();
    printf("\t");
    menu = getche();
  } while(menu != '1' && menu != '2' && menu != '3' && menu != '4');
}

void creditos (void){
  system("cls");
  linha();
  printf("\t-                   DESENVOLVIDO POR:                -\n");
  printf("\t-                      JOAO VICTOR                   -\n");
  printf("\t-       ESTUDANDTE DE ANALISE E DESENVOLVIMENTO      -\n");
  printf("\t-                     DE SISTEMAS                    -\n");
  printf("\t-                     MATERIA  DE                    -\n");
  printf("\t-                LOGICA DE PROGRAMACAO               -");
  linha();
  fflush(stdin);
  gets(lixo); 
}

void historico(void){
  FILE *registro;
  char historico00[1000];
  system("cls");

  registro = fopen("HISTORICO.txt","a+");
  while(fgets(historico00, 1000 ,registro) != NULL){
    printf("%s", historico00);
  }
  fclose(registro);
  fflush(stdin);
  gets(lixo);
}

void main(void){
  puts("INSIRA SEU NOME: ");         
  gets(nome);                        
  while(nome[0]=='\0')
  {
    puts("INSIRA SEU NOME: ");       
    gets(nome);                      
  }
  system("cls");          

  
  linha1('<','>');
  printf("\t<               BEM VINDO AO JOKEN PO            >");
  linha1('<','>');

  fflush(stdin); 
  gets(lixo);    

  system("cls"); 

  menu_opcoes();
  do{
    switch(menu){
     case '1':
        game();
        menu_opcoes();
        break;
      case '2':
        historico();
        menu_opcoes();
        break;
      case '3':
        creditos();
        menu_opcoes();
        break;
      case '4':
        break;
    }
  } while(menu != '4');

  system("cls");
  linha1('<','>');
  printf("\t\t\tATE MAIS TCHAU");
  linha1('<','>');
  system("pause");
}