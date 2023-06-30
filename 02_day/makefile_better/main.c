#include<stdio.h>
#include "add.h"
#include "sub.h"
int main(){
    int a=10,b=20;
    printf("Addition of %d and %d is %d\n",a,b,add(a,b));
    printf("Subtraction of %d and %d is %d\n",a,b,sub(a,b));
    return 0;
}