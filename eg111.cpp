/*
VIRTUAL DESTRUCTOR 
In case of inheritance,
if a pointer is created of base class, 
and object of derived class and 
the memory is allocated through new 
and its address is assigned to base class pointer,
then when the memory will be released using delete operator 
then the derived class destructor won't get called
unless the base class destructor is declared as virtual.


For what destructor is used?
Destructor is used to perform clean up activities.


*/