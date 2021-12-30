void save (int board[20][20], int sizeofboard,int gamemode, int playerNum, int remMoves, int time, int player1score, int player2score, char player1name[], char player2name[], int filenum) {
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
    fprintf(fp, "%d ", gamemode);
    fprintf(fp, "%d ", playerNum);
    fprintf(fp, "%d ", remMoves);
    fprintf(fp, "%d ", time);
    fprintf(fp, "%d ", player1score);
    fprintf(fp, "%d ", player2score);
    fprintf(fp,"\n");
    fprintf(fp, "%s\n", player1name);
    fprintf(fp, "%s\n", player2name);
    fprintf(fp,"\n");

    fclose(fp);

}

void load (int board[20][20], int sizeofboard, int *gamemode, int *playerNum, int *remMoves, int *time, int *player1score, int *player2score, char player1name[], char player2name[], int filenum) {
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
    int data[6];
    for (int i=0; i<6; i++) {
        fscanf (fp, " %d ", &data[i]);
    }

    *gamemode=data[0];
    *playerNum=data[1];
    *remMoves=data[2];
    *time=data[3];
    *player1score=data[4];
    *player2score=data[5];

    fscanf (fp, "%[^\n]%*c", player1name);
    fscanf (fp, "%[^\n]%*c", player2name);

    fclose(fp);

}
