#include "header.h"

void del()
{
    if(count ==0)
    {
        printf("\nThere is Nothing to delete\n");
        return;
    }
    char key1[30];
    char key2[30];
    printf("\nPlease Enter Last name:");
    scanf("%s",key1);
    printf("Please Enter First Name:");
    scanf("%s",key2);
    int i,z,n=0,flag=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(s[i].lastname,key1)==0 && strcasecmp(s[i].firstname,key2)==0)
        {
            if(n==0)
            {
                printf("\nNumber\tFirst Name   Last Name\t  Date\t\tAddress\t\t\t  Email\t\t\t       Phone\n");
                n++;
                z=i;
            }
            printf("%2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].firstname,s[i].lastname,s[i].d.day,s[i].d.month,s[i].d.year);
            printf("%-20s\t  %-28s 03-%d\n",s[i].address,s[i].email,s[i].phonenum);
            flag++;
        }
    }
    if(flag==1)
    {
    exchange(z,count-1);
    count--;
    }
    n=0;
    while(flag>1)
    {
        char *email=malloc(20);
        if(n==0)
            printf("\nPlease Enter Email(Users can't have same email):");
        else
            printf("Please Enter Valid Email from the previous list:");
        scanf("%s",email);
        for(i=0; i<count; i++)
        {
            if(strcasecmp(s[i].email,email)==0)
            {
                exchange(i,count-1);
                count--;
                flag=1;
                break;
            }
        }
        free(email);
    }
    if(flag==1)
        printf("Deleted\n");
    else if(flag==0)
        printf("Not Found\n");
    saveflag=0;   //If we added a new contact and chose exit the quit function will ask either we want to save this contact or not
}
