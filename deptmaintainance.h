//dept maintainance code block
#include "deptcounterupdater.h"



//functn defn
extern void deptmaintainancecode();
void add_dept(int *);
void view_all_dept();




//program start
extern void deptmaintainancecode()
{   int deptCode;
    char temp[10],temp1[10];
    FILE *fp;
    //file that contains various counters
    fp=fopen("updt.txt","r");
    fscanf(fp,"%s %s",temp,temp1);
    //converting sting to integer
    deptCode=atoi(temp);
    fclose(fp);
    while(1)
    {   //clear screen
        system("cls");
        int choice;
         printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
        printf("\t\t*******************DEPARTMENT MAINTAINANCE MENU**************\n");
        printf("\t\t 1. Add Department\n");
        printf("\t\t 2. Print Department Details\n");
        printf("\t\t 3. Back\n");
        //choice input
        printf("\t\tEnter Your Choice:-");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:add_dept(&deptCode);
                   updateddepcounter(&deptCode);
                   break;
            case 2:system("cls");
                     printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
                     printf("\t\t***********************ALL DEPARTMENT***********************\n");
                    view_all_dept();
                    break;
            case 3:return;
        }//end switch
    }//end while
}//functn end

//fucntion to add department
void add_dept(int *deptCode)
{       //opening file that contain dept info and phno counter
        FILE *fp,*fp1;
        fp=fopen("dept.txt","a+");
        fp1=fopen("phnoupdater.txt","a+");
       tryAgain:

       system("cls");
        //inputting choice
        printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
        printf("\t\t**********************ADD DEPARTMENT************************\n");
        printf("\n\t\tENTER DEPARTMENT NAME:-");
        char name[16],name1[16],temp1[10];
        scanf("%s",name);

        //comapring 2 strings to prevent similarities
         while(fscanf(fp,"%s %s",name1,temp1)!=EOF)
        {   //checking if name already exists or not
            if(strcasecmp(name,name1)==0)
            {
                printf("\t\tERROR!!!!\nNAME ALREADY EXISTS\n");
                rewind(fp);
                  printf("\t\tpress any key to try again\n");
                getch();
                //loop to check again
                goto tryAgain;
            }
            else
            {
                continue;
            }//endif else
            
            
        }//end while 
        *deptCode= *deptCode + 1;
        int temp=1;
        //copying data to files
        printf("\n\t\tDEPARTMENT CODE:- %d",*deptCode);
        fprintf(fp,"%s %d\n",name,*deptCode);
        fprintf(fp1,"%d %d\n",*deptCode,temp);
        printf("\n\t\tpress any key to go back\n");
        getch();
        fclose(fp);
        fclose(fp1);
        //closing files
}
//fucntion end

    //function to display departtment
    void view_all_dept()
    {   //open file
        FILE *fp;
        fp=fopen("dept.txt","r");
        
       //display section
        char name1[16],deptCode[10];
        printf("|\tNAME\t|\tDEPARTMENT CODE\t|\n");
        printf("|===============|=======================|\n");
        while(fscanf(fp,"%s %s",name1,deptCode)!=EOF)
        {   
            printf("|%-15s|%-23s|\n",name1,deptCode);
        
        }
        //end while
        printf("\n\t\tpress any key to continue\n");
        getch();
        fclose(fp);
      
    }//fucntion end
