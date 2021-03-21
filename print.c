#include "header.h"

void print()
{
    int i;
    printf("\n===========================================================");
    printf("=============================================================\n");
    printf("Number\tFirst Name   Last Name\t  Date\t\tAddress\t\t\t  Email\t\t\t       Phone\n");
    printf("============================================================");
    printf("============================================================\n");
    for(i=0; i<count; i++)
    {
        printf("%-2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].firstname,s[i].lastname,s[i].d.day,s[i].d.month,s[i].d.year);
        printf("%-20s\t  %-28s 03-%d\n",s[i].address,s[i].email,s[i].phonenum);
    }
    printf("============================================================");
    printf("============================================================\n");
    saveflag=0;
}
