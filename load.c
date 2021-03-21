#include "header.h"

void load(info *p,int *anycount)   //anycount is a pointer to change the value of either count or tempcount
{
    if(loadflag==1)
    {
        return;
    }
    FILE *fp;
    fp=fopen("data.txt","r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%[^,],%[^,],%d-%d-%d,",p[*anycount].lastname,p[*anycount].firstname,&p[*anycount].d.day,&p[*anycount].d.month,&p[*anycount].d.year);
            fscanf(fp,"%[^,],%[^,],03-%d\n",p[*anycount].address,p[*anycount].email,&p[*anycount].phonenum);
            if(strcasecmp(p[*anycount].lastname,"")==0 && saveflag==0)
            {
                printf("File is empty\n");
                fclose(fp);
                return;
            }
            if(nameval(p[*anycount].lastname)!=1 || nameval(p[*anycount].firstname)!=1 || emailval(p[*anycount].email)!=1 || substring(p[*anycount].email,".com")==0 ||phoneval(p[*anycount].phonenum)!=1 || p[*anycount].d.day>31 || p[*anycount].d.day<0 || p[*anycount].d.month<0 || p[*anycount].d.month>12 ||p[*anycount].d.year>2019 || p[*anycount].d.year<1920)
            {
                printf("File Contains invalid data\n");
                exit(-1);
            }
            (*anycount)++;
        }
    }
    else
    {
        printf("File doesn't exist\n");
        exit(-1);
    }
    fclose(fp);
    loadflag=1;
}
