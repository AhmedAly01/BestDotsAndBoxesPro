#define dot 254
#define Hline 205
#define Vline 186
typedef struct playerinfo {
  char playername[100];
  int playerscore;
};
struct playerinfo player1;
struct playerinfo player2;
int flag;
void Undo (int arr[60][6],int i,char player[20][20],int playerscore1,int playerscore2,int remMoves){
 i--;
 for(int k=0;k<=i;k++){
        if(arr[k][1]%2==0){
        player[arr[k][1]][arr[k][2]]=Hline;
        }
        else{
          player[arr[k][1]][arr[k][2]]=Vline;
        }
        playerscore1=arr[k][3];
        playerscore2=arr[k][4];
        remMoves=arr[k][5];
 }


}
void Redo(int arr[60][5],int i,char player[20][20],int playerscore1,int playerscore2,int remMoves){
  i++;
   for(int k=0;k<=i;k++){
        if(arr[k][1]%2==0){
        player[arr[k][1]][arr[k][2]]=Hline;
        }
        else{
          player[arr[k][1]][arr[k][2]]=Vline;
        }
        playerscore1=arr[k][3];
        playerscore2=arr[k][4];
        remMoves=arr[k][5];
 }
 }

int history[60][5];
int i=0;
int remMoves;
void gamemode2(int y,char player[20][20],int n,char playername1,char playername2){
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
                printf("\n\nPlayer 1 turn\n\n");
                printf ("remaining moves: %d \n\n", remMoves);
                printf("Enter number of row: ");
                scanf(" %d",&r);
                printf("\nEnter number of column: ");
                scanf ("%d",&c);
                 if(r==1&&c==1){
                    Undo(history, i,player ,player1.playerscore,player2.playerscore,remMoves);
                    goto place1;
                   }
                   else if(r==2 && c==2){
                    Redo(history, i,player ,player1.playerscore,player2.playerscore,remMoves);
                    goto place1;
                   }
                  else if((r+c)%2==0){
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
                            checkBox(n,player,i,player1.playerscore,player2.playerscore,flag);
                            history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
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
                   if(r==1&&c==1){
                    Undo(history, i,player ,player1.playerscore,player2.playerscore,remMoves);
                    goto place1;
                   }
                   else if(r==2 && c==2){
                    Redo(history, i,player ,player1.playerscore,player2.playerscore,remMoves);
                    goto place1;
                   }
                  else if((r+c)%2==0){
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
                            checkBox(n,player,i,player1.playerscore,player2.playerscore,flag);
                            history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
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
