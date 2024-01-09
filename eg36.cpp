//here also the programmer has provided the address of the encapusulated member
//returned address of block string
//title[0];
#include<iostream>
#include<string.h>
using namespace std;
class Book
{
private:
char title[36];
public:
void setTitle(const char *t)
{
if(strlen(t)>35)	title[0]='\0';
else strcpy(title,t);
}
char *getTitle()
{
return title;
}
};
int main()
{
char *k;
Book b;
k=b.getTitle();
strcpy(k,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
cout<<"Title : "<<b.getTitle()<<endl;
return 0;
}