#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dot 254
#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define Hline 205
#define vline 186
#define REDB "\e[41m"
#define BLUB "\e[44m"
#define reset "\e[0m"

void gamemode1(int y,int n,int player[20][20],char playername1[], int newOrLoad);
void gamemode2(int y,int n,int player[20][20],char playername1[],char playername2[],int newOrLoad);
void makeArray(int n1, int playergrid[20][20]);
void printArray (int n2,int playergrid[20][20]);
void undo(int history[60][3],int *counter ,int player [20][20],int n);
void redo(int history[60][3],int *counter ,int player [20][20],int n);
void rankHandle (char playerName[], int playerScore);
void printRank();
void save (int board[20][20], int sizeofboard, int gamemode, int playerNum, int remMoves, time_t timeStart, time_t timeEnd, int player1score, int player2score, char player1name[], char player2name[], int filenum);
void load (int board[20][20], int *sizeofboard, int *gamemode, int *playerNum, int *remMoves, time_t *timeStart, time_t *timeEnd, int *player1score, int *player2score, char player1name[], char player2name[], int filenum);

void makeArray(int n1, int playergrid[20][20]){
    for (int i=0; i<n1; i++){
        for (int j=0; j<n1; j++){
            playergrid[i][j] = 0;
        }
    }

    for (int i=0; i<n1; i++){
        for (int j=0; j<n1; j++){
            if ((i%2==0)&&(j%2==0)){
                playergrid[i][j] = -1;
            }
        }
    }
}

//printing the boards
 void printArray (int n2,int playergrid[20][20]) {
        printf("\n\n");
        printf("   ");
        for (int i=0; i<n2; i++) {
            printf ("%d ",i);
        }
        printf ("\n");
        for (int i=0; i<n2; i++) {
                if (i<10) printf(" %d ", i);
                else printf(" %d", i);
            for (int j=0; j<n2; j++) {
              if(i%2==0){
               if(playergrid[i][j]==0){
                printf("   ");
               }
               else if(playergrid[i][j]==-1){
                 printf("%c",dot);
               }
               else if(playergrid[i][j]==1){
                  printf(BRED"%c%c%c",Hline,Hline,Hline);
                  printf(""reset);
               }
               else if(playergrid[i][j]==2){
                printf(BBLU"%c%c%c",Hline,Hline,Hline);
                printf(""reset);
               }
              }
              else{
                if(playergrid[i][j]==0){
                   if (j%2==0) printf(" ");
                   else printf("   ");
               }
               if(playergrid[i][j]==-1){
                  printf("%c",dot);
               }
               if(playergrid[i][j]==1){
                  printf(BRED"%c",vline);
                  printf(""reset);
               }
               if(playergrid[i][j]==2){
                printf(BBLU"%c",vline);
                printf(""reset);
               }
              }
              if(playergrid[i][j]==3){
                printf(REDB"   ");
                printf(""reset);
              }
              if(playergrid[i][j]==4){
                printf(BLUB"   ");
                printf(""reset);
              }

            }
         printf("\n");
        }
    }
