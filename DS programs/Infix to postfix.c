#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define size 25
int it=0;
char pop(char s[],int top){
	char item;
	item=s[top];
	return item;
}
void push(char s[],int top,char item){
	if(top<size){
		s[top]=item;
	}
	else{
		printf("\nThe stack is full");
	}
}
char nexttoken(char ch[]){

	return ch[it++];
}
int isp(char c){
	switch(c){
		case '+':
		case '-':return 1;
                break;
		case '*':
		case '/':return 2;
                break;
		case '^':return 3;
                break;
		case '(':return 0;
                break;
		case '#':return -1;
                break;
		default: return 0;
                break;
	}
}
int icp(char c){
	switch(c){
		case '+':
		case '-':return 1;
                break;
		case '*':
		case '/':return 2;
                break;
		case '^':return 3;
                break;
		case '(':return 4;
                break;
		case ')':return 5;
                break;
		case '#':return -1;
                break;
		default: return 0;
                break;
	}
}
void postfix(char p[],int p_top){
	int i,top=-1,br=0;
	char x,y,stack[size],ch[size];
	stack[top]='#';
	top++;
	printf("\nEnter the expression : ");
	scanf("%s",&ch);
	for(i=0; ch[i] != '\0'; i++)
    {
        if(ch[i] == '(')
            br++;
        else if(ch[i] == ')')
            br--;
    }
    if(br != 0)
    {
        printf("Unbalanced parenthesis..Kindly check your expression again.");
        return;
    }
	x=nexttoken(ch);
	printf("\nThe postfix form is : ");
	while(x!='\0'){
		if(isdigit(x))
        {
			printf("%c",x);
			p_top++;
			push(p,p_top,x);
		}
		else if(x==')')
		{
			while(stack[top]!='('){
				y=pop(stack,top);
				top--;
				printf("%c",y);
				p_top++;
				push(p,p_top,y);
			}
			y=pop(stack,top);
			top--;
		}
		else{
			while(isp(stack[top])>=icp(x)){
				y=pop(stack,top);
				top--;
				printf("%c",y);
				p_top++;
				push(p,p_top,y);
			}
			top++;
			push(stack,top,x);
		}
		x=nexttoken(ch);
	}
	while(top>0)
    {
		y=pop(stack,top);
		top--;
		printf("%c",y);
		p_top++;
		push(p,p_top,y);
	}
}
char evaluvate(char y,char x,char z){
	int a,b;
	a=y-'0';
	b=z-'0';
	switch(x){
		case '+':return ((a+b)+'0');
                break;
		case '-':return ((a-b)+'0');
                break;
		case '*':return ((a*b)+'0');
                break;
		case '/':return ((a/b)+'0');
                break;
		case '^':return ((pow(a,b))+'0');
                break;
	}
}
void eval(char ch[]){
	int top=-1;
	it=0;
	char x,stack[size],y,z;
	x=nexttoken(ch);
	while(x!='\0'){
		if(isdigit(x)){
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
		x=nexttoken(ch);
	}
	printf("\nThe evaluated expression is : %d",stack[top]-'0');
}
void main(){
	char p[size],y;
	int i,top=-1,ch;
	printf("\n\tMENU");
    printf("\n 1)INFIX TO POSTFIX AND EVALUATION \n 2)POSTFIX EVALUATION ");
    do{
        printf("\n Enter choice : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            postfix(p,top);
        }
        else if(ch == 2)
        {
            printf("Enter the postfix form : ");
            scanf("%s",p);
            eval(p);
        }
        printf("\n Do you want to continue ? (y/n) ");
        scanf("%s",&y);
    }while((y=='y')||(y=='Y'));
}
