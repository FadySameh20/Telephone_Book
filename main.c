#include "header.h"
#include "add.c"
#include "save.c"
#include "search.c"
#include "modify.c"
#include "quit.c"
#include "print.c"
#include "sortbyLname.c"
#include "sortbydob.c"
#include "delete.c"
#include "load.c"

int main()
{
    int choice=0;
    printf("\n-------------------------------------------");
    printf("WELCOME TO PHONEBOOK PROGRAM");
    printf("-------------------------------------------\n");
    printf("\nMENU:\n\n");
    printf("1.Press 1 to Load\t\t2.Press 2 to Search\n3.Press 3 to Add\t\t4.Press 4 to Delete\n5.Press 5 to Modify\t\t6.Press 6 to Print(Sort)\n7.Press 7 to Save\t\t8.Press 8 to Exit\n9.Press 9 to show Menu\n\n");
    load(temp,&tempcount);  // To initialize temp & checking for duplicates when adding a new contact
    deleteduplicate(temp,&tempcount);
    loadflag=0;
    while(choice!=8)
    {
        printf("\nChoose a Function:");
        inputchecker(&choice);
        switch(choice)
        {
        case 1:
            load(s,&count);
            deleteduplicate(s,&count);
            if(tempcount>0)
                printf("Data Loaded !!\n");
            break;
        case 2:
            search();
            break;
        case 3:
            add();
            break;
        case 4:
            del();
            break;
        case 5:
            modify();
            break;
        case 6:
            if(count==0)
            {
                printf("\nNothing to Print or Sort\n");
                break;
            }
            printf("\nHow do you want to sort:\n1.Sort by Last Name\n2.Sort by date of birth\n");
            printf("Please Enter Your Choice:");
            inputchecker(&choice);
            if(choice==1)
                sortbyLname();
            else if(choice==2)
                sortbydob();
            else
                printf("Wrong choice!!");
            print();
            break;
        case 7:
            saveflag=1;
            if(loadflag==0)
            {
                load(s,&count);
            }
            save();
            break;
        case 8:
            quit(&choice);
            if(choice!=1)
            {
                printf("---------------------------------------------------");
                printf("---------------------------------------------------\n");
            }
            break;
        case 9:
            printf("1.Press 1 to Load\t\t2.Press 2 to Search\n3.Press 3 to Add\t\t4.Press 4 to Delete\n5.Press 5 to Modify\t\t6.Press 6 to Print(Sort)\n7.Press 7 to Save\t\t8.Press 8 to Exit\n9.Press 9 to show Menu\n");
            break;
        default:
            printf("Wrong Choice.Please Try Again\n");
            break;
        }
    }
    return 0;
}
