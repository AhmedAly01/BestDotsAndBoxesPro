void undoplayer(int undo_history[60][3], int *counter, int player[20][20], int *remMoves, int n,int *x,int redo_history[60][3],int*redocounter,int *check)
{
    int row,col;
    if(*counter!=0)
    {
            *counter-=1;

            *remMoves+=1;

            row=undo_history[*counter][1];
            *x=undo_history[*counter][0];
            col=undo_history[*counter][2];
            redo_history[*redocounter][0]=*x;
            redo_history[*redocounter][1]=row;
            redo_history[*redocounter][2]=col;
            *redocounter+=1;
            player[row][col]=0;
            undo_history[*counter][0]=0;
            undo_history[*counter][1]=0;
            undo_history[*counter][2]=0;

    }
    for (int j=1; j<=(n-2); j+=2)
    {
        for (int k=1; k<=(n-2); k+=2)
        {
            if ((player[j-1][k]==0)||(player[j+1][k]==0)||(player[j][k-1]==0)||(player[j][k+1]==0))
            {
                player[j][k]=0;
            }
        }
    }
}
void redoplayer(int undo_history[60][3], int *counter, int player[20][20], int *remMoves, int n,int *x,int redo_history[60][3],int*redocounter)
{
   int row,col;

            *counter+=1;
            *remMoves-=1;
            row=undo_history[*counter][1];
            *x=redo_history[*redocounter][0];
            col=redo_history[*counter][2];
            undo_history[*counter][0]=*x;
            undo_history[*counter][1]=row;
            undo_history[*counter][2]=col;
            *redocounter-=1;
            if(*x%2==0){
            player[row][col]=1;
            }
            else{
            player[row][col]=2;
            }
            redo_history[*redocounter][0]=0;
            redo_history[*redocounter][1]=0;
            redo_history[*redocounter][2]=0;


    for (int j=1; j<=(n-2); j+=2)
    {
        for (int k=1; k<=(n-2); k+=2)
        {
            if ((player[j-1][k]==0)||(player[j+1][k]==0)||(player[j][k-1]==0)||(player[j][k+1]==0))
            {
                player[j][k]=0;
            }
        }
    }
}

void undocomp(int undo_history[60][3], int *counter, int player[20][20], int *remMoves, int n,int *x,int redo_history[60][3],int*redocounter)
{
    int row,col;
    if(*counter!=0)
    {
        while(undo_history[*counter-1][0]%2!=0){
            *counter-=1;
            *remMoves+=1;
            row=undo_history[*counter][1];
            *x=undo_history[*counter][0];
            col=undo_history[*counter][2];
            redo_history[*redocounter][0]=*x;
            redo_history[*redocounter][1]=row;
            redo_history[*redocounter][2]=col;
            *redocounter+=1;
            player[row][col]=0;
            undo_history[*counter][0]=0;
            undo_history[*counter][1]=0;
            undo_history[*counter][2]=0;
        }
    }
    for (int j=1; j<=(n-2); j+=2)
    {
        for (int k=1; k<=(n-2); k+=2)
        {
            if ((player[j-1][k]==0)||(player[j+1][k]==0)||(player[j][k-1]==0)||(player[j][k+1]==0))
            {
                player[j][k]=0;
            }
        }
    }

}
void redocomp(int undo_history[60][3], int *counter, int player[20][20], int *remMoves, int n,int *x,int redo_history[60][3],int*redocounter)
{
    int row,col;
    if(*counter!=0)
    {
        while(redo_history[*counter+1][0]%2!=0){
            *counter+=1;
            *remMoves-=1;
            row=undo_history[*counter][1];
            *x=redo_history[*redocounter][0];
            col=redo_history[*counter][2];
            undo_history[*counter][0]=*x;
            undo_history[*counter][1]=row;
            undo_history[*counter][2]=col;
            *redocounter-=1;
            if(*x%2==0){
            player[row][col]=1;
            }
            else{
            player[row][col]=2;
            }
            redo_history[*redocounter][0]=0;
            redo_history[*redocounter][1]=0;
            redo_history[*redocounter][2]=0;

        }
    }
    for (int j=1; j<=(n-2); j+=2)
    {
        for (int k=1; k<=(n-2); k+=2)
        {
            if ((player[j-1][k]==0)||(player[j+1][k]==0)||(player[j][k-1]==0)||(player[j][k+1]==0))
            {
                player[j][k]=0;
            }
        }
    }

}
