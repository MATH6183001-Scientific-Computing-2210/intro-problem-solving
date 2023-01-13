#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int* a, int N){
    
    for(int i = 0; i < N/2; i++) {
        a[i] = a[i]+a[N-1-i];
        a[N-1-i] = a[i]-a[N-1-i];
        a[i] = a[i]-a[N-1-i];
    }

}

int main()
{
    int N = 4;
    int* a = (int*) malloc(N*sizeof(N));
    int tmp[] = {3,1,4,2};

    memcpy(a,tmp,N*sizeof(int));

    printf("The original sequence is\n");
    for(int i=0;i<N;i++) printf("%i ",a[i]);
    printf("\n");

    reverse(a,N);

    printf("The reversed sequence is\n");
    for(int i=0;i<N;i++) printf("%i ",a[i]);
    printf("\n");

    printf("\n");

    free(a);

    return 0;
}
