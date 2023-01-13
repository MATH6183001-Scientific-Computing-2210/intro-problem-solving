#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

struct bigInt{
    char* digit;
    int length;
};

typedef struct bigInt bigInt;

int getLengthInt(int x){
    
    assert(x>0);
    return (int) floor(log10(x))+1;
}

char intToChar(int x){

    if(x==0) {return '0';}
    else if(x==1) {return '1';}
    else if(x==2) {return '2';}
    else if(x==3) {return '3';}
    else if(x==4) {return '4';}
    else if(x==5) {return '5';}
    else if(x==6) {return '6';}
    else if(x==7) {return '7';}
    else if(x==8) {return '8';}
    else if(x==9) {return '9';}

    return 'x';
}

int charToInt(char x){
    if(x=='0') {return 0;}
    else if(x=='1') {return 1;}
    else if(x=='2') {return 2;}
    else if(x=='3') {return 3;}
    else if(x=='4') {return 4;}
    else if(x=='5') {return 5;}
    else if(x=='6') {return 6;}
    else if(x=='7') {return 7;}
    else if(x=='8') {return 8;}
    else if(x=='9') {return 9;}

    return -1;
}

bigInt bigContructorFromString(char* s, int length){

    bigInt result;

    result.digit = (char*) malloc(length*sizeof(char));
    result.length = length;

    for(int i=0; i<length; i++){
        result.digit[i] = s[i];
    }


    return result;

}

bigInt bigContructorWithLength(int length){
    bigInt result;
    
    // int digit;
    result.digit = (char*) malloc(length*sizeof(char));
    result.length = length;
    sprintf(result.digit,"%0*d",length,0);

    return result;

}

void bigPrint(bigInt x){
    for(int i=0; i<x.length; i++){
        printf("%c",x.digit[i]);
    }
}

void bigPrepend(bigInt* x, int new_length){
    
    if(new_length > x->length) {
        
        char* tmp = (char*) malloc(new_length*sizeof(char));

        int j = new_length-1;
        for(int i=x->length-1; i>=0; i--){
            tmp[j] = x->digit[i];
            j--;
        }

        for(int i=0; i<new_length-x->length;i++){
            tmp[i] = '0';
        }
        
        free(x->digit);
        x->digit = tmp;

        x->length = new_length;
        
    }

}

void bigAdd( bigInt* x, bigInt y){

    if(x->length<y.length){
        bigPrepend(x,y.length);
    } else{
        bigPrepend(&y,x->length);
    }

    bigInt z = bigContructorWithLength(x->length);

    int tmp = 0;
    int digit_x;
    int digit_y;
    for(int i=z.length-1; i>=0; i--){

        digit_x = charToInt(x->digit[i])+tmp;
        digit_y = charToInt(y.digit[i]);
        tmp = (digit_x+digit_y)/10;
        z.digit[i] = intToChar((int) (digit_x+digit_y)%10);

    }

    if(tmp==1){
        bigPrepend(&z,z.length+1);
        z.digit[0] = '1';
    }

    free(x->digit);
    x->digit = z.digit;
    x->length = z.length;

}

int main(void){

    bigInt x = bigContructorFromString("100000000000000000000",21);
    bigInt y = bigContructorFromString("2000000000000000000000",22);

    printf("x= ");
    bigPrint(x);

    printf(", y= ");
    bigPrint(y);

    bigAdd(&x,y);

    printf("\nx+y= ");
    bigPrint(x);
    printf("\n");

    return 0;
}