#include <iostream>

unsigned long Fib(unsigned long Current)
{

    if(Current == 0){return 0;}
    else if(Current == 1) {return 1;}
    else
    {
    return Fib(Current-1)+ Fib(Current-2);
    }
}


int main()
{
    std::cout<<Fib(66)<<"\n";
}


