#include<stdio.h>
struct Poly
{
    int coeff;
    int exp;
};
void display(struct Poly a[],int n)
{
    int i=0;
    while(i<n)
    {
        printf("%dx^%d",a[i].coeff,a[i].exp);
        if(i<n-1)
            printf(" + ");
        i++;
    }
}
void PolyMultiply(struct Poly a[],struct Poly b[],int a_count, int b_count)
{
   int i,j,a_terms, b_terms, c_terms=0,max=a[0].exp,min=a[0].exp,p_terms=0;
   struct Poly c[40],p[40];
   for(a_terms=0; a_count>a_terms; a_terms++)
       for(b_terms=0;b_count>b_terms; b_terms++)
       {
           c[c_terms].coeff = b[b_terms].coeff * a[a_terms].coeff;
           c[c_terms].exp = b[b_terms].exp + a[a_terms].exp;
           if(max < c[c_terms].exp)
            max = c[c_terms].exp;
           if(min > c[c_terms].exp)
            min = c[c_terms].exp;
           c_terms++;
       }
    for(i=max; i>=min; i--)
    {
        p[p_terms].coeff = 0;
        for(j=0; j<c_terms; j++)
        {
            if(i == c[j].exp)
            {
                p[p_terms].coeff += c[j].coeff;
                p[p_terms].exp = c[j].exp;
            }
        }
        p_terms++;
    }

    display(p,p_terms);
}
void PolyAdd(struct Poly a[],struct Poly b[], int a_count, int b_count)
{
    int a_terms=0, b_terms=0, c_terms=0;
    struct Poly c[40];
    while((a_terms<a_count)&&(b_terms<b_count))
    {
        if(a[a_terms].exp > b[b_terms].exp)
        {
            c[c_terms].coeff = a[a_terms].coeff;
            c[c_terms].exp = a[a_terms].exp;
            a_terms++;
        }
        else if(a[a_terms].exp < b[b_terms].exp)
        {
            c[c_terms].coeff = b[b_terms].coeff;
            c[c_terms].exp = b[b_terms].exp;
            b_terms++;
        }
        else
        {
            c[c_terms].coeff = a[a_terms].coeff + b[b_terms].coeff;
            c[c_terms].exp = a[a_terms].exp;
            a_terms++;
            b_terms++;
        }
        c_terms++;
    }
    for(;a_terms < a_count; a_terms++, c_terms++)
    {
        c[c_terms].coeff = a[a_terms].coeff;
        c[c_terms].exp = a[a_terms].exp;
    }
    for(;b_terms < b_count; b_terms++, c_terms++)
    {
        c[c_terms].coeff = b[b_terms].coeff;
        c[c_terms].exp = b[b_terms].exp;
    }
    display(c, c_terms);
}
void main()
{
    struct Poly p[20],q[20];
    int i,n,m,ch;
    char cho;
    printf("How many terms are there in the first polynomial function: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Coefficient of term no. %d :",i+1);
        scanf("%d",&p[i].coeff);
        printf("Enter exponent of term no. %d :",i+1);
        scanf("%d",&p[i].exp);
    }
    printf("How many terms are there in the second polynomial function: ");
    scanf("%d",&m);
    for(i=0; i<m; i++)
    {
        printf("Enter Coefficient of term no. %d :",i+1);
        scanf("%d",&q[i].coeff);
        printf("Enter exponent of term no. %d :",i+1);
        scanf("%d",&q[i].exp);
    }
    do
    {
        printf("\n\t\tMENU\n 1)Add \n 2)Multiply \n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        if(ch == 1)
        {
            PolyAdd(p,q,n,m);
        }
        else if(ch == 2)
        {
            PolyMultiply(p,q,n,m);
        }
        else
            printf("Enter valid choice");
        printf("\nDo you want to continue ?(y/n)");
        scanf("%s",&cho);
    }while(cho == 'y' || cho == 'Y');
}

