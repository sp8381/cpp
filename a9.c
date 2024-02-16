#include<stdio.h>
#include<string.h>

int main()
{
char rollNumber[11];
char name[21];
FILE *k;

printf("Enter roll number : ");
scanf("%s",&rollNumber);
while(getchar()!='\n');
rollNumber[strlen(rollNumber)]='\0';

printf("Enter name : ");
scanf("%s",name);
while(getchar()!='\n');
name[strlen(name)]='\0';

printf("%s \n %s\n",rollNumber,name);
//--------------------------------------------
k=fopen("student1.data","w");	
int i=0;
while(rollNumber[i]!='\0')
{
fputc(rollNumber[i],k);
i++;
}
fputc('!',k);
i=0;
while(name[i]!='\0')
{
fputc(name[i],k);
i++;
}
fputc('!',k);
fclose(k);
printf("Data added in file\n");
//--------------------------------------------

printf("Reading data from file\n");
char n[21];
char rn[11];
int sno;
char g;

FILE *u;
u=fopen("student1.data","r");
if(u==NULL) printf("File not opened\n");
printf("file opened\n");

sno=0;
while(1)
{
g=fgetc(u);
if(feof(u)) break;
rn[0]=g;
i=1;
while(1)
{
g=fgetc(u);
if(g=='!') break;
rn[i]=g;
i++;
}
rn[i]='\0';

i=0;
while(1)
{
g=fgetc(u);
if(g=='!') break;
n[i]=g;
i++;
}
n[i]='\0';
sno++;

printf("%d\n",sizeof(n));
printf("%d\n",sizeof(rn));
printf("%d  %s  %s\n",sno,rn,n);
}
printf("file closed\n");
fclose(u);

if(sno==0) printf("No data");
return 0;
}