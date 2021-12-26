#define dot 254
#define Hline 205
#define Vline 186
typedef struct playerinfo {
  char playername[100];
  int playerscore;
};
struct playerinfo player1;
struct playerinfo player2;
void gamemode2(int y,char player[20][20],int n){
  player1.playerscore= 0;
  player2.playerscore= 0;
  int i=0,r,c,remMoves;
  if (y==1) remMoves=12;
  else remMoves=60;
  createArray(y,player,n);
  place1:
  while(1){
        system("cls");
            printArray(player,n);
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
                      if(player[r][c]==' '){
                            if(r%2==0){
                                player[r][c]=Hline;
                            }
                            else{
                                player[r][c]=Vline;
                            }
                            checkBox(n,player,i,player1.playerscore,player2.playerscore);
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
                      if(player[r][c]==' '){
                            if(r%2==0){
                               player[r][c]=Hline;
                            }
                            else{
                                player[r][c]=Vline;
                            }
                            checkBox(n,player,i,player1.playerscore,player2.playerscore);
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
           if(remMoves==0){
            break;
           }
       }

}
