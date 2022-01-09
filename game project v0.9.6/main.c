#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "vsplayer.h"
#include "vscomputer.h"
#include "UndoAndRedo.h"
#include "GameGrid.h"
#include "rank.h"
#include "SaveAndLoad.h"

void gamemode1(int y,int n,int player[20][20],char playername1[], int newOrLoad);
void gamemode2(int y,int n,int player[20][20],char playername1[],char playername2[],int newOrLoad);
void makeArray(int n1, int playergrid[20][20]);
void printArray (int n2,int playergrid[20][20]);
void rankHandle (char playerName[], int playerScore);
void printRank();
void save (int board[20][20], int sizeofboard, int gamemode, int playerNum, int remMoves, time_t timeStart, time_t timeEnd, int player1score, int player2score, char player1name[], char player2name[], int filenum);
void load (int board[20][20], int *sizeofboard, int *gamemode, int *playerNum, int *remMoves, time_t *timeStart, time_t *timeEnd, int *player1score, int *player2score, char player1name[], char player2name[], int filenum);

int main(void){
 typedef struct playerinfo {
  char playername[100];
  int playerscore;
};
struct playerinfo player1,player2;
int x=0,y=0,z=0;
int playergame[20][20];
int n=0;
mainMenu:
 while(1){
   system("cls");
   printf("\n\t\t\t\t\t\t   Welcome to DOTS AND BOXES\n");
   printf("\t\t\t\t\t\t\t   Made by\n");
   printf("\t\t\t\t\t    Ahmed Mohamed Aly & Youssef Emad Mohamed\n\n\n\n\n");
   printf("\t\t 1.NEW GAME\n\n\n");
   printf("\t\t 2.LOAD GAME \n\n\n");
   printf("\t\t 3.LEADERBOARD\n\n\n");
   printf("\t\t 4.EXIT\n\n\n\n\n");
   printf("\t\tENTER THE NUMBER(1 OR 2 OR 3 OR 4):");
   scanf("%d",&x);
   if(x==1){
    goto j1;
    break;
   }
   else if(x==2){
    goto j2;
    break;
   }
   else if(x==3){
    goto j3;
    break;
   }
   else if(x==4){
    return 0;
   }
   else{
    printf("INVALID NUMBER\n");
    printf("ENTER THE RIGHT NUMBER\n");
    system("pause");
   }
 }
 j1:
 while(1){
    system("cls");
    printf("\t\t 1.BEGINNER\n\n\n");
    printf("\t\t 2.EXPERT\n\n\n\n\n");
    printf("\t\t ENTER THE NUMBER(1 OR 2):");
    scanf("%d",&y);
    if(y==1){
       break;
    }
    else if(y==2){
        break;
    }
    else{
    printf("INVALID NUMBER\n");
    printf("ENTER THE RIGHT NUMBER\n");
    system("pause");
    }
 }
while(1){
   system("cls");
    printf("\t\t 1. VS COMPUTER\n\n\n");
    printf("\t\t 2. VS PLAYER\n\n\n\n\n");
    printf("\t\t ENTER THE NUMBER(1 OR 2):");
    scanf("%d",&z);
    if(z==1){
       break;
    }
    else if(z==2){
        break;
    }
    else{
    printf("INVALID NUMBER\n");
    printf("ENTER THE RIGHT NUMBER\n");
    system("pause");
    }
}
n=6*y-1;
if(z==1){
    gamemode1(y,n,playergame,player1.playername,0);

}
else {
    gamemode2(y,n,playergame,player1.playername,player2.playername,0);
}

j2:
while (1) {
    system ("cls");
    printf ("SAVED FILES:\n\n1.save file 1\n2.save file 2\n3.save file 3\n\n");
    printf ("Enter save file number: ");
    int inputLoad, gamemode;
    scanf (" %d", &inputLoad);
    FILE *fp;
    if (inputLoad==1) {
        fp=fopen("1.bin", "rb");
    }
    else if (inputLoad==2) {
        fp=fopen("2.bin", "rb");
    }
    else if (inputLoad==3) {
        fp=fopen("3.bin", "rb");
    }
    fscanf (fp, "%d %d\n", &gamemode, &n);
    fclose(fp);
    if (gamemode==1) gamemode1(y,n,playergame,player1.playername,inputLoad);
    else if (gamemode==2) gamemode2(y,n,playergame,player1.playername,player2.playername,inputLoad);
    else { printf("\nUnexpected Error opening the file :(\n"); goto j2; }
}

j3:
while(1) {
    system ("cls");
    printRank();
    int inputRank;
    printf ("\n\n1.Main menu\n2.Exit\n\n");
    printf ("Enter a number (1 or 2): ");
    scanf ("%d", &inputRank);
    if (inputRank==1) goto mainMenu;
    else if (inputRank==2) return 0;
    else { printf("\nInvalid number\nEnter a correct number\n"); goto j3; }
    }

    return 0;
}

