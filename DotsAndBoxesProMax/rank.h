void rank (char playerName[], int playerScore) {
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

void print_rank(){
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