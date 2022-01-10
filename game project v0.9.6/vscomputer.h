#define BRED "\e[1;31m"
#define BBLU "\e[1;34m"
#define reset "\e[0m"
#define REDB "\e[41m"
#define BLUB "\e[44m"

void gamemode1(int y,int n,int player[20][20],char playername1[], int newOrLoad);
void gamemode2(int y,int n,int player[20][20],char playername1[],char playername2[],int newOrLoad);
void makeArray(int n1, int playergrid[20][20]);
void printArray (int n2,int playergrid[20][20]);
void undo(int undo_history[60][3], int *counter, int player[20][20], int *remMoves, int n,int *x,int redo_history[60][3],int*redocounter);
void redo(int undo_history[60][3], int *counter, int player[20][20], int *remMoves, int n,int *x,int redo_history[60][3],int*redocounter);
void rankHandle (char playerName[], int playerScore);
void printRank();
void save (int board[20][20], int sizeofboard, int gamemode, int playerNum, int remMoves, time_t timeStart, time_t timeEnd, int player1score, int player2score, char player1name[], char player2name[], int filenum);
void load (int board[20][20], int *sizeofboard, int *gamemode, int *playerNum, int *remMoves, time_t *timeStart, time_t *timeEnd, int *player1score, int *player2score, char player1name[], char player2name[], int filenum);

