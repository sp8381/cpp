#include<stdio.h>

class Fridge;

class TV
{
int price;
public:
void setPrice(int price)
{
this->price=price;
}
int getPrice()
{
return this->price;
}
friend class Fridge;
};


class Fridge
{
int price;
public:
void setPrice(int price)
{
this->price=price;
}
int getPrice()
{
return this->price;
}

int operator<(TV &t)
{
return this->price<t.price;
}
int operator>(TV &t)
{
return this->price>t.price;
}
int operator==(TV &t)
{
return this->price==t.price;
}
friend class compare;
};


 
int main()
{
Fridge f;
TV t;
f.setPrice(50000);
t.setPrice(50000);
if(f<t)
{
printf("price of fridge is less than TV\n");
}
else if(f>t)
{
printf("price of fridge is greater than TV\n");
}
else if(f==t)
{
printf("price of fridge is equals to TV\n");
}
else 
{
printf("Invalid \n");
}
return 0;
}