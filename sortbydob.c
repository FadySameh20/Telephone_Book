#include "header.h"

void sortbydob()
{
    int i,j;
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(s[i].d.year>s[j].d.year)
            {
                exchange(i,j);
            }
            else if(s[i].d.year==s[j].d.year)
            {
                if(s[i].d.month>s[j].d.month)
                {
                    exchange(i,j);
                }
                else if(s[i].d.month==s[j].d.month)
                {
                    if(s[i].d.day>s[j].d.day)
                    {
                        exchange(i,j);
                    }
                }
            }
        }
    }
}
