#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define dot -2
#define Hline -51
#define Vline -70
#define block -37
#define l 32

//main boards
char beginner[5][5];
char expert[11][11];

//defining colors
//player 1 will be red
//player 2 will be blue
void blue () {
    printf ("\033[1;34m");
}

void red () {
    printf ("\033[1;31m");
}

void yellow () {
    printf ("\033[1;33m");
}

void reset () {
    printf ("\033[0m");
}

//creating the boards
void createArray (int x) {
    if (x==1) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++){
             beginner[i][j]=0;
            }
        }
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if ((i%2==0)&&(j%2==0)) {
                    beginner[i][j]=dot;
                }
                else {
                    beginner[i][j]=' ';
                }
            }
        }
    }
    else if (x==2){
        for (int i=0; i<11; i++) {
            for (int j=0; j<11; j++){
             expert[i][j]=0;
            }
        }
        for (int i=0; i<11; i++) {
            for (int j=0; j<11; j++) {
                if ((i%2==0)&&(j%2==0)) {
                    expert[i][j]=dot;
                }
                else {
                    expert[i][j]=' ';
                }
            }
        }
    }
}

//printing the boards
 void printArray (int x) {
    if (x==1) {
        printf("\n\n");
        printf ("\t\t\t");
        printf ("  ");
        for (int i=0; i<5; i++) {
            printf (" %d ",i);
        }
        printf ("\n");
        for (int i=0; i<5; i++) {
                printf("\t\t\t");
                printf ("%d ",i);
            for (int j=0; j<5; j++) {
                printf (" %c ",beginner[i][j]);
            }
            printf ("\n");
        }
    }
   else if (x==2){
        printf("\n\n");
        printf ("   ");
        for (int i =0; i<11; i++) {
            printf (" %d ",i);
        }
        printf ("\n");
        for (int i=0; i<11; i++) {
            if (i>9) {
                printf ("%d ",i);
                for (int j=0; j<11; j++) {
                    printf(" %c ",expert[i][j]);
                }
                printf ("\n");
            }
            else {printf ("%d  ",i);
                for (int j=0; j<11; j++) {
                    printf(" %c ",expert[i][j]);
                }
                printf ("\n");
            }
        }
    }

}

//function for checking whether the move played completed a box
void checkBox (int n, char board[][n]) {
    for (int i=1;i<=(n-2);i+=2) {
        for (int j=1;j<=(n-2);j+=2) {
            if ((board[i-1][j]!=' ')&&(board[i+1][j]!=' ')&&(board[i][j-1]!=' ')&&(board[i][j+1]!=' ')) {
                board[i][j]=block;
            }
        }
    }
}

//gamemode2 algorithm (vs human)
void gamemode2(int y){
  createArray(y);
  int i=0,r,c,remMoves;
  if (y==1) remMoves=12;
  else remMoves=60;
  place1:
  while(1){
        system("cls");
       if(y==1){
            printArray(y);
             if(i%2==0){
                printf("\n\nPlayer 1 turn\n\n");
                printf ("remaining moves: %d \n\n", remMoves);
                printf("Enter number of row: ");
                scanf(" %d",&r);
                printf("\nEnter number of column: ");
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(beginner[r][c]==' '){
                            if(r%2==0){
                                beginner[r][c]=Hline;
                            }
                            else{
                                beginner[r][c]=Vline;
                            }
                            checkBox(5,beginner);
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                   }
             }
             else{
                printf("\n\n player 2 turn\n\n");
                printf ("remaining moves: %d \n\n", remMoves);
                printf("Enter number of row: ");
                scanf(" %d",&r);
                printf("\nEnter number of column: ");
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(beginner[r][c]==' '){
                            if(r%2==0){
                                beginner[r][c]=Hline;
                            }
                            else{
                                beginner[r][c]=Vline;
                            }
                            checkBox(5,beginner);
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                   }

             }
           i++;
           remMoves--;
       }
        else {
            printArray(y);
                if(i%2==0){
                printf("\n\n player 1 turn\n\n");
                printf ("remaining moves: %d \n\n", remMoves);
                printf("Enter number of row: ");
                scanf(" %d",&r);
                printf("\nEnter number of column: ");
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(expert[r][c]==' '){
                            if(r%2==0){
                                expert[r][c]=Hline;
                            }
                            else{
                                expert[r][c]=Vline;
                            }
                            checkBox(11,expert);

                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                   }
             }
             else{
                printf("\n\n player 2 turn\n\n");
                printf ("remaining moves: %d \n\n", remMoves);
                printf("Enter number of row: ");
                scanf(" %d",&r);
                printf("\nEnter number of column: ");
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(expert[r][c]==' '){
                            if(r%2==0){
                                expert[r][c]=Hline;
                            }
                            else{
                               expert[r][c]=Vline;
                            }
                            checkBox(11,expert);

                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                   }

             }
          i++;
          remMoves--;
      }
  }
}

//main 
int main(void){
    system ("COLOR");
    int mainChoice;
    int begOrEx,playernum,after;
    jump0:
    while(1){
        system("cls");
        //first menu
        reset();
        printf ("\t\t\t\t  Dots and boxes Game\n\n\n");
        printf ("\t\t\t\tEnter a number to start\n\n\n");
        yellow();
        printf ("1.New game\n\n\n");
        printf ("2.Load game\n\n\n");
        printf ("3.LeaderBoard\n\n\n");
        printf ("4.Exit\n\n\n");
        reset();
        printf ("Enter your choice: \n\n");
        scanf (" %d", &mainChoice);
        switch(mainChoice){
        case 1:
            goto jump1;
            break;
        case 2:
            goto jump2;
            break;
        case 3:
            goto jump3;
            break;
        case 4:
            goto jump4;
            break;
        default:
            system ("cls");
            yellow();
            printf("invalid number\n\n");
            system("pause");
            break;
        }
    }
    jump1:
    while(1){
        system("cls");
        reset();
        //second menu
        yellow();
        printf("1.one player\n\n\n");
        printf("2.two players\n\n\n");
        reset();
        printf("Enter your choice: \n\n");
        scanf("%d",&playernum);
        if(playernum==1 ||playernum==2){
            break;
        }
        else{
            system ("cls");
            yellow();
            printf("invalid number\n\n");
            system("pause");
        }
    }
        while(1){
         system("cls");
         reset();
         //third menu
         yellow();
         printf("1.beginner\n\n\n");
         printf("2.expert\n\n\n");
         reset();
         printf("Enter your choice: \n\n");
        scanf("%d",&begOrEx);
         if(begOrEx==1 || begOrEx==2){
            break;
        }
        else{
            system ("cls");
            yellow();
            printf("invalid number\n\n");
            system("pause");
        }
    }
        system("cls");
        if (playernum==2){
            gamemode2(begOrEx);
        }
        else {
            //gamemode1(begOrEx);
        }
        system("pause");
        jump5:
        while(1){
            system("cls");
            reset();
            //menu after end of game
            yellow();
            printf("1.main menu\n\n\n");
            printf("2.exit\n\n\n");
            reset();
            printf("Enter your choice: \n\n");
            scanf("%d",&after);
            if(after==1){
               goto jump0;

        }
        else if(after==2){
              goto jump4;
              system("cls");
        }
        else{
            system ("cls");
            yellow();
            printf("invalid number\n\n");
            system ("pause");
            goto jump5;
        }

        }


    jump2:
    jump3:
    jump4:
    return 0;
}
