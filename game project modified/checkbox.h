#define block 176
void checkBox (int n, char board[n][n],int i,int playerscore1,int playerscore2) {
    for (int i=1;i<=(n-2);i+=2) {
        for (int j=1;j<=(n-2);j+=2) {
            if ((board[i-1][j]!=' ')&&(board[i+1][j]!=' ')&&(board[i][j-1]!=' ')&&(board[i][j+1]!=' ')&&(board[i][j]==' ')) {
                board[i][j]=block;
                if (i%2==0){
                   playerscore1++;
                }
                else{
                     playerscore2++;
                }

            }
        }
    }
    printf("%d",n);
}
