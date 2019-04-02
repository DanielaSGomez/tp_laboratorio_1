#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"//BIBLIOTECA DE MIS FUNCIONES

int main()//FUNCION PRINCIPAL DE LA CALCULADORA

{
//DECLARACION DE VARIABLES
    int opcion;
    float primerNumero;
    float segundoNumero;
    float suma = 0;
    float resta = 0;
    float division = 0;
    float multiplicacion = 0;
    float factorialA = 0;
    float factorialB = 0;
    int flagA = 0;
    int flagB = 0;

//PLANTEO DENTRO DEL BUCLE DO WHILE PARA QUE SE EJECUTE EL PROGRAMA POR LO MENOS UNA VEZ.

    do
    {

        printf("<----------MENU---------->");
        printf("\nIngrese la opcion que corresponda: \n");
        printf("\n1-Ingresar operando A.\n2-Ingresar operando B.\n3-Realizar operaciones:\n(Suma, Resta, Multiplicacion, Division, FActorial A, Factorial B).\n4-Resultados.\n5-Salir\n");
        if(flagA==1)
        {
            printf("\nNumero A: %.2f\n",primerNumero);
        }

        if(flagB==1)
        {
            printf("\nNumero B: %.2f\n",segundoNumero);
        }

        scanf("%d",&opcion);//TOMO LA OPCION ELEGIDA

        switch(opcion)//PLANTEO LOS CASOS SEGUN LA OPCION ELEGIDA
        {
            case 1:
                printf("Ingrese el primer numero: \n");
                scanf("%f",&primerNumero);
                flagA = 1;
                break;

            case 2:

                printf("\nIngrese el segundo numero: \n");
                scanf("%f",&segundoNumero);
                flagB =1;
                break;

            case 3:

                    suma = sumarNumeros(primerNumero,segundoNumero);
                    resta = restarNumeros(primerNumero,segundoNumero);
                    if(segundoNumero!=0)
                    {
                        division = dividirNumeros(primerNumero,segundoNumero);
                    }
                    else
                    {
                        printf("\nALERTA: No se puede dividir por 0\n");
                    }

                    multiplicacion = multiplicarNumeros(primerNumero,segundoNumero);

                    if(primerNumero>=0)
                    {
                        factorialA = calcularFactorialA(primerNumero);
                    }
                    else
                    {
                        printf("\nALERTA: No existen factoriales de numeros negativos\n");
                    }

                    if(segundoNumero>=0)
                    {
                         factorialB = calcularFactorialB(segundoNumero);
                    }
                    else
                    {
                        printf("\nALERTA: No existen factoriales de numeros negativos\n");
                    }


                printf("\nCalculos Realizados!\n");
                break;

            case 4:
                printf("\n<-------RESULTADOS------->\nEl resultado de la suma es: %.0f",suma);
                printf("\nEl resultado de la resta es: %.0f",resta);
                if(segundoNumero!=0)
                {
                    printf("\nEl resultado de la division es: %.2f",division);

                }
                else
                {
                   printf("\nDivision: no se puede realizar la division por 0");
                }

                printf("\nEl resultado de la multiplicacion es: %.0f",multiplicacion);

                if(primerNumero<0)
                {
                    printf("\nFactorial de A: No se pueden calcular factoriales de numeros negativos");
                }
                else
                {
                  printf("\nEl resultado del factorial A es: %.2f",factorialA);
                }

                if(segundoNumero<0)
                {
                    printf("\nFactorial de B: No se pueden calcular factoriales de numers negativos");
                }
                else
                {
                    printf("\nEl resultado del factorial B es: %.2f\n",factorialB);
                }

                break;

            case 5:
                printf("La calculadora se cerrara... :( \n");
                break;

            default:
                printf("\nOpcion incorrecta");
        }
        system("pause");
        system("cls");


    }while(opcion!=5);//SI EL USUARIO INGRESA LA OPCION 5 SE CIERRA EL PROGRAMA.

return 0;

}
