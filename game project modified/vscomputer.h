int i=0,flag=0;
void gamemode1 (int y,char player[20][20],int n){
player1.playerscore= 0;
player2.playerscore=0;
int i=0,r,c,remMoves;
if (y==1) remMoves=12;

else remMoves=60;
createArray(y,player,n);
  while(1){
    place1:
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
                      goto place1;
                  }
                  else if((player[r-1][c]!=' ')&&(player[r+1][c]!=' ')&&(player[r][c+1]==' ')&&(player[r][c-1]!=' ')){
                       player[r][c-1]= Vline;
                       player2.playerscore++;
                       goto place1;
                  }
                  else if((player[r-1][c]!=' ')&&(player[r+1][c]==' ')&&(player[r][c+1]!=' ')&&(player[r][c-1]!=' ')){
                         player[r+1][c]= Hline;
                         player2.playerscore++;
                         goto place1;
                  }
                  else if((player[r-1][c]==' ')&&(player[r+1][c]!=' ')&&(player[r][c+1]!=' ')&&(player[r][c-1]!=' ')){
                      player[r-1][c]= Hline;
                      player2.playerscore++;
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
                    }
                    else{
                        player[r][c]=Vline;
                    }
                }

            }
        }
    }
     remMoves--;
     if(remMoves==0){
        break;
     }
     i++;
}
}
