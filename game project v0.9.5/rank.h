
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

void rankHandle (char playerName[], int playerScore) {
    char rankName[10][50];
    int rankScore[10];
    FILE *fp;
    fp= fopen("rank.bin","rb");
    for (int i=0; i<10; i++) {
        fscanf (fp, " %s %d", &rankName[i], &rankScore[i]);
        fscanf (fp, "\n");
    }
    fclose (fp);

    for (int i=0; i<10; i++) {
        if (playerScore>rankScore[i]) {
            for (int j=9; j<i; j--) {
                rankScore[j]=rankScore[j-1];
                for (int k=0; k<50; k++) {
                    rankName[j][k]=rankName[j-1][k];
                }
            }
            rankScore[i]=playerScore;
            for (int k=0; k<50; k++) {
                    rankName[i][k]=playerName[k];
                }
            break;
        }
    }

    fp= fopen("rank.bin","wb");
    for (int i=0; i<10; i++) {
        fprintf (fp, " %s %d", rankName[i], rankScore[i]);
        fprintf (fp, "\n");
    }
    fclose (fp);
}

void printRank(){
    char rankName[10][50];
    int rankScore[10];
    FILE *fp;
    fp= fopen("rank.bin","rb");
    for (int i=0; i<10; i++) {
        fscanf (fp, " %s %d", &rankName[i], &rankScore[i]);
        fscanf (fp, "\n");
    }
    fclose (fp);

    printf("TOP 10 players\n\n");
    for (int i=0; i<10; i++) {
        printf ("%d. %s %d", i+1, rankName[i], rankScore[i]);
        printf ("\n");
    }
}
