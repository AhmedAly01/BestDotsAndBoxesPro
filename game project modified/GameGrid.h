#define dot 254
void createArray (int x,char player[20][20],int n4) {
        n4=6*x-1;
        for (int i=0; i<n4; i++) {
            for (int j=0; j<n4; j++){
             player[i][j]=0;
            }
        }
        for (int i=0; i<n4; i++) {
            for (int j=0; j<n4; j++) {
                if ((i%2==0)&&(j%2==0)) {
                    player[i][j]=dot;
                }
                else {
                    player[i][j]=' ';
                }
            }
        }
}

//printing the boards
 void printArray (char player[20][20],int n5) {
        printf("\n\n");
        printf ("\t\t\t");
        printf ("  ");
        for (int i=0; i<n5; i++) {
            printf (" %d ",i);
        }
        printf ("\n");
        for (int i=0; i<n5; i++) {
                printf("\t\t\t");
                printf ("%d ",i);
            for (int j=0; j<n5; j++) {
                printf (" %c ",player[i][j]);
            }
            printf ("\n");
        }
    }

