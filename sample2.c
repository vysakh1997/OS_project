#include <stdio.h>
int main(){
int d=1;
    while(d<19600)
    {   int y=d*3;
        if((y%19600)==1)
            
            break;
        
        
        d++;
    }

    printf("%d",d);
    return 0;}