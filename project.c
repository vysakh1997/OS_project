#include<stdio.h>

unsigned short pows (unsigned short x,unsigned short y,unsigned short z)
{
 unsigned short i=1;
 long pro=x;
 for(;i<y;i++)
    {
        pro=pro*x;
        pro=pro%z;
    }
return (unsigned short)pro;
}

void encryption (unsigned short e, unsigned short n )
{
    FILE *fptr,*fptr2;
    fptr=fopen("text.txt","rb");
    fptr2=fopen("text2.txt","wb");
    int size;
    int i;
    fseek(fptr, 0L, SEEK_END);
    size = ftell(fptr);
    char buffer[size];
    fseek(fptr, 0, SEEK_SET);
    fread(buffer,size,1,fptr);
    if (size%2 == 1)
        {
            buffer[size] = 32;
            size++;   
        }    

    for(i = 0; i <= (size/2); i +=2)
    {
        char t;
        t = buffer[i];
        buffer[i] = buffer[i+1];
        buffer[i+1] = t;
    }
    
    unsigned short * pt=buffer;
    unsigned short c;
    unsigned short encrypted[size/2];
    for(i=0;i<(size)/2;i++)
    {   
        c = pows(pt[i], e,n); 
        encrypted[i]=c;
    }    
    char * ebuffer = encrypted;
    fwrite(ebuffer,size,1,fptr2);
    fclose(fptr);
    fclose(fptr2);
    return;
}  

void decryption (unsigned short d, unsigned short n )
{
    FILE *fptr,*fptr2;
    fptr=fopen("text2.txt","rb");
    fptr2=fopen("text3.txt","wb");
    int size;
    int i;
    fseek(fptr, 0L, SEEK_END);
    size = ftell(fptr);
    char buffer[size];
    fseek(fptr, 0, SEEK_SET);
    fread(buffer,size,1,fptr);

    unsigned short * pt=buffer;
    unsigned short m;
    unsigned short decrypted[size/2];
    for(i=0;i<size/2;i++)
    { 
        m = pows(pt[i], d,n);
        decrypted[i]=m;
    }
    char * dbuffer=decrypted;
    for(i = 0; i <= (size/2); i +=2)
    {
        char t;
        t = dbuffer[i];
        dbuffer[i] = dbuffer[i+1];
        dbuffer[i+1] = t;
    }
    fwrite(dbuffer,size, 1, fptr2);
    fclose(fptr);
    fclose(fptr2);
    return;
}

int main()
{
    unsigned short p;
    unsigned short q;
    unsigned short n;
    unsigned short e;
    unsigned short d;
    unsigned short phi ;
    FILE *fptr,*fptr2;
    fptr=fopen("public_vd.txt","r");
    fscanf(fptr,"%d",&e);
    fscanf(fptr,"%d",&n);
    fclose(fptr);
    
    printf("e = %d\nn = %d\n",e,n );
    e=3;
    fptr2 =fopen("private_me.txt","r");
    fscanf(fptr2,"%d",&d);
    fscanf(fptr2,"%d",&phi);
    fclose(fptr2);
    printf("d = %d phi = %d ",d,phi);
    encryption(e,n);
    decryption(d,n);
    return 0;
}