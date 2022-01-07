void save (int board[20][20], int sizeofboard, int gamemode, int playerNum, int remMoves, time_t timeStart, time_t timeEnd, int player1score, int player2score, char player1name[], char player2name[], int filenum) {
    FILE *fp;
    if (filenum==1) {
        fp=fopen("1.bin","wb");
    }
    else if (filenum==2) {
        fp=fopen("2.bin","wb");
    }
    else if (filenum==3) {
        fp=fopen("3.bin","wb");
    }

    for (int i=0; i<sizeofboard; i++) {
        for (int j=0; j<sizeofboard; j++) {
            fprintf(fp, "%d ", board[i][j]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp, "%d ", sizeofboard);
    fprintf(fp, "%d ", gamemode);
    fprintf(fp, "%d ", playerNum);
    fprintf(fp, "%d ", remMoves);
    fprintf(fp, "%d ", timeStart);
    fprintf(fp, "%d ", timeEnd);
    fprintf(fp, "%d ", player1score);
    fprintf(fp, "%d ", player2score);
    fprintf(fp,"\n");
    fprintf(fp, "%s\n", player1name);
    fprintf(fp, "%s\n", player2name);
    fprintf(fp,"\n");

    fclose(fp);
}

void load (int board[20][20], int *sizeofboard, int *gamemode, int *playerNum, int *remMoves, time_t *timeStart, time_t *timeEnd, int *player1score, int *player2score, char player1name[], char player2name[], int filenum) {
    FILE *fp;
    if (filenum==1) {
        fp=fopen("1.bin", "rb");
    }
    else if (filenum==2) {
        fp=fopen("2.bin", "rb");
    }
    else if (filenum==3) {
        fp=fopen("3.bin", "rb");
    }

    for (int i=0; i<sizeofboard; i++) {
        for (int j=0; j<sizeofboard; j++) {
            fscanf (fp, " %d ", &board[i][j]);
        }
        fscanf(fp, "\n");
    }
    int data[8];
    for (int i=0; i<8; i++) {
        fscanf (fp, " %d ", &data[i]);
    }

    *sizeofboard=data[0];
    *gamemode=data[1];
    *playerNum=data[2];
    *remMoves=data[3];
    *timeStart=data[4];
    *timeEnd=data[5];
    *player1score=data[6];
    *player2score=data[7];

    fscanf (fp, "%[^\n]%*c", player1name);
    fscanf (fp, "%[^\n]%*c", player2name);

    fclose(fp);

}
