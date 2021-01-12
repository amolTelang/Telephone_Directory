//EMPLOYEE MAINTAINANCE SYSTEM
#include "employeeCodeUpdater.h"

//functn delc
extern void employeemaintainancecode();
void add_emp(int *);
void view_all_emp();

//program start
extern void employeemaintainancecode()
{   //clear screen
    system("cls");
    int empCode;
    char temp[10],temp1[10];
    //opening file
    FILE *fp;
    fp=fopen("updt.txt","r");
    fscanf(fp,"%s %s",temp1,temp);
    empCode=atoi(temp);
    fclose(fp);
    while(1)
    {   system("cls");
        //inputting choice
        int choice;
        printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE***********\n");
        printf("\t\t******************EMPLOYEE MAINTAINANCE MENU*****************\n");
        printf("\t\t 1. Add Employee\n");
        printf("\t\t 2. Print Employee Details\n");
        printf("\t\t 3. Back\n");
    
        printf("\t\tEnter Your Choice:-");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:add_emp(&empCode);
                    updateEmpCode(&empCode);
               break;
            case 2:view_all_emp();
               break;
            case 3:return;
        }
    }
}


void add_emp(int *empCode)
{   //sstem clear
    system("cls");
    char ph[10]="0";
    FILE *fp;
    //openong file
    fp=fopen("emp.txt","a+");
    tryAgain:
    system("cls");
     printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
     printf("\t\t**********************ADD EMPLOYEE**************************\n");
    printf("\n\t\tENTER EMPLOYEE NAME    :-");
    char name[25],name1[25],temp1[10],temp2[10],temp3[10],temp4[10];
    scanf("%s",name);
    while(fscanf(fp,"%s %s %s %s %S",name1,temp1,temp2,temp3,temp4)!=EOF)
        {
            if(strcasecmp(name,name1)==0)
            {
                printf("\t\tERROR!!!!\nNAME ALREADY EXISTS\n");
                rewind(fp);
                printf("\t\tpress any key to TRY AGAIN\n");
                getch();

                //loop to chek again
                goto tryAgain;
            }
            else
            {
                continue;
            }//end if else
            
            
        } //end while
     //updating counter   
    *empCode=*empCode+1;
    //displayingt the data
     printf("\n\t\tEMPLOYEE CODE:- %d\n",*empCode);
     printf("================================================================\n");
     printf("\t\tselect any one department\n\n");
     view_all_dept();
     printf("================================================================\n");
     printf("\t\tenter your selected department code :-");
     int deptCode;
     scanf("%d",&deptCode);
     char loc[5];
     printf("\n\t\tEnter a LOCATON (!!!WARNING!!DO NOT EXCEED 5 CHARACTERS!!!) :-");
     scanf("%s",loc);

     fprintf(fp,"%s %d %d %s %s\n",name,*empCode,deptCode,loc,ph);

    printf("\n\t\tpress any key to go back\n");
    getch();
    fclose(fp);
    //file close
}//function end


//fucntion to view all employees 
void view_all_emp()
{
    FILE *fp;
    fp=fopen("emp.txt","r");
    system("cls");
     printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
    printf("\t\t**********************ALL EMPLOYEES**************************\n");
    printf("|\tNAME\t\t  |\tEMPID\t       |\tDEPID\t    |\tLOCATION\t |\tPHNO\t      |\n");
    printf("|=========================|====================|====================|====================|====================|\n");
    char name1[25],empCode[10],deptCode[10],loc[5],ph[10];
    while(fscanf(fp,"%s %s %s %s %s",name1,empCode,deptCode,loc,ph)!=EOF)
    {   
        printf("|%-25s|%-20s|%-20s|%-20s|%-20s|\n",name1,empCode,deptCode,loc,ph);
     
    }//end while
    printf("\n\t\tpress any key to go back\n");
    getch();
    fclose(fp);
    return;
}
//end function


