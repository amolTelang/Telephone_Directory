//c program to create a telephone directory maintainance system using files concept to understand the leisure of DBMS 
//Authors :-NAME-Amol Telang   USN:2sd18cs012
//          NAME-Sahil Naik    USN:2sd18cs084
//..................................................................................................................





//pre-processor directive
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<strings.h>
#include<windows.h>                     //..............................................helps to talk to the windwos APIs on minGW compiler
#include "deptmaintainance.h"           //.............................................department maintainance code block
#include "empmaintainance.h"            //.............................................employee maintainance code block
#include "phonnomaintainance.h"        //..............................................phone no directory maintainance code block
#include "teleenquiry.h"               //...............................................telephone enquiry code block


//function defn
int checkfile(char []);
int loginScr();

//main function
void main()
{
   //call for login screen 
    if(loginScr()==1)
    { 
        //gets called after correct pssword is entered
        while(1)
        {   //start
            system("cls");
            printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
            printf("\t\t*************************MAIN MENU**************************\n");
            printf("\t\t 1. DEPARTMENT MAINTENANCE\n");
            printf("\t\t 2. EMPLOYEE MAINTENANCE\n");
            printf("\t\t 3. TELEPHONE DIRECTORY MAINTENANCE\n");
            printf("\t\t 4. TELEPHONE ENQUIRY MENU\n");
            printf("\t\t 5. EXIT\n");
            printf("\t\tEnter Your Choice:-");
            int option;
            scanf("%d",&option);
            //function call for each of the option
            switch(option)
            {
                case 1:deptmaintainancecode();
                    break;
                case 2:employeemaintainancecode();
                   break;
                case 3:phonnomaintainance();
                   break;
                case 4:telenq();
                   break;
                case 5:exit(0);
            }//end of switch
        }//end of while
    }//end if
}
//end of function


//login screen function
int loginScr()
{  //default password is 0000
    char p[20];
    int n=3;
    //loop for password entrance
    flag:
    system("cls");
    printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
    printf("\t\t**************************LOGIN*****************************\n");
    printf("\n\t\tENTER EMPLOYEE ID:");
    scanf("%s", p);
    fflush(stdout);


     if(n>0)
     {    //password checker
          if(strcmp(p,"0000")==0)
          { 
            printf("\n\t\tsuccessfully LOGGED IN\n");
            printf("\t\tpress any key to ENTER\n");
            getch();
            return 1;
          }
          else if(checkfile(p)==1)
          {
            printf("\t\tsuccessfully LOGGED IN\n\n");
            printf("\t\tpress any key to ENTER\n");
            getch();
            return 1;
          }
          else
          { 
            
            printf("\t\t!!!!INCORRECT PASSWORD!!!!\n\n");
            n--;
            printf("\t\tyou have %d attempts REMAINING\n\n",n);
            printf("\t\tpress any key to CONTINUE......\n");
            getch();
            if(n==0)
            {
               exit(0);
            }

            goto flag;
          }//end if
      }//end if     
}//end if
//function end



//function that checks the file for emp code
int checkfile(char pass[20])
{ char temp1[20],temp2[20],temp3[20],temp4[20],temp5[20];
   FILE *fp;
   fp=fopen("emp.txt","r");
   //code to compare imput and emp ID
   while(fscanf(fp,"%s %s %s %s %s",temp1,temp2,temp3,temp4,temp5)!=EOF)
   {
      if(strcmp(pass,temp2)==0)
      {
        //found
        return 1;
      }//end if

   }//end while
   fclose(fp);
   return 0;
}//function end
