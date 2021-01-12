//employee code updater
extern void updateEmpCode(int *empCode)
{	char temp1[10],temp2[10];
	char temp[20];
	itoa(*empCode,temp,10);
	//opening file
	FILE *fp;
	fp=fopen("updt.txt","r+");
	fscanf(fp,"%s %s",temp1,temp2);
	fclose(fp);
	//closing the file
	remove("updt.txt");
	//removing temp file
	//recreating org file
	fp=fopen("updt.txt","a+");
	//store final data in file
	fprintf(fp,"%s %s",temp1,temp);
	fclose(fp);}
//function end