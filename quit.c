#include "header.h"

void quit(int *choice)
{
    if(saveflag==0 && count!=0)
    {
        printf("Are You sure you want to Exit without saving?\n1.Yes\n2.Save & Exit\n3.Don't Exit\n");
        printf("\nPlease Enter Your Choice:");
        inputchecker(choice);
        if(*choice==1)
            *choice=8;
        else if(*choice==2)
        {
            save();
            *choice=8;
        }
        else if(*choice==3)
            *choice=1;
    }
    else
        *choice=8;
}
