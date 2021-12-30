#define REDB "\e[41m"
#define BLUB "\e[44m"
 int flag;
void gamemode1 (int y,int player[20][20],int n,char playername1){
player1.playerscore= 0;
player2.playerscore=0;
int i=0,r,c;
int counter=0;
int remMoves=0;
if (y==1) remMoves=12;
else remMoves=60;
flag=0;
system("cls");
printf("ENTER PLAYER 1 NAME :");
scanf("%s",&playername1);
createArray(y,player,n);
  while(1){
    place1:
    system("cls");
    printArray(player,n);
     flag=0;
     if(i%2==0){
        printf("\n\nPlayer 1 turn\n\n");
        printf("player score = %d",player1.playerscore);
        printf("\t\t\t\t\t\t computer score = %d\n\n\n",player2.playerscore);
                printf ("remaining moves: %d \n\n", remMoves);
                printf("Enter number of row: ");
                scanf(" %d",&r);
                printf("Enter number of column: ");
                scanf ("%d",&c);
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
                      }
                      else{
                        printf("invalid move\n");
                        system("pause");
                        goto place1;
                      }

                 }
     }
    else{
         AI(player,n,flag);
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
                     flag=1;
                     player2.playerscore++;
                }

            }
        }
    }
     remMoves--;
     if(remMoves==0){
        break;
     }
     if(flag==0){
     i++;
     }
   counter++;
}
}
