#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define reset "\e[0m"
#define REDB "\e[41m"
#define BLUB "\e[44m"

void gamemode1 (int y,int n,int player[n][n],char playername1[]){
    int history[60][3];
    player1.playerscore= 0;
    player2.playerscore=0;
    int i=0,r,c;
    time_t start,end1;
    start=time(NULL);
    end1=start;
    int remMoves=0;
    if (y==1) remMoves=12;
    else remMoves=60;
    int flag=0;
    system("cls");
    printf("ENTER PLAYER 1 NAME :");
    scanf (" %[^\n]%*c", playername1);
    makeArray(n,player);
    while(1){
        place1:
        system("cls");
        printArray(n,player);
        flag=0;
        if(i%2==0){
            printf (BRED"\n\nPlayer turn\n\n"reset);
            printf (BRED"remaining moves: %d \n"reset, remMoves);
            printf ("player score= %d \tComputer score=%d\n", player1.playerscore, player2.playerscore);
            printf ("\t\t\t time passed= %.2lf\n",difftime(end1,start));
            printf ("\nEnter (1,1) for undo\t(2,2) for redo\t(3,3) for save\n\n");
            printf(BRED"Enter number of row: "reset);
            scanf(" %d",&r);
            printf(BRED"Enter number of column: "reset);
            scanf (" %d",&c);
            if(r==1&&c==1){
                undo(history,&i,player,n);
                undo(history,&i,player,n);
                goto place1;
            }
            else if(r==2 && c==2){
                redo(history,&i,player,n);
                redo(history,&i,player,n);
                goto place1;
            }
            else if((r+c)%2==0){
                printf("invalid move\n");
                system("pause");
                goto place1;
            }
            else if (r==3 && c==3) {
                system ("cls");
                printf ("Save files:\n\n1.save file 1.\n2.save file 2.\n3.save file 3.\n\n");
                printf ("Enter save file number: ");
                int fileNum;
                scanf ("%d", &fileNum);
                save(player,n,1,i,remMoves,start,end1,player1.playerscore,player2.playerscore,playername1,"computer",fileNum);
                printf ("\nSuccessfully save to file %d\n", fileNum);
                system ("pause");
                goto place1;
            }
            else{
                if(player[r][c]==0){
                player[r][c]=1;
                history[i][0]=i;
                history[i][1]=r;
                history[i][2]=c;
                }
                else{
                    printf("invalid move\n");
                    system("pause");
                    goto place1;
                }
            }
     }
    else{
        int r=0,c=0;
        for(int k=0 ;k<n;k++){
          for(int j=0;j<n;j++){
             if((k+j)%2==0){
               if(player[k][j]==0){
                  if((player[k-1][j]!=0)&&(player[k+1][j]!=0)&&(player[k][j+1]!=0)&&(player[k][j-1]==0)){
                      player[k][j-1]= 2;
                      history[i][0]=i;
                      history[i][1]=r;
                      history[i][2]=c;
                      goto place2;
                  }
                  else if((player[k-1][j]!=0)&&(player[k+1][j]!=0)&&(player[k][j+1]==0)&&(player[k][j-1]!=0)){
                       player[k][j-1]= 2;
                       history[i][0]=i;
                       history[i][1]=r;
                       history[i][2]=c;
                       goto place2;
                  }
                  else if((player[k-1][j]!=0)&&(player[k+1][j]==0)&&(player[k][j+1]!=0)&&(player[k][j-1]!=0)){
                         player[k+1][j]= 2;
                         history[i][0]=i;
                         history[i][1]=r;
                         history[i][2]=c;
                         goto place2;
                  }
                  else if((player[k-1][j]==0)&&(player[k+1][j]!=0)&&(player[k][j+1]!=0)&&(player[k][j-1]!=0)){
                      player[k-1][j]= 2;
                      history[i][0]=i;
                      history[i][1]=r;
                      history[i][2]=c;
                      goto place2;
                  }
                  else{
                  }
               }
             }
          }
        }
        while(1){
            srand(time(NULL));
            r=rand()%n;
            c=rand()%n;
            if((r+c)%2!=0){
                if(player[r][c]==0){
                       player[r][c]=2;
                       history[i][0]=i;
                       history[i][1]=r;
                       history[i][2]=c;
                       break;
            }
            else{
            }

        }
    }
    place2:
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
     if(flag==0){
       i++;
     }
     remMoves--;
     if(remMoves==0){
        system("cls");
        printArray(n,player);
        if (player1.playerscore>player2.playerscore) {
            printf (BRED"\n\nPlayer 1 wins!!\n"reset);
            rankHandle(playername1,player1.playerscore);
        }
        else {
            printf (BBLU"\n\nComputer wins!!\n"reset);
        }
        printf ("\n\nPress any key to go to main menu\n");
        system ("pause");
        break;
    }
}
}
}
