#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>
#include <math.h>
#define size 50
int it=0;
//fumction to pop an element
char pop(char s[50],int top){
	char item;
	item=s[top];
	return item;
}
//function to push an element
void push(char s[50],int top,char item){
	if(top<size){
		s[top]=item;
	}
	else{
		printf("\nThe stack is full");
	}
}
//this function returns the next character
char nexttoken(char ch[50]){
	
	return ch[it];
	//it++;
}
//this function contains the in-stack priority
int isp(char c){
	switch(c){
		case '+':
		case '-':return 1;break;
		case '*':
		case '%':
		case '/':return 2;break;
		case '^':return 3;break;
		case '(':return 0;break;
		case '#':return -1;break;
		default: return -1;break;
	}
}
//this function returns the incoming priority
int icp(char c){
	switch(c){
		case '+':
		case '-':return 1;break;
		case '*':
		case '%':
		case '/':return 2;break;
		case '^':return 3;break;
		case '(':return 4;break;
		case ')':return 5;break;
		case '#':return -1;break;
		default: return -1;break;
	}
}
//this function gives the postfix form
void postfix(char a[50],int a_top){
	int i,top=0,oc=0,cc=0;
	char x,y,stack[50],ch[50];
	//stack[top]='#';
	//top++;
	printf("\nEnter the Expression");
	printf("\nThe operands are from 0-9 and operators are +,-,*,/,^\n");
	scanf("%s",ch);
	for(i=0;ch[i]!='\0';i++){
		if(ch[i]=='(')
			oc++;
		else if(ch[i]==')')
			cc++;
	}
	if(oc==cc){
		x=nexttoken(ch);
		printf("\nThe postfix form is:\t");
		while(x!='\0'){
			if(isdigit(x)!=0||isalpha(x)!=0){
				//printf("%c",x );
				a_top++;
				push(a,a_top,x);
			}
			else if(x==')'){
				while(stack[top]!='('){
					y=pop(stack,top);
					top--;
					//printf("%c",y);
					a_top++;
					push(a,a_top,y);
				}
				y=pop(stack,top);
				top--;
			}
			else{
				while(isp(stack[top])>=icp(x)){
					y=pop(stack,top);
					top--;
					//printf("%c",y);
					a_top++;
					push(a,a_top,y);
				}
				top++;
				push(stack,top,x);
			}
			it++;
			x=nexttoken(ch);
		}
		while(top>0){
			y=pop(stack,top);
			top--;
			//printf("%c",y);
			a_top++;
			push(a,a_top,y);
		}
	}
	//return a_top;
	else{
		printf("\nThe expression is invalid");
	}
}
//this function returns the value after performing the operation
char evaluvate(char y,char x,char z){
	int a,b;
	a=y-'0';
	b=z-'0';
	switch(x){
		case '+':return ((a+b)+'0');break;
		case '-':return ((a-b)+'0');break;
		case '*':return ((a*b)+'0');break;
		case '/':return ((a/b)+'0');break;
		case '^':return ((pow(a,b))+'0');break;
		case '%':return ((a%b)+'0');break;
	}
}
//this function performs the evaluvation and returns the final value
void eval(char ch[50]){
	int top=-1;
	it=0;
	char x,stack[50],y,z;
	x=nexttoken(ch);
	while(x!='\0'){
		if(isdigit(x)!=0){
			top++;
			push(stack,top,x);
		}
		else{
			z=pop(stack,top);
			top--;
			y=pop(stack,top);
			top--;
			y=evaluvate(y,x,z);
			top++;
			push(stack,top,y);
		}
		it++;
		x=nexttoken(ch);
	}
	printf("\nThe result of the Expression is \t%d",stack[top]-'0');
}
//main function
int main(){
	char a[50],ch;
	int i,a_top=-1,opt;
	/*a_top=postfix(a,a_top);
	//printf("\n%s",a);
	eval(a);*/
	//do{
		printf("\nMENU\n1)Convert to postfix\n2)Evaluvate the expression\nEnter your choise\t");
		scanf("%d",&opt);
		switch(opt){
			case 1:{
				postfix(a,a_top);
				printf("\n %s",a);
				break;
			}
			case 2:{
				//postfix(a,a_top);
				printf("\nEnter the postfix expression:\t");
				scanf("%s",a);
				eval(a);
				break;
			}
			default:printf("\nInvalid Entry");
		}
	//	printf("\nDo you want to continue,Press y to continue\t");
	//	scanf(" %s",&ch);
	//}while(ch=='y'||ch=='Y');
	getch();
}