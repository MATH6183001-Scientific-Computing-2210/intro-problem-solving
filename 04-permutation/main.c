#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(int* x, int* y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int findNextItem(int* a, int N){

    // find pivot
    int p = N-1;
    while( (p>0) && a[p-1] >= a[p] ){
        p--;
    }

    // return if in the last order
    if(p<=0){
        return 0;
    }

    // find a value to be swapped
    int s = N-1;
    while(a[s]<=a[p-1]){
        s--;
    }

    // swap
    swap(&a[s],&a[p-1]);


    // reverse order
    for(int i=p; i<(N-1-p+1)/2+p; i++){
        swap(&a[i],&a[N-1-i+p]);
    }

    return 1;


}

int factorial(int N){

    int tmp=1;
    for(int i=1; i<=N; i++){
        tmp = tmp*i;
    }

    return tmp;
}

int main(void){

    int N = 5;
    int a[] = {0,1,2,3,4};

    for(int j=0; j<N; j++){
        printf("%d ",a[j]);
    }
    printf("\n");

    findNextItem(a,N);
    for(int j=0; j<N; j++){
        printf("%d ",a[j]);
    }
    printf("\n");

    while(findNextItem(a,N)){

        for(int j=0; j<N; j++){
            printf("%d ",a[j]);
        }
        printf("\n");

    }

    return 0;
}