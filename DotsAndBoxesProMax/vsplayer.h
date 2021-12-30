#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define reset "\e[0m"
#define REDB "\e[41m"
#define BLUB "\e[44m"
typedef struct playerinfo {
  char playername[100];
  int playerscore;
};
struct playerinfo player1;
struct playerinfo player2;

void gamemode2(int y,int player[20][20],char playername1[],char playername2[], int newOrLoad){
    int i=0;
    int counter;
    int remMoves=0;
    int flag;
    int n=6*y-1;
    int history[60][5];
    time_t start,end1=0;
    int r,c;
    player1.playerscore= 0;
    player2.playerscore= 0;
    system("cls");
    i=0;
    if (y==1) remMoves=12;
    else remMoves=60;
    createArray(y,player);
    start=time(NULL);
    end1=start;

    if (newOrLoad==2) load(player,n,i,remMoves,end1,player1.playerscore,player2.playerscore,player1.playername,player2.playername,1);
    else {
        printf("ENTER PLAYER 1 NAME : ");
        scanf ("%s", player1.playername);
        printf("\n\n\nENTER PLAYER 2 NAME : ");
        scanf ("%s", player2.playername);
    }
    place1:
    while(1){
        system("cls");
            printArray(player,n);
            flag=0;
             if(i%2==0){
                printf(BRED"\n\nPlayer 1 turn\n\n"reset);
                printf (BRED"remaining moves: %d "reset, remMoves);
                printf("player score = %d",player1.playerscore);
                printf ("\t\t\t time passed= %.2lf\n\n\n",difftime(end1,start));
                printf(BRED"Enter number of row: "reset);
                scanf(" %d",&r);
                printf(BRED"Enter number of column: "reset);
                scanf (" %d",&c);
                if (r==3 && c==3) {
                        save(player,n,2,i,remMoves,end1,player1.playerscore,player2.playerscore,player1.playername,player2.playername,1);
                        printf("Saved to file 1\n");
                        system ("pause");
                        goto place1;
                }
                if(r==1&&c==1){
                    goto place1;
                }
                else if(r==2 && c==2){
                    goto place1;
                }
                else if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                }
                else{
                      if(player[r][c]==0){
                                player[r][c]=1;

                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }
                    }
                }

             else{
                 printf(BBLU"\n\nPlayer 2 turn\n\n"reset);
                printf (BBLU"remaining moves: %d "reset, remMoves);
                printf("\nplayer score = %d",player2.playerscore);
                printf ("\t\t\t time passed= %.2lf\n\n\n",difftime(end1,start));
                printf(BBLU"Enter number of row: "reset);
                scanf(" %d",&r);
                printf(BBLU"Enter number of column: "reset);
                scanf (" %d",&c);
                   if(r==1&&c==1){
                    goto place1;
                   }
                   else if(r==2 && c==2){
                    goto place1;
                   }
                  else if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(player[r][c]==0){
                            if(r%2==0){
                                player[r][c]=2;
                            }
                            else{
                                player[r][c]=2;
                            }

                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                 }
             }
        for (int i=1;i<=(n-2);i+=2) {
         for (int j=1;j<=(n-2);j+=2) {
            if ((player[i-1][j]!=0)&&(player[i+1][j]!=0)&&(player[i][j-1]!=0)&&(player[i][j+1]!=0)&&(player[i][j]==0)) {
                if (i%2==0){
                   player[i][j]=3;
                   player1.playerscore++;
                   flag=1;
                }
                else{
                     player[i][j]=4;
                     player2.playerscore++;
                     flag=1;
                }
            }
         }
       }
          printArray(player,n);
          end1=time(NULL);
          if(flag==0){
           i++;
           }

           remMoves--;
           if(remMoves==0){
            break;
           }
  counter++;
      }
}
