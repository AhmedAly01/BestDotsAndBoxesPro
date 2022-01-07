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