void gamemode1(int y,int n,int player[20][20],char playername1[], int newOrLoad){
  int i=0, maxmoves=0, movesPlayed=0;
  int remMoves;
  int redocounter=0;
  int flag=0;
  int computerPlayed;
  int undo_history[60][3]={0};
  int redo_history[60][3]={0};
  makeArray(n,player);
  player1.playerscore= 0;
  player2.playerscore= 0;
  char playername2[]="computer";
  system("cls");
  int r,c;
  time_t start,end1;
  start=time(NULL);
  end1=start;
  if (y==1) remMoves=12;
  else remMoves=60;
  if (newOrLoad!=0) load(player,&n,&flag,&i,&remMoves,&start,&end1,&player1.playerscore,&player2.playerscore,playername1,playername2,newOrLoad);
  else {
    printf("ENTER PLAYER 1 NAME : ");
    scanf (" %[^\n]%*c", playername1);
  }
  place1:
  while(1){
        system("cls");
        printArray(n,player);
        flag=0;
        computerPlayed=0;
        if(i%2==0){
            printf (BRED"\n\nPlayer 1 turn\n\n"reset);
            printf (BRED"remaining moves: %d \n"reset, remMoves);
            printf ("player score = %d\t\tComputer score = %d\n\n", player1.playerscore, player2.playerscore);
            printf ("\t\tTime passed= %.2lf\n",difftime(end1,start));
            printf ("\nEnter (1,1) for undo\t(2,2) for redo\t(3,3) for save\n\n");
            printf(BRED"Enter number of row: "reset);
            scanf(" %d",&r);
            printf(BRED"Enter number of column: "reset);
            scanf (" %d",&c);
            if((r==1) && (c==1)){
                if (movesPlayed==0) { printf("\n\nNothig to undo!\n\n"); system("pause"); }
                else { undo(undo_history,&movesPlayed,player,&remMoves,n,&i,redo_history,&redocounter);
                undo(undo_history,&movesPlayed,player,&remMoves,n,&i,redo_history,&redocounter); }
                goto place1;
            }
            else if((r==2) && (c==2)){
                if ((maxmoves=i)) { printf("\n\nNothing to redo!\n\n"); system("pause"); }
                else redo(undo_history,&movesPlayed,player,&remMoves,n,&i,redo_history,&redocounter);
                goto place1;
            }
            else if ((r==3) && (c==3)) {
                system ("cls");
                printf ("Save files:\n\n1.save file 1\n2.save file 2\n3.save file 3\n\n");
                printf ("Enter save file number: ");
                int fileNum;
                scanf ("%d", &fileNum);
                save(player,n,1,i,remMoves,start,end1,player1.playerscore,player2.playerscore,playername1,"computer",fileNum);
                printf ("\nSuccessfully save to file %d\n", fileNum);
                system ("pause");
                goto place1;
            }
            else if((r+c)%2==0){
                printf("invalid move\n");
                system("pause");
                goto place1;
            }
            else if ((r>=n)||(c>=n)){
            printf("invalid move\n");
                system("pause");
                goto place1;
            }
            else{
                if(player[r][c]==0){
                    player[r][c]=1;
                    undo_history[movesPlayed][0]=r;
                    undo_history[movesPlayed][1]=c;
                }
                else{
                    printf("invalid move\n");
                    system("pause");
                    goto place1;
                }
            }
        }
             else{
                for (int j=1;j<=(n-2);j+=2) {
                    for (int k=1;k<=(n-2);k+=2) {
                        if (!computerPlayed) {
                            if ((player[j-1][k]==0)&&(player[j+1][k]!=0)&&(player[j][k-1]!=0)&&(player[j][k+1]!=0)&&(player[j][k]==0)) {
                                player[j-1][k]=2;
                                undo_history[movesPlayed][0]=j-1;
                                undo_history[movesPlayed][1]=k;
                                computerPlayed=1;
                            }
                            if ((player[j-1][k]!=0)&&(player[j+1][k]==0)&&(player[j][k-1]!=0)&&(player[j][k+1]!=0)&&(player[j][k]==0)) {
                                player[j+1][k]=2;
                                undo_history[movesPlayed][0]=j+1;
                                undo_history[movesPlayed][1]=k;
                                computerPlayed=1;
                            }
                            if ((player[j-1][k]!=0)&&(player[j+1][k]!=0)&&(player[j][k-1]==0)&&(player[j][k+1]!=0)&&(player[j][k]==0)) {
                                player[j][k-1]=2;
                                undo_history[movesPlayed][0]=j;
                                undo_history[movesPlayed][1]=k-1;
                                computerPlayed=1;
                            }
                            if ((player[j-1][k]!=0)&&(player[j+1][k]!=0)&&(player[j][k-1]!=0)&&(player[j][k+1]==0)&&(player[j][k]==0)) {
                                player[j][k+1]=2;
                                undo_history[movesPlayed][0]=j;
                                undo_history[movesPlayed][1]=k+1;
                                computerPlayed=1;
                            }
                        }
                    }
                }
                for (int j=1;j<=(n-2);j+=2) {
                    for (int k=1;k<=(n-2);k+=2) {
                        if (!computerPlayed) {
                            if ((player[j-1][k]==0)&&(player[j+1][k]==0)&&(player[j][k-1]==0)&&(player[j][k+1]!=0)&&(player[j][k]==0)) {
                                player[j-1][k]=2;
                                undo_history[movesPlayed][0]=j-1;
                                undo_history[movesPlayed][1]=k;
                                computerPlayed=1;
                            }
                            if ((player[j-1][k]==0)&&(player[j+1][k]==0)&&(player[j][k-1]!=0)&&(player[j][k+1]==0)&&(player[j][k]==0)) {
                                player[j-1][k]=2;
                                undo_history[movesPlayed][0]=j-1;
                                undo_history[movesPlayed][1]=k;
                                computerPlayed=1;
                            }
                            if ((player[j-1][k]==0)&&(player[j+1][k]!=0)&&(player[j][k-1]==0)&&(player[j][k+1]==0)&&(player[j][k]==0)) {
                                player[j-1][k]=2;
                                undo_history[movesPlayed][0]=j-1;
                                undo_history[movesPlayed][1]=k;
                                computerPlayed=1;
                            }
                            if ((player[j-1][k]!=0)&&(player[j+1][k]==0)&&(player[j][k-1]==0)&&(player[j][k+1]==0)&&(player[j][k]==0)) {
                                player[j][k+1]=2;
                                undo_history[movesPlayed][0]=j;
                                undo_history[movesPlayed][1]=k+1;
                                computerPlayed=1;
                            }
                        }
                    }
                }
                for (int j=1;j<=(n-2);j+=2) {
                    for (int k=1;k<=(n-2);k+=2) {
                        if (!computerPlayed) {
                            if ((player[j-1][k]==0)&&(player[j+1][k]==0)&&(player[j][k-1]==0)&&(player[j][k+1]==0)&&(player[j][k]==0)) {
                                player[j-1][k]=2;
                                undo_history[movesPlayed][0]=j-1;
                                undo_history[movesPlayed][1]=k;
                                computerPlayed=1;
                            }
                        }
                    }
                }
                for (int j=0; j<n; j++) {
                    for (int k=0; k<n; k++) {
                        if (!computerPlayed) {
                            if ((j+k)%2!=0) {
                                if ((j%2==0)||(k%2==0)) {
                                    if (player[j][k]==0) {
                                        player[j][k]=2;
                                        undo_history[movesPlayed][0]=j;
                                        undo_history[movesPlayed][1]=k;
                                        computerPlayed=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        for (int j=1;j<=(n-2);j+=2) {
         for (int k=1;k<=(n-2);k+=2) {
            if ((player[j-1][k]!=0)&&(player[j+1][k]!=0)&&(player[j][k-1]!=0)&&(player[j][k+1]!=0)&&(player[j][k]==0)) {
                if (i%2==0){
                   player[j][k]=3;
                   player1.playerscore++;
                   flag=1;
                }
                else{
                     player[j][k]=4;
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
           redocounter=0;
           maxmoves=i;
           remMoves--;
           movesPlayed++;
           if(remMoves==0){
                system("cls");
                printArray(n,player);
                if (player1.playerscore>player2.playerscore) {
                    printf (BRED"\n\nPlayer wins!!\n\n"reset);
                    rankHandle(playername1,player1.playerscore);
                }
                else if (player1.playerscore<player2.playerscore) {
                    printf (BBLU"\n\nComputer wins!!\n\n"reset);
                }
                else {
                    printf ("\n\nDraw!\n\n");
                }
                printf ("\nPress any key to go to main menu\n");
                system ("pause");
                main();
           }
      }
}
