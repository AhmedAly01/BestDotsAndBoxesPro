#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define Hline 205
#define vline 186
#define reset "\e[0m"
typedef struct playerinfo {
  char playername[100];
  int playerscore;
};
struct playerinfo player1;
struct playerinfo player2;
extern int flag;
int history[60][5];
int i=0;
int remMoves;
void gamemode2(int y,int player[20][20],int n,char playername1,char playername2){
  player1.playerscore= 0;
  player2.playerscore= 0;
  int r,c;
  i=0;
  if (y==1) remMoves=12;
  else remMoves=60;
  createArray(y,player,n);
  place1:
  while(1){
        system("cls");
            printArray(player,n);
            flag=0;
             if(i%2==0){

                printf(BRED"\n\nPlayer 1 turn\n\n"reset);
                printf (BRED"remaining moves: %d \n\n"reset, remMoves);
                printf(BRED"Enter number of row: "reset);
                scanf(" %d",&r);
                printf(BRED"Enter number of column: "reset);
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
                                player[r][c]=1;
                            }
                            else{
                                player[r][c]=1;
                            }
                            checkBox(n,player,i,player1.playerscore,player2.playerscore,flag);
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
                printf (BBLU"remaining moves: %d \n\n"reset, remMoves);
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
                            checkBox(n,player,i,player1.playerscore,player2.playerscore,flag);
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
