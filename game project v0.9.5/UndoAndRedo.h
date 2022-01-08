
void gamemode1(int y,int n,int player[20][20],char playername1[], int newOrLoad);
void gamemode2(int y,int n,int player[20][20],char playername1[],char playername2[],int newOrLoad);
void makeArray(int n1, int playergrid[20][20]);
void printArray (int n2,int playergrid[20][20]);
void undo(int history[60][3],int *counter ,int player [20][20],int n);
void redo(int history[60][3],int *counter ,int player [20][20],int n);
void rankHandle (char playerName[], int playerScore);
void printRank();
void save (int board[20][20], int sizeofboard, int gamemode, int playerNum, int remMoves, time_t timeStart, time_t timeEnd, int player1score, int player2score, char player1name[], char player2name[], int filenum);
void load (int board[20][20], int *sizeofboard, int *gamemode, int *playerNum, int *remMoves, time_t *timeStart, time_t *timeEnd, int *player1score, int *player2score, char player1name[], char player2name[], int filenum);

void undo(int history[60][3],int *counter ,int player [20][20],int n){
   *counter--;
   for(int k=0;k< n;k++){
        for(int j=0;j<n;j++){
            player[k][j]=0;
        }
   }
   for(int k=0;k<= *counter;k++){
        if(history[k][0]==0){
            break;
        }
        if((history[k][0])%2==0){
             player[(history[k][1])][(history[k][2])]=1;
        }
        else{
             player[(history[k][1])][(history[k][2])]=2;
        }
   }
}
void redo(int history[60][3],int *counter ,int player [20][20],int n){
   *counter++;
   for(int k=0;k< n;k++){
        for(int j=0;j<n;j++){
            player[k][j]=0;
        }
   }
   for(int k=0;k<=*counter;k++){
          if(history[k][0]==0){
            break;
          }
          if(history[k][0]%2==0){
            player[(history[k][1])][(history[k][2])]=1;
          }
          else{
            player[(history[k][1])][(history[k][2])]=1;
          }
   }

}
