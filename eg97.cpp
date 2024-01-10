/*
this POINTER 
A this pointer is provided by the compiler, to every non static method of the class.
this pointer stores the addres of the object for which it has been called.

changes by the compiler 
1.) add one parameter named as 'this'
type as name_of_class *
2.) In the methods attach 'this->' on the left side of the object variable(non static properties of the class)
3.)In code to call such methods(non static methods), an argument is added, argument(address of the object for which th method is called )
k.kalu() becomes k.kalu(&k);
m.kalia(20,30,'A') becomes m.kalia(20,30,'A',&m)
4.) we cannot declare the variable named as 'this' 
but we can use 'this' pointer

NOTE : 'this' is not a keyword.

class Bulb
{
int w;
void setWattage(int e,Bulb *this)
{
this->w=e;
}
int getWattage(Bulb *this)
{
return this->w;
}
};
int main()
{
Bulb b;
b.setWattage(60,&b);
cout<<b.getWattage(&b);

return 0;
}

*/