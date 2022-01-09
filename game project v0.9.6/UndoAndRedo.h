void undo(int history[60][2], int *counter, int player[20][20], int *remMoves, int n){
    *counter-=1;
    *remMoves+=1;
    int row, col;
    row=history[*counter][0];
    col=history[*counter][1];
    player[row][col]=0;
    for (int j=1;j<=(n-2);j+=2) {
        for (int k=1;k<=(n-2);k+=2) {
            if ((player[j-1][k]==0)||(player[j+1][k]==0)||(player[j][k-1]==0)||(player[j][k+1]==0)) {
                player[j][k]=0;
            }
        }
    }
}
void redo(int history[60][2],int *counter ,int player [20][20],int *remMoves, int n){

}
