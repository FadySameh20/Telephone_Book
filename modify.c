#include "header.h"

void modify()
{
    if(count ==0)
    {
        printf("\nThere is nothing to modify\n");
        return;
    }
    int i,z=0,flag=0,n=0,key;
    char *name1=malloc(20);
    printf("\nEnter last name: ");
    scanf("%s",name1);
    for(i=0; i<count; i++)
    {
        if(strcasecmp(s[i].lastname,name1)==0)
        {
            if(n==0)
            {
                printf("\nNumber\tFirst Name   Last Name\t  Date\t\tAddress\t\t\t  Email\t\t\t       Phone\n");
                n++;
            }
            z=i;
            printf("%2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].firstname,s[i].lastname,s[i].d.day,s[i].d.month,s[i].d.year);
            printf("%-20s\t  %-28s 03-%d\n",s[i].address,s[i].email,s[i].phonenum);
            flag++;
        }
    }
    free(name1);
    if(flag==0)
    {
        printf("Not Found\n");
        return;
    }
    n=0;
    while(flag>1)
    {
        char *name2=malloc(20);
        if(n==0)
            printf("\nPlease Enter Email(Users can't have same email):");
        else
            printf("Please Enter Valid Email from the previous list:");
        scanf("%s",name2);
        for(i=0; i<count; i++)
        {
            if(strcasecmp(s[i].email,name2)==0)
            {
                z=i;
                flag=0;
                break;
            }
        }
        free(name2);
        n++;
    }
    int m=tempcount;
    temp[m]=s[z];
    n=1;
    while(n!=2)
    {
        printf("\nModify:\n1.First Name\n2.Last Name\n3.Date\n4.Address\n5.E-mail\n6.Phone Number\n\nEnter Your Choice:");
        inputchecker(&key);
        if(key==1)
        {
            i=0;
            do
            {
                if(i==0)
                    printf("Please Enter First name:");
                else
                    printf("ERROR !! Please Enter Correct First Name:");
                scanf("%s",s[z].firstname);
                i++;
            }
            while(nameval(s[z].firstname)!=1);
            *(s[z].firstname+9)=0;
            strcpy(s[z].lastname,temp[m].lastname);
            s[z].d.day=temp[m].d.day;
            s[z].d.month=temp[m].d.month;
            s[z].d.year=temp[m].d.year;
            strcpy(s[z].address,temp[m].address);
            strcpy(s[z].email,temp[m].email);
            s[z].phonenum=temp[m].phonenum;
        }
        if(key==2)
        {
            getchar();
            printf("Please Enter Modified Last Name:");
            scanf("%s",s[z].lastname);
            while(nameval(s[z].lastname)!=1)
            {
                printf("Please Enter Correct Last Name:");
                scanf("%s",s[z].lastname);
            }
            *(s[z].lastname+9)=0;
            strcpy(s[z].firstname,temp[m].firstname);
            s[z].d.day=temp[m].d.day;
            s[z].d.month=temp[m].d.month;
            s[z].d.year=temp[m].d.year;
            strcpy(s[z].address,temp[m].address);
            strcpy(s[z].email,temp[m].email);
            s[z].phonenum=temp[m].phonenum;
        }
        else if(key==3)
        {
            printf("Please Enter Modified Day Month Year ,respectively:");
            inputchecker(&s[z].d.day);
            inputchecker(&s[z].d.month);
            inputchecker(&s[z].d.year);
             if(s[z].d.month==2)
                {
                    if(s[z].d.day>29)
                    {
                        printf("February shouldn't include more than 29 days\n");
                        s[z].d.day=35;
                    }
                }
            while(s[z].d.day>31 || s[z].d.day<0 || s[z].d.month<0 || s[z].d.month>12 ||s[z].d.year>2019 || s[z].d.year<1920)
            {
                printf("Please Enter Modified Day Month Year ,respectively:");
                inputchecker(&s[z].d.day);
                inputchecker(&s[z].d.month);
                inputchecker(&s[z].d.year);
                 if(s[z].d.month==2)
                {
                    if(s[z].d.day>29)
                    {
                        printf("February shouldn't include more than 29 days\n");
                        s[z].d.day=35;
                    }
                }
            }
        }
        else if(key==4)
        {
            getchar();
            printf("Please Enter Modified Address:");
            scanf("%[^\n]s",s[z].address);
            *(s[z].address+39)=0;
            int addressflag=addresssubstring(s[z].address);
            while(addressflag==0)
            {
                getchar();
                printf("Address mustn't contain \",\"\n");
                printf("Please Enter Correct Address:");
                scanf("%[^\n]s",s[z].address);
                *(s[z].address+39)=0;
                addressflag=addresssubstring(s[z].address);
            }
            strcpy(s[z].firstname,temp[m].firstname);
            strcpy(s[z].lastname,temp[m].lastname);
            s[z].d.day=temp[m].d.day;
            s[z].d.month=temp[m].d.month;
            s[z].d.year=temp[m].d.year;
            strcpy(s[z].email,temp[m].email);
            s[z].phonenum=temp[m].phonenum;
        }
        else if(key==5)
        {
            printf("Please Enter Modified Email:");
            scanf("%s",s[z].email);
            while(emailval(s[z].email)!=1 || substring(s[z].email,".com")==0 || duplicatechecker(s,z)==0)
            {
                printf("Please Enter Modified Email:");
                scanf("%s",s[z].email);
            }
            *(s[z].email+29)=0;
        }
        else if(key==6)
        {
            i=0;
            do
            {
                if(i==0)
                    printf("Please Enter Phone Number:03-");
                else
                    printf("Please Enter Valid Phone Number consisted of 7 Digits:03-");
                inputchecker(&s[z].phonenum);
                i++;
            }
            while(phoneval(s[z].phonenum)!=1);
        }
        while(getchar()!='\n');
        n=0;
        while(n>2 || n<1)
        {
            printf("Press 1 to continue modifying or Press 2 to return to menu:");
            inputchecker(&n);
        }
        temp[m]=s[z];
    }
    saveflag=0;
}
