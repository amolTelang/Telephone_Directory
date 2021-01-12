//phono genertaor

void counterupdater(char []);
void add_number();
void phonnomaintainance();


extern char* phonenogenerator(char depCode[])
{	char temp[10],deptcode[10];
	
	//opening a file
	FILE *fp;
	fp=fopen("phnoupdater.txt","r+");
	while(fscanf(fp,"%s %s",deptcode,temp)!=EOF)
        {	
        	
            if(strcmp(deptcode,depCode)==0)
            {	
            	int phup=atoi(temp);

            	//if counter less than 10
            	if(phup<10)
            	{	fclose(fp);
            		char final[3]="00";
            		strcat(final,temp);
            		counterupdater(depCode);
            		strcat(depCode,final);
					return(depCode);
            	}

            	//if counter less than or eq to 100
            	else if(phup<=99)
    			{
    				fclose(fp);
        			char final[3]="0";
        			strcat(final,temp);
        			counterupdater(depCode);
        			return(strcat(depCode,final));
    			}


    			else
    			{	printf("\t\t!!!ERROR!!! MAX ALLOCATION COMPLETE\n");
        			return(strcat(depCode,temp));
    			}

            }
       
           
       		
       	}
       	printf("\t\t!!!!ERROR!!!\n\t\tTELEPHONE NO NOT FOUND\n");
        printf("\t\tpress any key to continue\n");
        getch();
        fclose(fp);
        phonnomaintainance();
    
}



//funtion to update the counter that keeps track of the telephone no per department 
void counterupdater(char code[])
{
	
	//opening the files
    FILE *fp,*fp1;
    fp=fopen("phnoupdater.txt","r+");
    fp1=fopen("temp1.txt","w");
  
	//searching the deptcode from the file
    char temp[10];
    char deptcode[10];
    while(fscanf(fp,"%s %s",deptcode,temp)!=EOF)
    {	
    	

    	if(strcmp(code,deptcode)==0)
    	{	
    		//code to update the counter
    		int phup=atoi(temp);
    	    phup=phup+1;
    		char up[10];
    		sprintf(up,"%d",phup);
    		strcpy(temp,up);

 	   	}
 	   	//printing the details to a temporary file
 	   	fprintf(fp1,"%s %s\n",deptcode,temp);
    }
    fclose(fp);
    fclose(fp1);

    //copying the details from the temporary file to the main counter file
    fp=fopen("phnoupdater.txt","w");
    fp1=fopen("temp1.txt","r");
    while(fscanf(fp1,"%s %s",deptcode,temp)!=EOF)
    {

        fprintf(fp,"%s %s\n",deptcode,temp);
    }
    fclose(fp);
    fclose(fp1);

    //deleting the temporary file
    remove("temp1.txt");
	
	//close
	return;
}
