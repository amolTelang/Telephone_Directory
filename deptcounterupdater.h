//update department counter for dept code
extern void updateddepcounter(int *depcode)
{	//local variables
	char temp1[10],temp2[10];
	char temp[10];
	//convertinfg integer to string to store in file
	itoa(*depcode,temp,10);
	//opening file
	FILE *fp;
	fp=fopen("updt.txt","r+");
	fscanf(fp,"%s %s",temp1,temp2);
	fclose(fp);
	//removing temp file
	remove("updt.txt");
	//recreating the original file
	fp=fopen("updt.txt","a+");
	fprintf(fp,"%s %s",temp,temp2);
	fclose(fp);
}
//funciton end

