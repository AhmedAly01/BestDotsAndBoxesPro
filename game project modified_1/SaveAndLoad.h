void save (char board[20][20], int sizeofboard, int playerNum, int remMoves, int time, int player1score, int player2score, char player1name[], char player2name[], int filenum) {
    FILE *fp;
    if (filenum==1) {
        fp=fopen("save1.bin","wb");
        for (int i=0; i<sizeofboard; i++) {
            for (int j=0; j<sizeofboard; j++) {
                fprintf(fp, "%c", board[i][j]);
            }
            fprintf(fp,"\n");
        }
        fprintf(fp, "%d ", playerNum);
        fprintf(fp, "%d ", remMoves);
        fprintf(fp, "%d ", time);
        fprintf(fp, "%d ", player1score);
        fprintf(fp, "%d ", player2score);
        fprintf(fp,"\n");
        fprintf(fp, "%s\n", player1name);
        fprintf(fp, "%s\n", player2name);
        fprintf(fp,"\n");
    }
    else if (filenum==2) {
        fp=fopen("save2.bin","wb");
        for (int i=0; i<sizeofboard; i++) {
            for (int j=0; j<sizeofboard; j++) {
                fprintf(fp, "%c", board[i][j]);
            }
            fprintf(fp,"\n");
        }
        fprintf(fp, "%d ", playerNum);
        fprintf(fp, "%d ", remMoves);
        fprintf(fp, "%d ", time);
        fprintf(fp, "%d ", player1score);
        fprintf(fp, "%d ", player2score);
        fprintf(fp,"\n");
        fprintf(fp, "%s\n", player1name);
        fprintf(fp, "%s\n", player2name);
        fprintf(fp,"\n");
    }
    else if (filenum==3) {
        fp=fopen("save3.bin","wb");
        for (int i=0; i<sizeofboard; i++) {
            for (int j=0; j<sizeofboard; j++) {
                fprintf(fp, "%c", board[i][j]);
            }
            fprintf(fp,"\n");
        }
        fprintf(fp, "%d\n", playerNum);
        fprintf(fp, "%d\n", remMoves);
        fprintf(fp, "%d\n", time);
        fprintf(fp, "%d\n", player1score);
        fprintf(fp, "%d\n", player2score);
        fprintf(fp,"\n");
        fprintf(fp, "%s\n", player1name);
        fprintf(fp, "%s\n", player2name);
        fprintf(fp,"\n");
    }
    fclose(fp);

}

void load (char board[20][20], int sizeofboard , int *playerNum, int *remMoves, int *time, int *player1score, int *player2score, char player1name[], char player2name[], int filenum) {
    FILE *fp;
    if (filenum==1) {
        fp=fopen("save1.bin", "rb");
        for (int i=0; i<sizeofboard; i++) {
            for (int j=0; j<sizeofboard; j++) {
                fscanf (fp, " %c ", &board[i][j]);
            }
            fscanf(fp, "\n");
        }
        int data[5];
        for (int i=0; i<5; i++) {
                fscanf (fp, " %d ", &data[i]);
            }
        *playerNum=data[0];
        *remMoves=data[1];
        *time=data[2];
        *player1score=data[3];
        *player2score=data[4];

        fscanf (fp, "%[^\n]%*c", player1name);
        fscanf (fp, "%[^\n]%*c", player2name);
    }
    else if (filenum==2) {
        fp=fopen("save2.bin", "rb");
        for (int i=0; i<sizeofboard; i++) {
            for (int j=0; j<sizeofboard; j++) {
                fscanf (fp, " %c ", &board[i][j]);
            }
            fscanf(fp, "\n");
        }
        int data[5];
        for (int i=0; i<5; i++) {
                fscanf (fp, " %d ", &data[i]);
            }
        *playerNum=data[0];
        *remMoves=data[1];
        *time=data[2];
        *player1score=data[3];
        *player2score=data[4];

        fscanf (fp, "%[^\n]%*c", player1name);
        fscanf (fp, "%[^\n]%*c", player2name);

    }
    else if (filenum==3) {
        fp=fopen("save3.bin", "rb");
        for (int i=0; i<sizeofboard; i++) {
            for (int j=0; j<sizeofboard; j++) {
                fscanf (fp, " %c ", &board[i][j]);
            }
            fscanf(fp, "\n");
        }
        int data[5];
        for (int i=0; i<5; i++) {
                fscanf (fp, " %d ", &data[i]);
            }
        *playerNum=data[0];
        *remMoves=data[1];
        *time=data[2];
        *player1score=data[3];
        *player2score=data[4];

        fscanf (fp, "%[^\n]%*c", player1name);
        fscanf (fp, "%[^\n]%*c", player2name);

    }
    fclose(fp);

}