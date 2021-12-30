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
int n=0;
void createArray (int x,int player[20][20]) {
        n = 6*x-1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++){
             player[i][j]=0;
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if ((i%2==0)&&(j%2==0)) {
                    player[i][j]=-1;
                }
            }
        }
}

//printing the boards
 void printArray (int player[20][20],int x) {
        printf("\n\n");
        printf("   ");
        for (int i=0; i<n; i++) {
            printf ("%d ",i);
        }
        printf ("\n");
        for (int i=0; i<n; i++) {
                printf(" %d ",i);
            for (int j=0; j<n; j++) {
              if(i%2==0){
               if(player[i][j]==0){
                printf("   ");
               }
               else if(player[i][j]==-1){
                 printf("%c",dot);
               }
               else if(player[i][j]==1){
                  printf(BRED"%c%c%c",Hline,Hline,Hline);
                  printf(""reset);
               }
               else if(player[i][j]==2){
                printf(BBLU"%c%c%c",Hline,Hline,Hline);
                printf(""reset);
               }
              }
              else{
                if(player[i][j]==0){
                printf("   ");
               }
               if(player[i][j]==-1){
                 printf("%c",dot);
               }
               if(player[i][j]==1){
                  printf(BRED"%c",vline);
                  printf(""reset);
               }
               if(player[i][j]==2){
                printf(BBLU"%c",vline);
                printf(""reset);
               }
              }
              if(player[i][j]==3){
                printf(REDB"   ");
                printf(""reset);
              }
              if(player[i][j]==4){
                printf(BLUB"   ");
                printf(""reset);
              }

            }
         printf("\n");
        }
    }

