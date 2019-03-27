#include <stdio.h>
#include "biblioteca.h"
//A=X;
//B=Y;


int sumarNumeros(int x,int y)
{
    int total;
    total = x + y;
    return total;
}



int restarNumeros(int x,int y)
{
    int total;
    total = x - y;
    return total;

}


int multiplicarNumeros(int x,int y)
{
    int total;
    total = x * y;
    return total;

}

float dividirNumeros(float x, float y)
{
    float total;


   while(y==0)
   {
       printf("ERROR: No se puede dividir por 0...");
       printf("Ingrese el segundo numero: ");
       scanf("%f",&y);

   }

   total = x / y;

    return total;

}

float calcularFactorialA(float x)
{
    float calculoA;
    float resultadoFactorialX = 1;

    while (x < 0)
    {
        printf("No se puede calcular el factorial de numeros negativos.\nIngrese un numero positivo para X.");
        scanf("%f", &x);
    }

    for (calculoA = 1; calculoA <= x; calculoA++)
    {

        resultadoFactorialX = resultadoFactorialX * calculoA;

    }

    return resultadoFactorialX;
}

float calcularFactorialB(float y)
{
    float calculoB;
    float resultadoFactorialY = 1;

    while (y < 0)
    {
        printf("No se puede calcular el factorial de numeros negativos.\nIngrese un numero positivo para Y.");
        scanf("%f", &y);
    }

    for (calculoB = 1; calculoB <= y; calculoB++)
    {

        resultadoFactorialY = resultadoFactorialY * calculoB;

    }

    return resultadoFactorialY;
}





