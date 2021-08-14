#include<stdio.h>
#include<stdlib.h>
struct Poly
{
    int coeff;
    int exp;
    struct Poly *link;
};
void display(struct Poly *head)
{
    struct Poly *temp = head;
    while(temp->link != NULL)
    {
        printf("%dx^%d + ",temp->coeff,temp->exp);
        temp = temp->link;
    }
    printf("%dx^%d",temp->coeff,temp->exp);
}
struct Poly * create_node(int coeff, int exp)
{
    struct Poly *temp = (struct Poly *) malloc(sizeof(struct Poly));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->link=NULL;
    return(temp);
}
struct Poly * create_Poly(struct Poly *head , int total)
{
    int t = 0,coeff,exp;
    struct Poly *current = head,*temp2 = current;
    while(t<total)
    {
        printf("\n Enter the coefficient : ");
        scanf("%d" , &coeff);
        printf("\n Enter the power of x :");
        scanf("%d" , &exp);
        struct Poly * temp = create_node(coeff , exp);
        if(current == NULL)
        {
            current = temp;
            temp2 = current;
        }
        else
        {
            current->link = temp;
            current = current->link;
            current = temp;
        }
        ++t;
    }
    return temp2;
}
struct Poly * Polyadd(struct Poly *head_a ,struct Poly *head_b ,struct Poly *head_c)
{
    struct Poly *temp_a = head_a,*temp_b = head_b,*temp_c = head_c,*temp_c2 = NULL;
    struct Poly *temp;
    int sum;
    while (temp_a!=NULL && temp_b!=NULL)
    {
        if(temp_a->exp > temp_b->exp)
        {
            temp = create_node(temp_a->coeff , temp_a->exp);
            if(temp_c2 == NULL)
            {
                temp_c = temp;
                temp_c2 = temp_c;
            }
            else
            {
                temp_c->link = temp;
                temp_c = temp_c->link;
            }
            temp_a = temp_a->link;
        }
        else if(temp_a->exp < temp_b->exp)
        {
            temp = create_node(temp_b->coeff , temp_b->exp);
            if(temp_c2 == NULL)
            {
                temp_c = temp;
                temp_c2 = temp_c;
            }
            else
            {
                temp_c->link = temp;
                temp_c = temp_c->link;
            }
            temp_b = temp_b->link;
        }
        else
        {
            sum = temp_a->coeff + temp_b->coeff;
            temp = create_node(sum , temp_b->exp);
            if(temp_c2 == NULL)
            {
                temp_c = temp;
                temp_c2 = temp_c;
            }
            else
            {
                temp_c->link = temp;
                temp_c = temp_c->link;
            }
            temp_b = temp_b->link;
            temp_a = temp_a->link;
        }
    }
    while(temp_a != NULL)
    {
            temp = create_node(temp_a->coeff , temp_a->exp);
            if(temp_c2 == NULL)
            {
                temp_c = temp;
                temp_c2 = temp_c;
            }
            else
            {
                temp_c->link = temp;
                temp_c = temp_c->link;
            }
            temp_a = temp_a->link;
    }
    while(temp_b!=NULL)
    {
        temp = create_node(temp_b->coeff , temp_b->exp);
        if(temp_c == NULL)
        {
            temp_c = temp;
            temp_c2 = temp_c;
        }
        else
        {
            temp_c->link = temp;
            temp_c = temp_c->link;
        }
        temp_b = temp_b->link;
    }
     return temp_c2;
}
struct Poly * PolyMul(struct Poly * head_a ,struct Poly * head_b , struct Poly * head_c)
{
    struct Poly *temp_a = head_a, *temp_b = head_b, *temp_c = head_c, *temp_c2 = NULL,*temp,*temp1,*temp2=NULL;
    struct Poly *finalp = NULL;
    int max_power;
    int min_power;
    int i;
    int sum=0;
    while (temp_a!=NULL)
    {
        temp_b = head_b;
        while (temp_b!=NULL)
        {
            temp = create_node(temp_a->coeff*temp_b->coeff , temp_a->exp+temp_b->exp);
            if(temp_c2 == NULL)
            {
                temp_c = temp;
                temp_c2 = temp_c;
                max_power = temp_c2->exp;
                min_power = temp_c2->exp;
            }
            else
            {
                temp_c->link = temp;
                temp_c = temp_c->link;
                if(max_power < temp_c->exp)
                    max_power = temp_c->exp;
                if(min_power > temp_c ->exp)
                    min_power = temp_c->exp;
            }
            temp_b = temp_b->link;
        }
        temp_a = temp_a->link;
    }
     for(i=max_power ; i>=min_power ; i--)
     {
        temp = temp_c2;
        sum = 0;
        while(temp!=NULL)
        {
            if(temp->exp == i)
                sum += temp->coeff;
            temp = temp->link;
        }
        if(temp2 == NULL)
        {
            temp1 = create_node(sum,i);
            temp2 = temp1;
            finalp = temp2;
        }
        else
        {
            temp1 = create_node(sum,i);
            temp2->link = temp1;
            temp2 = temp2->link;
        }
    }
    return finalp;
}
void main()
{
    struct Poly *head_a = NULL,*head_b = NULL,*head_c = NULL;
    int n,cho;
    char ch;
    printf("Enter the number of elements in the first polynomial a :");
    scanf("%d" ,&n);
    head_a = create_Poly(head_a , n);
    printf(" \n Elements in a :");
    display(head_a);
    printf(" \nEnter the number of elements in the second polynomial b :");
    scanf("%d" ,&n);
    head_b = create_Poly(head_b , n);
    printf(" \n Elements in b :");
    display(head_b);
    printf("\n\t\t\t MENU \n 1. Addition \n 2. Multiplication ");
    do
    {
        printf("\n Enter Your Choice : ");
        scanf("%d" , &cho);
        switch (cho)
        {
        case 1 :printf("\nSum :");
                head_c =  Polyadd( head_a , head_b , head_c);
                display(head_c);
                break;
        case 2 : printf("\nProduct : ");
                head_c = PolyMul(head_a , head_b , head_c);
                display(head_c);
                break;
        default: printf("\nPlease enter valid choice\n");
            break;
        }
        printf("\n Do you want to continue");
        scanf("%s" , &ch);
    }while (ch == 'y' || ch == 'Y');
}

