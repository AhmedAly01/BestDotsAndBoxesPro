int flag,remMoves;
void gamemode1 (int y,char player[20][20],int n,char playername1){
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
        for(int i=0 ;i<n;i++){
          for(int j=0;j<n;j++){
             if((r+c)%2==0){
               if(player[r][c]==' '){
                  if((player[r-1][c]!=' ')&&(player[r+1][c]!=' ')&&(player[r][c+1]!=' ')&&(player[r][c-1]==' ')){
                      player[r][c-1]= Vline;
                      player2.playerscore++;
                       history[i][0]=i;
                        history[i][1]=r;
                        history[i][2]=c;
                        history[i][3]=player1.playerscore;
                        history[i][4]=player2.playerscore;
                        history[i][5]=remMoves;
                      goto place1;
                  }
                  else if((player[r-1][c]!=' ')&&(player[r+1][c]!=' ')&&(player[r][c+1]==' ')&&(player[r][c-1]!=' ')){
                       player[r][c-1]= Vline;
                       player2.playerscore++;
                        history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
                       goto place1;
                  }
                  else if((player[r-1][c]!=' ')&&(player[r+1][c]==' ')&&(player[r][c+1]!=' ')&&(player[r][c-1]!=' ')){
                         player[r+1][c]= Hline;
                         player2.playerscore++;
                          history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
                         goto place1;
                  }
                  else if((player[r-1][c]==' ')&&(player[r+1][c]!=' ')&&(player[r][c+1]!=' ')&&(player[r][c-1]!=' ')){
                      player[r-1][c]= Hline;
                      player2.playerscore++;
                       history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
                      goto place1;
                  }

                  else{
                    goto place2;
                  }
               }
             }
          }
        }
        place2:
        while(1){
            srand(time(NULL));
            r=rand()%11;
            c=rand()%11;
            if((r+c)%2==0){
            }
            else{
                if(player[r][c]==' '){
                    if(r%2==0){
                        player[r][c]=Hline;
                         history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
                            break;
                    }
                    else{
                        player[r][c]=Vline;
                         history[i][0]=i;
                            history[i][1]=r;
                            history[i][2]=c;
                            history[i][3]=player1.playerscore;
                            history[i][4]=player2.playerscore;
                            history[i][5]=remMoves;
                            break;
                    }
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
}
}
