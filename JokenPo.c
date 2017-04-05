#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char menu;                 //variaveis globais
char nome[40];
char lixo[10];

//FUNCAO QUE COMPARA OS VALORES E DEFINE QUEM VENCEU
void comparar(int x , int y, int *user, int *pc)
 {

     /* 1 = Pedra  -- 2 = Papel -- 3 = Tesoura -- x = computador -- y = usuario */

      if (x == y){
         printf("\tEMPATOU");
      }
      else if (x == 1){
         if(y == 2 ){
            printf("\tVOCE GANHOU");
            *user += 1;
         } else {
            printf("\tVOCE PERDEU");
            *pc += 1;
         }
      }
      else if (x == 2){
         if (y == 1){
            printf("\tVOCE PERDEU");
            *pc += 1;
         }
         else{
            printf("\tVOCE GANHOU");
            *user += 1;
         }
      }
      else if (x == 3){
         if (y == 1){
            printf("\tVOCE GANHOU");
            *user += 1;
         }
         else{
            printf("\tVOCE PERDEU");
            *pc += 1;
         }
      }
 }

// EXIBE UMA LINHA -- PROCEDIMENTO
 void linha (void)
 {
   printf("\n\t------------------------------------------------------\n");
 }

//EXIBE UMA LINHA COM DOIS TIPOS DE CARACTERE
 void linha1 (char x, char z)
 {
      int c;

      printf("\n\t");

      for(c = 0; c < 25; c++)
      {
         printf("%c%c",x,z);
      }

      printf("\n");
 }


//TODO O CODIGO DO JOGO DESENVOLVIMENTO E APLICAÇÃO DA LOGICA
void game(void){
  //DECÇARACAO DE VARIAVEIS
  int choice_pc;
  int choice_user=0;
  int try_again = 0;
  int user;
  int comp;
  comp=user=0;
  FILE *registro;      //PONTEIRO PARA O TIPO FILE


  do{
    system("cls");

    srand (time(NULL));               //SEMENTE PARA A FUNCAO RAND
    choice_pc = rand() % 9;           //ATRIBUINDO UM NUMERO ALEATORIO PARA CHOICE_PC
    if (choice_pc < 3)                // DECIFRANDO ESCOLHA ALEATORIA DO COMPUTADOR
      choice_pc = 1;                 //PEDRA
    else if (choice_pc < 6)
     choice_pc = 2;                  //PAPEL
    else
      choice_pc = 3;                  //TESOURA


    //PARTE REFERENTE A ESCOLHA DO USUARIO

    printf("\t<><><><><><><><><><><> JOKEN PO <><><><><><><><><><><>\n");
    linha();

    // ---------------------------------------------
    printf("\t<><><><><><><><><>< FACA SUA ESCOLHA ><><><><><><><><>\n");
    printf("\t1 = PEDRA\n\t2 = PAPEL\n\t3 = TESOURA\n\t");
    scanf(" %d" , &choice_user);
      while (choice_user != 1 && choice_user != 2 && choice_user != 3) {
        printf("\n\tESCOLHA INVALIDA, TENTE NOVAMENTE\n");
        printf("\t<><><><><><><><><>< FACA SUA ESCOLHA ><><><><><><><><>\n");
        printf("\t1 = PEDRA\n\t2 = PAPEL\n\t3 = TESOURA\n\t");
      }

      // ----------------------------------------------
      //exibe na tela a escolha feita pelo usuario
      switch(choice_user){
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

      linha();   // exibe uma linha --

      //-----------------------------------------------
      //MOSTRANDO A ESCOLHA DO COMPUTADOR

      if (choice_pc == 1)
        printf("\tO COMPUTADOR ESCOLHEU PEDRA");
      else if (choice_pc == 2)
        printf("\tO COMPUTADOR ESCOLHEU PAPEL");
      else
        printf("\tO COMPUTADOR ESCOLHEU TESOURA");

      linha();

    // ------------------------------------------

    //MOSTRA NA TELA QUEM VENCEU
    comparar(choice_pc, choice_user, &user, &comp );
    linha();

    // MOSTRA NA TELA O PLACAR ATUAL DO JOGO
    printf("\t%s %d X %d PC",nome, user, comp );
    linha();

    //-------------------------------------------
    // -----  MENU 2----
    printf("\t1 = JOGAR NOVAMENTE\n");
    printf("\t2 = SAIR\n\t");
    scanf(" %d" , &try_again);
    linha();

      //  ------ INTEGRIDADE DE DADOS DO MENU ------
      while (try_again != 1 && try_again != 2)
      {
        printf("\tESCOLHA INVALIDA\n\tTENTE NOVAMENTE\n");
        printf("\t1 = JOGAR NOVAMENTE\n\t2 = MENU\n\t");
        scanf(" %d" , &try_again);
        linha();
      }

      //------------------------------------------
  } while (try_again == 1 ); // FINAL DO LAÇO DO...WHILE
  // RETORNANDO AO INICIO DO JOGO CASO A ESCOLHA SEJA DE JOGAR NOVAMENTE

  //------------------------------------------
  /*
  CASO O USUARIO NÃO QUEIRA MAIS JOGAR
  E GERADO UM REGISTRO COM OS DADOS DA DISPUTA
  */
  registro = fopen("HISTORICO.txt","a+");
  fprintf(registro,"\n%s\n%s" ,__DATE__,__TIME__);
  fprintf(registro,"\n%s %d\nCOMPUTADOR %d\n\n",nome,user,comp);
  fclose(registro);



} //FINAL DO BLOCO GAME ****

// APRESENTA O MENU DE OPCOES PRINCIPAL
void menu_opcoes(){
   //EXIBE NA TELA O MENU
   //E COLHE A OPCAO DO USUARIO
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
  // USANDO O LACO DO..WHILE PARA GARANTIR A INTEGRIDADE DOS DADOS
}

// MOSTRA OS CREDITOS DO JOGO
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
   gets(lixo); // PARAR A TELA
}

//CRIA UM ARQUIVO .TXT COM COM OS DADOS DAS PARTIDAS
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
  puts("INSIRA SEU NOME: ");         //SOLICITA O NOME DO USUARIO
  gets(nome);                        //PARA DEPOIS COLOCAR NO HISTORICO
    while(nome[0]=='\0')
    {
      puts("INSIRA SEU NOME: ");           //PARA GARANTIR QUE UM NOME SEJA DIGITADO
      gets(nome);                          //E NAO SEJA DADO APENAS <ENTER>
    }
  system("cls");          //LIMPA A TELA

  //ENTRADA DO JOGO
  linha1('<','>');
  printf("\t<               BEM VINDO AO JOKEN PO            >");
  linha1('<','>');

  fflush(stdin);         //LIMPA O BUFFER DO TECLADO
  gets(lixo);            //ESPERA A ENTRADA DE UMA TECLA QUALQUER PARA CONTINUAR A FLUXO

  system("cls");         //LIMPA A TELA

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
  }while(menu != '4');
  /*
  CASO SEJA DIFERENTE DE 4 RETORNAR PARA O BLOCO SWICTH DENTRO DO LACO
  E EXIBE O QUE FOI SELECIONADO NO MENU
  */
  //CASO A ESCOLHA SEJA SAIR, EXECUTAR O FLUXO FINAL

    system("cls");
    linha1('<','>');
    printf("\t\t\tATE MAIS TCHAU");
    linha1('<','>');
    system("pause");
}
