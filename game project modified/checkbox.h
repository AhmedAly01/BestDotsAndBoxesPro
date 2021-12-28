#define block 176
#define REDB "\e[41m"
#define BLUB "\e[44m"

void checkBox (int n, int board[n][n],int i,int playerscore1,int playerscore2,int flag) {
    for (int i=1;i<=(n-2);i+=2) {
        for (int j=1;j<=(n-2);j+=2) {
            if ((board[i-1][j]!=0)&&(board[i+1][j]!=0)&&(board[i][j-1]!=0)&&(board[i][j+1]!=0)&&(board[i][j]==0)) {
                board[i][j]=3;
                if (i%2==0){
                   playerscore1++;
                   flag=1;
                }
                else{
                     flag=1;
                     playerscore2++;
                }

            }
        }
    }
    printf("%d",n);
}
