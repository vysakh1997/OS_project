#include<stdio.h>



int main()
{
	unsigned short p=251;
    unsigned short q=257;
    unsigned short n=p*q;
    unsigned short e=3;
    unsigned short phi=(p-1)*(q-1);
	unsigned short d=1;
    while(d<phi)
    {   long y=(long)d*e;
        if((y%phi)==1)
            break;
        d++;
    }
    printf("p = %d\n",p);
    printf("q = %d\n",q);
    printf("n = %d\n",n);
    printf("e = %d\n",e);
    printf("phi = %d\n",phi);
    printf("d = %d\n",d);
}