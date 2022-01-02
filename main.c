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

int main(void){
 typedef struct playerinfo {
  char playername[100];
  int playerscore;
};
int x1=0,y=0,z=0;

int n=0;
struct playerinfo player1,player2;
mainMenu:
 while(1){
   system("cls");
   printf("\t\t\t\t\t\t\tDOTS AND BOXES\n\n\n\n");
   printf("\t\t 1.NEW GAME\n\n\n");
   printf("\t\t 2.LOAD GAME \n\n\n");
   printf("\t\t 3.LEADERBOARD\n\n\n");
   printf("\t\t 4.EXIT\n\n\n\n\n");
   printf("\t\t.ENTER THE NUMBER(1 OR 2 OR 3 OR 4):");
   scanf("%d",&x1);
   if(x1==1){
    goto j1;
    break;
   }
   else if(x1==2){
     goto j2;
    break;
   }
   else if(x1==3){
    goto j3;
    break;
   }
   else if(x1==4){
    return 0;
   }
   else{
    printf("INVALID NUMBER\n");
    printf("ENTER THE RIGHT NUMBER");
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
    printf("ENTER THE RIGHT NUMBER");
    system("pause");
    }
 }
 while(1){
   system("cls");
    printf("\t\t 1. VS A HUMAN\n\n\n");
    printf("\t\t 2. VS A COMPUTER\n\n\n\n\n");
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
    printf("ENTER THE RIGHT NUMBER");
    system("pause");
    }
 }
 if(z==1){

 }
 else{

 }
n=6*y-1;
int playergame[20][20];
 if(z==1){
     gamemode2(y,n,playergame,player1.playername,player2.playername);

    }
    else {
        gamemode1(y,n,playergame,player1.playername);
    }
goto mainMenu;

j2:

j3:
while(1) {
    system ("cls");
    printRank();
    int inputRank;
    printf ("\n\n1.Main menu\n2.Exit\n\n");
    printf ("Enter a number: ");
    scanf ("%d", &inputRank);
    if (inputRank==1) goto mainMenu;
    else return 0;
    }

    return 0;
}

