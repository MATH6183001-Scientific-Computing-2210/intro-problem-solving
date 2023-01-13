#include <stdio.h>
#include <stdlib.h>

struct School {
    int numStudents;
    char* name;
};

typedef struct School School;

int main(void){

    School binus;
    binus.numStudents = 1000;

    int x = 10;
    int* a = (int*) malloc(10*sizeof(int));

    a[0] = 1;
    a[1] = 2;
    // ...

    int* px = &x;

    *px = 12;

    printf("%d\n",x);
    printf("%p\n",a);
    printf("%d\n",*(a+0));
    printf("%d\n",*(a+1));

    return 0;
}