#include<stdio.h>
namespace sales
{
int x=10;
int numberOftransation=50;
int getLastTransactionAmount()
{
return 1000;
}
}
namespace purchase
{
int y=200;
int numberOfTransaction=100;
int getLastTransactionAmount()
{
return 2000;
}
}
using namespace sales;
using namespace purchase;
int main()
{

int amount=sales::getLastTransactionAmount();
printf("Last Transaction Amount : %d\n",amount);
printf("%d\n",x);
printf("%d\n",y);
return 0;
}