#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count=0;//Counter for s
int tempcount=0;//counter for temp
int addflag=0;//Flag to know if we added another contact and flag is used when printing
int saveflag=0;//Flag to know if program is already saved or not
int loadflag=0;//Flag to know if program is already loaded or notz

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    char firstname[10];
    char lastname[10];
    date d;
    char address[40];
    char email[30];
    int phonenum;
} info;

info s[100];
info temp[100];

void load(info *p,int *anycount);

int duplicatechecker(info *s,int n)   //Compare with contacts recently added during program execution
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcasecmp(s[n].email,s[i].email)==0)
            return 0;
    }
    return 1;
}

void exchange(int i,int j)
{
    info temp1[300];
    temp1[i]=s[i];
    s[i]=s[j];
    s[j]=temp1[i];
}

int emailval(char *st)
{
    int n=strlen(st);
    int i,flag=0;

    for(i=0; i<n; i++)
    {
        if(st[i]=='@')
            flag++;
    }
    return flag;
}

int phoneval(int x)
{
    int m=x,i=0;
    while(m)
    {
        m=m/10;
        i++;
    }
    if(i==7)
        return 1;
    return 0;
}

int nameval(char *st)
{
    int i;
    for( i=0; i<strlen(st); i++)
    {
        if(isalpha(st[i])==0)
        {
            return 0;
        }
    }
    return 1;
}
int substring(char s1[], char s2[])
{
    int i,j,n=0,flag=0;
    for(i=strlen(s1)-4,j=0; i<strlen(s1) && flag==0; i++)
    {
        if(s1[i]==s2[j])
        {
            n=n+1;
            j++;
            if(n==strlen(s2))
            {
                flag=1;
                break;
            }
        }
        else
        {
            j=0;
            n=0;
        }
    }
    return flag;
}
int addresssubstring(char s1[])
{
    int i;
    for(i=0;i<strlen(s1);i++)
    {
            if(s1[i]==',')
                return 0;
    }
    return 1;
}
void deleteduplicate(info *p,int *n)
{
    int i,j,k;
    for(i=0; i<*n; i++)
    {
        for(j=i+1; j<*n;)
        {
            if(strcasecmp(p[i].email,p[j].email)==0)
            {
                for(k=j; k<*n; k++)
                {
                    exchange(k,k+1);
                }
                (*n)--;
            }
            else
                j++;
        }
    }
}
void inputchecker(int *choice)
{
    while(scanf("%d",choice)==0)
    {
        printf("Incorrect Entry\nPlease Try Again:");
        while(getchar()!='\n');
    }
}
#endif // HEADER_H_INCLUDED
