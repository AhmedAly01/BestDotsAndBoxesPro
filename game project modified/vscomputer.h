int flag,remMoves;
void gamemode1 (int y,int player[20][20],int n,char playername1){
player1.playerscore= 0;
player2.playerscore=0;
int i=0,r,c;
if (y==1) remMoves=12;
else remMoves=60;
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
                      if(player[r][c]==' '){
                            if(r%2==0){
                                player[r][c]=Hline;
                            }
                            else{
                                player[r][c]=vline;
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
         AI(player,n);
    }
     remMoves--;
     if(remMoves==0){
        break;
     }
     if(flag==0){
     i++;
     }
}
}
