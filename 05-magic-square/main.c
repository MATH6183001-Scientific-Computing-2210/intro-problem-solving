#include <stdio.h>
#include <stdlib.h>

#define LOWER 1
#define UPPER 9

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

int** initMat(int N){

    int** M = (int**) malloc(N*sizeof(int*));

    for(int i=0; i<N; i++){
        M[i] = (int*) malloc(N*sizeof(int));
        for(int j=0; j<N; j++){
            M[i][j] = generateRandomInt(LOWER,UPPER);
        }
    }

    return M;

}

void printMatrix(int** M, int N){
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            printf("%d\t",M[i][j]);
        }
        printf("\n");
    }
}

int sumThreeNumbers(int arr0, int arr1, int arr2){
    return arr0+arr1+arr2;
}

int isValid(int** s){
    // check uniqueness
    int tmp_arr[9] = {0,0,0,0,0,0,0,0,0};

    for(int i=0;i<9;i++){
        tmp_arr[s[i/3][i%3]-1]++;
    }

    for(int i=0;i<9;i++){
        if(tmp_arr[i]!=1) {
            // printf("here\n");
            return 0;
        }
    }


    // check row
    if(
        sumThreeNumbers(s[0][0], s[0][1], s[0][2]) != 
        sumThreeNumbers(s[1][0], s[1][1], s[1][2]) ||
        sumThreeNumbers(s[2][0], s[2][1], s[2][2]) != 
        sumThreeNumbers(s[1][0], s[1][1], s[1][2]) ||
        sumThreeNumbers(s[0][0], s[0][1], s[0][2]) != 
        sumThreeNumbers(s[2][0], s[2][1], s[2][2]) 
    ){
        return 0;
    }
    
    // check col
    if(
        sumThreeNumbers(s[0][0], s[1][0], s[2][0]) != 
        sumThreeNumbers(s[0][1], s[1][1], s[2][1]) ||
        sumThreeNumbers(s[0][2], s[1][2], s[2][2]) != 
        sumThreeNumbers(s[0][1], s[1][1], s[2][1]) ||
        sumThreeNumbers(s[0][0], s[1][0], s[2][0]) != 
        sumThreeNumbers(s[0][2], s[1][2], s[2][2]) 
    ){
        return 0;
    }
    
    // check diag
    if(
        sumThreeNumbers(s[0][0], s[1][1], s[2][2]) != 
        sumThreeNumbers(s[2][0], s[1][1], s[0][2]) 
    ){
        return 0;
    }
    
    // check accross direction
    if(
        sumThreeNumbers(s[2][0], s[2][1], s[2][2]) !=
        sumThreeNumbers(s[0][0], s[1][0], s[2][0]) ||
        sumThreeNumbers(s[2][0], s[2][1], s[2][2]) !=
        sumThreeNumbers(s[0][0], s[1][1], s[2][2])
    ){
        return 0;
    }
    
    return 1;
}


int main(void){

    int N=3;

    // all possible 3x3 magic square
    int matrix[8][9] = {
            {8,1,6,3,5,7,4,9,2},
            {6,1,8,7,5,3,2,9,4},
            {2,7,6,9,5,1,4,3,8},
            {4,9,2,3,5,7,8,1,6},
            {4,3,8,9,5,1,2,7,6},
            {8,3,4,1,5,9,6,7,2},
            {6,7,2,1,5,9,8,3,4},
            {2,9,4,7,5,3,6,1,8},
        };

    int** M = initMat(N);

    printf("The random matrix is:\n");
    printMatrix(M,N);

    printf("Is it a valid magic square?\n");
    printf("%s\n", isValid(M)?"Yes":"No");

    // find the minimum value
    int arrResults[8] = {0,0,0,0,0,0,0,0};
    for(int i=0;i<8;i++){
        for(int j=0;j<9;j++){
            arrResults[i]+=abs(matrix[i][j]-M[j/3][j%3]);
        }
    }

    int minValue = arrResults[0];
    int idxMinVal = 0;
    for(int i=1;i<8;i++){
        if(minValue > arrResults[i]){
            minValue = arrResults[i];
            idxMinVal = i;
        }
    }

    printf("The closest magic square is:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d\t",matrix[idxMinVal][N*i+j]);
        }
        printf("\n");
    }

    printf("And the total distance is:\n");
    printf("%d\n",minValue);


    return 0;
}