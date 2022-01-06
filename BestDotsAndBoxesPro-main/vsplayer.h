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
 int i;
 int remMoves2;
void gamemode2(int y,int n,int player[20][20],char playername1,char playername2){
  int flag;
  int history[60][3];
  for(int l=0;l<60;l++){
    for(int m=0;l<3;m++){
      history[l][m]=0;
    }
}
  makeArray(n,player);
  player1.playerscore= 0;
  player2.playerscore= 0;
  system("cls");
  printf("ENTER playergame 1 NAME : ");
  scanf("%s",&playername1);
  printf("\n\n\nENTER PLAYER 2 NAME : ");
  scanf("%s",&playername2);
  int r,c;
  i=0;
  time_t start,end1;
  if (y==1) remMoves2=12;
  else remMoves2=60;
  start=time(NULL);
  end1=start;
  place1:
  printArray(n,player);
  startOfGame:
  while(1){
        system("cls");
            printArray(n,player);
            flag=0;
             if(i%2==0){
                printf (BRED"\n\nPlayer 1 turn\n\n"reset);
                printf (BRED"remaining moves: %d \n"reset, remMoves2);
                printf ("player score = %d",player1.playerscore);
                printf ("\t\t\t time passed= %.2lf\n",difftime(end1,start));
                printf ("\nEnter(3,3) to save\n\n");
                printf(BRED"Enter number of row: "reset);
                scanf(" %d",&r);
                printf(BRED"Enter number of column: "reset);
                scanf (" %d",&c);
                if (r==3 && c==3) {
                    system ("cls");
                    printf ("Save files:\n\n1.save file 1.\n2.save file 2.\n3.save file 3.\n\n");
                    printf ("Enter save file number: ");
                    int fileNum;
                    scanf ("%d", &fileNum);
                    save(player,n,2,i,remMoves2,start,end1,player1.playerscore,player2.playerscore,playername1,playername2,fileNum);
                    printf ("\nSuccessfully save to file %d\n", fileNum);
                    system ("pause");
                    goto startOfGame;
                }
                if(r==1&&c==1){
                    undo(history,i,player,remMoves2,n);
                    goto place1;
                }
                else if(r==2 && c==2){
                    redo(history,i,player,remMoves2,n);
                    goto place1;
                }
                else if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                }
                else if (r>=n&&c>=n){
                    printf("invalid move\n");
                      system("pause");
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
                 printf(BBLU"\n\nPlayer 2 turn\n\n"reset);
                printf (BBLU"remaining moves: %d "reset, remMoves2);
                printf("\nplayer score = %d",player2.playerscore);
                printf ("\t\t\t time passed= %.2lf\n\n\n",difftime(end1,start));
                printf ("\nEnter(3,3) to save\n");
                printf(BBLU"Enter number of row: "reset);
                scanf(" %d",&r);
                printf(BBLU"Enter number of column: "reset);
                scanf (" %d",&c);
                if (r==3 && c==3) {
                    system ("cls");
                    printf ("Save files:\n\n1.save file 1.\n2.save file 2.\n3.save file 3.\n\n");
                    printf ("Enter save file number: ");
                    int fileNum;
                    scanf ("%d", &fileNum);
                    save(player,n,2,i,remMoves2,start,end1,player1.playerscore,player2.playerscore,playername1,playername2,fileNum);
                    printf ("\nSuccessfully save to file %d\n", fileNum);
                    system ("pause");
                    goto startOfGame;
                }
                   if(r==1&&c==1){
                     undo(history,i,player,remMoves2,n);
                    goto place1;
                   }
                   else if(r==2 && c==2){
                     redo(history,i,player,remMoves2,n);
                    goto place1;
                   }
                  else if((r+c)%2==0){
                      printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else if (r>=n&&c>=n){
                    printf("invalid move\n");
                      system("pause");
                      goto place1;
                   }
                   else{
                      if(player[r][c]==0){
                            player[r][c]=2;
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
           printArray(n, player);
           end1=time(NULL);
           if(flag==0){
            i++;
           }

           remMoves2--;
           if(remMoves2==0){
                if (player1.playerscore>player2.playerscore) {
                    printf ("\n\nPlayer 1 wins!!\n");
                    rankHandle(playername1,player1.playerscore);
                }
                else {
                    printf ("\n\nPlayer 2 wins!!\n");
                    rankHandle(playername2,player2.playerscore);
                }
                printf ("\n\nPress any key to go to main menu\n");
                system ("pause");
            break;
           }
      }
}
