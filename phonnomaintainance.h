//TELEPHONE DIRECTORY MAINTAINANCE 
#include "phnoenerator.h"



//fucnt decl
extern void phonnomaintainance();
void add_number();


extern void phonnomaintainance()
{   while(1)
    {   system("cls");
    //inputting choiec
        int choice;
        printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
        printf("\t******************PHONENO MAINTAINANCE MENU*******************\n");
         printf("\t\t 1. Add Contact\n");
        printf("\t\t  2. Back\n");
    
        printf("\t\tEnter Your Choice:-");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:add_number();
               break;
    
            case 2:return;
        }//end switch
    }//end while
}//fucntion end


void add_number()
{   //open the files
    FILE *fp,*fp1;
    fp=fopen("emp.txt","r+");
    fp1=fopen("temp.txt","w");
    there:
    system("cls");
     printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
    printf("\t\t***************************ADD NUMBER*************************\n");
    printf("\n\t\tENTER  EMPLOYEE CODE    :-");
    char code[20];
    scanf("%s",code);
    char name[25],empCode[20],depCode[20],loc[20],ph[10],test[10];
    int wordExist=0;
    //checking for valid employee code
    while(fscanf(fp,"%s %s %s %s %s",name,empCode,depCode,loc,ph)!=EOF)
    {  
        if(strcmp(code,empCode)==0)
        {
            wordExist=1;
        }//end if
    }//end while

    if(wordExist==1)
    {   rewind(fp);
        goto here;
    }
    else
    {
        printf("\t\tCode does not exist\n");
        printf("\t\tpress any key to continue\n");
        getch();
        rewind(fp);
        goto there;
    }//end ifelse

    here:
    while(fscanf(fp,"%s %s %s %s %s",name,empCode,depCode,loc,ph)!=EOF)
    {   if(strcmp(code,empCode)==0)
            {  
                if(strcmp(ph,"0")==0)
                {
                 char temp[8],temp1[10];
                printf("\n\t\tLOCATION   :- %s\n",loc);
                printf("\n\t\tDEPARTMENT CODE  :- %s\n",depCode);
                strcpy(temp1,depCode);
                strcpy(temp,phonenogenerator(depCode));
                printf("\n\t\tTELEPHONE NO ALLOCATED IS :- %s\n",temp);
                 fprintf(fp1,"%s %s %s %s %s\n",name,empCode,temp1,loc,temp);
                 continue;
                }
                else
                {
                   fprintf(fp1,"%s %s %s %s %s\n",name,empCode,depCode,loc,ph);
                     printf("\t\tPHONE NO IS ALREADY ALLOCATED\n");
                     printf("\t\tenter any key to CONTINUE\n");
                     getch();
                     phonnomaintainance();
                     
                }//end if else

             }
             else
            {
                 fprintf(fp1,"%s %s %s %s %s\n",name,empCode,depCode,loc,ph);
            }//end ifelse
    
       
    }//end while
    fclose(fp1);
    fclose(fp);
    //close files
    //reopen files
    fp=fopen("emp.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s",name,empCode,depCode,loc,ph)!=EOF)
    {
        fprintf(fp,"%s %s %s %s %s\n",name,empCode,depCode,loc,ph);
    }//end while
     fclose(fp);
    fclose(fp1);
    //closing the fi;e
    remove("temp.txt");
    //deleting temp file
    printf("\t\tpress any key to continue\n");
    getch();
}
//function end

