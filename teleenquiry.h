//telephone enquiry
//contains searching of names fucntions
extern void telenq();
void searchByPhno();
void searchByName();


extern void telenq()
{	
	
	while(1)
	{
		system("cls");
         printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
		printf("\t\t*******************TELEPHONE ENQUIRY MENU********************\n");
		int choice;
		printf("\t\t 1.SEARCH BY NAME\n");
		printf("\t\t 2.SEARCH BY PH NUMBER\n");
		printf("\t\t 3.BACK\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:searchByName();
					break;
			case 2:searchByPhno();
					break;
			case 3:return;
		}
	}
}

void searchByName()
{
	FILE *fp,*fp1;
    fp=fopen("emp.txt","r");
    //fp1=fopen("empphno.txt","r");
    system("cls");
     printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n");
     printf("\t\t**********************SEARCH USING NAME*********************\n");
        printf("\n\t\tENTER EMPLOYEE NAME:-");
        char name[25],name1[25],empid[20],depid[20],loc[5],phno[20];
        scanf("%s",name);

        //comapring 2 strings
         while(fscanf(fp,"%s %s %s %s %s",name1,empid,depid,loc,phno)!=EOF)
        {
            if(strcasecmp(name,name1)==0)
            {   printf("\n\t\t======================================\n");
                printf("\t\tEMPLOYEE NAME          :- %s\n",name1);
                printf("\t\tEMPLOYEE ID            :- %s\n",empid);
                printf("\t\tEMPLOYEE DEPARTMENT ID :- %s\n",depid);
                printf("\t\tEMPLOYEE LOC           :- %s\n",loc);
                printf("\t\tEMPLOYEE PHONE NUMBER  :- %s\n",phno);
                printf("\t\t======================================\n");
                fclose(fp);
                printf("\t\tpress any key to continue\n");
                getch();
                return;
            }
            else
            {
                continue;
            }
            
            
        }
        fclose(fp);
        printf("\t\t!!!ERROR NAME DOES NOT EXIST\n");
        getch();
        printf("\t\tPress any key to go back\n");
        return;
        
}
void searchByPhno()
{
	FILE *fp,*fp1;
        fp=fopen("emp.txt","r");
        system("cls");
        printf("\t\t**********TELEPHONE DIRECOTRY MAINTENANCE SOFTWARE**********\n"); 
        printf("\t\t*****************SEARCH USING PHONE NUMBER******************\n");
        printf("\n\t\tENTER EMPLOYEE PH NUMBER:-");
        char name[25],empid[20],depid[20],loc[5],phno[20],phno1[20];
        scanf("%s",phno);

        //comapring 2 strings
         while(fscanf(fp,"%s %s %s %s %s",name,empid,depid,loc,phno1)!=EOF)
        {
            if(strcmp(phno,phno1)==0)
            {   printf("\n\t\t======================================\n");
                printf("\t\tEMPLOYEE NAME          :- %s\n",name);
                printf("\t\tEMPLOYEE ID            :- %s\n",empid);
                printf("\t\tEMPLOYEE DEPARTMENT ID :- %s\n",depid);
                printf("\t\tEMPLOYEE LOC           :- %s\n",loc);
                printf("\t\tEMPLOYEE PHONE NUMBER  :- %s\n",phno1);
                printf("\t\t======================================\n");
                fclose(fp);
                printf("\t\tpress any key to continue\n");
                getch();
                return;
            }
            else
            {
                continue;
            }
            
            
        }
        fclose(fp);
        printf("\t\t!!!ERROR PHNO DOES NOT EXIST\n");
        printf("\t\tPress any key to go back\n");
        getch();
        return;
}