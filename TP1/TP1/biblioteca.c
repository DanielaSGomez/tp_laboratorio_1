#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
//A=X;
//B=Y;


float sumarNumeros(float x,float y)
{
    float total;
    total = x + y;
    return total;
}



float restarNumeros(float x,float y)
{
    float total;
    total = x - y;
    return total;

}


float multiplicarNumeros(float x,float y)
{
    float total;
    total = x * y;
    return total;

}

float dividirNumeros(float x, float y)
{
    float total;

    total = x / y;

    return total;

}

float calcularFactorialA(float x)
{
   int factorial;

    if(x==0)
    {
        factorial=1;
    }
    else
    {
        factorial=x*calcularFactorialA(x-1);
    }

    return factorial;
}

float calcularFactorialB(float y)
{
   int factorial;

    if(y==0)
    {
        factorial=1;
    }
    else
    {
        factorial=y*calcularFactorialB(y-1);
    }

    return factorial;
}





