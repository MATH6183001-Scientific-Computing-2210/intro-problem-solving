#include <stdio.h>
#include <stdlib.h>

int main(void){

    int N = 5;

    int** matrix = (int**) malloc((2*N-1)*sizeof(int*));
    for(int i=0; i< 2*N-1;i++){
        matrix[i] = (int*) malloc((2*N-1)*sizeof(int*));
    }

    for(int n=N; n>=1 ; n--){
        for(int row=N-n; row<2*N-1-N+n; row++){
            for(int col=N-n; col<2*N-1-N+n; col++){
                matrix[row][col]=n;
            }
        }
    }

    for(int i=0;i<2*N-1;i++){
        for(int j=0;j<2*N-1;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;

}
