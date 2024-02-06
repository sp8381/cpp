#include<iostream>
using namespace std;
class PiggyBank
{
int amount;
public:
PiggyBank();
PiggyBank(int amount);
void setAmount(int amount);
int getAmount();
PiggyBank operator+(PiggyBank &other);
};
PiggyBank::PiggyBank()
{
this->amount=0;
}
PiggyBank::PiggyBank(int amount)
{
this->amount=amount;
}
void PiggyBank::setAmount(int amount)
{
this->amount=amount;
}
int PiggyBank::getAmount()
{
return this->amount;
}
PiggyBank PiggyBank::operator+(PiggyBank &other)
{
int total = this->amount=other.amount;
return total;
}
int main()
{
PiggyBank b1(100),b2(200),b3;
b3=b1+b2;
cout<<b3.getAmount()<<endl;
return 0;
}