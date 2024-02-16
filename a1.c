#include<stdio.h>
int main()
{
struct _IO_FILE *u;
char g;
char name[26];
char contact_number[101];
int serial_number;
int i;

u=fopen("friends.fd","r");
if(u==NULL)
{
printf("NO FRIENDS\n");
return 0;
}

serial_number=0;
while(1)
{
g=fgetc(u);
if(feof(u)) break;
name[0]=g;
i=1;
while(1)
{
g=fgetc(u);
if(g=='!') break;
name[i]=g;
i++;
}
// logic to read name ends.
name[i]='\0';
i=0;
while(1)
{
g=fgetc(u);
if(g=='!') break;
contact_number[i]=g;
i++;
}
contact_number[i]='\0';
serial_number++;
printf("%10d %-25s %s\n",serial_number,name,contact_number);
}

fclose(u);
if(serial_number==0)	printf("No Friends record\n");

return 0;
}