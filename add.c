#include"header.h"

void add()
{
    int flag=0;
    int i,j;
    while(flag==0)
    {
        i=0;
        printf("\nUser=%d\n",count+1);
        do
        {
            if(i==0)
                printf("Please Enter First name:");
            else
                printf("ERROR!!Please Enter Correct First Name:");
            scanf("%s",s[count].firstname);
            i++;
        }
        while(nameval(s[count].firstname)!=1);
        *(s[count].firstname+9)=0;
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Last name:");
            else
                printf("ERROR!!Please Enter Correct Last Name:");
            scanf("%s",s[count].lastname);
            i++;
        }
        while(nameval(s[count].lastname)!=1);
        *(s[count].lastname+9)=0;
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Day Month Year ,respectively:");
            else
                printf("ERROR!!Please Enter Correct Day Month Year ,respectively:");
            inputchecker(&s[count].d.day);
            inputchecker(&s[count].d.month);
            inputchecker(&s[count].d.year);
            if(s[count].d.month==2)
            {
                if(s[count].d.day>29)
                {
                    printf("February shouldn't include more than 29 days\n");
                    s[count].d.day=35;  //To Enter the loop once again
                }
            }
            i++;
        }
        while(s[count].d.day>31 || s[count].d.day<0 || s[count].d.month<0 || s[count].d.month>12 ||s[count].d.year>2019 || s[count].d.year<1920);
        getchar();
        printf("Please Enter Address:");
        scanf("%[^\n]s",s[count].address);
        *(s[count].address+39)=0;
        int addressflag=addresssubstring(s[count].address);
        while(addressflag==0)
        {
            getchar();
            printf("Address mustn't contain \",\"\n");
            printf("Please Enter Correct Address:");
            scanf("%[^\n]s",s[count].address);
            *(s[count].address+39)=0;
            addressflag=addresssubstring(s[count].address);
        }
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Email:");
            else
                printf("ERROR !! Please Enter Valid email:");
            scanf("%s",s[count].email);
            i++;
        }
        while(emailval(s[count].email)!=1 || substring(s[count].email,".com")==0);
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Phone Number:03-");
            else
                printf("Please Enter Valid Phone Number consisted of 7 Digits:03-");
            inputchecker(&s[count].phonenum);
            i++;
        }
        while(phoneval(s[count].phonenum)!=1);
        printf("\nLoading File To Check for Duplicates..........\n");
        flag=duplicatechecker(s,count);
        if(flag==0)   //Compare with contacts recently added during program execution
        {
            printf("This name has already been added\n");
            printf("Please Try Again\n");
        }
        if(flag==1)
        {
            for(j=0; j<tempcount; j++)  //Compare with contacts in files
            {
                if (strcasecmp(temp[j].email,s[count].email)==0)
                {
                    printf("%s %s already exists in file\n",s[count].firstname,s[count].lastname);
                    flag=0;
                    printf("Please Try Again\n");
                    break;
                }
            }
        }
    }
    printf("\n");
    saveflag=0;
    count++;
    addflag=1;
}
