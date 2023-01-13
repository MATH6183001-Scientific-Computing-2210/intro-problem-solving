#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* x, int* y){
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;

}

int* naiveSort(int* a, int N){

    int* sortedArr = (int*) malloc(N*sizeof(int));

    memcpy(sortedArr,a,N*sizeof(int));

    if(N>2){
        int idxMinVal;

        for(int i=0; i<N-1; i++){
            // find minimum
            idxMinVal = i+1;
            for (int j = i+2; j < N; j++){
                if(sortedArr[idxMinVal]>sortedArr[j]){
                    idxMinVal = j;
                }
            }

            // swap with the minimum if sortedArr[idxMinVal]<sortedArr[i]
            if(sortedArr[idxMinVal]<sortedArr[i]){
                swap(&sortedArr[i],&sortedArr[idxMinVal]);
            }

        }
    }


    return sortedArr;

}

int* bubbleSort(int* a, int N){

    int* sortedArr = (int*) malloc(N*sizeof(int));

    memcpy(sortedArr,a,N*sizeof(int));

    if(N>2){

        for(int i=0; i<N-1; i++){
            for (int j = 0; j < N-1-i; j++){
                if(sortedArr[j] > sortedArr[j+1]){
                    swap(&sortedArr[j],&sortedArr[j+1]);
                }
            }
        }
    }


    return sortedArr;

}


int main(void){

    int a[] = {4,2,3,5,1};

    int* resultNaiveSort = naiveSort(a,5);
    int* resultBubbleSort = bubbleSort(a,5);

    for(int i=0; i<5; i++){
        printf("%d ",resultNaiveSort[i]);
    }
    printf("\n");

    for(int i=0; i<5; i++){
        printf("%d ",resultBubbleSort[i]);
    }
    printf("\n");

    return 0;

}