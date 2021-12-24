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
#define RED "\033[1;31m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[1;0m"
//main boards
int n=1;
char player[20][20];
int scoreplayer1=0;
int scoreplayer2=0;
int flag=0;

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
    printf ("\033[;0m");
}
void Undo_and_Redo(){




}
//creating the boards
void createArray (int x) {
        n=6*x-1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++){
             player[i][j]=0;
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if ((i%2==0)&&(j%2==0)) {
                    player[i][j]=dot;
                }
                else {
                    player[i][j]=' ';
                }
            }
        }
}

//printing the boards
 void printArray (int x) {
        printf("\n\n");
        printf ("\t\t\t");
        printf ("  ");
        for (int i=0; i<n; i++) {
            printf (" %d ",i);
        }
        printf ("\n");
        for (int i=0; i<n; i++) {
                printf("\t\t\t");
                printf ("%d ",i);
            for (int j=0; j<n; j++) {
                printf (" %c ",player[i][j]);
            }
            printf ("\n");
        }
    }
//function for checking whether the move played completed a box
void checkBox (int n, char board[20][20],int k) {
    for (int i=1;i<=(n-2);i+=2) {
        for (int j=1;j<=(n-2);j+=2) {
            if ((board[i-1][j]!=' ')&&(board[i+1][j]!=' ')&&(board[i][j-1]!=' ')&&(board[i][j+1]!=' ')) {

                if(k%2==0){
                    scoreplayer1++;
                    flag=1;
                    board[i][j]=RED block RESET;
                }
                else{
                    scoreplayer2++;
                    flag=1;
                    board[i][j]=BLUE block RESET;
                }
            }
        }
    }
    printf("%d",n);
}
void gamemode1(int y){
   createArray(y);
  int i=0,r,c,remMoves;
  if (y==1) remMoves=12;
  else remMoves=60;
    place2:
    while(1){
        system("cls");
        flag=0;
        printArray(y);
        if(i%2==0){
            printf(RED"\n\nPlayer's turn\n\n"RESET);
                printf (RED"remaining moves:"RESET);
                printf("%d\n",remMoves);
                printf(RED"player1 score="RESET);
                printf("%d\n",scoreplayer1);
                printf(RED"Enter number of row: "RESET);
                scanf(" %d",&r);
                printf(RED"\nEnter number of column: "RESET);
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place2;
                   }
                   else{
                      if(player[r][c]==' '){
                            if(r%2==0){
                                player[r][c]=(RED Hline RESET);
                            }
                            else{
                                player[r][c]=(RED Vline RESET);
                            }
                            checkBox(n,player,i);
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place2;
                      }
                   }
        }
        else{

             if((player[r-1][c]!=' ')&&(player[r+1][c]!=' ')&&(player[r][c-1]!=' ')&&(player[r][c+1]==' ')){
                   if(r%2==0){
                    player[r][c]=(BLUE Hline RESET);
                    }
                   else{
                    player[r][c]=(BLUE Vline reset ());
                    }
                    checkBox(n,player,i);

             }
             else if((player[r-1][c]!=' ')&&(player[r+1][c]!=' ')&&(player[r][c-1]==' ')&&(player[r][c+1]!=' ')){
                if(r%2==0){
                    player[r][c-1]=(BLUE Hline RESET);
                    }
                   else{
                    player[r][c-1]=BLUE Vline RESET;
                    }
                    checkBox(n,player,i);
             }
             else if((player[r-1][c]!=' ')&&(player[r+1][c]==' ')&&(player[r][c-1]!=' ')&&(player[r][c+1]!=' ')){
                if((r+1)%2==0){
                    player[r][c]=(BLUE Hline RESET);
                    }
                   else{
                    player[r][c]=(BLUE Vline RESET);
                    }
                    checkBox(n,player,i);
             }
             else if ((player[r-1][c]==' ')&&(player[r+1][c]!=' ')&&(player[r][c-1]!=' ')&&(player[r][c+1]!=' ')) {
                if((r-1)%2==0){
                    player[r-1][c]=(BLUE Hline RESET);
                    }
                   else{
                    player[r-1][c]=(BLUE Vline RESET);
                    }
                   checkBox(n,player,i);
             }

        }
                while(1){
                  srand(time(NULL));
                  r=rand()%11;
                  c=rand()%11;
                  if((r+c)%2==0){
                       goto place2;
                   }
                   else{
                      if(player[r][c]==' '){
                            if(r%2==0){
                                player[r][c]=BLUE Hline;
                            }
                            else{
                                player[r][c]= Vline;
                            }
                            checkBox(n,player,i);
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place2;
                      }
                   }
        }
         if(flag==0){
               i++;
         }
           remMoves--;
        if(remMoves==0){
        break;
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
            flag=0;
            printArray(y);
             if(i%2==0){
                printf(RED"\n\nPlayer 1 turn\n\n"RESET);
                printf (RED"remaining moves:"RESET);
                printf("%d\n",remMoves);
                printf(RED"player1 score="RESET);
                printf("%d\n",scoreplayer1);
                printf(RED"Enter number of row: "RESET);
                scanf(" %d",&r);
                printf(RED"\nEnter number of column: "RESET);
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(player[r][c]==' '){
                            if(r%2==0){
                                player[r][c]=(RED Hline RESET);
                            }
                            else{
                                player[r][c]=(RED Vline RESET);
                            }
                            checkBox(n,player,i);
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                   }
             }
             else{
                printf(BLUE"\n\n player 2 turn\n\n"RESET);
                printf (BLUE"remaining moves: %d \n\n", remMoves RESET);
                printf(BLUE"player2 score= "RESET);
                printf("%d\n",scoreplayer2);
                printf(BLUE"Enter number of row: " RESET);
                scanf(" %d",&r);
                printf(BLUE"\nEnter number of column: " RESET);
                scanf ("%d",&c);
                   if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(player[r][c]==' '){
                            if(r%2==0){
                               player[r][c]=(BLUE Hline RESET);
                            }
                            else{
                                player[r][c]=(BLUE Vline RESET);
                            }
                            checkBox(n,player,i);
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                   }

             }
           if(flag==0){
               i++;
           }
           remMoves--;
           if(remMoves==0){
        break;
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
            gamemode1(begOrEx);
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
