//Write a C/C++ -- program to Implement Lexical Analyzer

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int iskeyword(char buffer[]){
char keyword[32][10]={"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int i,flag=0;
for(i=0;i<32;i++){
    if(strcmp(keyword[i],buffer)==0){
        flag=1;
        break;
    }
}
return flag;
}
int main(){
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;
    fp=fopen("program.txt","r");
    if(fp==NULL){
        printf("error while opening the file");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF){
        for(i=0;i<6;i++){
            if(ch==operators[i]){
                printf("%c is operator\n",ch);
            }
        }
        if(isalnum(ch)){
            buffer[j++]=ch;
        }
        else if((ch==' '||ch=='\n')&&(j!=0)){
            buffer[j]='\0';
            j=0;
			if(iskeyword(buffer)==1)
				printf("%s is keyword\n",buffer);
			else
				printf("%s is identifier\n",buffer);
		}
    }
    fclose(fp);
    return 0;
}
/*
//PROGRAM.TXT
int main(){
int num1, num2;
num1=4;
num2=6;
return 0;
}

OUTPUT:
int is keyword
main is identifier
int is keyword
num1 is identifier
num2 is identifier
num1 is identifier
= is operator
4 is identifier
num2 is identifier
= is operator
6 is identifier
return is keyword
0 is identifier

*/
