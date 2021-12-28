void AI(int player[20][20],int n){
    int r=0,c=0;
        for(int i=0 ;i<n;i++){
          for(int j=0;j<n;j++){
             if((i+j)%2==0){
               if(player[i][j]==0){
                  if((player[i-1][j]!=0)&&(player[i+1][j]!=0)&&(player[i][j+1]!=0)&&(player[i][j-1]==0)){
                      player[i][j-1]= 2;
                      player2.playerscore++;
                      flag=1;
                  }
                  else if((player[i-1][j]!=0)&&(player[i+1][j]!=0)&&(player[i][j+1]==0)&&(player[i][j-1]!=0)){
                       player[i][j-1]= 2;
                       player2.playerscore++;
                       flag=1;
                  }
                  else if((player[i-1][j]!=0)&&(player[i+1][j]==0)&&(player[i][j+1]!=0)&&(player[i][j-1]!=0)){
                         player[i+1][j]= 2;
                         player2.playerscore++;
                         flag=1;
                  }
                  else if((player[i-1][j]==0)&&(player[i+1][j]!=0)&&(player[i][j+1]!=0)&&(player[i][j-1]!=0)){
                      player[i-1][j]= 2;
                      player2.playerscore++;
                      flag=1;
                  }

                  else{
                    goto place2;
                  }
               }
             }
          }
        }
        place2:
        while(1){
            srand(time(NULL));
            r=rand()%11;
            c=rand()%11;
            if((r+c)%2==0){
            }
            else{
                if(player[r][c]==0){
                    if(r%2==0){
                        player[r][c]=2;
                            break;
                    }
                    else{
                        player[r][c]=2;
                            break;
                    }
                }

            }
        }
}
