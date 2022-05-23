//Predictive Parser
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char input[7]="i+i*i$", m[6][7][9]={" ", "+", "*", "(",")","i","$",
                                        "e", "_", "_", "e->tE", "_", "e->tE", " -",
                                        "E", "E->+tE", "_", "_", "E->@", "_", "E->@",
                                        "t", "_", "_", "t->fT", "_", "t->fT", "_",
                                        "T", "T->@", "T->*fT", "_", "T->@", "_", "_",
                                        "f", "_", "_", "f->(e)", "_", "f->i", "_" };
    char stack[20],prod[20],a,st;
    int i,j,k,inp=0,top=0,r,c,max=6;
    stack[0] = '$';
    top++;
    stack[top] = 'e';
    do{
        a=input[inp]; st = stack[top];
        if(st == a){
            printf("\n");
            for(i=0;i<top;i++)
                printf("%c",stack[i]);
            printf("\t%s",input);
            stack[top]=' ';
            input[inp]=' ';
            top--; inp++;
        }else{
            for(i=0;i<7;i++){
                if(m[0][i][0] == a){
                    c = i;
                    break;
                }
            }
            
            for(i=0;i<6;i++){
                if(m[i][0][0] == st){
                    r = i; break;
                }
            }
            
            if(m[r][c][0]==' '){
                printf("Error");
                exit(0);
            }else{
                for(i=0,k=3;k<8;k++,i++){
                    prod[i] = m[r][c][k];
                }
                int i,len,temp;
                len = strlen(prod);
                for(i=0;i<len/2;i++){
                    temp = prod[i];
                    prod[i] = prod[len-i-1];
                    prod[len-i-1] = temp;
                }
            }
            if(prod[0] == '@'){
                printf("\n");
                for(i=0;i<=top;i++){
                    printf("%c",stack[i]);
                }
                printf("\t%s",input);
                stack[top]=' ';
                top--;
            }else{
                printf("\n");
                for(i=0;i<=top;i++){
                    printf("%c",stack[i]);
                }
                printf("\t%s",input);
                stack[top]=' '; top--;
                for(i=0;i<strlen(prod);i++){
                    top++;
                    stack[top] = prod[i];
                }
            }
        }
    }while(stack[top]!='$');
    if(stack[top]=='$' && input[inp]=='$'){
        printf("\n%c %c \n String is Accepted",stack[top],input[inp]);
    }else{
        printf("String is not Accepted");
    }
}
