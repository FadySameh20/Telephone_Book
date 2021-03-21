#include "header.h"

void sortbyLname()
{
    int i,j;
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcasecmp(s[i].lastname,s[j].lastname)==1)
            {
                exchange(i,j);
            }
        }
    }
}
