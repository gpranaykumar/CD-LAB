//Generate the Three Address Code for a Given Expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[100]; char j='A';
    printf("Enter the expression\n"); scanf("%s",s);
    printf("3address code\n"); int i=2,n,h;
    n=strlen(s);
    for(i=2;i<=n;i++)
    {
        if(s[i]=='*'||s[i]=='/')
        {
            printf("%c=%c%c%c\n",j,s[i-1],s[i],s[i+1]); s[i-1]=j++;
            for(h=i;h<n-1;h++)
                s[h]=s[h+2];
            n-=2;
            i=i-1;
        }
    }
    for(i=2;i<=n;i++)
    {
        if(s[i]=='+'||s[i]=='-')
        {
            printf("%c=%c%c%c\n",j,s[i-1],s[i],s[i+1]); s[i-1]=j++;
            for(h=i;h<n-1;h++)
                s[h]=s[h+2];
            n-=2;
            i=i-1;
        }
    }
    printf("%c=%c",s[0],s[2]);
    return 0;
}

/*
z=a+b*c+d
OUTPUT:
Enter the expression
z=a+b*c+d        
3address code
A=b*c
B=a+A
C=B+d
z=C
*/
