//Write a Program to implement Top Down Parsing for a given
//Grammar.

#include<stdio.h>
#include<string.h>

char input[100];
int i,l;
int E(){
    if(T()){
        if(EP()){
            return 1;
        }
    }
    return 0;
}
int EP(){
    if(input[i] == '+'){
        i++;
        if(T()){
            if(EP()){
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

int T(){
    if(F()){
        if(TP()){
            return 1;
        }
    }
    return 0;
}
int TP(){
    if(input[i] == '*'){
		i++;
        if(F()){
            if(TP()){
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
int F(){
    if(input[i] == '('){
        i++;
        if(E()){
            if(input[i]==')'){
                i++;
                return 1;
            }
        }
        return 0;
    }else if( (input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z')){
        i++;
        return 1;
    }
    return 0;
}
int main(){
	printf("\n Recursive descent parsing for all following grammer\n");
	printf("\n E->TE'\n E'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/id\n");
	printf("Enter the string to be checked: ");
	scanf("%s",input);
	
	if(E()){
	    if(input[i+1] == '\0'){
	        printf("\nString is accepted");
	    }else{
	        printf("\nString is not accepted");
	    }
	}else{
	    printf("\nString is not accepted");
	}
	return 0;
}

/*
input: (a+b)*c
OUTPUT:
Enter the string to be checked: (a+b)*c

String is accepted
*/
