#include "header.h"

void save()
{
    if(count==0)
    {
        printf("\nNo Data To Save\n");
        return;
    }
    FILE *fp;
    fp=fopen("data.txt","w");//append in case of adding contacts
    if(fp==NULL)
    {
        printf("File doesn't exist\n");
        exit(-1);
    }
    int i;
    if(addflag==1 || loadflag==1) //Here contacts can be modified ,sorted and deleted before saving to file
    {
        for(i=0; i<count; i++)
        {
            fprintf(fp,"%s,%s,%d-%d-%d,",s[i].lastname,s[i].firstname,s[i].d.day,s[i].d.month,s[i].d.year);
            fprintf(fp,"%s,%s,03-%d",s[i].address,s[i].email,s[i].phonenum);
            fprintf(fp,"\n");
        }
    }
    addflag=0;
    fclose(fp);
}
