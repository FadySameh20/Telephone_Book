#include "header.h"

void search()
{
    if(count ==0)
    {
        printf("\nNothing to Search for\n");
        return;
    }
    char key1[20];
    char key2[20];
    char key3[20];
    char key4[20];
    char key5[20];
    char key6[20];
    char key7[20];
    char key8[20];
    int z,d,y,m;
    printf("\nMulti-Search");
    getchar();
    printf("\nPlease Enter First Name :");
    gets(key1);
    printf("Please Enter Last Name:");
    gets(key2);
    printf("Please Enter Email:");
    gets(key3);
    printf("Please Enter Address:");
    gets(key4);
    printf("Please Enter Phone Number: 03-");
    gets(key5);
    printf("Please Enter day of Birth:");
    gets(key6);
    printf("Please Enter Month of Birth:");
    gets(key7);
    printf("Please Enter Year of Birth:");
    gets(key8);
    d=atoi(key6);
    m=atoi(key7);
    y=atoi(key8);
    z=atoi(key5);
    if(strcasecmp(key1,"")==0 && strcasecmp(key2,"")==0 && strcasecmp(key3,"")==0 && strcasecmp(key4,"")==0&& strcasecmp(key5,"")==0 && strcasecmp(key6,"")==0 && strcasecmp(key7,"")==0&&strcasecmp(key8,"")==0)
    {
        printf("Blank Search!!\n");
        return;
    }
    int i,n=0,flag=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(s[i].firstname,key1)==0 || strcasecmp(key1,"")==0)
            if(strcasecmp(s[i].lastname,key2)==0 || strcasecmp(key2,"")==0)
                if(strcasecmp(s[i].email,key3)==0 || strcasecmp(key3,"")==0)
                    if(strcasecmp(s[i].address,key4)==0 || strcasecmp(key4,"")==0)
                        if(z==s[i].phonenum || strcasecmp(key5,"")==0)
                            if((d==s[i].d.day && m==s[i].d.month && y==s[i].d.year )||(strcasecmp(key6,"")==0||strcasecmp(key7,"")==0||strcasecmp(key8,"")==0))
                            {
                                if(n==0)
                                {
                                    printf("\nNumber\tFirst Name   Last Name\t  Date\t\tAddress\t\t\t  Email\t\t\t       Phone\n");
                                    n++;
                                }
                                z=i;
                                printf("%2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].firstname,s[i].lastname,s[i].d.day,s[i].d.month,s[i].d.year);
                                printf("%-20s\t  %-28s 03-%d\n",s[i].address,s[i].email,s[i].phonenum);
                                flag=1;
                            }

    }
    if(flag==0)
        printf("Not Found\n");
}

