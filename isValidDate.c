#include<stdio.h>
#include<string.h>

void isValidDate(const char *dateString,int *isValid,int *date,int *month,int *year)
{
int dd,mm,yy;
char sep;
int sepIndex1,sepIndex2;
int mth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

*isValid=0;
if(dateString==NULL) return;
int x=strlen(dateString);
if(x<8 || x>10) return;
if(!(dateString[1]=='/' || dateString[2]=='/' || dateString[1]=='-' || dateString[2]=='-')) return;
if(dateString[1]=='/' || dateString[1]=='-') sepIndex1=1;
else sepIndex1=2;
sep=dateString[sepIndex1];
if(dateString[0]<48 || dateString[0]>57) return;
if(sepIndex1==2 && (dateString[1]<48 || dateString[1]>57 || dateString[1]<48 || dateString[1]>57)) return ;
if(sepIndex1==1)
{
dd=dateString[0]-48;
if(dd==0) return;
}
else
{
dd=((dateString[0]-48)*10)+(dateString[1]-48);
if(dd==0) return;
}
int i=sepIndex1+1;
if(!(dateString[i+1]==sep || dateString[i+2]==sep)) return;
if(dateString[i+1]==sep) sepIndex2=i+1;
else sepIndex2=i+2;
if(dateString[i]<48 || dateString[i]>57) return ;
if(sepIndex2==i+2 && (dateString[i+1]<48 || dateString[i+1]>57)) return;
if(sepIndex2==i+1) 
{
mm=dateString[i]-48;
}
else 
{
mm=((dateString[i]-48)*10)+(dateString[i+1]-48);
}
if(mm<1 || mm>12) return ;
i=sepIndex2+1;
yy=0;

int r=0;
while(r<=3)
{
if(dateString[i+r]<48 || dateString[i+r]>57) return;
yy=(yy*10)+(dateString[i+r]-48);
r++;
}
if(yy<1901) return;
if(yy%400==0) mth[1]=29;
else if(yy%100==0) mth[1]=28;
else if(yy%4==0) mth[1]=29;
else mth[1]=28;
printf("dd %d\n",dd);
printf("mm %d\n",mm);
printf("yy %d\n",yy);

if(dd<1 || dd>mth[mm-1]) return;
if(mm<1 || mm>12) return;
*date=dd;
*month=mm;
*year=yy;
*isValid=1;
}

int main()
{
char dateString[51];
int d,m,y;
int isValid;
printf("Enter a date : ");
scanf("%s",dateString);
isValidDate(dateString,&isValid,&d,&m,&y);
if(isValid)
{
printf("Valid %d-%d-%d\n",d,m,y);
}
else
{
printf("Not Valid \n");
}
return 0;
}