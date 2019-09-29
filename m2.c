
#include<stdio.h>

#include<stdlib.h>
void main()
{

	char ch, choice, fname[20];
	FILE *fps, *fpt;
	printf("Enter file name to save the decrytpet file which you have encrypted : ");
	gets(fname);
int n,n1,temp;

	printf("enter a eight digit pin (only numbers)\n");
	scanf("%d",&n1);
	temp=n1;

	n=1;
	while(n1!=0)
	{
		n=n*(n1%10+1);
		n1=n1/10;

	}
	n=n%100;
	n=100-n;
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nPress any key to exit...");
		getchar();
		exit(7);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file..!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		getchar();
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-n;
			fputc(ch, fps);
		}
	}
	printf("File %s decrypted successfully..!!",fname);
	printf("\nPress any key to exit...");
	fclose(fps);
	fclose(fpt);
	getchar();
}

