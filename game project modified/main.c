#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include<windows.h>
#include "vsplayer.h"
#include "vscomputer.h"
#include "GameGrid.h"
#include "checkbox.h"
#include "PlayerInfo.h"
#include"bot.h"
int main(){
    struct playerinfo {
  char playername[100];
  int playerscore;
};
int x,y,z;
int playergame[20][20];
int n=0;
struct playerinfo player1,player2;

 while(1){
   system("cls");
   printf("\t\t\t\t\t\t\tDOTS AND BOXES\n\n\n\n");
   printf("\t\t 1.NEW GAME\n\n\n");
   printf("\t\t 2.LOAD GAME \n\n\n");
   printf("\t\t 3.LEADERBOARD\n\n\n");
   printf("\t\t 4.EXIT\n\n\n\n\n");
   printf("\t\t.ENTER THE NUMBER(1 OR 2 OR 3 OR 4):");
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
    printf("\t\t 1.VS A HUMAN\n\n\n");
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
 createArray(y,playergame);
 if(z==1){
   system("cls");
    printf("ENTER playergame 1 NAME : ");
    scanf("%s",&player1.playername);
    printf("\n\n\nENTER PLAYER 2 NAME : ");
    scanf("%s",&player2.playername);
 }
 else{
        system("cls");
    printf("ENTER PLAYER 1 NAME :");
    scanf("%s",player1.playername);
 }

 if(z==1){
     gamemode2(y,playergame,n,player1.playername,player2.playername);

    }
    else {
        gamemode1(y,playergame,n,player1.playername);
    }
j2:
j3:
    return 0;
}
