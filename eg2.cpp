#include<stdio.h>
namespace sales
{
int x=1000;
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
int main()
{
int amount=sales::getLastTransactionAmount();
printf("Last Transaction Amount(sales) : %d\n",amount);
amount=purchase::getLastTransactionAmount();
printf("Last Transaction Amount(purchase) : %d\n",amount);
return 0;
}